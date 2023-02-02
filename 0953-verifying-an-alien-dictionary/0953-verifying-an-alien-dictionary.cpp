class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int,int> mp;
        int n=order.length();
        for(int i=0;i<n;i++)
            mp[order[i]]=i;
        
        n=words.size();
        for(int i=0;i<n-1;i++)
        {
            string check=words[i];
            string tmp=words[i+1];
            if(mp[check[0]]<mp[tmp[0]]) continue;
            if(mp[check[0]] > mp[tmp[0]]) return false;
                
            int k=0,l=0;
            while(k<check.length() and l<tmp.length())
            {
                 if(mp[check[k]] > mp[tmp[l]]) return false;
                 k++;
                 l++;
            }
         if(k!=check.length() and l==tmp.length() and mp[check[l-1]]==mp[tmp[l-1]])return false;
        }
        
        return true;
    }
};