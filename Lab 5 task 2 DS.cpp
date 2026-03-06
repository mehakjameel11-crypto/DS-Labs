#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

int main(){

    Node *head=NULL, *tail=NULL;

    int rain, total=0;
    int max=0, min=9999;
    int maxDay=0, minDay=0;

    for(int i=1;i<=7;i++){

        cout<<"Enter rainfall for day "<<i<<": ";
        cin>>rain;

        if(rain<0){
            cout<<"Negative values are not allowed\n";
            i--;
            continue;
        }

        Node* n=new Node();
        n->data=rain;
        n->next=NULL;
        n->prev=NULL;

        if(head==NULL){
            head=tail=n;
        }
        else{
            tail->next=n;
            n->prev=tail;
            tail=n;
        }

        total+=rain;

        if(rain>max){
            max=rain;
            maxDay=i;
        }

        if(rain<min){
            min=rain;
            minDay=i;
        }
    }

    cout<<"\nTotal Rainfall = "<<total<<endl;
    cout<<"Average Rainfall = "<<total/7.0<<endl;

    cout<<"Highest Rainfall = "<<max<<" on day "<<maxDay<<endl;
    cout<<"Lowest Rainfall = "<<min<<" on day "<<minDay<<endl;

    
    Node* temp=head;
    int count=1;

    while(temp!=NULL){
        if(count==6){
            cout<<"Rainfall after 5th node = "<<temp->data<<endl;
            break;
        }
        temp=temp->next;
        count++;
    }

}
