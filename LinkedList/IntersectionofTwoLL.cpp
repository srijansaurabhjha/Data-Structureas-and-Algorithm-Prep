class Solution {
public:
    int length(ListNode* head){
        if(!head)return 0;
        
        ListNode*temp=head;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)return NULL;
        
        int lenA=length(headA);
        int lenB=length(headB);
        ListNode*temp1=headA;
        ListNode*temp2=headB;
       if(lenA>lenB){
           int dist=lenA-lenB;
           
           while(dist--&&temp1){
               temp1=temp1->next;
           }
       }else{
         int dist=lenB-lenA;
           
           while(dist--&&temp2){
               temp2=temp2->next;
           }          
       }
        
       while(temp1&&temp2){
           if(temp1==temp2)return temp1;
           
           temp1=temp1->next;
           temp2=temp2->next;
       }
        
       return NULL;
    }
};