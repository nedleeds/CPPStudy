#include <iostream>
using namespace std;

void printArray(const int arr[], const int length);
void selectionSort(int arr[], const int length);
void swap_values(int arr[], const int i, const int j);
void bubbleSort(int arr[], const int length);

int main()
{
    int arr[] = {3, 5, 2, 1, 4};
    const int arrSize = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, arrSize);
    // selectionSort(arr, arrSize);
    bubbleSort(arr, arrSize);

    return 0;
}

void printArray(const int arr[], const int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(int arr[], const int length)
{
    for (int i = 0; i < length; i ++)
    {
        int min_value = arr[i];
        int min_idx   = i;

        for (int j = i + 1; j < length; j++)
        {
            if (min_value > arr[j])
            {
                min_value = arr[j];
                min_idx = j;    
            }
        }

        swap_values(arr, i, min_idx);
    }
}

void bubbleSort(int arr[], const int length)
{
    for (int i = 0; i < length; i++)
    {
        // cout << "[" << i << "]\n";
        for (int j = 1; j < length - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
        printArray(arr, length);
    }
}

void swap_values(int arr[], const int i, const int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    printArray(arr, 5);
}