#include <iostream>
using namespace std;

int smallestCharacter(string a);
int frequencyOfSmalChar(string a);
int totalElements(string a);
int *comparison(string firstString, string secondString, int result[]);


int smallestCharacter(string a)
{
    int length = a.size();
    int *temp = new int[length];

    for (int i = 0; i < length; i++)
    {
        int ascii = 0;
        ascii = a[i];
        *(temp + i) = ascii;
    }

    int smallestNum;
    smallestNum = *temp;

    for (int i = 0; i < length; i++)
    {
        if (*(temp + i) < smallestNum)
        {
            smallestNum = *(temp + i);
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
    int length = a.size();
    for (int i = 0; i < length; i++)
    {
        conversion = a[i];
        if ((smallestChar == conversion))
        {
            frequency++;
        }
    }
    return frequency;
}

int totalElements(string a)
{
    int totalCombinations = 1;
    int length = a.size();

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == ',')
            totalCombinations++;
    }

    return totalCombinations;
}

int *comparison(string firstString, string secondString, int result[])
{

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
        *(smallFirstStringFrequency + i) = frequencyOfSmalChar(temp);
        j++;
    }

    for (int i = 0; i < totalElements(firstString); i++)
    {
        cout << *(smallFirstStringFrequency + i) << " space ";
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
        *(smallSecondStringFrequency + i) = frequencyOfSmalChar(temp);
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

    delete[] string1;
    delete[] smallFirstStringFrequency;
    delete[] string2;
    delete[] smallSecondStringFrequency;

    return result;
}