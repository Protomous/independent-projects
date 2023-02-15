#include <iostream>
using namespace std;

int main()
{
    string name;
    int age;
    string food;

    cout << "Please, enter your name: ";
    getline(cin >> ws, name);

    cout << "Please, enter your age: ";
    cin >> age;

    cout << "Please, enter your favorite food: ";
    getline(cin >> ws, food);

    cout << "Hello, " << name << "!\n";
    cout << "You are " << age << " years old, correct?\n";
    cout << "Welcome. Would you like to have something to eat? I know you like " << food << ", so please enjoy.\n";
    return 0;
}