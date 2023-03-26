class Solution {
public:
    double distance(int x1,int y1, int x2, int y2)
    {
        return sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    }
    
    void dfs(int node, unordered_map<int,vector<int>> &gp, vector<int>&vis, int &c)
    {
        vis[node]=true;
        c++;
        for(auto v: gp[node])
        {
            if(!vis[v])
            {
                dfs(v,gp,vis,c);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>> gp;
        int n=bombs.size();
        for(int i=0;i<n;i++)
        {
            int x1=bombs[i][0];
            int y1=bombs[i][1];
            int r1=bombs[i][2];
            for(int j=i+1;j<n;j++)
            {
                //if(i==j)continue;
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                int r2=bombs[j][2];
                double dis=distance(x1,y1,x2,y2);
                if(dis<=r1)
                {
                    gp[i].push_back(j);
                }
                if(dis<=r2)
                {
                    gp[j].push_back(i);
                }
            }
        }
        
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,false);
            int count=0;
            dfs(i,gp,vis,count);
            maxi=max(maxi,count);
        }
        return maxi;
    }
};