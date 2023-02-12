class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j)
        {
            int n1=nums[i];
            int n2=nums[j];
            long long tmp=n1;
            int revDigit=0;
            int zero=0;
            while(n2)
            {
                int d=n2%10;
                if(revDigit==0 and d==0)zero++;
                revDigit=(revDigit*10)+d;
                n2/=10;
            }
            
            while(revDigit)
            {
                int d=revDigit%10;
                tmp=(tmp*10)+d;
                revDigit/=10;
            }
            
            while(zero>0)
            {
                tmp*=10;
                zero--;
            }
            
            ans+=tmp;
            i++;
            j--;
        }
        if(i==j)
        {
            ans+=nums[i];
        }
        return ans;
    }
};