class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i+=2)
        {
            int freq=nums[i];
            int digit=nums[i+1];
            while(freq--)
                ans.push_back(digit);
        }
        return ans;
    }
};