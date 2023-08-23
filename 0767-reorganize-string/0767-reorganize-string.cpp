class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char,int> mp;
        string str="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto it: mp)
            pq.push({it.second,it.first});
        
        while(pq.size() > 1)
        {
            char ch1= pq.top().second;
            int size1= pq.top().first;
            size1--;
            pq.pop();
            
            str+=ch1;
            char ch2= pq.top().second;
            int size2= pq.top().first;
            size2--;
            str+=ch2;
            
            pq.pop();
            
            
            if(size1>0)
            {
                pq.push({size1,ch1});
            }
            if(size2>0)
            {
                pq.push({size2,ch2});
            }
        }
        
        
        while(!pq.empty())
        {
            if(pq.top().first > 1)return "";
            else
            {
                str+=pq.top().second;
                pq.pop();
            }
        }
        
        return str;
    }
};