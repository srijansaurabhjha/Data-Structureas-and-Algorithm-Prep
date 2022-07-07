class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head,*fast=head;
        
        while(fast&&fast->next){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)break;
        }
        
        if(!fast||!fast->next)return NULL;
        
        
        ListNode*ptr1=head,*ptr2=fast;
        while(ptr1!=ptr2){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        return ptr2;
    }
};