#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
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

const int MAX = 1e6;

class coor{
    public:
        int a,b,c;
};

bool comp(coor c1, coor c2){
    if(c1.a!=c2.a) return c1.a<c2.a;//sort by x coordinate
    if(c1.b!=c2.b) return c1.b<c2.b;
    return c1.c<c2.c;
}

class segTree{
private:
    int IN = 0;
    int n;
    vector<int> seg;
    int comb(int a, int b) {return a+b;}
public:
    segTree(int n){
        this->n = n;
        seg.resize(2*n,IN);
    }
    void pull(int p){
        seg[p]=comb(seg[2*p],seg[2*p+1]);
    }
    void update(int id, int val){
        seg[id+=n]+=val;
        for(id/=2;id;id/=2) pull(id);
    }
    int query(int l, int r){
        int lnode = IN, rnode = IN;
        for(l+=n,r+=n+1;l<r;l/=2,r/=2){
            if(l&1) lnode=comb(lnode,seg[l++]);
            if(r&1) rnode=comb(rnode,seg[--r]);
        }
        return comb(lnode,rnode);
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<coor> coors;
    segTree seg(MAX+5);
    int ans = 1;
    for(int i=0;i<n;i++){
        int y,l,r;
        cin>>y>>l>>r;
        coors.push_back({l,-1,y});
        coors.push_back({r,MAX+1,y});
        if(l==0 && r==MAX) ans++;
    }
    for(int i=0;i<m;i++){
        int x,l,r;
        cin>>x>>l>>r;
        coors.push_back({x,l,r});
        if(l==0 && r==MAX) ans++;
    }
    sort(coors.begin(),coors.end(),comp);
    for(auto c:coors){
        if(c.b==-1) seg.update(c.c,1);
        else if(c.b==MAX+1) seg.update(c.c,-1);
        else ans+=seg.query(c.b,c.c);
    }
    cout<<ans<<endl;
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
