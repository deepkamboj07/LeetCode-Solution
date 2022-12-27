class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int, int>&b)
    {
        if(a.first - a.second < b.first - b.second)return true;
        else return false;
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int addi) {
        vector<pair<int,int>> vc;
        int n=capacity.size();
        for(int i=0;i<n;i++)
        {
            vc.push_back({capacity[i], rocks[i]});
        }
        
        sort(vc.begin(), vc.end(), comp);
        
        int count=0;
        for(auto it: vc)
        {
            int diff=it.first-it.second;
            if(addi < diff)break;
            else
            {
                addi-=diff;
                count++;
            }
            //cout<<it.first<<" "<<it.second<<endl;
        }
        
        return count;
    }
};