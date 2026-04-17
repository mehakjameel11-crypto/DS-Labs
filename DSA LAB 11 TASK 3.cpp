#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {

    if (size == 0)
        return -1;

    if (arr[size - 1] == key)
        return size - 1;

    return linearSearch(arr, size - 1, key);
}

int main() {
    int arr[] = {20, 35, 48, 62, 98};
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int result = linearSearch(arr, 5, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}
