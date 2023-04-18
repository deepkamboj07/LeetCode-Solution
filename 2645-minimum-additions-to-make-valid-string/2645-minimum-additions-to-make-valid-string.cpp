class Solution {
public:
    int addMinimum(string word) {
        string tm="abc";
        int n= word.length();
        int ans=0,i=0,j=0;

       while(i<n)
       {
           int c=0;
           if(word[i]=='a')
           {
                c++;
                i++;
           }
           
           if(i<n and word[i]=='b')
           {
              c++;
               i++;
           }
           
           if(i<n and word[i]=='c')
           {
              c++;
              i++;
           }
           
           ans+=(3-c);
        }

        return ans;    
    }
};