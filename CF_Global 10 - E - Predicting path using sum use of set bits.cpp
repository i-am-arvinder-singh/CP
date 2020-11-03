#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

//#define endl            "\n"
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

bool checkbit(int s, int k)
{
    return ((s>>k)&1);
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        int val = (1ll<<i);
        for(int j=0;j<n;j++){
            if(i&1) cout<<val<<" ";
            else    cout<<0<<" ";
            val<<=1;
        }
        cout<<endl;
    }
    int times;
    cin>>times;
    while(times--){
        int sum;
        cin>>sum;
        int r =1, c=1, k=0;
        int total = 2*n-1;
        while(total--){
            cout<<r<<" "<<c<<endl;
            if(checkbit(sum,k+1)){
                if(r&1) r++,k++;
                else    c++,k++;
            }
            else{
                if(r&1) c++,k++;
                else    r++,k++;
            }
        }

    }
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

