class Solution {
public:
    int sum(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
    int size(int n)
    {
        int s=0;
        while(n)
        {
            s++;
            n/=10;
        }
        return s;
    }
    int addDigits(int num) {
        
        while(size(num)>=0 and size(num)>1)
        {
            num=sum(num);
        }
        return num;
        
    }
};