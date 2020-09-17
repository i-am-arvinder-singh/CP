#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
#define ll              long long
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=(int)a; i<(int)b; i++)
#define bfl(i,a,b)      for(int i=(int)a-1; i>=(int)b; i--)
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

const int MAX = 1e5+5;
vector<int> g[MAX];
vector<int> s(MAX);
vector<int> c;
int n;

void dfs(int node, int p = -1)
{
    s[node] = 1;
    bool flag = true;//Assuming the current node is a centroid
    for(auto child : g[node]){
        if(child == p) continue;
        dfs(child,node);//Perform check for every child
        s[node]+=s[child];
        if(s[child]>n/2) flag = false;
    }
    if(n-s[node] > n/2 || !flag) return;
    c.push_back(node);
}

void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    s.clear();
    c.clear();
    dfs(1,-1);
    if((int)c.size() == 1){
        cout<<1<<" "<<g[1].back()<<endl;
        cout<<1<<" "<<g[1].back()<<endl;
        return;
    }
    int node;
    for(auto child:g[c[0]]){
        if(child!=c[1]){
            node = child;
        }
    }
    // cout<<"O/P:"<<endl;
    cout<<c[0]<<" "<<node<<endl;
    cout<<node<<" "<<c[1]<<endl;
}

int32_t main()
{
	omniphantom
	#if 1
	w(t)
	#endif // 0
    solve();
	return 0;
}

