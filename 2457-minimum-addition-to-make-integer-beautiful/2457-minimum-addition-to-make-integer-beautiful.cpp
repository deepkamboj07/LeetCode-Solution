class Solution {
public:
    long long reverseD(long long n,long long zero)
    {
        long long ans=0;
        while(n)
        {
            int digit=n%10;
            ans=(ans*10)+digit;
            n/=10;
        }
        while(zero)
        {
            ans*=10;
            zero--;
        }
        return ans;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        if(n<=target)return 0;
        int sum=0;
        long long digit=n;
        while(digit)
        {
            int d=digit%10;
            sum+=d;
            digit/=10;
        }
        if(sum<=target)return 0;
        
        int carry=0;
        long long ans=0;
        long long zero=0;
        while(sum>target and n)
        {
            digit=((n)%10 +carry);
            if(digit!=0)
            {
                int val=(10-digit);
                carry=1;
                if(val!=0){
                    sum-=digit;
                    sum+=carry;
                    ans=(ans*10)+val;
                }
                else if(val==0 and digit==10)
                {
                    sum-=10;
                    sum+=carry;
                    ans*=10;
                }
                
                //cout<<sum<<" ";
            }
            else zero++;
            
            n/=10;
            
        }
       // cout<<zero;
                         
        return reverseD(ans,zero);
    }
};