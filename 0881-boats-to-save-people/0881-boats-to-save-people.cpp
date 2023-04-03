class Solution {
public:

    int numRescueBoats(vector<int>& people, int limit) {
        
       sort(people.begin(), people.end());
        int low=0;
        int n=people.size();
        int count=0;
        int high=n-1;
        
        while(low<=high)
        {
            if(people[high]==limit)
            {
                count++;
                high--;
            }
            else if(people[low] + people[high] > limit)
            {
                count++;
                high--;
            }
            else
            {
                count++;
                high--;
                low++;
            }
        }
        
        return count;
    }
};