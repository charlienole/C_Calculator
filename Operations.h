#ifndef OPERATIONS_H
#define OPERATIONS_H 

#include <cmath>
#include <iostream>
#include <sstream> 
#include <string> 

// operations for calculuator, include throw for potential errors

// add

double add(double a, double b){
    //std::cout << "Called add function \n"; // debug
    double sum = a+b;
    return sum;
}

// subtract
double sub(double a, double b){
    //std::cout << "Called subtract function \n"; // debug
    double sub = a-b;
    return sub;
}

// multiply
double product(double a, double b){
    //std::cout << "Called product function \n"; // debug
    double product = a*b;
    return product;
}

// divide
double divide(double a, double b){
    //std::cout << "Called divide function \n"; // debug
    if (b == 0) {
        throw std::runtime_error("Division by zero is undefined");
    }
    double divide = a/b;
    return divide;
}

// power
double power(double a, double b){
    //std::cout << "Called power function \n"; // debug
    if (b==0){
        return 1;
    }
    if (a==0){
        return 0;
    }
    if (a==1){
        return 1;
    }
    double power = pow(a,b);
    return power;
}

// sqrt
double sqroot(double a){
    //std::cout << "Called square root function on " << a << std::endl; // debug
    if (a < 0){
        throw std::runtime_error("Square root of negative number is not real.");
    }
    double squarert = sqrt(a);
    return squarert;
}

// exp()
double expn(double a){
    //std::cout << "Called exponential function on " << a << std::endl; // debug
    double epow = exp(a);
    return epow;
}

// log10
double logten(double a){
    //std::cout << "Called log10 function on " << a << std::endl; // debug
    if (a <= 0){
        throw std::runtime_error("Log of value less than/equal to zero is undefined.");
    }
    double log = log10(a);
    return log;
}

//ln
double ln(double a){
    //std::cout << "Called ln function on " << a << std::endl; // debug
    if (a <= 0){
        throw std::runtime_error("Natural log of value less than/equal to zero is undefined.");
    }
    double ln = log(a);
    return ln;
}

// factorial 
double factorial(double a){
    //std::cout << "Called factorial function \n"; // debug
    if (a < 0){
        throw std::runtime_error("Cannot calculate the factorial of a negative value.");
    }
    if (a == 0){
        return 1;
    }    
    // check if integer val
    std::ostringstream t;
    t << a;
    std::string temp = t.str();
        if (temp.find(".") != std::string::npos){
            // if input is NOT integer
            throw std::runtime_error("Invalid argument, must be integer value.");
        }

    double factorial = 1;
    for (int i = 0; i < a; i++){
        factorial = factorial * (a-i);
    }
    return factorial;
}



#endif