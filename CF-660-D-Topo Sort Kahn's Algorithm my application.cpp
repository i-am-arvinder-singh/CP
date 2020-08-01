#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

//#define endl            "\n"
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

class answer{
private:
    int n;
    vt(pii) g;
    vt(vi) dir;
    vi in;
    vi res;
    vi a;
    vi b;
    vi neg;
    int ans = 0;
public:
    answer(int n)
        :n(n)
    {
        dir.resize(n+1);
        in.resize(n+1);
        a.resize(n+1);
        b.resize(n+1);
    }
    void input()
    {
        fl(i,1,n+1) cin>>a[i];
        fl(i,1,n+1){
            cin>>b[i];
            if(b[i]!=-1) dir[i].pb(b[i]),in[b[i]]++;
        }
        kahn();
        bfl(i,neg.size(),0){
            int cur = neg[i];
            res.pb(cur);
            ans+=a[cur];
        }
        cout<<ans<<endl;
        for(auto x:res) cout<<x<<" ";
    }
    void kahn()
    {
        queue<int> q;
        fl(i,1,n+1) if(in[i]==0) q.push(i);
        while(!q.empty()){
            int cur = q.front();//id
            bool f = false;
            if(a[cur]>=0){
                f = true;
                ans+=a[cur];
                res.pb(cur);
            }
            else{
                neg.pb(cur);
            }
            q.pop();
            for(auto child:dir[cur]){
                if(f) a[b[cur]]+=a[cur];
                in[child]--;
                if(in[child]==0) q.push(child);
            }
        }
    }
};

void solve()
{
    int n;
    cin>>n;
    answer a(n);
    a.input();
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
