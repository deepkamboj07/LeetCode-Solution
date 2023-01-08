class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2)return n;
        
        int maxi=2;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int count=0;
                for(int k=j+1;k<n;k++)
                {
                    int x1=points[i][0], y1=points[i][1];
                    int x2=points[j][0], y2=points[j][1];
                    int x3=points[k][0], y3=points[k][1];
                    
                    if((y1-y2)*(x1-x3) == (y1-y3)*(x1-x2))
                    {
                        count++;
                    } 
                }
                maxi=max(maxi,(count+2));
            }
        }
        return maxi;
    }
    
};