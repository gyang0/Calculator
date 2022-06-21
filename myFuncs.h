#ifndef MY_FUNCS_H
#define MY_FUNCS_H

double pythag(double a, double b);
// Pretty obvious what this does.


void solveQuad(double a, double b, double c);
// In the form ax^2 + bx + c
// Either there are no solutions, there is one solution, or there are two solutions.


void getNumInfo(double num);
// If the number is a positive/negative integer or a decimal.
// If the number is prime
// Factors of the number


void findResult(std::string what, double arr[], int size, int &i);
// Used for evalExpression function
// Finds the result of doing one of the four operators on two items in an array.


void evalExpression(std::string str);
// Evaluates a basic expression involving +, -, *, /, and ().
// Doesn't work for decimals.


#endif
