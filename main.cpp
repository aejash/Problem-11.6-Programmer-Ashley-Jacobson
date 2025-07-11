/**** Problem 11.6 - Chapter 11, Project C
*---------------------------------------------
***** Refine the is_palindrome function to work with arbitrary strings,
***** by ignoring non-letter characters and the distinction between upper-
***** and lowercase letters. For example, if the input string is
***** "Madam, I’m Adam!" then you’d first strip off the last character because it isn’t a letter,
***** and recursively check whether the shorter string

***** "Madam, I’m Adam"
***** is a palindrome.
*---------------------------------------------
// Programmer - Ashley Jacobson
// Tester - Giannfranco Brance

// Group Project C //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string text, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    else
    {
        if (!isalpha(text[end]))
        {
            text.erase(end);
        }
        char first = tolower(text[start]);
        char last = tolower(text[end]);
        if (isalpha(first) && isalpha(last))
        {
            if (first == last)
            {
                return is_palindrome(text, start + 1, end - 1);
            }
            else
            {
                return false;
            }
        }
        else if (!isalpha(last))
        {
            return is_palindrome(text, start, end - 1);
        }
        else
        {
            return is_palindrome(text, start + 1, end);
        }
    }
}

bool is_palindrome(string text)
{
    return is_palindrome(text, 0, text.length() - 1);
}
int main()
{
    cout << "Are these palindromes?: " << endl;
    cout << boolalpha << "Madam, I’m Adam!: " << is_palindrome("Madam, I’m Adam!") << endl;
    cout << "Hannah: " << is_palindrome("Hannah") << endl;
    cout << "Hello World: " << is_palindrome("Hello World") << endl;
    cout << "No lemon, no melon: " << is_palindrome("No lemon, no melon") << endl;

    return 0;
}
