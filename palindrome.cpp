#include <iostream>
#include <string>

using namespace std;

string getWord(string word);

bool isPalindrome(string word);

bool redo();

int main()
{
    cout << endl;
    cout << "*****************************\n";
    cout << "**** PALINDROME DETECTOR ****\n";
    cout << "*****************************\n";
    cout << endl;
    do
    {
        string word;
        word = getWord(word);

        if (isPalindrome(word))
        {
            toupper(word[0]);
            cout << word << " is a palindrome!\n";
        }
        else
        {
            toupper(word[0]);
            cout << word << " is not a palindrome!\n";
        }
    } while (redo());

    cout << endl;
    cout << "*****************************\n";
    cout << "*****************************\n";
    cout << "*****************************\n";
    cout << endl;
}

bool isPalindrome(string word)
{
    string check;
    string tempword;

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == ' ' || word[i] == '.' || word[i] == ',' || word[i] == '?' || word[i] == '!' || word[i] == ':' || word[i] == ';')
        {
            continue;
        }
        else
        {
            tempword += tolower(word[i]);
        }
    }

    for (int i = tempword.size() - 1; i >= 0; i--)
    {
        if (tempword[i] == ' ')
        {
            continue;
        }
        else
        {
            tempword[i] = tolower(tempword[i]);
            check += tempword[i];
        }
    }

    if (check == tempword)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool redo()
{
    char answer;
    cout << "Would you like to enter another word? (Y/N)\n";
    cin >> answer;

    if (tolower(answer) == 'y')
    {
        cout << endl;
        return true;
    }
    else
    {
        cout << endl;
        cout << "Have a good day!\n";
        return false;
    }
}

string getWord(string word)
{
    cout << "Type in a word or phrase, and I'll tell you if it's a palindrome!\n";
    getline(cin >> ws, word);
    return word;
}