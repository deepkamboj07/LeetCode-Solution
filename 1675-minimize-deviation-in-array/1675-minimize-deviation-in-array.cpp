class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini=1e9;
        for(auto num: nums)
        {
            if(num%2!=0)
            {
                num*=2;
            }
            mini=min(mini,num);
            pq.push(num);
        }
        
        cout<<mini<<" ";
        int dev=1e9;
        while(true)
        {
            int top=pq.top();
            dev=min(dev, top-mini);
            pq.pop();
            if(top%2==1)break;
            top/=2;
            pq.push(top);
            mini=min(mini,top);
        }
        //int top=pq.top();
        return dev;
    }
};