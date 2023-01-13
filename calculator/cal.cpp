#include <iostream>
using namespace std;

int main()
{
    int choice;
    float a, b;

    cout << "Basic Calculator\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (choice == 1)
        cout << "Result = " << a + b;
    else if (choice == 2)
        cout << "Result = " << a - b;
    else if (choice == 3)
        cout << "Result = " << a * b;
    else if (choice == 4)
    {
        if (b != 0)
            cout << "Result = " << a / b;
        else
            cout << "Cannot divide by zero";
    }
    else
        cout << "Invalid choice";

    return 0;
}
