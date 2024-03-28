#pragma once

using namespace std;

class Result{
  private:
    string value;
  public:
    Result(string value): value(value){}

    char at(int index){
      return value.at(index);
    }

    string toString(){
      return value;
    }
};