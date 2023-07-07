class Solution {
public:
    int solve(string str,int k,char ch)
    {
        int i=0,j=0;
        int n=str.size();
        int maxi=0;

        while(j<n)
        {
            if(str[j]==ch)
            {
                maxi=max(maxi,j-i+1);
            }
            else
            {
                if(k>0)
                {
                    k--;
                    maxi=max(maxi,j-i+1);
                }
                else
                {
                    while(i<j and k==0)
                    {
                        if(str[i]!=ch)k++;
                        i++;
                    }
                    k--;
                }
            }
            j++;
        }
        
        return maxi;
        
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int maxi1=solve(answerKey,k,'T');
        int maxi2=solve(answerKey,k,'F');
        
        cout<<maxi1<<" "<<maxi2<<endl;
        if(maxi1>=maxi2)return maxi1;
        return maxi2;
    }
};