#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;


int Calculator::wordToNumber(const string& word) {
    // create a map of words to numbers
    static map<string, int> wordMap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
        {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
        {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60},
        {"seventy", 70}, {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000}
    }; 
    
    int number = 0;
    int temp = 0; 
    stringstream ss(word);
    string token;

    while (ss >> token) {
        if (wordMap.find(token) != wordMap.end()) { // if token is found in wordMap
            temp += wordMap[token]; // add the value of token to temp
        } else if (token == "and") { // if token is "and", skip it
            continue;
        } else {
            if (temp > 0) { // if temp is not 0
                number += temp; // add the value of temp to number
                temp = 0; // reset temp to 0
            }
            number *= 10; // multiply number by 10
            number += wordMap[token]; // add the value of token to number
        }
    }
    number += temp; // add the value of temp to number
    return number;
}

int Calculator::calculate(int operand1, int operand2, char operation) {
    switch(operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                cout << "Error: Division by zero" << endl;
                return 0;
            }
        default:
            cout << "Error: Invalid operation" << endl;
            return 0;
    }
}

int Calculator::evaluate(const string& input) {
    stringstream ss(input);
    string word;
    int result = 0;
    int operand1, operand2;
    char operation = '\0';
    bool isFirstOperand = true;

    while (ss >> word) {
        if (word == "plus" || word == "sum" || word == "add" || word == "added" 
         || word == "addition" || word == "increase" || word == "increased" || word == "total"
         || word == "combine" || word == "combined" || word == "join" || word == "joined"
         || word == "append" || word == "appended") 
        { operation = '+'; } 
        
        else if (word == "minus" || word == "sub"|| word == "subtract" || word == "subtracted"
         || word == "subtraction" || word == "decrease" || word == "decreased" || word == "difference"
         || word == "less" || word == "lessen" || word == "lessened" || word == "reduce" || word == "reduced"
         || word == "take away" || word == "taken away" || word == "deduct" || word == "deducted")
        { operation = '-'; } 
        
        else if (word == "times" || word == "multiply" || word == "multiplied" || word == "multiplication"
         || word == "multiplied by" || word == "product" || word == "timesed" || word == "timesing" || word == "timeses") 
        { operation = '*'; } 
        
        else if (word == "divide" || word == "divided" || word == "divided by" || word == "split") 
        { operation = '/'; } 
        
        else {
            int number = wordToNumber(word);
            if (isFirstOperand) {
                operand1 = number;
                isFirstOperand = false;
            } 
            else {
                operand2 = number;
                result = calculate(operand1, operand2, operation);
                operand1 = result;
                operation = '\0';
            }
        }
    }

    return result;
}