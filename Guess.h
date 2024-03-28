#pragma once
#include "Word.h"
#include "Result.h"

class Guess{
  private:
    Word word;
    Result result;

  public:
    Guess(Word word, Result result): word(word),result(result){};

    string toString(){
      stringstream out;
      out << "Word: " << word.toString() << endl;
      out << "Result: " << result.toString() << endl;
      return out.str();
    }
};