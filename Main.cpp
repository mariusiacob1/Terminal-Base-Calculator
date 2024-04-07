#include "Calculator.h"
#include <iostream>
#include <string>

int main() {
    string input;
    cout << "Enter your calculation: ";
    getline(cin, input);

    Calculator calc;
    int result = calc.evaluate(input);

    cout << "Result: " << result << endl;

    return 0;
}
