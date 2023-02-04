class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp;
        for(auto c: s1)
            mp[c]++;
        
        int n=s2.length();
        int k=s1.length(),i=0,j=0;
        
        map<char,int> mp2;
        while(j<n)
        {
            char c=s2[j];
            mp2[c]++;
            
            if(j-i+1==k)
            {
                if(mp2==mp)return true;
                else
                {
                    mp2[s2[i]]--;
                    if(mp2[s2[i]]==0)mp2.erase(s2[i]);
                    i++;
                }
            }
            j++;
        }
        
        return false;
    }
};