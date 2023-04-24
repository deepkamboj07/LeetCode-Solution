class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n=stones.size();
        for(int i=0;i<n;i++)
            pq.push(stones[i]);
        
        int n1,n2;
        
        while(pq.size()!=1 && pq.size()!=0)
        {
            n1=pq.top();
            pq.pop();
            n2=pq.top();
            pq.pop();
            
            if(n1!=n2)
                pq.push(n1-n2);
        }
        
        return (pq.size()==0)?0:pq.top();
    }
};