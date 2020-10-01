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

int n;
string s;

struct coor{
    int a,b,c;
};

class segTree{
private:
    vector<coor> seg;
    int getMid(int x, int y)
    {
        return x+(y-x)/2;
    }
public:
    void init(int n)
    {
        int height = (int) ceil((float)log2(n));
        int MAX_SIZE = 2*((int)pow(2,height))-1;
        seg.resize(MAX_SIZE);
        constructSegTree(0,n-1,0);
    }
    void constructSegTree(int segStart, int segEnd, int segId)
    {
        if(segStart==segEnd){
            seg[segId].a = 0;
            seg[segId].b = (s[segStart]=='('?0:1);//How many opening brackets the sequence does not contain
            seg[segId].c = (s[segStart]=='('?1:0);
            return;
        }
        int mid = getMid(segStart,segEnd);
        constructSegTree(segStart,mid,LEFT(segId));
        constructSegTree(mid+1,segEnd,RIGHT(segId));
        int t = min(seg[LEFT(segId)].c ,seg[RIGHT(segId)].b);
        seg[segId].a = seg[LEFT(segId)].a + seg[RIGHT(segId)].a + t;
        seg[segId].b = seg[LEFT(segId)].b + seg[RIGHT(segId)].b - t;
        seg[segId].c = seg[LEFT(segId)].c + seg[RIGHT(segId)].c - t;
    }
    coor query(int segStart, int segEnd, int queryStart, int queryEnd, int segId)
    {
        coor c;
        c.a=0,c.b=0,c.c=0;
        if(segEnd<queryStart || queryEnd<segStart) return c;
        if(queryStart <= segStart && segEnd <= queryEnd){
            return seg[segId];
        }
        int mid = getMid(segStart,segEnd);
        auto c1 = query(segStart, mid, queryStart, queryEnd, LEFT(segId));
        auto c2 = query(mid+1, segEnd, queryStart, queryEnd, RIGHT(segId));
        int t = min(c1.c ,c2.b);
        c.a = c1.a + c2.a + t;
        c.b = c1.b + c2.b - t;
        c.c = c1.c + c2.c - t;
        return c;
    }
    // void display()
    // {
    //     cout<<"****** "<<endl;
    //     for(int i=0;i<MAX_SIZE;i++){
    //         cout<<seg[i].a<<" "<<seg<<" ";
    //     }
    //     cout<<endl<<"***** "<<endl;
    // }
};


void solve()
{
    cin>>s;
    n = s.length();
    segTree seg;
    seg.init(n);
    seg.constructSegTree(0,n-1,0);
    // seg.display();
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        auto c = seg.query(0,n-1,x,y,0);
        cout<<2*c.a<<endl;
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

