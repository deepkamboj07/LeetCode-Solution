class UndergroundSystem {
    map<pair<string,string>,pair<double,int>> res;
    unordered_map<int,pair<string,int>> checkn;
    int index;
public:
    UndergroundSystem() {
        index=0;
    }
    
    void checkIn(int id, string stationName, int t) {
        checkn[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(checkn.find(id)!=checkn.end())
        {
            string station=checkn[id].first;
            int time=checkn[id].second;
            
            if(res.find({station,stationName})!=res.end())
            {
                int prev=res[{station,stationName}].first;
                int size=res[{station,stationName}].second;
                res[{station,stationName}]={prev+(t-time),size+1};
            }
            else
            {
                res[{station,stationName}]={(t-time),1};
            }
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        int total=res[{startStation,endStation}].first;
        int size=res[{startStation,endStation}].second;
        return (double)total/(double)size;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */