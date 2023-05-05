class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int j=0,i=0;
        int b=0,w=0;
        int n=blocks.size();
        int mini=1e9;
        
        while(j<n)
        {
            if(blocks[j]=='W')
                w++;
            
            if(j-i+1==k)
            {
                mini=min(mini,w);
                if(blocks[i]=='W')
                {
                    w--;
                }
                i++;
            }
            j++;
        }
        
        return mini;
    }
};