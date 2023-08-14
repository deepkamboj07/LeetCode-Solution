class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pq.size()<k)
                pq.push(nums[i]);
            else if(pq.size()==k)
            {
                if(nums[i]>pq.top())
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};