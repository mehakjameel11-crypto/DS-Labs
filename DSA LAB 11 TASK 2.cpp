#include <iostream>
using namespace std;

bool binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return false;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return true;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int key = 40;

    if (binarySearch(arr, 0, 4, key))
        cout << "Element found";
    else
        cout << "Element not found";

    return 0;
}
