#pragma once
#include "Guess.h"

using namespace std;

class Game{
  private:
    vector<Guess> guesses;

  public:
    Game(){}

    void addGuess(Guess guess){
      guesses.push_back(guess);
    }

    string toString(){
      stringstream out;
      for(Guess guess : guesses){
        out << guess.toString() << endl;
      }
      return out.str();
    }
};