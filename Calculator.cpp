#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <cctype>

int Calculator::calculate(std::string query) {
    std::istringstream iss(query);
    char op = '+';
    int result = 0;
    int temp;
    
    while (iss >> temp) {
        switch (op) {
            case '+':
                result += temp;
                break;
            case '-':
                result -= temp;
                break;
            case '*':
                result *= temp;
                break;
            case '/':
                if (temp == 0) {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    return 0;
                }
                result /= temp;
                break;
        }
        
        if (!(iss >> op)) break; // If no more operator, break out
    }
    
    return result;
}
