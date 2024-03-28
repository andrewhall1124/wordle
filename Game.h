#pragma once
#include "Guess.h"
#include "Word.h"

using namespace std;
class Game{
  private:
    vector<Guess> guesses;
    vector<Word> wordBank;
    vector<Word> remainingWords;

    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    void removeWords(Guess guess){
      for(int col = 0; col < guess.getWord().size(); col++){
        for(int index = 0; index < remainingWords.size(); index++){
          char letter = guess.getWord().at(col);
          char type = guess.getResult().at(col);
          Word word = remainingWords.at(index);
          vector<Word> newWords;
          switch(type){
            //First remove words that dont' have letter in position i (Green)
            case 'G':
              if(word.at(col) == letter){
                newWords.push_back(word);
              }
              break;
            //Second remove words that have letter (Grey)
            case 'X':
              for(char character : word.toString()){
                if(character == letter){
                  return;
                }
              }
              newWords.push_back(word);
              break;
            //Third remove letter that have letter in position i (Yellow)
            case 'Y':
              if(word.at(col) != letter){
                newWords.push_back(word);
              }
              break;
          }
          remainingWords = newWords;
        }
      }
    }

  public:
    Game(){}

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

    string toString(){
      stringstream out;
      for(Guess guess : guesses){
        out << guess.toString() << endl;
      }
      return out.str();
    }
};