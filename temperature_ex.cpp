#include <iostream>
#include <cmath>
#include <string>

using namespace std;

enum Temperature
{
    fahrenheit,
    celsius,
    kelvin,
    delisle,
    newton,
    gasmark,
    rankine,
    romer,
    reaumur
};

void convertTemperature(Temperature &temperature);

class Scale
{
public:
    double celsius;
    double fahrenheit;
    double kelvin;
};
class Fahrenheit : public Scale
{
public:
    Fahrenheit(double fahrenheit)
    {
        this->fahrenheit = fahrenheit;
        this->celsius = ((fahrenheit - 32) * 0.5556);
        this->kelvin = ((fahrenheit - 32) * 0.5556) + 273.15;
    }
};
class Celsius : public Scale
{
public:
    Celsius(double celsius)
    {
        this->celsius = celsius;
        this->fahrenheit = (celsius * 1.8) + 32;
        this->kelvin = celsius + 273.15;
    }
};
class Kelvin : public Scale
{
public:
    Kelvin(double kelvin)
    {
        this->kelvin = kelvin;
        this->celsius = kelvin - 273.15;
        this->fahrenheit = ((kelvin - 273.15) * 1.8) + 32;
    }
};
class Delisle : public Scale
{
public:
    double delisle;
    Delisle(double delisle)
    {
        this->delisle = delisle;
        this->fahrenheit = (212 - delisle * (6 / 5));
        this->celsius = ((212 - delisle * (6 / 5)) - 32) * 0.5556;
        this->kelvin = (((212 - delisle * (6 / 5)) - 32) * 0.5556) + 273.15;
    }
};
class Newton : public Scale
{
public:
    double newton;
    Newton(double newton)
    {
        this->newton = newton;
        this->celsius = newton * (100 / 33);
        this->fahrenheit = ((newton * (100 / 33)) * 1.8) + 32;
        this->kelvin = (newton * (100 / 33)) + 273.15;
    }
};
class Gasmark : public Scale
{
public:
    double gasmark;
    Gasmark(double gasmark)
    {
        this->gasmark = gasmark;
        if (gasmark >= 1)
        {
            this->celsius = (gasmark * 14) + 121;
            this->fahrenheit = (((gasmark * 14) + 121) * 1.8) + 32;
            this->kelvin = ((gasmark * 14) + 121) + 273.15;
        }
        else if (gasmark == 0.5 || gasmark == 0.25 || gasmark == 0.125)
        {
            this->celsius = (243 - (25 * log2(pow(gasmark, -1)))) / 1.8;
            this->fahrenheit = (((243 - (25 * log2(pow(gasmark, -1)))) / 1.8) * 1.8) + 32;
            this->kelvin = ((243 - (25 * log2(pow(gasmark, -1)))) / 1.8) + 273.15;
        }
        else
        {
            std::cout << "Not possible! Sorry.\n";
        }
    }
};
class Rankine : public Scale
{
public:
    double rankine;
    Rankine(double rankine)
    {
        this->rankine = rankine;
        this->fahrenheit = rankine - 459.67;
        this->celsius = ((rankine - 459.67) - 32) * 0.5556;
        this->kelvin = (((rankine - 459.67) - 32) * 0.5556) + 273.15;
    }
};
class Romer : public Scale
{
public:
    double romer;
    Romer(double romer)
    {
        this->romer = romer;
        this->celsius = ((romer - 7.5) * (40 / 21));
        this->fahrenheit = (((romer - 7.5) * (40 / 21)) * 1.8) + 32;
        this->kelvin = ((romer - 7.5) * (40 / 21)) + 273.15;
    }
};
class Réaumur : public Scale
{
public:
    double reaumur;
    Réaumur(double reaumur)
    {
        this->reaumur = reaumur;
        this->celsius = (reaumur * (5 / 4));
        this->fahrenheit = ((reaumur * (5 / 4)) * 1.8) + 32;
        this->kelvin = (reaumur * (5 / 4)) + 273.15;
    }
};

