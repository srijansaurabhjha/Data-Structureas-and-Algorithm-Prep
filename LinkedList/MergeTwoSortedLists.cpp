class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1)return list2;
        
        if(!list2)return list1;
        
        ListNode*head=NULL;
        ListNode*tail=NULL;
        
        ListNode*t1=list1;
        ListNode*t2=list2;
        
        while(t1&&t2){
            if(head==NULL){
                if(t1->val>t2->val){
                    head=t2;
                    tail=t2;
                    t2=t2->next;
                }else{
                    head=t1;
                    tail=t1;
                    t1=t1->next;
                }
            }else{
                
                 if(t1->val>t2->val){
                     tail->next=t2;
                     tail=t2;
                     t2=t2->next;
                 }else{
                     tail->next=t1;
                     tail=t1;
                     t1=t1->next;
                 }
            }
        }
        
        
        if(t1!=NULL){
            tail->next=t1;
        }
        
        if(t2!=NULL){
            tail->next=t2;
        }
        
        return head;
    }
};


//Recursive solution
class Solution {
public:
    
    ListNode*merge(ListNode* list1,ListNode* list2){
        if(!list1)return list2;
        if(!list2)return list1;
        
        if(list2->val>list1->val){
            list1->next=merge(list1->next,list2);
            return list1;
        }else{
            list2->next=merge(list1,list2->next);
            return list2;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1,list2);
    }
};