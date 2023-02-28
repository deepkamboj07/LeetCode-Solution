class Cashier {
public:
    int n;
    int bill=0;
    int discount;
    unordered_map<int,int> mp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n=n;
        this->discount=discount;
        int s=products.size();
        for(int i=0;i<s;i++)
        {
            mp[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        bill++;
        
        bool discountValid=(bill%n==0)?true:false;
        //cout<<bill<<" "<<discountValid<<endl;
        double total=0;
        int s=product.size();
        for(int i=0;i<s;i++)
        {
            total+=(amount[i] * mp[product[i]]);
        }
        
        if(discountValid)
        {
            total=total*((100-discount)/100.0);
        }
        
        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */