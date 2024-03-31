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

    //Initial guess
    cout << "Guess: ";
    cin >> guess;
    cout << "Result: ";
    cin >> result;
    //Initial sugguestion 
    game.addGuess(guess, result);
    cout << endl << "Remaining words: " << endl;
    cout << game.getRemainingWords() << endl;
    cout << endl << "Most common letters: " << endl;
    cout << game.getMostCommonLetters() << endl;
    cout << endl << "Next guess: ";
    cout << game.firstGuess(guess, result) << endl;

    //Guess 2
    cout << "Guess: ";
    cin >> guess;
    cout << "Result: ";
    cin >> result;
    //Suggestion 2
    game.addGuess(guess, result);
    cout << endl << "Remaining words: " << endl;
    cout << game.getRemainingWords() << endl;
    cout << endl << "Most common letters: " << endl;
    cout << game.getMostCommonLetters() << endl;
    cout << endl << "Next guess: ";
    cout << game.firstGuess(guess, result) << endl;
    cout << endl;

    //Guess 3
    cout << "Guess: ";
    cin >> guess;
    cout << "Result: ";
    cin >> result;
    //Suggestion 3
    game.addGuess(guess, result);
    cout << endl << "Remaining words: " << endl;
    cout << game.getRemainingWords() << endl;
    cout << endl << "Most common letters: " << endl;
    cout << game.getMostCommonLetters() << endl;
    cout << endl << "Next guess: ";
    cout << game.secondGuess(guess, result) << endl;
    cout << endl;

    //Guess 4
    cout << "Guess: ";
    cin >> guess;
    cout << "Result: ";
    cin >> result;
    //Suggestion 4
    game.addGuess(guess, result);
    cout << endl << "Remaining words: " << endl;
    cout << game.getRemainingWords() << endl;
    cout << endl << "Most common letters: " << endl;
    cout << game.getMostCommonLetters() << endl;
    cout << endl << "Next guess: ";
    cout << game.secondGuess(guess, result) << endl;
    cout << endl;
    return 0;
}