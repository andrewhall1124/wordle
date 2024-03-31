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

    bool contains(char letter){
      for(char c : value){
        if(c == letter){
          return true;
        }
      }
      return false;
    }

    bool containsAll(vector<char> letters){
      for(char letter : letters){
        if(!contains(letter)){
          return false; 
        }
      }
      return true;
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