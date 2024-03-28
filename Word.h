#pragma once

using namespace std;

class Word{
  private:
    string value;
    string occurence;

  public:
    Word(string value): value(value) {};

    void setOccurence(string occurence){
      occurence = occurence;
    }

    bool has(char letter, int index){
      return value.at(index) == letter;
    }

    char at(int index){
      return value.at(index);
    }

    int size(){
      return value.length();
    }

    string toString(){
      return value;
    }

};