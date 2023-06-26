#define ll long long  
#define umii unordered_map<int,int> 
class Solution {
public:
    
    long long totalCost(vector<int>& costs, int k, int candidates) {
        ll res=0;
        priority_queue<int, vector<int>, greater<int> > pq1;
        priority_queue<int, vector<int>, greater<int> > pq2;
        int i=0;
        while(i<candidates){
            pq1.push(costs[i]);
            i++;
        }
        int count=0;
        int j= costs.size()-1;
        if(candidates > costs.size()- candidates){
            candidates= costs.size()- candidates;
        }
    
        while(count<candidates){
            pq2.push(costs[j]);
            count++;
            j--;
        }
        
        while(k--){
            if(pq1.size()==0){
                res+=pq2.top();
                pq2.pop();
                if(i<=j){
                   pq2.push(costs[j]);
                    j--;
                } 
                
            }
            else if(pq2.size()==0){
                res+=pq1.top();
                pq1.pop();
                if(i<=j){
                    pq1.push(costs[i]);
                    i++;
                } 
            }
            else if(pq1.top()<=pq2.top()){
                res+=pq1.top();
                pq1.pop();
                if(i<=j){
                    pq1.push(costs[i]);
                    i++;
                }
            }
            else{
                res+=pq2.top();
                pq2.pop();
                if(i<=j){
                 pq2.push(costs[j]);
                    j--;
                } 
                
                
            }
        }
        return res;
    }
};