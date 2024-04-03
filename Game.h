#pragma once

using namespace std;
class Game{
  private:
    vector<string> guesses;
    vector<string> results;
    vector<string> wordBank;
    vector<string> remainingWords;
    bool complete = false;

    void loadWordBank(){
      ifstream file("wordle.csv");
      if (!file.is_open()) {
          cout << "Error opening file." << endl;
      }

      string line;
      while (getline(file, line)) {
          vector<string> tokens = split(line, ',');
          string word(tokens[0]);
          wordBank.push_back(word);
      }

      file.close();
    }

    void loadRemainingWords(){
      ifstream file("remaining_words.csv");
      if (!file.is_open()) {
          cout << "Error opening file." << endl;
      }

      string line;
      while (getline(file, line)) {
          vector<string> tokens = split(line, ',');
          string word(tokens[0]);
          remainingWords.push_back(word);
      }

      file.close();
    }

    vector<string> split(const string& s, char delimiter) {
      vector<string> tokens;
      string token;
      istringstream tokenStream(s);
      while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
      }
      return tokens;
    }

    void updateRemainingWords(const string& guess, const string& result) {
      vector<string> newRemainingWords;

      for (const string& word : remainingWords) {
        bool keepWord = true;
        vector<int> letterIndices(26, -1);  // Initialize with -1 for all letters

        // Mark the indices of each letter in the word
        for (int i = 0; i < word.size(); ++i) {
            letterIndices[word[i] - 'a'] = i;
        }

        for (int i = 0; i < guess.size(); ++i) {
            char letter = guess[i];
            char type = result[i];

            switch (type) {
              case 'G':  // Green: The letter is in the word and in the correct spot
                if (word[i] != letter) {
                    keepWord = false;
                }
                break;
              case 'X':  // Gray: The letter is not in the word
                if (letterIndices[letter - 'a'] != -1) {
                    keepWord = false;
                }
                break;
              case 'Y':  // Yellow: The letter is in the word but in the wrong spot
                if (word[i] == letter || letterIndices[letter - 'a'] == -1) {
                    keepWord = false;
                } else {
                    letterIndices[letter - 'a'] = -2;  // Mark the letter as used
                }
                break;
            }
            if (!keepWord) break;
        }
        if (keepWord) {
            newRemainingWords.push_back(word);
        }
      }
      remainingWords = move(newRemainingWords);
    }

    vector<pair<char,int>> mostCommonLetters(){
      vector<bool> knownColumns(5,false);
      for(string result : results){
        for(int i = 0; i < result.size(); i++){
          if(result[i] == 'G'){
            knownColumns[i] = true;
          }
        }
      }

      map<char, int> letterMap;
      for (char c = 'a'; c <= 'z'; c++) {
          letterMap[c] = 0;
      }

      for (const string& word : remainingWords) {
          for (int i = 0; i < word.size(); i++) {
              if (knownColumns[i]) {
                  continue;
              }
              char letter = word[i];
              letterMap[letter]++;
          }
      }

      for(int i = 0; i < results.size(); i++){
        string guess = guesses[i];
        string result = results[i];
        for(int j = 0; j < result.size(); j++) {
          char type = result[j];
          if(type == 'G'){
            letterMap[guess[j]] = 0;
          }
        }
      }

      vector<pair<char, int>> letterCountPairs(letterMap.begin(), letterMap.end());
      sort(letterCountPairs.begin(), letterCountPairs.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
          return a.second > b.second;
      });

      return letterCountPairs;
    }

  public:
    Game(){
      loadWordBank();
      loadRemainingWords();
    }

    void addGuess(string guess, string result){
      guesses.push_back(guess);
      results.push_back(result);
      updateRemainingWords(guess, result);
    }

    string optimalGuess(string guess, string result){
      vector<pair<char,int>> commonLetters = mostCommonLetters();
      int maxCount = 0;
      string bestWord;
      for (const string& word : wordBank) {
        int count = 0;
        for (pair letter : commonLetters) {
            if (word.find(letter.first) != string::npos) {
                count+=letter.second;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            bestWord = word;
        }
      }

      return bestWord;
    }

    string nextGuess(string guess, string result){
      stringstream out;
      out << endl << "Next guess: ";
      if(remainingWords.size() == 1){
        out << remainingWords[0] << endl;
        complete = true;
      }
      else{
        out << optimalGuess(guess, result);
      }
      return out.str();
    }

    string getRemainingWords(){
      stringstream out;
      out << endl << "Remaining words ("<< remainingWords.size() << "): " << endl;
      int cols = 8;
      if(remainingWords.size() <= 8){
        for(int i = 0; i < remainingWords.size(); i++){
          string word = remainingWords[i];
          out << word << "    ";
          if((i + 1) % cols == 0 && (i + 1) != cols){
            out << endl;
          }
        }
      }
      return out.str();
    }

    string getMostCommonLetters(){
      stringstream out;
      out << endl << "Most common letters: " << endl;
      int cols =8;
      vector<pair<char,int>> commonLetters = mostCommonLetters();
      for(int i = 0; i < commonLetters.size(); i++){
        char letter = commonLetters[i].first;
        int count = commonLetters[i].second;
        if(!count == 0){
          out << letter << ": " << count << "    ";
          if((i + 1) % cols == 0){
            out << endl;
          }
        }
      }
      return out.str();
    }

    bool getComplete(){
      return complete;
    }
};