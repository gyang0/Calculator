#include <iostream>
#include "myFuncs.h"
using namespace std;

int main()
{
    int choice;
    
    // Input to be used later
    double a, b, c,
           num;
    string str;
    
    // Back to menu or quit (Y/N)
    char again;
    
    do {
        cout << "Pick one:\n";
        cout << "1. Pythagorean theorem\n";
        cout << "2. Solve quadratic formula\n";
        cout << "3. Get number info\n";
        cout << "4. Evaluate expression\n";
        
        
        // Input
        cin >> choice;
        while(!(choice >= 1 && choice <= 4))
        {
            cout << "Try again: ";
            cin >> choice;
        }
        
        
        // Depending on choice
        switch(choice)
        {
            case 1: // Pythagorean theorem
                cout << "Enter the two legs of a triangle (a and b): ";
                    cin >> a >> b;
                cout << "The length of the hypotenuse is " << pythag(a, b) << "\n";
            break;
            
            case 2: // Quadratic formula
                cout << "Enter three numbers a, b, and c where ax^2 + bx + c = 0.\n";
                cout << "Separate each number by a space: ";
                cin >> a >> b >> c;
                solveQuad(a, b, c);
            break;
            
            case 3: // Get number info
                cout << "Enter a number: ";
                cin >> num;
                getNumInfo(num);
            break;
            
            case 4: // Get number info
                cout << "Enter an expression: ";
                cin.ignore();
                getline(cin, str);
                evalExpression(str);
            break;
        }
        
        
        cout << "\nBack to menu? (Y/N)\n";
        cin >> again;
        cout << "\n\n";
        
    } while(again == 'Y' || again == 'y');
    
    return 0;
}
