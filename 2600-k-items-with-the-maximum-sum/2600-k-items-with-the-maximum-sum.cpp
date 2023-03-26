class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans=0;
        while(k and numOnes)
        {
            ans++;
            k--;
            numOnes--;
        }
        if(k==0)return ans;
        while(k and numZeros){
            k--;
            numZeros--;
        }
        if(k==0)return ans;
        
        while(k and numNegOnes){
            ans--;
            k--;
            numNegOnes--;
        }
        return ans;
    }
};