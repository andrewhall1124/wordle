#pragma once

using namespace std;
class Game{
  private:
    vector<string> guesses;
    vector<string> wordBank;
    vector<string> remainingWords;

    void loadWordBank(){
      cout << "Loading word bank..." << endl;
      ifstream file("wordle.csv");
      if (!file.is_open()) {
          cout << "Error opening file." << endl;
      }

      string line;
      while (getline(file, line)) {
          vector<string> tokens = split(line, ',');
          string word(tokens[0]);
          wordBank.push_back(word);
      }
      remainingWords = wordBank;

      file.close();
      cout << "Complete!" << endl;
    }

    vector<string> split(const string& s, char delimiter) {
      vector<string> tokens;
      string token;
      istringstream tokenStream(s);
      while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
      }
      return tokens;
    }

  public:
    Game(){
      loadWordBank();
    }

    string toString(){
      stringstream out;
      for(string guess : guesses){
        out << guess << endl;
      }
      return out.str();
    }
};