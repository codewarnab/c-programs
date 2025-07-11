#include <iostream>

using namespace std;

int binarySearchIterative(int arr[], int size, int target)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found 
}

int main()
{
    int arr[] = {2, 4, 10, 23, 40, 55, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearchIterative(arr, size, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}