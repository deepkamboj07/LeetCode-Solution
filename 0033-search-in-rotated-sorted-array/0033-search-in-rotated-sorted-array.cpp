class Solution {
public:
     
    int search(vector<int>& A, int key) {
        int n=A.size();
        int l=0;
        int h=n-1,min=-1;
        
        if(n==0) return -1;
      
      while(l<=h)
      {
          int mid=l+((h-l)/2);
          
           int prev=(mid+n-1)%n;
           int nex=(mid+1)%n;
           
           if(A[l]<=A[h])
           {
               min=l;
               break;
           }
           
           else if(A[mid]<=A[prev] && A[mid]<=A[nex])
           {
               min=mid;
               break;
           }
           else if(A[mid]>=A[l])l=mid+1;
           else if(A[mid]<=A[h])h=mid-1;
      }
      
      
      if(key==A[min]) return min;
      else if(key>A[min] && key<=A[n-1])
      {
          l=min+1;
          h=n-1;
      }
      else {
          h=min-1;
          l=0;
      }
      
      while(l<=h)
      {
           int mid=l+((h-l)/2);
           
           if(key==A[mid]) return mid;
           
           else if(key>A[mid]) l=mid+1;
           
           else h=mid-1;
      }
      
      return -1; 
      
     
     
    }
        
        
   
};