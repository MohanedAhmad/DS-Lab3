#include <iostream>
#define arraySize 10

using namespace std;

void linearSearch(int arr[], int Size, int value, int indices[], int &_found)
{
    _found = 0;

    for(int i = 0 ; i < Size ; i++)
    {
        indices[i] = -1;
    }

    for (int i = 0; i < Size; i++)
    {
        if (arr[i] == value)
        {
            indices[_found] = i;
            _found++;
        }
    }
}

void printIndices(int _foundIndices[], int _found)
{
    if (_found == 0)
    {
        cout << "\nNo elements found in the array !!!\n";
    }
    else
    {
        int j = 0;
        while(_foundIndices[j] != -1)
        {
            cout << "Value found at index: " << _foundIndices[j] << endl;
            j++;
        }
    }
}

int main()
{
    int myArr[arraySize] = {6, 50, 21, 13, 54, -20, 300, 99, -20, 788};
    int foundIndices[arraySize];
    int found = 0;


    linearSearch(myArr, arraySize, -20, foundIndices, found);
    printIndices(foundIndices, found);

    cout << "\n----------------------------------------------------------------------------------------\n";

    linearSearch(myArr, arraySize, 788, foundIndices, found);
    printIndices(foundIndices, found);

    cout << "\n----------------------------------------------------------------------------------------\n";

    linearSearch(myArr, arraySize, 200, foundIndices, found);
    printIndices(foundIndices, found);

    return 0;
}
