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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n,m;
    cin>>n>>m;
    int e[n+1]={};
    set<pii> s;
    fl(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        e[a]-=c;
        e[b]+=c;
    }
    fl(i,1,n+1) s.insert({e[i],i});
    vi u,v,w;
    while(s.size()){
        auto a1 = *s.begin();
        auto a2 = *prev(s.end());
        if(a1.ff==0) break;
        int val = min(abs(a1.ff),abs(a2.ff));
        s.erase(a1);
        s.erase(a2);
        a1.ff+=val;
        a2.ff-=val;
        u.pb(a1.ss);
        v.pb(a2.ss);
        w.pb(val);
        s.insert(a1);
        s.insert(a2);
    }
    cout<<u.size()<<endl;
    for(int i=0;i<u.size();i++){
        cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
    }
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
