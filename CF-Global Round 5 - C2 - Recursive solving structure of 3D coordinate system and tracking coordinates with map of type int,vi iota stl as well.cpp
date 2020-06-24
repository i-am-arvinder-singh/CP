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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define ppii            pair<pii,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini N = 5e4+5;
vector<vector<int>> p(N,vector<int> (3));

int f(vi ids, int k)//k->dimensions
{
    if(k==3) return ids[0];
    map<int,vi> my;
    for(auto x:ids){
        my[p[x][k]].pb(x);//Index is pushed back for this particular valued dimension
    }
    vi a;
    for(auto q:my){
        auto cur = f(q.ss,k+1);
        if(cur!=-1) a.pb(cur);
    }
    for(int i=0;(i+1)<a.size();i+=2){
        cout<<a[i]+1<<" "<<a[i+1]+1<<endl;
    }
    return (a.size()%2==1 ? a.back():-1);
}

void solve()
{
    int n;
    cin>>n;
    fl(i,0,n) fl(j,0,3) cin>>p[i][j];
    vector<int> t(n);
    iota(t.begin(),t.end(),0);
    f(t,0);//Initially start with 0th dimension
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
