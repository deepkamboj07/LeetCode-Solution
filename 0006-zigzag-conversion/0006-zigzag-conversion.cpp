class Solution {
public:
    string convert(string s, int numRows) {
        int item=(numRows-1);
        if(numRows==1)return s;
        int n=s.length();
        vector<vector<char>> mat(numRows,vector<char>(n,'@'));
        int col=0;
        for(int j=0;j<n;)
        {
            vector<char> vec(numRows,'@');
            if(item==0)item=(numRows-1);
            
            for(int i=0;i<=item;i++)
            {
                char c=s[j];
                if(item==(numRows-1))
                {
                    mat[i][col]=c;
                    j++;
                }
                else if(item==i)
                {
                    mat[i][col]=c;
                    j++;
                }
                if(j>=n)break;
            }
           // mat.push_back(vec);
            col++;
            item--;
        }
        
        string ans="";
        for(auto it: mat)
        {
            for(auto i: it)
            {
                if(i!='@')
                    ans+=i;
            }
        }
       
        return ans;
        
    }
};