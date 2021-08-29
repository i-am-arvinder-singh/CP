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

class segmentTree{
private:
    int n;
    vi inp,seg;
public:
    segmentTree(int n, vi v)
        : n(n),inp(v)
    {
        seg.resize(4*n+5);
    }
    void build(int id, int ss, int se)
    {
        if(ss==se){
            seg[id]=inp[ss];
            return;
        }
        int mid = (ss+se)>>1ll;
        build(2*id,ss,mid);
        build(2*id+1,mid+1,se);
        seg[id]=min(seg[2*id],seg[2*id+1]);
    }
    int query(int id, int ss, int se, int qs, int qe)
    {
        if(qe<ss || se<qs) return inf;
        if(qs<=ss && se<=qe) return seg[id];
        int mid = (ss+se)>>1ll;
        return min(query(2*id,ss,mid,qs,qe),query(2*id+1,mid+1,se,qs,qe));
    }
};

void solve()
{
    int n;
    cin>>n;
    vi v(n+1);
    fl(i,1,n+1) cin>>v[i];
    int q;
    cin>>q;
    segmentTree s(n,v);
    s.build(1,1,n);
//    s.display();
    while(q--){
        int a,b;
        cin>>a>>b;
        a++,b++;
        cout<<s.query(1,1,n,a,b)<<endl;
    }
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
