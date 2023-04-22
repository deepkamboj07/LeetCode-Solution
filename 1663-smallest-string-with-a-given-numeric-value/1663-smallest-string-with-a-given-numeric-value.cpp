class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=0;i<n;i++)
        {
            ans+='a';
        }
        k-=n;
        
        for(int i=n-1;i>=0;i--)
        {
            if(k==0)break;
            
            if(k<25)
            {
                ans[i]=char('a'+k);
                k=0;
            }
            else
            {
                ans[i]=char('a'+25);
                k-=25;
            }
        }
        
//         while(n>0)
//         {
//             int num=n-1;
//             int high=26,low=1;
//             int max=26;
//             while(low<=high)
//             {
//                 int mid=(low+high)/2;
//                 if(k-mid<num)
//                 {
//                     high=mid-1;
//                 }
//                 else{ 
//                     max=mid;
//                     low=mid+1;
//                 }
//             }

//             k-=max;
//             n--;
//             char ch='a'+(max-1);
//             ans=ch+ans;
//         }
        
        return ans;
    }
};