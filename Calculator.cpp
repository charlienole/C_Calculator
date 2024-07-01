#include "Operations.h"
#include "Functions.h"

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

int main() {
// introduce available functions

std::cout << "Welcome to this calculator program!\nThe functions available to the user, for real numbers A and B, are defined below: \n";
    // a+b
    std::cout << "  'A+B' -> adds A and B. \n";
    // a-b
    std::cout << "  'A-B' -> subtracts B from A. \n";
    // a*b
    std::cout << "  'A*B' -> multiplies A and B. \n";
    // a/b
    std::cout << "  'A/B' -> divides A by B. \n";
    // a^b
    std::cout << "  'A^B' -> raises A to the power of B. \n";
    // sqrt(a)
    std::cout << "  'sqrt(A)' -> calculates the square root of A. \n";
    // exp(a) (e^a)
    std::cout << "  'exp(A)' -> raises e to the power of A. \n";
    // log(a) (base 10)
    std::cout << "  'log(A)' -> calculates log (base 10) of A. \n";
    // ln(a) (base e)
    std::cout << "  'ln(A)' -> calculates the natural log of A. \n";
    // a! (factorial)
    std::cout << "  'A!' -> calculates the factorial of A. \n";
    // ANS
    std::cout << "  'ANS' -> carries value of the previous result to be used in further calculations. \n";
    // X
    std::cout << "  'X' -> exits calculator program. \n\n";


// how to allow for user to enter multiple functions at once? BEDMAS like 2*(3/7)^4 etc. ???

// store previous answer in variable so user can call ANS
// wait for user input, call functions accordingly
// user types X to exit program

std::string input;
int n = 1;
double previousAnswer = 0;

std::cout << "Calculator is ready for user input: \n";

while (n == 1){

    double a = 0;
    double b = 0;
    double ans;
    char op = '\0';
    std::string func = "";

    std::getline(std::cin, input);
    
    if (input == "X"){
        std::cout << "Exiting calculator program. Thank you! \n";
        n == 0;
        break;
    }
    else {
        try {
        parseInput(input, a, b, op, func, previousAnswer);
        ans = performOperation(a, b, op, func);
        std::cout << "= " << ans << std::endl;
        previousAnswer = ans;
        }
        catch (std::string msg){
            std::cout << "error caught in calculator.cpp \n"; // debug
            std::cerr << msg << std::endl;
        }
    }

};

}

