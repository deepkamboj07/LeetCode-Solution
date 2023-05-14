class Solution {
public:
    int dp[1 << 15];
    int n;

    int f(int op, vector<int>& nums, int mask) {
        if(op == n)return 0;
        if(dp[mask] != -1)return dp[mask];

        int ret = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                for(int j = i + 1; j < n; j++) {
                    if(nums[j] != 0) {
                        int a = nums[i], b = nums[j];
                        int g = __gcd(a, b);
                        nums[i] = nums[j] = 0;
                        mask = mask | (1 << i) | (1 << j);
                        ret = max(ret, f(op+1, nums, mask) + (op+1) * g);
                        nums[i] = a;nums[j] = b;
                        mask = mask ^ (1 << i) ^ (1 << j);
                    }
                }
            }
        }

        return dp[mask] = ret;
    }

    int maxScore(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return f(0, nums, 0);
    }
};