//With Extra stack space
class Solution {
public:
    void reverse(ListNode* s,ListNode* e){
        ListNode*curr=s,* prev=NULL,*next=NULL;
        while(prev!=e){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next||k==1)return head;
        
        ListNode* s=head,*e=head; 
        int cnt=k-1;
        
        while(cnt--){
           e=e->next;
           if(e==NULL)return head;
        }
        
        ListNode* temp=reverseKGroup(e->next,k);
        reverse(s,e);
        
        s->next=temp;
        
        return e;
    }
};