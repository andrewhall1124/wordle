#pragma once
#include <string>

using namespace std;

class Word{
  private:
    string value;

  public:
    Word(string value): value(value) {};

    string toString(){
      return value;
    }

};