class Solution {
public:
    string reverseVowels(string s) {
        string vo="";
        
        for(auto it: s)
        {
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u' || 
              it=='A' || it=='E' || it=='I' || it=='O' || it=='U')
            {
                vo+=it;
            }
        }
        
        reverse(vo.begin(),vo.end());
        
        string ans="";
        int i=0;
        for(auto it: s)
        {
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u' || 
              it=='A' || it=='E' || it=='I' || it=='O' || it=='U')
            {
                ans+=vo[i];
                i++;
            }
            else ans+=it;
        }
        
        return ans;
    }
};