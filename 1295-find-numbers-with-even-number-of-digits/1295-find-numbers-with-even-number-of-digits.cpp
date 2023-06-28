class Solution {
public:
    bool check(int n)
    {
        int c=0;
        while(n)
        {
            c++;
            n/=10;
        }
        if(c%2==0)return true;
        return false;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;        
        for(int num:nums)
        {
            if(check(num))count++;
        }
        return count;
    }
};