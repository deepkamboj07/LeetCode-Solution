class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        
        queue<pair<int,int>> pq;
        vector<bool> vis(n*n+1,false);
        pq.push({1,0});
        vis[1]=true;
        int mini=0;
        int step=0;
        
        while(!pq.empty())
        {
            int cur_dist=pq.front().second;
            int loc=pq.front().first;
            pq.pop();
            
            if(loc >=(n*n) )return cur_dist;
            
            for(int i=1; i<=6 && loc+i <= n*n ;i++)
            {
                int newLocation=loc+i;
                int newRow= (n-1)-(newLocation-1)/n;
                int newCol= (newLocation-1)%n;
                
                if((n%2==1 && newRow%2==1)||(n%2==0 && newRow%2==0))
                    newCol = n-1-newCol;

                    int next=loc + i;
                    if(board[newRow][newCol]!=-1)
                    {
                        next=board[newRow][newCol];
                    }

                    if(!vis[next])
                    {
                        vis[next]=true;
                        pq.push({next, cur_dist+1});
                    }
            }
        }
        
        return -1;
    }
};