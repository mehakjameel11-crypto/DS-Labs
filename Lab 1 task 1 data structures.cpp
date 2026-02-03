#include<iostream>
using namespace std;
int main() {
	int arr[4]={30,40,50,60};
	int key=40;
	for(int i=0 ; i<4 ; i++){
		if(arr[i]==key){
			cout<<"element found at index"<<" "<<i;
			return 0;
		}
	}
	cout<<"element not found";
	return 0;
}