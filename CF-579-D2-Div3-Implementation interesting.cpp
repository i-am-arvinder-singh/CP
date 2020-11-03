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

void solve()
{
    string s,t;
    cin>>s>>t;
    vi v;
    int n = s.length();
    int m = t.length();
    int pos = n-1;
    bfl(i,m,0){
        if(!v.empty()) pos=v.back()-1;
        while(s[pos]!=t[i]) pos--;
        v.pb(pos);
    }
    reverse(v.begin(),v.end());
    int ans = 0;
    pos = 0;
    fl(i,0,n){
        int r = n-1;
        if(pos<m) r=v[pos]-1;
        ans=max(ans,r-i+1);
//        cout<<"*** "<<r-i+1<<endl;
        if(t[pos]==s[i] && pos<m) pos++;
    }
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
