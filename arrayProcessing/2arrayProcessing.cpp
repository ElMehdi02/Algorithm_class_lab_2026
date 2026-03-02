/***************************************************************
 //  El Mehdi Bensouda
 //  COSC 300 - Program #2
 //  Due: 01/27/2026
 //
 // This program inserts and removes numbers from a [ ]
 // integer array while keeping the array in ascending order.
 // The array starts empty (size 0) and grows with  add or delete [ ].
 // If the user didn't insert enough number the program keeps asking until it gets exactly "count" numbers.
 // If user types extra numbers, the FIRST extra is stored in extraInsert.
 ***************************************************************/
#include <iostream>
using namespace std;

void display(int *a, int sz)
{
    cout << "[ ";
    for (int i = 0; i < sz; i = i + 1)
    {
        cout << *(a + i) << " ";
    }
    cout << "]" << endl;
}

void insert(int *&a, int &sz, int n)
{
    int *b;
    int pos;

    b = new int[sz + 1];

    pos = 0;
    while (pos < sz && *(a + pos) < n)
    {
        pos = pos + 1;
    }

    for (int i = 0; i < pos; i = i + 1)
    {
        *(b + i) = *(a + i);
    }

    *(b + pos) = n;

    for (int i = pos; i < sz; i = i + 1)
    {
        *(b + i + 1) = *(a + i);
    }

    delete[] a;
    a = b;
    sz = sz + 1;
}

void removeNum(int *&a, int &sz, int n)
{
    int index;
    index = -1;

    for (int i = 0; i < sz; i = i + 1)
    {
        if (*(a + i) == n)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << n << " not found." << endl;
        return;
    }

    if (sz == 1)
    {
        delete[] a;
        a = nullptr;
        sz = 0;
        return;
    }

    int *b;
    b = new int[sz - 1];

    for (int i = 0; i < index; i = i + 1)
    {
        *(b + i) = *(a + i);
    }

    for (int i = index + 1; i < sz; i = i + 1)
    {
        *(b + i - 1) = *(a + i);
    }

    delete[] a;
    a = b;
    sz = sz - 1;
}

int main()
{
    int *a;
    int sz;
    int count;
    int n;

    a = nullptr;
    sz = 0;

    cout << "How many numbers do you want to insert? ";
    cin >> count;

    cout << "Enter the numbers: ";
    for (int i = 0; i < count; i = i + 1)
    {
        cin >> n;
        insert(a, sz, n);
    }

    cout << "Array after insertions: ";
    display(a, sz);

    cout << "Enter a number to insert: ";
    cin >> n;
    insert(a, sz, n);

    cout << "Array after insertion: ";
    display(a, sz);

    cout << "Enter a number to remove: ";
    cin >> n;
    removeNum(a, sz, n);

    cout << "Array after removal: ";
    display(a, sz);

    delete[] a;
    return 0;
}