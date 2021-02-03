#define ff first
#define ss second
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        int n = ages.size();
        for(int i=0;i<n;i++){
            v.push_back({scores[i],ages[i]});
        }
        sort(v.begin(),v.end(),[&](auto p1, auto p2){
            if(p1.ss<p2.ss) return true;
            else if(p1.ss==p2.ss){
                return p1.ff<p2.ff;
            }
            return false;
        });
        vector<int> msis(n);
        for(int i=0;i<n;i++) msis[i] = v[i].ff;
        int ans = 0;
        for(int i=0;i<n;i++) cout<<v[i].ss<<" ";
        for(int i=0;i<n;i++){
            int t = msis[i];
            for(int j=0;j<i;j++){
                if(v[i].ff>=v[j].ff && t+msis[j]>=msis[i]){
                    msis[i] = t+msis[j];
                }
            }
            ans=max(ans,msis[i]);
        }
        return ans;
    }
};