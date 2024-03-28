#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Game.h"
#include "Word.h"
#include "Result.h"
#include "Guess.h"

using namespace std;

int main()
{
    string input;
    Game game;
    game.loadWordBank();
    while(input != "Correct"){
        cout << "Guess: ";
        cin >> input;
        if(input == "Correct"){
            break;
        }
        Word word(input);
        cout << "Response: ";
        cin >> input;
        Result result(input);
        Guess guess(word, result);
        game.addGuess(guess);
        cout << "Next guess: " << game.genGuess() << endl;
    }
    return 0;
}