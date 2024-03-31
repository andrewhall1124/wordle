#pragma once

using namespace std;
class Game{
  private:
    vector<string> guesses;
    vector<string> wordBank;
    vector<string> remainingWords;

    void loadWordBank(){
      cout << "Loading word bank..." << endl;
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
      remainingWords = wordBank;

      file.close();
      cout << "Complete!" << endl;
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

  public:
    Game(){
      loadWordBank();
    }

    void addGuess(string guess, string result){
      guesses.push_back(guess);
      updateRemainingWords(guess, result);
    }

    string firstGuess(string guess, string result){
      return "guess" + '\n';
    }

    string getRemainingWords(){
      stringstream out;
      int cols = 5;
      for(int i = 0; i < remainingWords.size(); i++){
        string word = remainingWords[i];
        out << word << "    ";
        if((i + 1) % cols == 0){
          out << endl;
        }
      }
      return out.str();
    }
};