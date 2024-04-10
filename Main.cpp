#include "Calculator.h"
#include <iostream>
#include <string>

int main() {
    Calculator calculator;
    std::string input;

    while (true) {
        std::cout << "Enter calculation (digits and operators only, type 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Exiting..." << std::endl;
            break;
        }

        int result = calculator.calculate(input);
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
