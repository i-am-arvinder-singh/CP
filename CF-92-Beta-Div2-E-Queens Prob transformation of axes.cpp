#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

// #define endl            "\n"
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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)         2*x+2

const double pi = acos(-1.0);

void solve()
{
    int n,m;
    cin>>n>>m;
    const int MAX = 1e5+3;
    map<int,set<int>> r,c;
    pair<int,int> p[m+2];
    int ans[m+2] = {};
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        p[i] = {x,y};
        r[x].insert(y);
        c[y].insert(x);
    }
    for(int i=1;i<=m;i++){
        int res = 0;
        auto pp = p[i];
        int x = pp.ff, y= pp.ss;
        if(r[x].upper_bound(y)!=r[x].end()) res++;
        auto it = r[x].lower_bound(y);
        if(*it==y){
            if(it!=r[x].begin()) res++;
        }
        else res++;

        if(c[y].upper_bound(x)!=c[y].end()) res++;
        it = c[y].lower_bound(x);
        if(*it==x){
            if(it!=c[y].begin()) res++;
        }
        else res++;
        ans[i] = res;
    }
    for(auto &p:r){
        p.ss.clear();
    }
    for(auto &p:c){
        p.ss.clear();
    }
    for(int i=1;i<=m;i++){
        auto &pp = p[i];
        int x = pp.ff, y = pp.ss;
        int newx = x+y;
        int newy = -x+y;
        pp = {newx,newy};
        r[newx].insert(newy);
        c[newy].insert(newx);
    }
    for(int i=1;i<=m;i++){
        int res = 0;
        auto pp = p[i];
        int x = pp.ff, y= pp.ss;
        if(r[x].upper_bound(y)!=r[x].end()) res++;
        auto it = r[x].lower_bound(y);
        if(*it==y){
            if(it!=r[x].begin()) res++;
        }
        else res++;

        if(c[y].upper_bound(x)!=c[y].end()) res++;
        it = c[y].lower_bound(x);
        if(*it==x){
            if(it!=c[y].begin()) res++;
        }
        else res++;
        ans[i] += res;
        // cout<<x<<" "<<y<<endl;
    }
    int final_ans[9]={};
    for(int i=1;i<=m;i++){
        final_ans[ans[i]]++;
    }
    for(int i=0;i<=8;i++){
        cout<<final_ans[i]<<" ";
    }
    cout<<endl;
}

int32_t main()
{
	omniphantom
	#if 0
	w(t)
	#endif // 0
    solve();
	return 0;
}

