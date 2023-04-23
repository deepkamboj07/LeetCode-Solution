class ProductOfNumbers {
public:
    vector<int> pref;
    int p=1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0)
        {
            pref.clear();
            p=1;
        }
        else
        {
            p*=num;
            pref.push_back(p);
        }
    }
    
    int getProduct(int k) {
        if(k==pref.size())return p;
        
        int ind=pref.size()-k;
        if(ind>0) return p/pref[ind-1];
        
        return 0;   
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */