#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define omniphantom     ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vt(set<int>) leaves;

class comp{
public:
    bool operator() (int a, int b) const{
        if(leaves[a].size()==leaves[b].size()) return a>b;
        return leaves[a].size()>leaves[b].size();
    }
};

void solve()
{
    int n,k;
    cin>>n>>k;
    vt(set<int>) g(n);
    leaves.resize(n);
    fl(i,0,n) leaves[i].clear();
    fl(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    fl(i,0,n) if(g[i].size()==1){
        int p = *g[i].begin();
        leaves[p].insert(i);
    }
    set<int,comp> st;
    fl(i,0,n) st.insert(i);
    int ans = 0;
    while(true){
        int p = *st.begin();//Sabse jada bacho wala parent
        if(leaves[p].size()<k) break;//Agar required bache se kam bache hai toh break!
        fl(i,0,k){//for all bache
            int leaf = *leaves[p].begin();
            //Remove from graph
            g[leaf].erase(p);
            g[p].erase(leaf);
            //Remove from st
            st.erase(p);
            st.erase(leaf);
            //Remove from leaves(collection of parents)
            leaves[p].erase(leaf);
            //Special case
            //  (leaf_1)----(leaf_2)
            if(leaves[leaf].count(p)) leaves[leaf].erase(p);
            if(g[p].size()==1){
                int ch = *g[p].begin();
                st.erase(ch);//Deletes previous info
                //Remove the above ch using info from previous leaves and then
                //update the leaves and then insert it again.
                leaves[ch].insert(p);
                st.insert(ch);
            }
            st.insert(p);
        }
        ans++;
    }
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
    w(t) solve();
	return 0;
}
