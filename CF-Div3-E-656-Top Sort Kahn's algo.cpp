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

class answer{
private:
    int n,m;
    vt(pii) g;
    vt(vi) dir;
    vi in;
    vi res;
public:
    answer(int n, int m)
        :n(n),m(m)
    {
        dir.resize(n+1);
        in.resize(n+1);
    }
    void input()
    {
        int t,x,y;
        fl(i,0,m){
            cin>>t>>x>>y,g.pb({x,y});
            if(t) dir[x].pb(y),in[y]++;
        }
        if(kahn()){
            cout<<"YES"<<endl;
            map<int,int> my;
            fl(i,0,n) my[res[i]]=i;
            for(auto e:g){
                if(my[e.ff]>my[e.ss]) swap(e.ff,e.ss);
                cout<<e.ff<<" "<<e.ss<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
    bool kahn()
    {
        queue<int> q;
        fl(i,1,n+1) if(in[i]==0) q.push(i);
        while(!q.empty()){
            int cur = q.front();
            res.pb(cur);
            q.pop();
            for(auto child:dir[cur]){
                in[child]--;
                if(in[child]==0) q.push(child);
            }
        }
        return res.size()==n;
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    answer a(n,m);
    a.input();
}

int32_t main()
{
	omniphantom
    w(t) solve();
	return 0;
}
