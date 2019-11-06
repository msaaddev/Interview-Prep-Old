#include <iostream>
#include <cstring>
using namespace std;

int *comparison(string firstString, string secondString);
int smallestAscii(string a);

int main()
{
    string a = "abcd,bcda";
    string b = "aaa,aa";
    string c = "aacd";

    cout << smallestAscii(c);
}

int smallestAscii(string a)
{
    int *temp = new int[a.length()];

    for (int i = 0; i < a.length(); i++)
    {
        int ascii = 0;
        ascii = a[i];
        *(temp + i) = ascii;
    }

    int length = sizeof(temp) / sizeof(*temp);
    int smallestNum;
    smallestNum = *temp;

    for (int i = 0; i < length; i++)
    {
        if (temp[i] <= smallestNum)
            smallestNum = temp[i];
    }

    delete[] temp;
    return smallestNum;
}

int *comparison(string firstString, string secondString, int result[])
{
    string secondTemp = "";
    int totalCombinations = 1;
    result[0] = 1;
    result[1] = 2;

    for (int i = 0; firstString[i] != '/0'; i++)
    {
        if (firstString[i] == ',')
            totalCombinations++;
    }

    for (int i = 0; i < totalCombinations; i++)
    {
        string temp = "";
        static int j = 0;
        while (firstString[j] != ',')
        {
            temp += firstString[i];
            i++;
        }
    }

    return result;
}
