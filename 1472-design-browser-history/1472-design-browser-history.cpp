class BrowserHistory {
public:
    int curr=-1,dubli=-1,forw=-1,backw=-1;
    vector<string> history;
    BrowserHistory(string homepage) {
        curr=0;
        dubli=0;
        history.push_back(homepage);
    }
    
    void visit(string url) {
        history.erase(history.begin()+1+curr,history.end());
        curr++;
        history.push_back(url);
    }
    
    string back(int steps) {
       curr=max(0,curr-steps);
       return history[curr];
    }
    
    string forward(int steps) {
       curr=min((int)history.size()-1, curr+steps);
       return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */