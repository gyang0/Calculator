#include "myFuncs.h"
#include <iostream>
#include <cmath>
using namespace std;

double evalExpression(string str)
{
    // 1. Parentheses
    
    // 2. Evaluate square roots, powers, and trig
    
    // 2. Multiplication and division
    
    // 3. Addition and subtraction
    
    return 0.0;
}


double solveQuad()
{
    return 0.0;
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
        if(num > 0) cout << num << " is a positive integer.\n";
        else if(num < 0) cout << num << " is a negative integer.\n";
        else cout << "Input is zero.";
        
        isInt = true;
    }
    else
        cout << num << "is an decimal.\n";
    
    
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
            cout << intVal << " is a prime.\n";
        else
            cout << intVal << " is not a prime.\n";
        
        
        
        // Give factors
        cout << "Factors: 1";
        for(int i = 2; i <= intVal; i++)
        {
            if(intVal % i == 0)
                cout << ", " << i;
        }
    }
    
}
