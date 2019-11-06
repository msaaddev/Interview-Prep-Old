#include <iostream>
using namespace std;

int smallestAscii(string a);
int frequencyOfSmalChar(string a);
int *comparison(string firstString, string secondString);

int smallestAscii(string a)
{
    int *temp = new int[a.length()];

    for (int i = 0; i < a.length(); i++)
    {
        int ascii = 0;
        ascii = a[i];
        *(temp + i) = ascii;
    }

    int smallestNum;
    smallestNum = *temp;

    for (int i = 0; i < a.length(); i++)
    {
        if (*(temp + i) < smallestNum)
        {
            smallestNum = temp[i];
        }
    }

    delete[] temp;
    return smallestNum;
}

int frequencyOfSmalChar(string a)
{
    int frequency = 0;
    int conversion;
    int smallestChar = smallestAscii(a);

    for (int i = 0; i < a.length(); i++)
    {
        conversion = a[i];
        if (smallestChar == conversion)
        {
            frequency++;
        }
    }
    return frequency;
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

    int *smalString = new int[totalCombinations];

    for (int i = 0; i < totalCombinations; i++)
    {
        string temp = "";
        static int j = 0;
        while (firstString[j] != ',')
        {
            temp += firstString[j];
            j++;
        }

        smalString[i] = frequencyOfSmalChar(temp);
    }

    return result;
}