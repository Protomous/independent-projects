#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string maxop;
    double num1;
    double num2;
    double result;
    char m;

    cout << "What type of calculation would you like?\n"
         << "(Options between 'multiplication', 'division', 'addition', 'subtraction', 'root squared', 'cubic root', 'power')\n";
    cout << "Please enter here: ";
    getline(cin >> ws, maxop);

    m = maxop[0];

    switch (m)
    {
    case 'm':
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        result = num1 * num2;
        cout << "Your result is: " << result << "\n";
        break;
    case 'a':
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        result = num1 + num2;
        cout << "Your result is: " << result << "\n";
        break;
    case 's':
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        result = num1 - num2;
        cout << "Your result is: " << result << "\n";
        break;
    case 'd':
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        result = num1 / num2;
        cout << "Your result is: " << result << "\n";
        break;
    case 'r':
        cout << "Enter the number: ";
        cin >> num1;
        result = sqrt(num1);
        cout << "Your result is: " << result << "\n";
        break;
    case 'p':
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        result = pow(num1, num2);
        cout << "Your result is: " << result << "\n";
        break;
    case 'c':
        cout << "Enter the number: ";
        cin >> num1;
        result = cbrt(num1);
        cout << "Your result is: " << result << "\n";
        break;
    default:
        cout << "Not a supported operation.\n";
        break;
    }

    return 0;
}