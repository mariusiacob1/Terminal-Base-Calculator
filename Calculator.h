#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
using namespace std;

class Calculator {
private:
    int wordToNumber(const string& word);
    int calculate(int operand1, int operand2, char operation);

public:
    Calculator() {}
    int evaluate(const string& input);
    
};

#endif // CALCULATOR_H
