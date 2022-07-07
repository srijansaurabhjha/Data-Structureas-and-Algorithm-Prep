class Solution {
public:
    
    ListNode*reverse(ListNode*head){
        
        ListNode*curr=head;
        ListNode*next=NULL;
        ListNode*prev=NULL;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        
        //Finding Before Mid
        ListNode*slow=head,*fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }
        
        slow->next=reverse(slow->next);
        
        ListNode*start=head,*mid=slow->next;
        
        bool ans=true;
        
        while(mid){
            if(start->val!=mid->val)ans=false;
            start=start->next;
            mid=mid->next;
        }
        
        slow->next=reverse(slow->next);
        
        return ans;
    }
};