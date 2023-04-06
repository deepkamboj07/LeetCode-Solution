class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.length();
        
        vector<int> p1(3,0),p2(3,0);
        
        for(int i=0;i<n;i++)
        {
            if(start[i]=='L')
                p1[0]++;
            else if(start[i]=='R')
                p1[1]++;
            else if(start[i]=='_')p1[2]++;
            
            if(target[i]=='L')
                p2[0]++;
            else if(target[i]=='R')
                p2[1]++;
            else if(target[i]=='_')p2[2]++;
        }
        
        if(p1!=p2)return false;
        
        
        int i=0,j=0;
        while(i<n and j<n)
        {
            while(i<n and start[i]=='_')i++;
            while(j<n and target[j]=='_')j++;
            
            if(i==n || j==n)return i==n and j==n;
            
            if(start[i]!=target[j])return false;
            
            
            if(start[i]=='L')
            {
                if(i<j)return false;
            }
            else
            {
                if(i>j)return false;
            }
            
            i++;
            j++;
        }
        
        return true;
        
        
    }
};