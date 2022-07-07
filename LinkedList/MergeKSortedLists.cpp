class cmp{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //min Heap
        priority_queue<ListNode*,vector<ListNode*>,cmp>q;
        ListNode* dummy=new ListNode(-1);
        ListNode*tail=dummy;
        for(int i=0;i<lists.size();i++){
           if(lists[i])q.push(lists[i]);
        }
        
        while(!q.empty()){
            ListNode*curr=q.top();
            q.pop();
            tail->next=curr;
            tail=curr;
            if(curr->next){
            curr=curr->next;
            q.push(curr);
            }
        }
        
        return dummy->next;
    }
};


// T.C-> 0(N*logK)   N->no. of nodes & K->no. of LL's
//S.C->0(K)