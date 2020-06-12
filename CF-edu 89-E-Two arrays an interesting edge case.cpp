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

ini N = 2e5+7;

int a[N],b[N];

int mul(int a, int b)
{
    return (a*b)%mod;
}

void solve()
{
    //Always try to do increments in the end 
    //Also check for any end or edge cases in the beginning of the loop
    //Assertions are good way to check validity of a code snippet
    //and helps in debugging (nothing more than that) :P
    int n,m;
    cin>>n>>m;
    fl(i,0,n) cin>>a[i];
    fl(i,0,m) cin>>b[i];

    reverse(a,a+n);
    reverse(b,b+m);
    int mn = a[0];
    int pos = 0;
    while(pos<n && mn>b[0]){
        pos++;
        mn=min(mn,a[pos]);
    }
    if(mn<b[0]||pos==n){
        cout<<0<<endl;
        return;
    }
    int res = 1;
    int i=0;
    while(true){
        if(i==m-1){
            if(*min_element(a+pos,a+n)<b[i]){
                cout<<0<<endl;
                return;
            }
            break;
        }
        int pos_ = pos; //Mark our current position
        bool ok = true;
        while(pos_<n && b[i+1]!=mn){
            pos_++;
            mn=min(mn,a[pos_]);
            if(mn<b[i] && ok){
                res=mul(res,pos_-pos);
                ok=false;
            }
        }
        if(pos_==n||b[i+1]!=mn){
            cout<<0<<endl;
            return;
        }
        pos=pos_;
        i++;
    }
    cout<<res<<endl;
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
