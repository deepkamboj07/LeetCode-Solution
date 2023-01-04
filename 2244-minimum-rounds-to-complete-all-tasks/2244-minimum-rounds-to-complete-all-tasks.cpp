class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto it: tasks)
            mp[it]++;
        
        int count=0;
        for(auto it: mp)
        {
           // cout<<it.first<<" "<<it.second<<endl;
            int freq=it.second;
            if(freq==2 || freq==3)
                count++;
            else
            {
                int times1= freq/3;
                int times2= freq/2;
                
                int rem1=freq%3;
                int rem2=freq%2;
                int check=0;
                if(rem1==0)
                {
                    check+=times1;
                }
                else if(rem1==2)
                {
                    check+=times1;
                    check++;
                }
                else
                {
                    int c=0;
                    while(freq%3!=0 and freq>=0)
                    {
                        freq-=2;
                        c++;
                    }
                    if(freq<0)return -1;
                   // cout<<"checking : "<<count<<" ";
                    count+=c;
                    count+=(freq/3);
                   // cout<<count<<endl;
                    
                }
                
                count+=check;
            }
        }
        return count;
    }
};