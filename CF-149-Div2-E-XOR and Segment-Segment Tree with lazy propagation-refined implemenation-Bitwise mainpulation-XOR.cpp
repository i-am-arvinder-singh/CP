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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)         2*x+2

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class segTree{
private:
    int n;  
    vector<int> seg; 
    vector<int> lazy; 
    vector<int> v;
    int getMid(int x, int y){
        return x+(y-x)/2;
    }
public: 
    segTree(int n, vector<int> &v) : n(n), seg(4*n+1), lazy(4*n+1), v(v) {}

    void propagate(int segId, int segStart, int segEnd)
    {
        //Not matter what always propagate fist otherwise the logic will break somewhere
        //and it will become hard to debug
        if(lazy[segId]){
            seg[segId] = segEnd - segStart + 1 - seg[segId];
            lazy[segId] = 0;
            if(segStart!=segEnd){
                lazy[LEFT(segId)] ^= 1;
                lazy[RIGHT(segId)] ^= 1;
            }
        }
    }

    int init(int segStart, int segEnd, int segId)
    {
        if(segStart==segEnd){
            seg[segId] = v[segStart];
            return seg[segId]; 
        }
        int mid = getMid(segStart,segEnd);
        seg[segId] = init(segStart,mid,LEFT(segId)) + init(mid+1,segEnd,RIGHT(segId));
        return seg[segId];
    }

    void Update(int segStart, int segEnd, int segId, int qStart, int qEnd)
    {
        propagate(segId,segStart,segEnd);
        if(qEnd < segStart || segEnd < qStart) return;
        if(qStart <= segStart && segEnd <= qEnd){
            if(segStart==segEnd){
                seg[segId] ^= 1;
                return;
            }
            seg[segId] = segEnd - segStart + 1 - seg[segId];
            lazy[LEFT(segId)] ^= 1;
            lazy[RIGHT(segId)] ^= 1;
            return;
        }
        int mid = getMid(segStart,segEnd);
        Update(segStart,mid,LEFT(segId),qStart,qEnd);
        Update(mid+1,segEnd,RIGHT(segId),qStart,qEnd);
        seg[segId] = seg[LEFT(segId)] + seg[RIGHT(segId)];
    }

    int query(int segStart, int segEnd, int segId, int qStart, int qEnd)
    {
        propagate(segId,segStart,segEnd);
        if(qEnd < segStart || segEnd < qStart) return 0;
        if(qStart <= segStart && segEnd <= qEnd){
            if(segStart==segEnd) return seg[segId];
            return seg[segId];
        }
        int mid = getMid(segStart,segEnd);
        return query(segStart,mid,LEFT(segId),qStart,qEnd) + query(mid+1,segEnd,RIGHT(segId),qStart,qEnd);
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    segTree *seg[20];
    for(int i=0;i<20;i++){
        int val = (1ll<<i);
        vector<int> temp;
        for(int i=0;i<n;i++){
            int x = v[i]&val;
            if(x) temp.pb(1);
            else temp.pb(0);
        }
        seg[i] = new segTree(n,temp);
        seg[i]->init(0,n-1,0);
    }
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int x,y;
            cin>>x>>y;
            int ans = 0;
            for(int i=0;i<20;i++){
                int sum = seg[i]->query(0,n-1,0,x-1,y-1);
                ans+=(sum*(1ll<<i));
            }
            cout<<ans<<endl;
        }
        else{
            int x,y,val;
            cin>>x>>y>>val;
            for(int i=0;i<20;i++){
                int check = (1ll<<i);
                int bit   = val&check;
                if(bit){
                    seg[i]->Update(0 , n-1, 0, x-1, y-1);
                }
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

