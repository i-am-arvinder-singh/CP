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

ini mx = 2e5 +5;
vi v(mx);
int n,x,a,y,b,k,__lcm;

int lcm(int x, int y)
{
    return (x*y)/(__gcd(x,y));
}

bool ok(int m)
{
    int i = n-1;
    int w = m/__lcm;
    int ans = 0;
    int t = w;
    while(t--){
        ans+=((v[i]/100)*(x+y));
        i--;
    }
    int val_a = m/a;
    val_a-=w;//x
    int val_b = m/b;
    val_b-=w;//y
    if(x>y){
        while(val_a--){
            ans+=((v[i]/100)*x);
            i--;
        }
        while(val_b--){
            ans+=((v[i]/100)*y);
            i--;
        }
    }
    else{
        while(val_b--){
            ans+=((v[i]/100)*y);
            i--;
        }
        while(val_a--){
            ans+=((v[i]/100)*x);
            i--;
        }
    }
    return ans>=k;
}

void solve()
{
    cin>>n;
    fl(i,0,n) cin>>v[i];
    sort(v.begin(),v.begin()+n);
    cin>>x>>a;
    cin>>y>>b;
    cin>>k;
    int l=min(a,b), r = n;
    __lcm = lcm(a,b);
    if(!ok(n)){
        cout<<-1<<endl;
        return;
    }
    //Binary Search 
    while(l<r){
        int m = (l+r)>>1ll;
        if(ok(m)) r=m;
        else l=m+1;
    }
    cout<<l<<endl;
}

int32_t main()
{
	omniphantom
    w(t) solve();
	return 0;
}
