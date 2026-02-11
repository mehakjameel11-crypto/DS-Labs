  #include <iostream>
using namespace std;

struct Product
{
    char name[50];
    int code;
    float price;
};

int main()
{
    int n;
    cout << "Enter number of products: ";
    cin >> n;

  
    Product *p = new Product[n];

 
    for(int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i+1 << endl;

        cout << "Name: ";
        cin >> p[i].name;

        cout << "Code: ";
        cin >> p[i].code;

        cout << "Price: ";
        cin >> p[i].price;
    }

   
    cout << "\n...Product List is as follows...\n";
    for(int i = 0; i < n; i++)
    {
        cout << "\nName: " << p[i].name;
        cout << "\nCode: " << p[i].code;
        cout << "\nPrice: " << p[i].price << endl;
    }

     
    delete[] p;

    return 0;
}