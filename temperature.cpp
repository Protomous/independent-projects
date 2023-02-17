#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string temp;
    double f, c, k, d, n, g, rankine, romer, reaumur;
    cout <<"\n";
    cout <<"\n";
    cout <<"\n";
    cout << "***************** Scale Converter *****************\n";

    cout << "Please specify which temperature scale to use: ";
    cin >> temp;

    char t = temp[0];
    if (temp == "rankine" || temp == "romer" || temp == "reaumur")
    {
        char e = temp[1];
        switch (e)
        {
        case 'a':
            cout << "Nice try.\n";
            cout << "Give me a temperature: ";
            cin >> rankine;
            f = rankine - 459.67;
            c = (f - 32) * 0.5556;
            cout << "It corresponds to " << f << " degrees fahrenheit, and " << c << " degrees celsius.\n";
            break;
        case 'o':
            cout << "Nice try.\n";
            cout << "Give me a temperature: ";
            cin >> romer;
            c = (romer - 7.5) * (40 / 21);
            f = (c * 1.8) + 32;
            cout << "It corresponds to " << c << " degrees celsius, and " << f << " degrees fahrenheit.\n";
            break;
        case 'e':
            cout << "Nice try. \n";
            cout << "Give me a temperature: ";
            cin >> reaumur;
            c = (reaumur * (5 / 4));
            f = (c * 1.8) + 32;
            cout << "It corresponds to " << c << " degrees celsius, and " << f << " degrees fahrenheit.\n";
            break;
        }
    }
    else
    {
        switch (t)
        {
        case 'f':
            cout << "You have selected Fahrenheit!\n";
            cout << "Please, type in the temperature: ";
            cin >> f;
            c = ((f - 32) * 0.5556);
            k = c + 273.15;
            cout << "It is " << c << " degrees Celsius!\n";
            cout << "This means it is also " << k << " degrees Kelvin!\n";
            break;
        case 'c':
            cout << "You have selected celsius!\n";
            cout << "Please, type in the temperature: ";
            cin >> c;
            f = (c * 1.8) + 32;
            k = c + 273.15;
            cout << "It is " << f << " degrees Fahrenheit!\n";
            cout << "It is also " << k << " degrees Kelvin!\n";
            break;
        case 'k':
            cout << "You have selected kelvin!\n";
            cout << "Please, type in the temperature: ";
            cin >> k;
            c = k - 273.15;
            f = (c * 1.8) + 32;
            cout << "It is " << c << " degrees Celsius.\n";
            cout << "It is also " << f << " degrees Fahrenheit.\n";
            break;
        case 'd':
            cout << "Nice try.\n";
            cout << "Give me a temperature: ";
            cin >> d;
            f = (212 - d * (6 / 5));
            c = (f - 32) * 0.5556;
            cout << "It corresponds to " << f << " degrees fahrenheit, and " << c << " degrees celsius.\n";
            break;
        case 'n':
            cout << "Nice try.\n";
            cout << "Give me a temperature: ";
            cin >> n;
            c = n * (100 / 33);
            f = (c * 1.8) + 32;
            cout << "It corresponds to " << f << " degrees fahrenheit, and " << c << " degrees celsius.\n";
            break;
        case 'g':
            cout << "Nice try.\n";
            cout << "Give me a temperature: ";
            cin >> g;
            if (g >= 1)
            {
                c = (g * 14) + 121;
                f = (c * 1.8) + 32;
                cout << "It corresponds to " << f << " degrees fahrenheit, and " << round(c) << " degrees celsius.\n";
            }
            else if (g == 0.5 || g == 0.25 || g == g == 0.125)
            {
                c = (243 - (25 * log2(pow(g, -1)))) / 1.8;
                f = (c * 1.8) + 32;
                
                cout << "It corresponds to " << f << " degrees fahrenheit, and " << round(c) << " degrees celsius.\n";
            }
            else
            {
                cout << "You tried to be funny and didn't even know this wasn't possible?\n";
            }
            break;
        default:
            cout << "Not a valid temperature scale, unfortunately!\n";
            break;
        }
    }
    cout << "***************************************************\n";
    return 0;
}