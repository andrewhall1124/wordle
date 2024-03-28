#pragma once
#include "Guess.h"
#include <vector>

using namespace std;

class Game{
  private:
    vector<Guess> guesses;

  public:
    Game(){}

    void addGuess(Guess guess){
      guesses.push_back(guess);
    }
};