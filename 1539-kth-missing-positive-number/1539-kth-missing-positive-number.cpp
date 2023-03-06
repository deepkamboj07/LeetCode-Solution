class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=1;
        int n=arr.size();
        int high=3000;
        unordered_set<int> st(arr.begin(), arr.end());
        if(k<low)return k;
        
        while(low<=high and k>=1)
        {
            if(st.find(low)==st.end())
            {
                k--;
            }
            if(k>=1)low++;
        }
        
        return low;
    }
};