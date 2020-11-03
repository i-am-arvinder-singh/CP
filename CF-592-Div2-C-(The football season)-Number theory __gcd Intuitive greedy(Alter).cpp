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

void solve()
{
    int n,p,w,d;
    cin>>n>>p>>w>>d;
    //w*x + y*d = p -- 1
    //if y>=w =>  y = w*u + k
    //1=> w*x + (w*u + k) *d = p
    //=> w*(x+u*d) + k*d = p
    //k belongs to 0 to w-1 after that it can be merged with w
    
    //Faster
    if(p%__gcd(w,d)!=0){
        cout<<-1<<endl;
        return;
    }
    
    for(int i=0;i<w;i++){
        int x = (p-i*d)/w;
        if((p-i*d)%w==0 && x+i<=n && x>=0){
            cout<<x<<" "<<i<<" "<<n-(x+i)<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
