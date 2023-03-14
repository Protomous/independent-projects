#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string word);

bool redo();

int main()
{
    do
    {
        cout << "Type in a word or phrase, and I'll tell you if it's a palindrome!\n";
        string word;
        getline(cin, word);

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
    string tempword;

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == ' ' || word[i] == '.' || word[i] == ',' || word[i] == '?' || word[i] == '!' || word[i] == ':' || word[i] == ';')
        {
            continue;
        }
        else
        {
            tempword += word[i];
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
        return true;
    }
    else
    {
        return false;
    }
}