# Calculator Program in C++

User operated calculator program. Program calculates the result of simple numerical operations and functions. The user can call on the following:

operators: '+' '-' '*' '/' '^' functions: 'sqrt()' 'exp()' 'log()' 'ln()' '!'

The user can also call on the answer from the previous line to use in further calculations by typing ANS.

Currently, the program only accepts input with one operator OR one function. The program utilises exception handling and input validation methods to ensure proper function. Some exaples of user inputs are for real numbers A, B, and ANS (previous answer):

Accepted input: A+B, A-B, A*ANS, A/B, ANS^B, sqrt(A), exp(ANS), log(A), ln(A), ANS!, etc...

Unaccepted input (results in error, aborts program): A, A+, /B, sqrt(ANS, log, A*exp(B), A/B+C, A B, A$B, etc..
