#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include "Game.h"
#include "Word.h"
#include "Result.h"
#include "Guess.h"

using namespace std;

int main()
{
    string input;
    Game game;
    while(input != "Correct"){
        cout << "Guess: ";
        cin >> input;
        if(input == "Correct"){
            break;
        }
        string word = input;
        cout << "Response: ";
        cin >> input;
        Result result(input);
        Guess guess(word, result);
        game.addGuess(guess);
        cout << "Next guess: "  << endl << game.genGuess() << endl;
        cout << "Next guess: " <<  game.genGuess2() << endl;
        cout << endl;
    }
    return 0;
}