#define pb push_back
#define ff first
#define ss second
#define tup tuple<int,int,int>

struct comp{
    bool operator() (const tup &f1,const tup &f2){
        return get<0>(f1)<get<0>(f2);
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<pair<int,int>>> g(m+1);
        for(auto v:flights){
            g[v[0]].pb({v[1],v[2]});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<tup, vector<tup>, comp> pq;
        dist[src]=0;
        pq.push({0,src,0});//dist,dist_from_src_to_node,edges_which_is_k+1
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int cur = get<1>(t);
            if(get<2>(t)>=k+1) continue;
            for(auto next:g[cur]){
                if(dist[next.ff]>dist[cur]+next.ss){
                    dist[next.ff]=dist[cur]+next.ss;
                    pq.push({dist[next.ff],next.ff,get<2>(t)+1});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        else return dist[dst];
    }
};




