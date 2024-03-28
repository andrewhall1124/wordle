#include "Word.h"
#include "Result.h"

class Guess{
  private:
    Word word;
    Result result;

  public:
    Guess(Word word, Result result): word(word),result(result){};
};