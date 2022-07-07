

//Iterative Method
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head)return head;
        
        ListNode* curr= head,* prev= NULL,*temp= NULL;
        
        while(curr){
            cout<<curr->val<<" ";
            temp=curr->next;
            curr->next=prev;    
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
};


//Recursive Method
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode* temp=NULL;
        
        ListNode * tmpHeadNxt=head->next;
        
        temp=reverseList(head->next);
        tmpHeadNxt->next=head;
        head->next=NULL;
        return temp;
    }
};
