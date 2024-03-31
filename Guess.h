#pragma once
#include "Word.h"
#include "Result.h"

class Guess{
  private:
    string word;
    Result result;

  public:
    Guess(string word, Result result): word(word),result(result){};

    Result getResult(){
      return result;
    }

    Word getWord(){
      return word;
    }

    string toString(){
      stringstream out;
      out << "Word: " << word << endl;
      out << "Result: " << result.toString() << endl;
      return out.str();
    }
};