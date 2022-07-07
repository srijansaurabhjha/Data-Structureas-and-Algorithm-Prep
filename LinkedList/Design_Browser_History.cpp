class BrowserHistory {
public:
    list<string>l;
    list<string>::iterator it;
    
    BrowserHistory(string homepage) {
        l.push_back(homepage);
        it=l.begin();
    }
    
    void visit(string url) {
        list<string>::iterator next=it;
        next++;
        
        l.erase(next,l.end());
        
        l.push_back(url);
        it++;
    }
    
    string back(int steps) {
        
        while(it!=l.begin()&&steps--){
            it--;
        }
        
        return *it;
    }
    
    string forward(int steps) {
        while(it!=(--l.end())&&steps--){
            it++;
        }
       return *it; 
    }
};