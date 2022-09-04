#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }
};

class list{
    Node* head;
    Node* tail;
    public:
    list(){
        head=tail=NULL;
    }

    void print(){
         Node*temp=head;
         while(temp){
             cout<<temp->data<<" ";
             temp=temp->next;
         }
         cout<<endl;
    }

    void printBack(){
        Node*temp=tail;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }

    void push_back(int value){
        if(head==NULL){
            Node* newNode=new Node(value);
            head=newNode;
            tail=newNode;
        }else{
            Node* newNode=new Node(value);
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    void pop_back(){
        if(head==NULL)return;
        if(head->next==NULL){
            delete head;
            head=tail=NULL;
            return;
        }

        Node*NodetoBeDelete=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete NodetoBeDelete;
    }

    
};

int main()
{
    list l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    l.print();
    l.printBack();

    l.pop_back();
    l.print();
    l.printBack();


    return 0;
}