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

void solve()
{
    string s;
    cin>>s;
    int n = s.length();
    int m;
    cin>>m;
    int a[m],b[m];
    map<char,int> my;
    fl(i,0,n) my[s[i]]++;
    fl(i,0,m){
        cin>>a[i];
        b[i]=a[i];
    }
    bool mark[m]={};
    char ans[m];
    fl(k,0,m){
        vi v;
        fl(i,0,m){
            if(b[i]==0 && !mark[i]){
                mark[i]=true;
                v.pb(i);
            }
        }
        if(v.size()==0) break;
        while(true){
            auto p = *my.rbegin();
            if(p.ss<v.size()){//This sentence or statement or piece of code explains why "It is guaranteed that for each test case the answer exists" in input section was written.
                my.erase(p.ff);
            }
            else break;
        }
        auto p = *my.rbegin();
        fl(i,0,v.size()){
            ans[v[i]]=p.ff;
        }
        my.erase(p.ff);
        fl(i,0,m){
            if(!mark[i]){
                fl(j,0,v.size()) b[i]-=(abs(v[j]-i));
            }
        }
    }
    for(auto x:ans) cout<<x;
    cout<<endl;
}

int32_t main()
{
	omniphantom
    w(t) solve();
	return 0;
}
