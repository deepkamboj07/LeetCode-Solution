class Solution {
public:
    string discountPrices(string s, int d) {
       string ans = "";
       int n = s.size();
       for(int i = 0; i < n; ++i){
           if(s[i] == '$'){
               ++i;
               string amt = "";
               bool f = false;
               while(i < n && s[i] != ' '){
                   if(!isdigit(s[i])){
                       f = true;
                       amt.push_back(s[i]);
                   }else{
                       amt.push_back(s[i]);
                   }
                   ++i;
               }
               if(f == true || amt.size() == 0){
                   ans += " $" + amt;
               }else{
                   long double v = stoll(amt);
                   v = v - (v * d / 100.0);
                   amt = to_string(v);
                   ans += " $" + amt.substr(0, amt.find('.') + 3);
               }
           }else{
               string word = "";
               while(i < n && s[i] != ' '){
                   word.push_back(s[i]);
                   ++i;
               }
               ans += " " + word;
           }
       }
       return ans.substr(1);
   }
    
};