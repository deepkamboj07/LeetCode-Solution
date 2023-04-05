class Solution {
public:
    typedef long long ll;

    // Function to check if a given target value is valid
    // by checking if it's possible to make all elements of nums <= target
    bool isValid(ll target, vector<int>& nums){
        if(nums[0]>target) return false; 
        ll prev=nums[0];
        for(int i=1;i<nums.size();++i){
            ll diff=target-prev; // Calculate the difference between target and previous element
            prev=nums[i]-diff; // Update prev by subtracting the difference from current element
            if(prev>target) return false; 
        }
        return true; // If all elements can be made <= target, return true
    }

    int minimizeArrayValue(vector<int>& nums) {
        ll left=0, right=*max_element(nums.begin(),nums.end()); // Set left to 0 and right to the maximum element in nums
        while(left<right){ 
            int mid=left+(right-left)/2; 
            if(isValid(mid,nums)) right=mid; // If mid is a valid target, update right pointer
            else left=mid+1; // If mid is not a valid target, update left pointer
        }
        return right; // Return the smallest valid target value
    }
};