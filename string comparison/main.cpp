#include <iostream>
#include <cstring>
#include "functions.cpp"
using namespace std;

int main()
{
    string a = "abcd,bcda";
    string b = "aaa,aa";
    string c = "eccd";

    cout << frequencyOfSmalChar(c);
}
