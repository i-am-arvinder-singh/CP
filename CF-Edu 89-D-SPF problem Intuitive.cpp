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

ini mx = 1e7+10;

int spf[mx];

void precompute()
{
    spf[1] = 1;
    for (int i=2; i<mx; i++)
        spf[i] = i;
    for (int i=4; i<mx; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<mx; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<mx; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    int a[n];
    fl(i,0,n) cin>>a[i];
    pii p[n];
    fl(i,0,n){
        int val = a[i];
        int sp = spf[a[i]];
        vi v;
        int d1=1,d2;
        while(val%sp==0){
            val/=sp;
            d1*=sp;
        }
        if(val>1){
            d2=a[i]/d1;
            p[i].ff = d1;
            p[i].ss = d2;
        }
        else{
            p[i].ff = -1;
            p[i].ss = -1;
        }
    }
    fl(i,0,n) cout<<p[i].ff<<" ";
    cout<<endl;
    fl(i,0,n) cout<<p[i].ss<<" ";
}

int32_t main()
{
	omniphantom
	precompute();
	solve();
	return 0;
}
