  #include <iostream>
using namespace std;

int main()
{
    char *p = new char;   // create memory

    *p = 'H';             // store character

    cout <<"Stored character is: "<<*p;           // print character

    delete p;             // free memory
    p = nullptr;          // make pointer empty

    return 0;
}


