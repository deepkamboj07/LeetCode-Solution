class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        HashMap<Integer,List<Integer>>map=new HashMap();
        int n=nums2.length;
        for(int i=0;i<n;i++){
            List<Integer>list=map.getOrDefault(nums2[i],new ArrayList());
            list.add(i);
            map.put(nums2[i],list);
        }
        
        n=nums1.length;
        int max=0;
        for(int i=0;i<n;i++){
            if(!map.containsKey(nums1[i])){
                continue;
            }
            List<Integer>list=map.get(nums1[i]);
            for(int j=0;j<list.size();j++){
                int len=getLength(nums1,i,nums2,list.get(j));
                max=Math.max(max,len);
            }
        }
        return max;
    }
    
    public int getLength(int[]A,int i, int[]B,int j){
        int len=0;
        while(i<A.length && j<B.length && A[i]==B[j]){
            len++;
            i++;
            j++;
        }
        return len;
    }
}