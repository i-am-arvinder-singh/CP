#define pb push_back
#define ff first
#define ss second
class Solution {
    void solve(int src, int dst, int K, int fare,vector<vector<pair<int,int>>> &g,vector<bool> &vis, int &ans)
    {
        if(K<-1) return;
        if(src==dst){
            ans=min(ans,fare);
            return;
        }
        vis[src]=true;
        for(auto next:g[src]){
            if(!vis[next.ff] && next.ss+fare<=ans)//further optimization
                solve(next.ff,dst,K-1,fare+next.ss,g,vis,ans);
        }
        vis[src]=false;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> g(n+1);
        int m = flights.size();
        for(int i=0;i<m;i++){
            g[flights[i][0]].pb({flights[i][1],flights[i][2]});
        }
        vector<bool> vis(n+1,false);
        int ans = INT_MAX;
        solve(src,dst,K,0,g,vis,ans);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};