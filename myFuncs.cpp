#include <iostream>
#include <cmath>
#include "myFuncs.h"


// Pythagorean theorem
double pythag(double a, double b)
{
    return sqrt(pow(a, 2) + pow(b, 2));
}


// Quadratic equation solver
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


// Give some info about the input number
void getNumInfo(double num)
{
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
        if(num > 1 && isPrime)
            std::cout << intVal << " is a prime.\n";
        else
            std::cout << intVal << " is not a prime.\n";
        
        
        // Give factors
        if(num > 0)
        {
            std::cout << "Factors: 1";
            for(int i = 2; i <= intVal; i++)
            {
                if(intVal % i == 0)
                    std::cout << ", " << i;
            }
        }
        
    }
}


// Finds the result of doing one of the four operators on an array
void findResult(std::string what, double arr[], int size, int &i)
{
    int before, after;
    
    // Find the next number
    after = i + 1;
    while(arr[after] < 0 && after < size) after++;
    
    // Find the previous number
    before = i - 1;
    while(arr[before] < 0 && before >= 0) before--;
    
    if(what == "multiplication") arr[before] = arr[before] * arr[after];
    else if(what == "division") arr[before] = arr[before] / arr[after];
    else if(what == "addition") arr[before] = arr[before] + arr[after];
    else arr[before] = arr[before] - arr[after];
    
    // Reset
    arr[i] = -100;
    arr[after] = -100;
    
    i = 0;
}


// Evaluates a string
void evalExpression(std::string str)
{
    std::string result;
    for(int i = 0; i < str.length(); i++)
        if(str[i] != ' ') result += str[i];
    
    
    double arr[(result.length())];
    
    for(int i = 0; i < result.length(); i++)
    {
        if(isdigit(result[i]))
            arr[i] = (int)result[i] - 48;
        else
        {
            if(result[i] == '+') arr[i] = -1;
            else if(result[i] == '-') arr[i] = -2;
            else if(result[i] == '*') arr[i] = -3;
            else if(result[i] == '/') arr[i] = -4;
            else arr[i] = -100;
        }
    }
    
    
    
    int count = 1,
        posCount = -100; // Position to replace with a -100 later
    
    // Go through arr backwards
    for(int i = result.length() - 1; i >= 0; i--)
    {
        // If more than 1 position is a number
        if(arr[i] >= 0 && arr[i - 1] >= 0)
        {
            // Update numbers
            arr[i - 1] *= pow(10, count);
            arr[i - 1] += arr[i];
            
            // Replace the previous pos with a -100 (meaning to skip that pos)
            posCount >= 0 ? arr[posCount] = -100 : posCount = posCount;
            
            posCount = i;
            count++;
        
        } else
            count = 1;
    }
    
    
    
    // Number before and after the operator sign
    int after = 0, before = 0;
    
    // Go through and multiply/divide numbers
    for(int i = 0; i < result.length(); i++)
    {
        // Multiplication
        if(arr[i] == -3)
            findResult("multiplication", arr, result.length(), i);
        
        // Division
        else if(arr[i] == -4)
            findResult("division", arr, result.length(), i);
    }
        
    
    // Go through and add/subtract numbers
    for(int i = 0; i < result.length(); i++)
    {
        // Addition
        if(arr[i] == -1)
            findResult("addition", arr, result.length(), i);
        
        // Subtraction
        else if(arr[i] == -2)
            findResult("subtraction", arr, result.length(), i);
    }
    
    
    // Give the result
    for(int i = 0; i < result.length(); i++)
        if(arr[i] != -100)
        {
            std::cout << arr[i];
            break;
        }
    
}
