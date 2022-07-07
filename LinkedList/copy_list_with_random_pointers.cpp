
//Approach 1
class Solution {
public:
    map<Node*,Node*>mp;
    
    Node* copyRandomList(Node* head) {
        
        if(!head)return head;
        
        Node* temp=head;
        while(temp){
            Node* copy=new Node(temp->val);
            mp[temp]=copy;
            temp=temp->next;
        }
        
        temp=head;
        while(temp){
            mp[temp]->next=mp[temp->next];
            mp[temp]->random=mp[temp->random];
            temp=temp->next;
        }
        
        return mp[head];
    }
};


//Approach 2
class Solution {
public:
    
    void mergeList(Node* head){
        Node*temp=head,*n=head->next;
        while(temp){
            Node*copy=new Node(temp->val);
            temp->next=copy;
            copy->next=n;
            temp=n;
            if(n)n=n->next;
        }
    }
    
    void DoRandomConn(Node* head){
        Node* temp=head;
        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }    
            temp=temp->next->next;
        }
    }
    
    Node*seperate(Node* head){
         Node* dummy=new Node(-1);
         Node* tail=dummy;
         Node*temp=head;
        
         while(temp){
            tail->next=temp->next;
            tail=tail->next;
             
            temp->next=tail->next;
            temp=tail->next;
             
         }
        return dummy->next;
    }
    
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        mergeList(head);
        
        DoRandomConn(head);
        
        return seperate(head);
    }
};