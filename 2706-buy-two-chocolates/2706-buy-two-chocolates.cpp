class Solution {
    int mon=0;
public:
    int buyChoco(vector<int>& prices, int money) {
          sort(prices.begin(),prices.end());
      int minimum_sum=prices[0]+prices[1];
        
      if(minimum_sum>money) return money;
      else return money-minimum_sum;
    }
};