int main()
{
    char redo;
    bool redoB;
    string temp;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "***********************************************************************************\n";
    cout << "*************************** TEMPERATURE SCALE CONVERTER ***************************\n";
    cout << "***********************************************************************************\n";
do{
    cout << "Please specify which temperature scale to use: ";
    cin >> temp;

    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    if (temp == "fahrenheit")
    {
        Temperature temperature = fahrenheit;
        convertTemperature(temperature);
    }
    else if (temp == "celsius")
    {
        Temperature temperature = celsius;
        convertTemperature(temperature);
    }
    else if (temp == "kelvin")
    {
        Temperature temperature = kelvin;
        convertTemperature(temperature);
    }
    else if (temp == "delisle")
    {
        Temperature temperature = delisle;
        convertTemperature(temperature);
    }
    else if (temp == "newton")
    {
        Temperature temperature = newton;
        convertTemperature(temperature);
    }
    else if (temp == "delisle")
    {
        Temperature temperature = delisle;
        convertTemperature(temperature);
    }
    else if (temp == "delisle")
    {
        Temperature temperature = delisle;
        convertTemperature(temperature);
    }
    else if (temp == "gasmark")
    {
        Temperature temperature = gasmark;
        convertTemperature(temperature);
    }
    else if (temp == "rankine")
    {
        Temperature temperature = rankine;
        convertTemperature(temperature);
    }
    else if (temp == "romer")
    {
        Temperature temperature = delisle;
        convertTemperature(temperature);
    }
    else if (temp == "reaumur" || temp == "réaumur")
    {
        Temperature temperature = reaumur;
        convertTemperature(temperature);
    }
    else
    {
        cout << "Not a valid scale!";
    }

    cout << "Do you want to do it again? (Y or N)";
    cin >> redo;
    if(toupper(redo) == 'Y'){
        redoB = true;
    }else{
        redoB = false;
    }

    }while(redoB);

    cout << "***********************************************************************************\n";
    cout << "***********************************************************************************\n";
    cout << "***********************************************************************************\n";

}

void convertTemperature(Temperature &temperature)
{

    switch (temperature)
    {
    case fahrenheit:
    {
        double x;
        cout << "Please input the temperature in Fahrenheit: ";
        cin >> x;
        Fahrenheit convert(x);
        cout << "Celsius: " << convert.celsius << endl;
        cout << "Kelvin: " << convert.kelvin << endl;
        break;
    }
    case celsius:
    {
        double x;
        cout << "Please input the temperature in Celsius: ";
        cin >> x;
        Celsius convert(x);
        cout << "Fahrenheit: " << convert.fahrenheit << endl;
        cout << "Kelvin: " << convert.kelvin << endl;
        break;
    }
    case kelvin:
    {
        double x;
        cout << "Please input the temperature in Kelvin: ";
        cin >> x;
        Kelvin convert(x);
        cout << "Celsius: " << convert.celsius << endl;
        cout << "Fahrenheit: " << convert.fahrenheit << endl;
        break;
    }
    case delisle:
    {
        double x;
        cout << "Please input the temperature in the Delisle scale: ";
        cin >> x;
        Delisle convert(x);
        cout << "Celsius: " << convert.celsius << endl;
        cout << "Fahrenheit: " << convert.fahrenheit << endl;
        cout << "Kelvin: " << convert.kelvin << endl;
        break;
    }
    case newton:
    {
        double x;
        cout << "Please input the temperature in the Newton scale: ";
        cin >> x;
        Newton convert(x);
        cout << "Celsius: " << convert.celsius << endl;
        cout << "Fahrenheit: " << convert.fahrenheit << endl;
        cout << "Kelvin: " << convert.kelvin << endl;
        break;
    }
    case gasmark:
    {
        double x;
        cout << "Please input the temperature in the Gas Mark scale: ";
        cin >> x;
        Gasmark convert(x);
        cout << "Celsius: " << convert.celsius << endl;
        cout << "Fahrenheit: " << convert.fahrenheit << endl;
        cout << "Kelvin: " << convert.kelvin << endl;
        break;
    }
    case rankine:
    {
        double x;
        cout << "Please input the temperature in the Rankine scale: ";
        cin >> x;
        Rankine convert(x);
        cout << "Celsius: " << convert.celsius << endl;
        cout << "Fahrenheit: " << convert.fahrenheit << endl;
        cout << "Kelvin: " << convert.kelvin << endl;
        break;
    }
    case romer:
    {
        double x;
        cout << "Please input the temperature in the Romer scale: ";
        cin >> x;
        Romer convert(x);
        cout << "Celsius: " << convert.celsius << endl;
        cout << "Fahrenheit: " << convert.fahrenheit << endl;
        cout << "Kelvin: " << convert.kelvin << endl;
        break;
    }
    case reaumur:
    {
        double x;
        cout << "Please input the temperature in the Réaumur scale: ";
        cin >> x;
        Réaumur convert(x);
        cout << "Celsius: " << convert.celsius << endl;
        cout << "Fahrenheit: " << convert.fahrenheit << endl;
        cout << "Kelvin: " << convert.kelvin << endl;
        break;
    }
    default:
        cout << "Something has gone wrong!\n";
        break;
    }
}