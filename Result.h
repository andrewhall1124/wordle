#pragma once

using namespace std;

class Result{
  private:
    string value;
  public:
    Result(string value): value(value){}

    string toString(){
      return value;
    }
};