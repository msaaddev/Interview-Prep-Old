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

    result[0] = 1;
    result[1] = 2;

    string *string1 = new string[totalElements(firstString)];
    int *smallFirstStringFrequency = new int[totalElements(firstString)];

    for (int i = 0; i < totalElements(firstString); i++)
    {
        string temp = "";
        static int j = 0;
        while (firstString[j] != ',')
        {
            temp += firstString[j];
            j++;
        }
        string1[i] = temp;
        smallFirstStringFrequency[i] = frequencyOfSmalChar(temp);
    }

    string *string2 = new string[totalElements(secondString)];
    int *smallSecondStringFrequency = new int[totalElements(secondString)];

    for (int i = 0; i < totalElements(secondString); i++)
    {
        string temp = "";
        static int j = 0;
        while (secondString[j] != ',')
        {
            temp += secondString[j];
            j++;
        }
        string2[i] = temp;
        smallSecondStringFrequency[i] = frequencyOfSmalChar(temp);
    }

    for (int i = 0; i < totalElements(secondString); i++)
    {
        for (int j = 0; j < totalElements(firstString); j++)
        {
            int first = smallestCharacter(string1[j]);
            int second = smallestCharacter(string2[i]);
            int counter = 0;

            if (frequencyOfSmalChar(string1[j]) < frequencyOfSmalChar(string2[i]))
            {
                result[i] = counter++;
            }
        }
    }

    return result;
}