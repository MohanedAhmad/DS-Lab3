#include <iostream>
#define arraySize 10

using namespace std;

int binarySearch(int arr[], int Size, int value)
{
    int low = 0, high = Size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 7, 8};
    int result = -1;


    result = binarySearch(arr, arraySize, 5);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }

    cout << "\n----------------------------------------------------------------------------------------\n";

    result = binarySearch(arr, arraySize, 4);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }

    return 0;
}
