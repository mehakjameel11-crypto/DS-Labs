  #include <iostream>
using namespace std;

struct Player{
    string name;
    int score;
    Player* next;
    Player* prev;
};

Player* head=NULL;
 
void addPlayer(string n,int s){

    Player* p=new Player{n,s,NULL,NULL};

    if(head==NULL){
        head=p;
        return;
    }

    Player* t=head;

    while(t->next!=NULL && t->score < s)
        t=t->next;

    if(t==head && s < head->score){
        p->next=head;
        head->prev=p;
        head=p;
    }
    else{
        p->next=t->next;

        if(t->next!=NULL)
            t->next->prev=p;

        t->next=p;
        p->prev=t;
    }
}
 
void deletePlayer(string n){

    Player* t=head;

    while(t!=NULL){
        if(t->name==n){

            if(t->prev!=NULL)
                t->prev->next=t->next;
            else
                head=t->next;

            if(t->next!=NULL)
                t->next->prev=t->prev;

            delete t;
            cout<<"Player deleted\n";
            return;
        }
        t=t->next;
    }

    cout<<"Player not found\n";
}

// Display list
void display(){

    Player* t=head;

    while(t!=NULL){
        cout<<t->name<<"  "<<t->score<<endl;
        t=t->next;
    }
}
 
void lowest(){

    if(head!=NULL)
        cout<<"Lowest Score Player: "<<head->name<<" "<<head->score<<endl;
}
 
void sameScore(int s){

    Player* t=head;

    while(t!=NULL){
        if(t->score==s)
            cout<<t->name<<" "<<t->score<<endl;

        t=t->next;
    }
}

// Backward from player
void backward(string n){

    Player* t=head;

    while(t!=NULL && t->name!=n)
        t=t->next;

    if(t==NULL){
        cout<<"Player not found\n";
        return;
    }

    t=t->prev;

    while(t!=NULL){
        cout<<t->name<<" "<<t->score<<endl;
        t=t->prev;
    }
}

int main(){

    int ch,s;
    string n;

    do{

        cout<<"\n1 Add\n2 Delete\n3 Display\n4 Lowest\n5 Same Score\n6 Backward\n0 Exit\n";
        cin>>ch;

        switch(ch){

        case 1:
            cout<<"Enter name: ";
            cin>>n;
            cout<<"Enter score: ";
            cin>>s;
            addPlayer(n,s);
            break;

        case 2:
            cout<<"Enter name: ";
            cin>>n;
            deletePlayer(n);
            break;

        case 3:
            display();
            break;

        case 4:
            lowest();
            break;

        case 5:
            cout<<"Enter score: ";
            cin>>s;
            sameScore(s);
            break;

        case 6:
            cout<<"Enter player name: ";
            cin>>n;
            backward(n);
            break;

        }

    }while(ch!=0);

}
