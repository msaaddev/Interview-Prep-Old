/*
    100
    5
    50 10 20 30 40

    Output: 90
 */

#include <iostream>
#include <cstring>
using namespace std;

int maxPic(int num, int *&arr, int length)
{
    int  max = arr[0];

    for (int i = 0; i < length - 2; i++)
    {
        for (int j = i + 2; j < length; j++)
        {
            if (arr[i] + arr[j] > max && arr[i] + arr[j] < num)
            {
                max = arr[i] + arr[j];
            }
        }
    }
    return max;
}

int main()
{
    int length, num;
    cin >> num >> length;

    int *arr = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    cout << maxPic(num, arr, length);

    delete[] arr;
}
