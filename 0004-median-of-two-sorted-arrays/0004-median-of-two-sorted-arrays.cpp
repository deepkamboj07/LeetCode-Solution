class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr, vector<int>& vec) {
      
        if(arr.size()>vec.size())
           return findMedianSortedArrays(vec,arr);
        
        int n=arr.size();
        int m=vec.size();
        int low=0,high=n;
        
        while(low<=high)
        {
           int mid=(low+high)>>1;
           int cut1=mid;
           int cut2=(n+m+1)/2-cut1;
           
         // cout<<cut1<<" "<<cut2<<endl;
           int l1=(cut1==0)?INT_MIN:arr[cut1-1];
           int l2=(cut2==0)?INT_MIN:vec[cut2-1];
           int r1=(cut1==n)?INT_MAX:arr[cut1];
           int r2=(cut2==m)?INT_MAX:vec[cut2];
           
           if(l2<=r1 and l1<=r2){
             //   cout<<max(l2,l1)<<" "<<min(r2,r1)<<" ";
                if((n+m)%2==0)
                    return (max(l2,l1)+min(r2,r1))/(double)2;
                else 
                return max(l2,l1);
           }
           if(l2>r1)
                low=cut1+1;
           else
                high=cut1-1;
        }
        return 0.0;

    }
};