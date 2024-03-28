#include <iostream>
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
        Word word(input);
        cout << "Response: ";
        cin >> input;
        Result result(input);
        Guess guess(word, result);
        game.addGuess(guess);
    }
    return 0;
}