#include <iostream>
#include <cstring>
using namespace std;

int totalElements(string a)
{
    int elements = 1;
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        if (a[i] == ',')
            elements++;
    }
    return elements;
}

string mostBookedRoom(string a)
{
    int size = a.size();
    int x = 0, y = 3, index;
    int occurences = 1, maximun = 0;
    string subStrings[10] = {"\0"};
    string booked[10] = {"\0"};
    string maxBooked[10]{"\0"};
    int maxOccurences[10] = {0};

    for (int i = 0; i < totalElements(a); i++)
    {
        static int j = 0;
        string temp = "";
        while (a[j] != ',' && a[j] != '\0')
        {
            temp += a[j];
            j++;
        }
        j++;
        subStrings[i] = temp;
    }

    for (int i = 0; i < totalElements(a); i++)
    {
        static int j = 0;
        string temp = "";
        temp = subStrings[i];
        if (temp[0] == '+')
        {
            booked[j] = temp;
            j++;
        }
    }

    for (int i = 0; booked[i] != "\0"; i++)
    {
        for (int j = i + 1; booked[j] != "\0"; j++)
        {
            if (booked[i] == booked[j])
            {
                occurences++;
                maxBooked[i] = booked[i];
                maxOccurences[i] = occurences;
            }
        }
        occurences = 1;
    }

    for (int i = 0; maxOccurences[i] != 0; i++)
    {
        if (maximun < maxOccurences[i])
        {
            maximun = maxOccurences[i];
            index = i;
        }
    }
    return maxBooked[index];
}

int main()
{
    string a = "+1A,+3E,-1A,+4F,+1A,+3E,+4F,+4F";
    cout << mostBookedRoom(a);
}
