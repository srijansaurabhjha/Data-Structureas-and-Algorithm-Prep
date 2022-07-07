
//Approach 1
class MyHashSet {
public:
    int n=1e6;
    vector<int>s;
    MyHashSet() {
        s.assign(n+1,0);
    }
    
    void add(int key) {
        s[key]=1;
    }
    
    void remove(int key) {
        s[key]=0;
    }
    
    bool contains(int key) {
        return s[key]==1;
    }
};

//Approach 2
class MyHashSet {
public:
    int n=50;
    vector<list<int>>s;
    MyHashSet() {
        s.resize(n+1);
    }
    
    int hash(int key){
        return key%n;
    }
    
    list<int> ::iterator search(int key){
        int i=hash(key);
        return find(s[i].begin(),s[i].end(),key);
    }
    
    void add(int key) {
        if(contains(key))return;
        int i=hash(key);
        s[i].push_back(key);
    }
    
    void remove(int key) {
        int i=hash(key);
        if(search(key)==s[i].end())return;
        s[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        return (search(key)!=s[i].end());
    }
};