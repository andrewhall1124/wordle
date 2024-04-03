#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include "Game.h"

using namespace std;

int main(){
    Game game;

    string guess;
    string result;

    bool complete = false;
    while(!complete){
        cout << endl << "Guess: ";
        cin >> guess;
        cout << "Result: ";
        cin >> result;
        game.addGuess(guess, result);
        cout << game.getRemainingWords() << endl;
        cout << game.getMostCommonLetters() << endl;
        cout << game.nextGuess(guess, result) << endl;
        complete = game.getComplete();
    }
    
    return 0;
}