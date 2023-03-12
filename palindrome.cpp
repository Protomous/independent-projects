#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string word);

bool redo();

int main()
{
    do
    {
        cout << "Type in a word, and I'll tell you if it's a palindrome!\n";
        string word;
        cin >> word;

        if (is_palindrome(word))
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
}

bool is_palindrome(string word)
{
    string check;

    for (int i = word.size()-1; i >= 0; i--)
    {
        word[i] = tolower(word[i]);
        check += word[i];
    }

    if (check == word)
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
        return true;
    }
    else
    {
        return false;
    }
}