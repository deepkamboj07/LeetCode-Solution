class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b)
    {
        if(a[0]<b[0])return true;
        else if(a[0]==b[0])return a[1]<b[1];
        return false;
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0; i<n; i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());

        vector<int> ans;
        long long int t=tasks[0][0],i=0;
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        
        while(!pq.empty() or i<n)
        {
            while(i<n && t>=tasks[i][0])
             {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
             }
           
            if(pq.empty())
            {
                t = tasks[i][0];
            }
            
            else
            {
               pair<int,int> p = pq.top();
               pq.pop();
               ans.push_back(p.second);
               t += p.first; 
            }  
        }
        return ans;
    }
};