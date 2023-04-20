class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=0;
        int ind=-1,i=0;
        for(auto num: nums)
        {
            if(maxi<num)
            {
                maxi=num;
                ind=i;
            }
            i++;
        }
        
        for(auto num:nums)
        {
            if(num==maxi)continue;
            if(num*2 > maxi)return -1;
        }
        
        return ind;
    }
};