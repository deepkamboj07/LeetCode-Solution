class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd,even;
        string rev=to_string(num);
        while(num)
        {
            int d=num%10;
            if(d%2==0)even.push(d);
            else odd.push(d);
            num/=10;
        }
        
        int ans=0,i=0;
        while(i<rev.size())
        {
            int d=rev[i]-'0';
            if(d%2==0)
            {
                ans=(ans*10)+even.top();
                even.pop();
            }
            else
            {
                ans=(ans*10)+odd.top();
                odd.pop();
            }
            
            i++;
        }
        
        return ans;
    }
};