#include<iostream>
using namespace std;

class Node{
   private:
     Node* next;
     int data;
   public:
     Node(){
        next=NULL;
        data=0;
     }
     Node(int data){
        next=NULL;
        this->data=data;
     }
     friend class LL;
     friend void print(Node* root);

};

void print(Node *root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}

class LL{
    public:
    Node* head;
    LL(){
        head=NULL;
    }

    void add(int data){
        Node* newNode=new Node(data);
        if(head==NULL){ 
            head=newNode;
            return;
        }else{
            Node* temp=head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
};


int main(){
     LL l;
     l.add(1);
     l.add(2);
     l.add(3);
     l.add(4);
     l.add(5);
     print(l.head);
return 0;
}