class Solution {
public:
     int stonesAliceGets(vector<int>&piles, vector<vector<vector<int>>>&dp, int m, int startIdx, int turn)
    {
        if (startIdx == piles.size()) return 0;
        if (dp[m][startIdx][turn] != -1) return dp[m][startIdx][turn]; //use stored results
        
        int takenCount = 0;
        int ans = (turn == 0)? 0 : INT_MAX;
        for (int x = 1; x <= (2 * m); x++)
        {
            int pileIdx = startIdx + x - 1;
            if (pileIdx >= piles.size()) break;
            takenCount += piles[pileIdx];
            
            if (turn == 0)
            {
                int nextAliceCount = stonesAliceGets(piles, dp, max(m, x), pileIdx + 1, 1);
                int totalCount = takenCount + nextAliceCount; 
                ans = max(ans, totalCount); //maximize what Alice will get
            }
            else
            {
                int nextAliceCount = stonesAliceGets(piles, dp, max(m, x), pileIdx + 1, 0);
                ans = min(ans, nextAliceCount); //minimize what Alice will get
            }
        }
        return dp[m][startIdx][turn] = ans; //store the results
    }
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(n, vector<int>(2, -1)));
        int ans = stonesAliceGets(piles, dp, 1, 0, 0);
        return ans;
        
    }
};