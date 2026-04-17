#include <iostream>
using namespace std;

int sumArray(int arr[], int n, int i) {
    if (i == n)   
        return 0;

    return arr[i] + sumArray(arr, n, i + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Sum = " << sumArray(arr, n, 0);

    return 0;
}
