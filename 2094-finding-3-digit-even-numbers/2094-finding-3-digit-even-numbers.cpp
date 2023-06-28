class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        int n=digits.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i!=j and j!=k and k!=i)
                    {
                        if(digits[i]!=0)
                        {
                            int digit=(((digits[i]*10)+(digits[j]))*10) + digits[k];
                            if(digit%2==0)ans.insert(digit);
                        }
                    }
                }
            }
        }
     
        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};