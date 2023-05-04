class Solution {
public:
    string predictPartyVictory(string &st) {
        
        queue<int> qr,qd;
        int n=st.size();
        for(int i=0;i<n;i++)
        {
            if(st[i]=='R')
            {
                qr.push(i);
            }
            else
            {
                qd.push(i);
            }
        }
        
        while(!qr.empty() && !qd.empty()){
            
            int r_id = qr.front(), d_id = qd.front();
            qr.pop(), qd.pop();
            (r_id < d_id)?qr.push(r_id + n):qd.push(d_id + n);
        }
        
        if(qd.size() > qr.size())return "Dire";
        else return "Radiant";
    }
};