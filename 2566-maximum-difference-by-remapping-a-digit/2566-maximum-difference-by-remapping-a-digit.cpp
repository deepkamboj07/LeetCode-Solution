class Solution {
public:

    int minMaxDifference(int num) {
        string n=to_string(num);               
        //reverse(n.begin(), n.end());       
        
        int maxi=0;
        int mini=0;
        int c1=-1,c2=-1;
        
        for(auto d: n)
        {
            int digit1=d-'0';
            int digit2=digit1;
            
            if(digit1<9 and c1==-1)
            {
                c1=digit1;
                maxi=(maxi*10)+9;
            }
            else if(c1==digit1)
            {
                maxi=(maxi*10)+9;
            }
            else
            {
                maxi=(maxi*10)+digit1;
            }

            if(digit2<=9 and c2==-1)
            {
                c2=digit2;
                mini=(mini*10)+0;
            }
            else if(c2==digit2)
            {
                mini=(mini*10)+0;
            }
            else
            {
                mini=(mini*10)+digit2;
            }  
        }

        cout<<maxi<<" "<<mini<<endl;
        return (maxi-mini);
        
    }
};