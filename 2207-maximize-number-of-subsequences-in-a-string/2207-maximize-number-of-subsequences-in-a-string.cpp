class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        int maxi1=0,maxi2=0;
        long long int total=0,total1=0;
        long long int ch1=1,ch2=0,n=text.length();
        
        for(int i=0;i<n;i++)
        {
            if(text[i]==pattern[0])
            {
                if(ch2!=0)
                {
                    total+=(ch1*ch2);
                }
                ch1++;
                ch2=0;
            }
            else if(text[i]==pattern[1])
            {
                ch2++;
            }
        }
        
        total+=(ch2*ch1);
        ch1=0,ch2=0;
        
        for(int i=0;i<n;i++)
        {
            if(text[i]==pattern[0])
            {
                if(ch2!=0)
                {
                    total1+=(ch1*ch2);
                }
                ch1++;
                ch2=0;
            }
            else if(text[i]==pattern[1])
            {
                ch2++;
            }
        }
        
        total1+=(ch1*(ch2+1));
        
        if(pattern[0]==pattern[1])
        {
            long long int prod=((long long int)(total1)*(long long int)(total1+1))/2;
            return prod;
        }
        return max(total,total1);
    }
};