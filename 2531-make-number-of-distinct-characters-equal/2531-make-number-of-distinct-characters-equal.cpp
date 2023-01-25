class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> a(26,0), b(26,0);
        
        for(auto c: word1)
        {
            a[c-'a']++;
        }
        for(auto c: word2)
        {
            b[c-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(a[i]>0)
            {
                for(int j=0;j<26;j++)
                {
                    if(b[j]>0)
                    {
                        a[j]++;
                        a[i]--;

                        b[i]++;
                        b[j]--;

                        unordered_map<char,int> mp1,mp2;

                        for(int k=0;k<26;k++)
                        {
                            if(a[k]>0){
                                char d=(char)('a'+k);
                                mp1[d]++;
                            }
                            if(b[k]>0){
                                char d=(char)('a'+k);
                                mp2[d]++;
                            }
                        }

                        if(mp1.size()==mp2.size()) return true;

                        a[j]--;
                        a[i]++;
                        b[i]--;
                        b[j]++;
                    }
                }
            }
        }
        
        
        
        return false;
    }
};