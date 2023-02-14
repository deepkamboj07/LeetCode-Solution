class Solution {
public:
    string addBinary(string a, string b) {
        if(a=="0")return b;
        if(b=="0")return a;
        
        int n=a.length()-1;
        int m=b.length()-1;
        
        string ans="";
        int carry=0;
        while(n>=0 or m>=0)
        {
            if(n<0)
            {
                int sum=(b[m--]-'0')+carry;
                carry=sum/2;
                sum=sum%2;
                ans+=to_string(sum);
            }
            else if(m<0)
            {
                int sum=(a[n--]-'0')+carry;
                carry=sum/2;
                sum=sum%2;
                ans+=to_string(sum);
            }
            else
            {
                int sum=(a[n--]-'0') + (b[m--]-'0')+carry;
                carry=sum/2;
                sum=sum%2;
                ans+=to_string(sum);
            }
        }
        if(carry!=0)
            ans+=to_string(carry);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};