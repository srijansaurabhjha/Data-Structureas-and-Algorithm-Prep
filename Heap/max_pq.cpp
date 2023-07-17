#include<iostream>
#include<vector>
using namespace std;

class maxHeap{
    vector<int>pq;

    public:

    void push(int value){        
        pq.push_back(value);

        int i=pq.size()-1;

        while(i>=1){
           int parent_ind=(i-1)/2;
           if(pq[parent_ind]<pq[i]){
              swap(pq[parent_ind],pq[i]);
              i=parent_ind;
           }else break;
        }
    }


    void pop(){
        if(pq.size()==0)return;

        pq[0]=pq.back();

        pq.pop_back();

        int i=0;

        int n=pq.size();

        while(i<n){
            int lc=2*i+1;
            int rc=2*i+2;

            int larger=i;
            if(lc<n&&pq[larger]<pq[lc]){
                larger=lc;
            }
            if(rc<n&&pq[larger]<pq[rc]){
                larger=rc;
            }

            if(larger==i)break;

            swap(pq[larger],pq[i]);
            i=larger;
        }
    }

    int top(){
        if(pq.size()==0)return -1;
        return pq[0];
    }

    void print(){
        for(int i=0;i<pq.size();i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    maxHeap pq;
    pq.push(1);
    pq.push(4);
    pq.push(3);
    pq.push(2);
    pq.push(7);
    pq.push(5);
    pq.push(6);

    return 0;
}