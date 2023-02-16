#include <iostream>
#include <ctime>
using namespace std;

bool rerollF(string answer);
void rollerF(int amount, int sides);

int main()
{
    int amount;
    int sides;
    bool reroll;
    string answer;
    srand(time(NULL));

    do
    {
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "************* DICE ROLLER *************";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";

        do
        {
            cout << "Please enter how many dice you want to roll: ";
            cin >> amount;
            cout << "Please enter how many sides each die has: ";
            cin >> sides;
        } while (amount <= 0 && sides <= 0);

        rollerF(amount, sides);

        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "***************************************";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";

        reroll = rerollF(answer);

    } while (reroll == true);
    return 0;
}
bool rerollF(string answer)
{
    do
    {
        cout << "Would you like to roll again?\n";
        cout << "(y/n)\n";
        cin >> answer;

        switch (answer.at(0))
        {
        case 'y':
            return true;
            break;
        case 'n':
            cout << "\n";
            cout << "\n";
            cout << "Thanks for rolling!\n";
            cout << "\n";
            cout << "\n";
            return false;
            break;
        default:
            cout << "Please only answer with 'y' or 'n'\n";
            break;
        }
    } while (answer.at(0) != 'y' & answer.at(0) != 'n');
}
void rollerF(int amount, int sides)
{
    for (int i = 1; i <= amount; i++)
    {
        int num = (rand() % sides) + 1;
        cout << num << " ";
    }
}