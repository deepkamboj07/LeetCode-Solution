class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> arr(st.begin(), st.end());
        vector<vector<int>> vec;
        for(int i=0;i<arr.size();i++)
        {
            vector<int> ds;
            ds.push_back(arr[i]);
            while(i<arr.size()-1 and arr[i]+1==arr[i+1])
            {
                i++;
            }
            ds.push_back(arr[i]);
            vec.push_back(ds);
        }
        
        //int prev=-1;
        return vec;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */