class Solution {
public:
    int distMoney(int money, int child) {
        if(money < child)return -1;
        if(money==child)return 0;
        if(money > child * 8)return child-1;
        
        int ans=0;
        while(money>0 and money-8 >= child-1)
        {
            ans++;
            money-=8;
            child--;
        }
        if(money==4 and child==1)ans--;
        return ans;
    }
};