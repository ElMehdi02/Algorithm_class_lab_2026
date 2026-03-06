/*******************************************************
 //  El Mehdi Bensouda
 //  COSC 300 - Program #3
 //  Due: 02/03/2026
 //
 //  This program implements and tests three C-string
 //  functions using ONLY pointer notation:
 //   strCmp  - compares two C-strings
 //   strPbrk - finds the first matching character
 //   ItoA    - converts an integer to a C-string
 //
 //  The user is asked to enter two strings and one integer.
 //  Strings must NOT contain spaces. If the user types a space,
 //  the input will be treated as separate strings.
 //  For integers, if the user types extra values separated by
 //  spaces, only the first integer is read by the program.
 *******************************************************/


#include <iostream>
using namespace std;

int strCmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
        s1 = s1 + 1;
        s2 = s2 + 1;
    }

    if (*s1 == *s2)
        return 0;

    if (*s1 < *s2)
        return -1;

    return 1;
}

char* strPbrk(const char *s1, const char *s2)
{
    const char *p1;
    const char *p2;

    p1 = s1;

    while (*p1 != '\0')
    {
        p2 = s2;

        while (*p2 != '\0')
        {
            if (*p1 == *p2)
            {
                return (char*)p1;  // return where it matched in s1
            }
            p2 = p2 + 1;
        }

        p1 = p1 + 1;
    }

    return nullptr;
}


char* ItoA(int n, char *s)
{
    int temp = n;
    int length = 0;

    // handle 0 separately
    if (n == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }

    // handle negative numbers
    int isNegative = 0;
    if (n < 0)
    {
        isNegative = 1;
        n = -n;
    }

    // count how many digits
    temp = n;
    while (temp > 0)
    {
        length++;
        temp = temp / 10;
    }

    // add space for minus sign
    if (isNegative)
        length++;

    s[length] = '\0';  // end of string
    length--;

    // build string from right to left
    while (n > 0)
    {
        s[length] = (n % 10) + '0';
        n = n / 10;
        length--;
    }

    if (isNegative)
        s[0] = '-';

    return s;
}


int main()
{
    char s1[200];
    char s2[200];
    int num;
    char out[200];

    cout << "Enter first string (no spaces, because a space will be treated as a separate string): ";
    cin >> s1;


    cout << "Enter second string : ";
    cin >> s2;



    cout << "\nstrCmp result:\n";
    cout << "strCmp(\"" << s1 << "\",\"" << s2 << "\") = " << strCmp(s1, s2) << endl;



    cout << "\nstrPbrk result:\n";
    char *pos = strPbrk(s1, s2);


    if (pos != nullptr)
        cout << "First matching char: " << *pos << " and pointer prints: " << pos << endl;
    else
        cout << "No match found." << endl;


    cout << "\nEnter an integer: ";
    cin >> num;


    cout << "ItoA(" << num << ") = " << ItoA(num, out) << endl;

    return 0;
}