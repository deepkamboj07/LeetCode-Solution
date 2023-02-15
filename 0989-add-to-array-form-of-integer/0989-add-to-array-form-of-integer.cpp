class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        int n=num.size();
        vector<int> ans;
        int i=0;
        for(i=n-1;i>=0 and k ;i--)
        {
            int dig=k%10;
            k=k/10;
            
            int sum=num[i]+dig+carry;
            carry=sum/10;
            sum=sum%10;
            
            ans.push_back(sum);
        }
        
        while(i>=0)
        {
            int sum=num[i--]+carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back(sum);
        }
        while(k)
        {
            int dig=k%10;
            k=k/10;
            int sum=dig+carry;
            carry=sum/10;
            sum%=10;
            ans.push_back(sum);
        }
        if(carry!=0)
            ans.push_back(carry);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};