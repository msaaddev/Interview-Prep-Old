#include <iostream>
using namespace std;

int smallestCharacter(string a);
int frequencyOfSmalChar(string a);
int totalElements(string a);
int *comparison(string firstString, string secondString);

int smallestCharacter(string a)
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
    int smallestChar = smallestCharacter(a);

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

int totalElements(string a)
{
    int totalCombinations = 1;

    for (int i = 0; a[i] != '/0'; i++)
    {
        if (a[i] == ',')
            totalCombinations++;
    }

    return totalCombinations;
}

int *comparison(string firstString, string secondString, int result[])
{

    int elementsFirstString = totalElements(firstString);
    result[0] = 1;
    result[1] = 2;

    int *smallFirstStringFrequency = new int[elementsFirstString];

    for (int i = 0; i < elementsFirstString; i++)
    {
        string temp = "";
        static int j = 0;
        while (firstString[j] != ',')
        {
            temp += firstString[j];
            j++;
        }

        smallFirstStringFrequency[i] = frequencyOfSmalChar(temp);
    }

    int elementsSecondString = totalElements(secondString);
    int *smallSecondStringFrequency = new int[elementsSecondString];

    for (int i = 0; i < elementsSecondString; i++)
    {
        string temp = "";
        static int j = 0;
        while (secondString[j] != ',')
        {
            temp += secondString[j];
            j++;
        }

        smallSecondStringFrequency[i] = frequencyOfSmalChar(temp);
    }

    

    return result;
}