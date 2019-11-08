#include <iostream>
using namespace std;

int *indices(int arr[], int target, int result[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 4; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                result[0] = i;
                result[1] = j;
            }
        }
    }
    if (result[0] == -1)
        return 0;
    return result;
}

int main()
{

    int *result = new int[2], arr[4], target;
    char a;

    result[0] = -1;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            cin >> a;
        }
        cin >> arr[i];
        cin >> a;
    }
    cin >> target;

    result = indices(arr, target, result);
    if (result == 0)
    {
        cout << "Sum not possible.";
    }
    else
        cout << "[" << result[0] << ", " << result[1] << "]";

    delete[] result;
}
