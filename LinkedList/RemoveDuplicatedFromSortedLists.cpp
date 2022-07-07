class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode*dummy=new ListNode(-101);
        ListNode*s=dummy;
        ListNode*skip=head;
        
        while(skip){
            if(skip->val!=s->val){
                s->next=skip;
                s=s->next;
            }
            skip=skip->next;
        }
        s->next=NULL;
        return dummy->next;
    }
    
};