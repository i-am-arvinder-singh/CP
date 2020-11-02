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
    int getMid(int x, int y){
        return x+(y-x)/2;
    }
public: 
    segTree(int n) : n(n), seg(4*n+1), lazy(4*n+1) {}

    void propagate(int segId, int segStart, int segEnd)
    {
        //Not matter what always propagate fist otherwise the logic will break somewhere
        //and it will become hard to debug
        if(lazy[segId]){
            seg[segId] += (segEnd - segStart + 1)*lazy[segId];
            int val = lazy[segId];
            lazy[segId] = 0;
            if(segStart!=segEnd){
                lazy[LEFT(segId)] += val;
                lazy[RIGHT(segId)] += val;
            }
        }
    }

    int init(int segStart, int segEnd, int segId)
    {
        if(segStart==segEnd){
            seg[segId] = 0;
            return seg[segId]; 
        }
        int mid = getMid(segStart,segEnd);
        seg[segId] = init(segStart,mid,LEFT(segId)) + init(mid+1,segEnd,RIGHT(segId));
        return seg[segId];
    }

    void Update(int segStart, int segEnd, int segId, int qStart, int qEnd, int val)
    {
        propagate(segId,segStart,segEnd);
        if(qEnd < segStart || segEnd < qStart) return;
        if(qStart <= segStart && segEnd <= qEnd){
            if(segStart==segEnd){
                seg[segId] += val;
                return;
            }
            seg[segId] += (segEnd - segStart + 1)*val ;
            lazy[LEFT(segId)] += val;
            lazy[RIGHT(segId)] += val;
            return;
        }
        int mid = getMid(segStart,segEnd);
        Update(segStart,mid,LEFT(segId),qStart,qEnd,val);
        Update(mid+1,segEnd,RIGHT(segId),qStart,qEnd,val);
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
    string st;
    cin>>st;
    map<char,set<int>> my;
    for(int i=0;i<(int)st.length();i++){
        char ch = st[i];
        my[ch].insert(i);
    }
    segTree s(n);
    s.init(0,n-1,0);
    reverse(st.begin(),st.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        char ch = st[i];
        int pos = *my[ch].begin(); my[ch].erase(my[ch].begin());
        int temp = pos;
        pos+=s.query(0,n-1,0,pos,pos);
        s.Update(0,n-1,0,0,temp-1,1);
        ans+=(pos-i);
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

