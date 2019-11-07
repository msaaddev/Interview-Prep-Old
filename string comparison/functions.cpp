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

    for (int i = 0; i < totalElements(firstString); i++)
    {
        string temp = "";
        static int j = 0;
        while (firstString[j] != ',' && firstString[j] != '\0')
        {
            temp += firstString[j];
            j++;
        }
        string1[i] = temp;
        j++;
    }

    string *string2 = new string[totalElements(secondString)];

    for (int i = 0; i < totalElements(secondString); i++)
    {
        string temp = "";
        static int j = 0;
        while (secondString[j] != ',' && secondString[j] != '\0')
        {
            temp += secondString[j];
            j++;
        }

        string2[i] = temp;
        j++;
    }

    for (int i = 0; i < totalElements(secondString); i++)
    {
        static int counter = 0;
        for (int j = 0; j < totalElements(firstString); j++)
        {

            if (frequencyOfSmalChar(string1[j]) < frequencyOfSmalChar(string2[i]))
            {
                counter++;
                result[i] = counter;
            }
            else
            {
                result[i] = 0;
            }
        }
        counter = 0;
    }

    delete[] string1;
    delete[] string2;
    return result;
}