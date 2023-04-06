class Solution {
public:
    bool canTransform(string start, string end) {
        int i=0,j=0;
        int n=start.length();
        
        while(i<n || j<n)
        {
            while(i<n and start[i]=='X')
            {
                i++;
            }
            while(j<n and end[j]=='X')
            {
                j++;
            }
            
            
            if(start[i]!=end[j])return false;
            
            if(start[i]=='R' and i>j)return false;
            if(start[i]=='L' and i<j)return false;
            i++;
            j++;
        }
        
        return true;
    }
};