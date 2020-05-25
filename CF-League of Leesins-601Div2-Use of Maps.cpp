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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n;
    cin>>n;
    map<int,set<int>> m;
    fl(i,0,n-2){
        int x,y,z;
        cin>>x>>y>>z;
        m[x].insert(y);
        m[x].insert(z);
        m[y].insert(x);
        m[y].insert(z);
        m[z].insert(x);
        m[z].insert(y);
    }
    int ans[n];
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++){
        if(m[i].size()==2){
            if(ans[0]==-1){
                ans[0]=i;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(m[i].size()==3){
            if(m[i].find(ans[0])!=m[i].end()){
                ans[1]=i;
                break;
            }
        }
    }
    for(int i=0;i<n-2;i++){
        int cur = ans[i];
        if(i==0){
            m[cur].erase(ans[1]);
            ans[2]= *m[cur].begin();
        }
        else if(i==1){
            m[cur].erase(ans[0]);
            m[cur].erase(ans[2]);
            ans[3]= *m[cur].begin();
        }
        else{
            m[cur].erase(ans[i-2]);
            m[cur].erase(ans[i-1]);
            m[cur].erase(ans[i+1]);
            ans[i+2]= *m[cur].begin();
        }
    }
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
