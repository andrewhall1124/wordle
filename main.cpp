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
    }
    return 0;
}