#pragma once
#include "Guess.h"
#include "Word.h"

using namespace std;
class Game{
  private:
    vector<Guess> guesses;
    vector<Word> wordBank;
    vector<Word> remainingWords;

    void loadWordBank(){
      cout << "Loading word bank..." << endl;
      ifstream file("wordle.csv");
      if (!file.is_open()) {
          cout << "Error opening file." << endl;
      }

      string line;
      while (getline(file, line)) {
          vector<string> tokens = split(line, ',');
          Word word(tokens[0]);
          word.setOccurence(tokens[1]);
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

    void removeWords(Guess guess) {
      vector<Word> newWords;
      for (Word word : remainingWords) {
        cout << word.toString() << endl;


        bool addWord = true;

        for (int col = 0; col < guess.getWord().size(); col++) {
          cout << "Col: " << col << endl;

          char letter = guess.getWord().at(col);
          char type = guess.getResult().at(col);

          switch (type) {
            // First remove words that don't have letter in position i (Green)
            case 'G':
                if (word.at(col) != letter) {
                    addWord = false;
                }
                break;
            // Second remove words that have letter (Grey)
            case 'X':
                for (char character : word.toString()) {
                    if (character == letter) {
                        addWord = false;
                        break;
                    }
                }
                break;
            // Third remove words that have letter in position i (Yellow)
            // Also remove words that don't have letter
            case 'Y':
              if(word.at(col) == letter){
                addWord = false;
              }
              bool hasLetter = false;
              for (char character : word.toString()) {
                  if (character == letter) {
                      hasLetter = true;
                      break;
                  }
              }
              if (!hasLetter) {
                  addWord = false;
              }
              break;
          }
        }
        if (addWord){
            newWords.push_back(word);
        }
        remainingWords = newWords;
      }
    }

  public:
    Game(){
      loadWordBank();
    }

    

    void addGuess(Guess guess){
      guesses.push_back(guess);
      //Remove words from remainingWords
      cout << "Prev Length: " << remainingWords.size() << endl;
      removeWords(guess);
      cout << "New Length: " << remainingWords.size() << endl;
    }

    string genGuess(){
      stringstream out;
      for(Word word : remainingWords){
        out << word.toString() << endl;
      }
      return out.str();
    }

    string genGuess2(){
      map<char,int> letterMap;
      bool knownColumns[5] = {false, false, false, false, false};

      //Find known columns
      for(Guess guess : guesses){
        Result result = guess.getResult();
        for(int i = 0; i < 5; i++){
          char letter = result.toString().at(i);
          if(letter == 'G'){
            knownColumns[i] = true;
          }
        }
      }

      //Count letter in unknownColumns
      for(Word word : remainingWords){
        for(int i = 0; i < word.toString().size(); i++){
          if(!knownColumns[i]){
            char letter = word.toString().at(i);
            if(letterMap.find(letter) == letterMap.end()){
              //Key does not exist
              letterMap[letter] = 1;
            }
            else{
              //Key does exist
              int count = letterMap[letter];
              letterMap[letter] = count + 1;
            }
          }
        }
      }

      //Create sorted vector of most frequent letters
      // Sort letterMap based on count in descending order
      vector<pair<char, int>> sortedCounts(letterMap.begin(), letterMap.end());
      sort(sortedCounts.begin(), sortedCounts.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
          return a.second > b.second;
      });
      for (const auto& pair : sortedCounts) {
        cout << pair.first << ": " << pair.second << endl;
      }

      //Find word made up of most common letter. 
      string result = "";
      int letterIndex = 0;
      for(int i = 0; i < sortedCounts.size(); i++){
        //Create vector of letters to check
        vector<char> check;
        for(int j = letterIndex; j < 5+letterIndex; j++){
          char addLetter = sortedCounts[j].first;
          check.push_back(addLetter);
        }
        //Iterate over all remaining words
        for(int k = 0; k < remainingWords.size(); k++){
          Word word = remainingWords[k];
          if(word.containsAll(check)){
            result = word.toString();
            break;
          }
        }
      }

      return "";
    }

    string toString(){
      stringstream out;
      for(Guess guess : guesses){
        out << guess.toString() << endl;
      }
      return out.str();
    }
};