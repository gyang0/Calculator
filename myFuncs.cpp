#include <iostream>
#include <cmath>
#include "myFuncs.h"

double pythag(double a, double b)
{
    return sqrt(pow(a, 2) + pow(b, 2));
}


void solveQuad(double a, double b, double c)
{
    double determinant = pow(b, 2) - (4*a*c),
           solution1,
           solution2;
    
    
    if(determinant < 0)
        std::cout << "There are no solutions.\n";
    else
    {
        solution1 = (-b + sqrt(determinant))/(2*a);
        solution2 = (-b - sqrt(determinant))/(2*a);
        
        if(determinant > 0)
            std::cout << "There are two solutions: " << solution1 << " and " << solution2 << "\n";
        else
            std::cout << "There is one solution: " << solution1 << "\n";
    }
}


void getNumInfo(double num)
{
    // If the number is prime
    // Factors of the number
    // Number in binary
    // Number in hexadecimal
    bool isInt = false;
    
    if(num - (int)num == 0)
    {
        if(num > 0) std::cout << num << " is a positive integer.\n";
        else if(num < 0) std::cout << num << " is a negative integer.\n";
        else std::cout << "Input is zero.";
        
        isInt = true;
    }
    else
        std::cout << num << " is a decimal.\n";
    
    
    if(isInt)
    {
        bool isPrime = true;
        int intVal = static_cast<int>(num);
        
        // Check if it's prime
        for(int i = 2; i <= sqrt(intVal); i++)
        {
            if(intVal % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            std::cout << intVal << " is a prime.\n";
        else
            std::cout << intVal << " is not a prime.\n";
        
        
        
        // Give factors
        std::cout << "Factors: 1";
        for(int i = 2; i <= intVal; i++)
        {
            if(intVal % i == 0)
                std::cout << ", " << i;
        }
    }
    
}
