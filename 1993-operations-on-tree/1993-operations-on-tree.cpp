class LockingTree {
    unordered_map<int,vector<int>> graph;
    unordered_map<int,vector<int>> parents;
    int n;
    unordered_map<int,pair<bool,int>> locked;
    
    bool parentsNodeCheck(int node)
    {
        if(locked.find(node)!=locked.end() and locked[node].first)return false;
        for(auto u: parents[node])
        {
           if(!parentsNodeCheck(u))return false;
        }
        return true;
    }
    
    void childNodeChange(int node, bool &lock)
    {
        if(locked[node].first)
        {
            lock=true;
            locked[node].first=false;locked[node].second=-1;
        }
        
        for(auto v: graph[node])
        {
            childNodeChange(v,lock);
        }
    }
public:
    LockingTree(vector<int>& parent) {
        n=parent.size();
        for(int i=0;i<n;i++)
        {
            if(parent[i]!=-1)
            {
                graph[parent[i]].push_back(i);
                parents[i].push_back(parent[i]);
            }
        }
    
    }
    
    bool lock(int num, int user) {
        if(locked[num].first) return false;
        else
        {
            locked[num].first=true;
            locked[num].second=user;
            return true;
        }
    }
    
    bool unlock(int num, int user) {
        if(locked.find(num)==locked.end())return false;
        if(!locked[num].first) return false;
        else if(locked[num].second!=user)return false;
        else
        {
            locked[num].first=false;
            locked[num].second=-1;
            return true;
        }
    }
    
    bool upgrade(int num, int user) {

        bool acestorsLocked=parentsNodeCheck(num);
        if(!acestorsLocked)return false;
        
        bool lock=false;
        childNodeChange(num,lock);
       // cout<<num<<" ";
        if(!lock)return false;
        
        locked[num].first=true;
        locked[num].second=user;
        return true;
        
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */