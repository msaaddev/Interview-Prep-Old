#include <iostream>
using namespace std;

string maxTime(string a)
{
    if (a[0] == '?' && a[1] == '?' && a[3] == '?' && a[4] == '?')
    {
        a = "23:59";
    }
    else
    {
        if (a[0] == '2' && a[1] == '?')
        {
            a[1] = '3';
        }
        else if (a[0] == '0' && a[1] == '?')
        {
            a[1] = '9';
        }
        if (a[0] == '?' && a[1] < 4)
        {
            a[0] = '2';
        }
        else if (a[0] == '?' && a[1] > 3)
        {
            a[0] = '1';
        }

        if (a[0] == '1' && a[1] == '?')
        {
            a[1] = '9';
        }
        else if (a[0] == '2' && a[1] == '?')
        {
            a[1] = '3';
        }

        if (a[3] == '?')
        {
            a[3] = '5';
        }
        if (a[4] == '?')
        {
            a[4] = '9';
        }
    } 
    return a;
}

int main()
{
    string a = "0?:??";
    cout << maxTime(a);
}