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

int inv_f(int x)
{
    if(x<=8) return x;
    x-=8;
    int rem = x%9;
    x-=rem;
    int d = x/9;
    int ans=0,p=1;
    fl(i,0,d){
        p*=10;
        ans+=(p*9);
    }
    p*=10;
    ans+=(p*rem);
    ans+=8;
    return ans;
}

void solve()
{
    //Just construct a number of type (prefix) (99...9) (d+i)
    //Refer the following link for exact details
    //https://www.youtube.com/watch?v=MD552gJLNYk
    int n,k;
    cin>>n>>k;
    int p=1,ans=inf;
    fl(nines,0,17){
        p*=10;
        fl(d,0,10){
            int type1 = min(10-d,k+1);
            int num = n-(9*nines*type1)-(k+1)+type1;
            fl(i,0,k+1) num-=((d+i)%10);
            if(num>=0 && num%(k+1)==0){
                int f_prefix=num/(k+1);
                int w=(p*(inv_f(f_prefix))+p-10+d);
                ans=min(ans,w);
            }
        }
    }
    if(ans==inf) cout<<-1<<endl;
    else        cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
    w(t) solve();
	return 0;
}
