#include <iostream>
#include "Game.h"
#include "Word.h"
#include "Result.h"
#include "Guess.h"

using namespace std;

int main()
{
    string guess;
    string response;
    Game game;
    while(guess != "Correct"){
        cout << "Guess: ";
        cin >> guess;
        cout << "Response: ";
        cin >> response;
        Word word(guess);
        Result result(response);
        Guess guess(word, result);
    }
    return 0;
}