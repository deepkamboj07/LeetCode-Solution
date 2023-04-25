class SmallestInfiniteSet {
public:
    int small;
    set<int> st;
    SmallestInfiniteSet() {
        small=1;
    }
    
    int popSmallest() {
        if(st.size())
        {
            int top=*st.begin();
            st.erase(top);
            return top;
        }
        else
        {
            small++;
            return small-1;
        }
    }
    
    void addBack(int num) {
        if(small > num)
        {
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */