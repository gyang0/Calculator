#include <iostream>
#include "myFuncs.h"
using namespace std;

int main()
{
    int choice;
    int num;
    
    cout << "Pick one:\n";
    cout << "1. Evaluate expression\n";
    cout << "2. Solve quadratic formula\n";
    cout << "3. Get number info\n";
    
    cin >> choice;
    
    switch(choice)
    {
        case 1:
            
        break;
        
        case 2:
            
        break;
        
        case 3:
            cout << "Enter a number: ";
            cin >> num;
            getNumInfo(num);
            
        break;
        
        default:
            cout << "Try again: ";
            cin >> choice;
    }
    
    
    return 0;
}
