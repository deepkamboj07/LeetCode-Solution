class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        
        int n=group.size();
        for(int i=0;i<n;i++)
        {
            mp[group[i]].push_back(i);
        }
        
        for(auto it: mp)
        {
            int size=it.first;
            int member= it.second.size();         
            int p = member / size;
            
            int i=0;
            while(p--)
            {
                int k=i;
                vector<int> tmp;
                while(k < (i+size))
                {
                    tmp.push_back(it.second[k]);
                    k++;
                }
                
                i=size;         
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
};