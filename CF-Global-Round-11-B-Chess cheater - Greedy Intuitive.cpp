#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
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
#define inf             1e18+1000
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)        2*x+2
#define MAX_SIZE        100003

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt_L = 0;
    for(auto ch:s) cnt_L += (ch=='L');
    if(k>=cnt_L){ 
        cout<<1+(n-1)*2<<endl;
        return;
    }
    else if(n-cnt_L==0){
        if(k) cout<<1+(k-1)*2<<endl;
        else  cout<<0<<endl;
        return;
    }
    vector<pair<pii,int>> v;
    int i=0, j=n-1;
    while(i<n && s[i]=='L') i++;
    while(j>=0 && s[j]=='L') j--;
    while(i<=j){
        while(i<=j && s[i]=='W') i++;
        if(i>j) break;
        int left = i;
        int cnt = 0;
        while(i<=j && s[i]=='L'){
            i++;
            cnt++;
        }
        v.pb({{left,i-1},cnt});
    }
    sort(v.begin(),v.end(),[&](auto p1, auto p2){
        return p1.ss<p2.ss;
    });
    for(auto tt:v){
        if(tt.ss<=k){
            int left = tt.ff.ff, right = tt.ff.ss;
            for(int i=left;i<=right;i++) s[i] = 'W';
            k-=tt.ss;
        }
    }
    i= 0;
    int ans = 0;
    while(i<n){
        int cnt = 0;
        while(i<n && s[i]=='W'){
            i++;
            cnt++;
        }
        if(cnt) ans+=(1+(cnt-1)*2);
        while(i<n && s[i]=='L') i++;
    }
    ans+=(k*2);
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
	#if 1
	w(t)
	#endif // 0
    solve();
	return 0;
}

