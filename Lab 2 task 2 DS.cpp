#include <iostream>
using namespace std;

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main()
{
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    swap(&a, &b);

    cout << "After swapping:" << endl;
    cout << "First number = " << a << endl;
    cout << "Second number = " << b << endl;

    return 0;
}