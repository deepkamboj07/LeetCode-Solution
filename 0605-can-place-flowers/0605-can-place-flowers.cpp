class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        
        if(n==0) return true;
        if(arr[0]==0)
            arr.insert(arr.begin(),0);
        
        if(arr[arr.size()-1]==0)
            arr.push_back(0);
        
        int adj=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                adj++;
                if(adj==3)
                {
                    n--;
                    adj-=2;
                }
            }
            else adj=0;
        }
        
        if(adj==3)
        {
                n--;
        }
        
        //cout<<n<<" ";
        
        return n<=0;
    }
};