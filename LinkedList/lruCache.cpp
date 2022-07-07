class LRUCache {
public:
    
    unordered_map<int,int>mp;
    list<int>l;  //lru feature implentation
    
    unordered_map<int,list<int>::iterator>address; //mapping of list nodes addresses
    
    int cp;
    int sz;
    LRUCache(int capacity) {
        cp=capacity;
        sz=0;
    }
    
    int get(int key) {

        if(mp.find(key)==mp.end())return -1;
        
        list<int>::iterator it=address[key];
        
        l.erase(it);
        l.push_front(key);
        
        address.erase(key);
        
        address[key]=l.begin();
        
        return mp[key];
    }
    
    void put(int key, int value) {
        
        //If key is already present just remove it
        if(mp.find(key)!=mp.end()){
            
            list<int>::iterator it=address[key];
            l.erase(it);
            mp.erase(key);
            address.erase(key);
            sz--;
        }
        
        //updating list for lru feature
        if(sz==cp){
            int k=l.back();
            l.pop_back();
            mp.erase(k);
            address.erase(k);
            sz--;
        }
        
        mp[key]=value;
        l.push_front(key);
        address[key]=l.begin();
        sz++;
    }
};