class MovieRentingSystem {
    unordered_map<int,set<pair<int,int>>> plist;//movie -> price,shop
    map<pair<int,int>,int> pricelist;
    set<tuple<int,int,int>> rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i=0;i<entries.size();i++){
            plist[entries[i][1]].insert({entries[i][2],entries[i][0]});
            pricelist[{entries[i][0],entries[i][1]}]=entries[i][2];
        }
    }
    
    vector<int> search(int movie) {
        int cnt = 5;
        auto it = plist[movie].begin();
        vector<int> temp;
        while(it!=plist[movie].end() && cnt--){
            temp.push_back(it->second);
            it=next(it);
        }
        return temp;
    }
    
    void rent(int shop, int movie) {
        rented.insert({pricelist[{shop,movie}],shop,movie});
        plist[movie].erase({pricelist[{shop,movie}],shop});
    }
    
    void drop(int shop, int movie) {
        rented.erase({pricelist[{shop,movie}],shop,movie});
        plist[movie].insert({pricelist[{shop,movie}],shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(auto p:rented){
            int shopid, movieid, price;
            tie(price,shopid,movieid) = p;
            ans.push_back({shopid,movieid});
            if(ans.size()==5) 
                break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */