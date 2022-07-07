class MyHashMap {
    vector<list<pair<int,int>>>s;
    int n;
    public:
    MyHashMap() {
        n=100;
        s.resize(n+1);
    }
    
    int hash(int key){
        return key%n;
    }
    
    list<pair<int,int>>:: iterator search(int key){
        int i=hash(key);
        // return find(s[i].begin(),s[i].end(),{key,val});  Cannot use find function because we don't know the val
        
        list<pair<int,int>>:: iterator it=s[i].begin();
        
        for(;it!=s[i].end();it++){
            if(it->first==key)return it;
        }
        
        return it;
    }
    
    void put(int key, int value) {
        int i=hash(key);
        if(search(key)!=s[i].end()){
            remove(key);
        }
        
        s[i].push_back({key,value});
    }
    
    int get(int key) {
        int i=hash(key);
        list<pair<int,int>> :: iterator it=search(key);
        
        if(it==s[i].end())return -1;
        
        
        return it->second;
    }
    
    void remove(int key) {
        int i=hash(key);
        
        list<pair<int,int>>:: iterator it=search(key);
        
        if(it==s[i].end())return;
        
        s[i].erase(it);
    }
};
