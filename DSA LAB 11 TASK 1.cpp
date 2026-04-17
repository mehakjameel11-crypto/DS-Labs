#include <iostream>
using namespace std;

bool checkWinner(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num)
            return true;
    }
    return false;
}

int main() {
    int tickets[10] = {13579, 26791, 26792, 33445, 55555,
                       62483, 77777, 79422, 85647, 93121};

    int winningNumber;
    cout << "Enter winning number: ";
    cin >> winningNumber;

    if (checkWinner(tickets, 10, winningNumber))
        cout << "Winner ticket found!";
    else
        cout << "Invalid number";

    return 0;
}
