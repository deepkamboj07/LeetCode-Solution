class Solution {
public:
    // karlena dubara jab isko dekho
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int total_cost=0,total_fuel=0,n=cost.size();
        for(int i=0;i<n;i++)
        {
            total_cost+=cost[i];
            total_fuel+=gas[i];
        }
      
        if(total_fuel<total_cost)
        {
            return -1;
        }
        
        int co=0,start=0;
        for(int i=0;i<n;i++)
        {
            if(co<0)
            {
                co=0;
                start=i;
            }
            co+=gas[i]-cost[i];
        }
        return start;
    }
};