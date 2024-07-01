#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Operations.h"
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>

// add debugging messages to check where errors are occuring

// parse input function
// add a way to prevent user from typing 2*3*7 for example, as this doesn't work currently.
void parseInput(const std::string& input, double& a, double& b, char& op, std::string& func, double prevAns){

    size_t ansPos = input.find("ANS");
    std::string tempInput = input;
    if (ansPos != std::string::npos) {
        tempInput.replace(ansPos, 3, std::to_string(prevAns));
    }

    // Count occurrences of functions and operators
    int functionCount = 0;
    if (tempInput.find("log(") != std::string::npos) functionCount++;
    if (tempInput.find("exp(") != std::string::npos) functionCount++;
    if (tempInput.find("ln(") != std::string::npos) functionCount++;
    if (tempInput.find("sqrt(") != std::string::npos) functionCount++;
    if (tempInput.find("!") != std::string::npos) functionCount++;

    int operatorCount = 0;
    for (char ch : tempInput) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            operatorCount++;
        }
    }

    // Check if more than one function or operator is present
    if (functionCount > 1 || operatorCount > 1 || (functionCount > 0 && operatorCount > 0)) {
        throw std::runtime_error("Error: Multiple functions or operators are not allowed.");
    }

    // search for functions log, exp, factorial, ln
    if (tempInput.find("log(") != std::string::npos){
        //std::cout << "Found log function. \n"; //debug
        func = "log";
        size_t start = tempInput.find('(') + 1;
        size_t end = tempInput.find(')');
        if (end == std::string::npos) throw std::runtime_error("Error: Missing closed parenthesis for log function.");
        //std::string debug = tempInput.substr(start, end - start); // debug
        //std::cout << debug << std::endl; // debug
        a = std::stod(tempInput.substr(start, end - start)); // issue with stod() when ANS is used
        return;
    }
    else if (tempInput.find("!") != std::string::npos) {
        //std::cout << "Found factorial function. \n"; //debug
        func = "factorial";
        // std::string temp = tempInput.substr(0, tempInput.length() - 1);
        // if (temp.find(".") != std::string::npos){
        //     // if input is NOT integer
        //     throw std::runtime_error("Invalid argument, must be integer value.");
        // }
        a = std::stod(tempInput.substr(0, tempInput.length() - 1));
        return;
    }
    else if (tempInput.find("exp(") != std::string::npos){
        //std::cout << "Found exponential function. \n"; //debug
        func = "exponential";
        size_t start = tempInput.find('(') + 1;
        size_t end = tempInput.find(')');
        if (end == std::string::npos) throw std::runtime_error("Error: Missing closing parenthesis for exp function.");
        a = std::stod(tempInput.substr(start, end - start));
        return;
    }
    else if (tempInput.find("ln(") != std::string::npos){
        //std::cout << "Found ln function. \n"; //debug
        func = "ln";
        size_t start = tempInput.find('(') + 1;
        size_t end = tempInput.find(')');
        if (end == std::string::npos) throw std::runtime_error("Error: Missing closing parenthesis for ln function.");
        a = std::stod(tempInput.substr(start, end - start));
        return;
    }
    else if (tempInput.find("sqrt(") != std::string::npos){
        //std::cout << "Found square root function. \n"; //debug
        func = "sqrt";
        size_t start = tempInput.find('(') + 1;
        size_t end = tempInput.find(')');
        if (end == std::string::npos) throw std::runtime_error("Error: Missing closing parenthesis for sqrt function.");
        a = std::stod(tempInput.substr(start, end - start));
        return;
    }

    std::istringstream iss(tempInput);
    if (!(iss >> a)) throw std::runtime_error("Error: Invalid input format.");
    if (!(iss >> op)) throw std::runtime_error("Error: Operator not found.");
    if (!(iss >> b)) throw std::runtime_error("Error: Second operand not found."); // should find errors in user input

    // Validate operator
    if (op != '+' && op != '-' && op != '*' && op != '/' && op != '^') {
        throw std::runtime_error("Error: Invalid operator.");
    }
}

double performOperation(double a, double b, char op, const std::string& func){
    // use try and catch statements to catch errors
    try {
        
    if (func == "log"){
        //std::cout << "Performing log. \n"; //debug
        return logten(a);
    }
    else if (func == "factorial"){
        //std::cout << "Performing factorial. \n"; //debug
        return factorial(a);
    }
    else if (func == "exponential"){
        //std::cout << "Performing exponential. \n"; //debug
        return expn(a);
    }
    else if (func == "ln"){
        //std::cout << "Performing ln. \n"; //debug
        return ln(a);
    }
    else if (func == "sqrt"){
        //std::cout << "Performing sqrt. \n"; //debug
        return sqroot(a);
    }
    else if (op != '\0'){
    switch (op) {
        case '+': return add(a, b);
        case '-': return sub(a, b);
        case '*': return product(a, b);
        case '/': return divide(a, b);
        case '^': return power(a, b); 
    }
    }
    else {
    //std::cout << "function not found. \n"; //debug
    return 0.0;
    }

    }
    catch (std::string msg){
        //std::cout << "error caught in peformOperation \n"; // debug
        std::cerr << msg << std::endl;
        throw;
        return 0.0;
    }

    return 0.0;
    
}

#endif