class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> mp;
            for(auto ch: words[i])
            {
                if(mp[ch]==0)mp[ch]=1;
            }
            for(int j=i+1;j<n;j++)
            {
                unordered_map<char,int> mp2;
                for(auto ch: words[j])
                {
                    if(mp2[ch]==0)mp2[ch]=1;
                }
                
                if(mp==mp2)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};