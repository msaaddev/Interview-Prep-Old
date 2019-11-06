#include <iostream>
#include <cstring>
#include "functions.cpp"
using namespace std;

int main()
{
    string a = "abcd,aabc,bd";
    string b = "aaa,aa";

    int *arr = new int[5];
    int result[2];

    arr = comparison(a, b, result); 

    for (int i = 0; i < 2; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
}
