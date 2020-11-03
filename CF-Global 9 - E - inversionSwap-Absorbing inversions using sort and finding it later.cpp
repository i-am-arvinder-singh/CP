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
#define ppii            pair<int,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n;
    cin>>n;
    vi a(n),b(n);
    for(auto &x : a) cin>>x;
    iota(b.begin(),b.end(),0);
    sort(b.begin(),b.end(),[&](int i, int j){//Lambda function i represents the next element i>j in case of increasing order array in consideration
        //We sort the array a in increasing order and track b (mark the word increasing, hence we use strictly '<' less than sign
        return a[i]<a[j];
        });
    vt(pii) v;
    fl(i,0,n) fl(j,1,n) if(b[j-1]>b[j]){
        v.pb({b[j]+1,b[j-1]+1});
        swap(b[j-1],b[j]);
    }
    cout<<v.size()<<endl;
    for(auto x:v) cout<<x.ff<<" "<<x.ss<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
