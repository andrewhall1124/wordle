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
    cout << "Guess: ";
    cin >> guess;
    cout << "Result: ";
    cin >> result;

    game.addGuess(guess, result);
    cout << endl << "Remaining words: " << endl;
    cout << game.getRemainingWords() << endl;
    cout << endl << "Next guess: ";
    cout << game.firstGuess(guess, result) << endl;

    cout << "Guess: ";
    cin >> guess;
    cout << "Result: ";
    cin >> result;

    game.addGuess(guess, result);
    cout << endl << "Remaining words: " << endl;
    cout << game.getRemainingWords() << endl;
    cout << endl << "Next guess: ";
    cout << game.firstGuess(guess, result) << endl;
;

    return 0;
}