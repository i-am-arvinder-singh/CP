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
    void set_(int x, int y)
    {
        inp[x]=y;
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
        seg[id]=seg[2*id]+seg[2*id+1];
    }
    int query(int id, int ss, int se, int qs, int qe)
    {
        if(qe<ss || se<qs) return 0;
        if(qs<=ss && se<=qe) return seg[id];
        int mid = (ss+se)>>1ll;
        return query(2*id,ss,mid,qs,qe)+query(2*id+1,mid+1,se,qs,qe);
    }
    void update(int id , int ss, int se, int qi)
    {
        if(ss==se){
            seg[id]=inp[qi];
            return;
        }
        int mid = (ss+se)>>1ll;
        if(qi<=mid) update(2*id,ss,mid,qi);
        else        update(2*id+1,mid+1,se,qi);
        seg[id]=seg[2*id]+seg[2*id+1];
    }
    void display()
    {
        cout<<"*****"<<endl;
        fl(i,1,4*n+1) cout<<seg[i]<<" ";
        cout<<"*****"<<endl;
    }
};

void solve()
{
    int n;
    cin>>n;
    vi v(n+1),e(n+1,0),o(n+1,0);
    fl(i,1,n+1) cin>>v[i],(v[i]&1?o[i]++:e[i]++);
    int q;
    cin>>q;
    segmentTree even(n,e),odd(n,o);
    even.build(1,1,n);
    odd.build(1,1,n);
//    even.display();
//    odd.display();
    while(q--){
        int type,x,y;
        cin>>type>>x>>y;
//        cout<<s.query(1,1,n,a,b)<<endl;
        if(type==0){
            v[x]=y;
            if(y&1) o[x]=1,e[x]=0,odd.set_(x,1),even.set_(x,0);
            else o[x]=0,e[x]=1,odd.set_(x,0),even.set_(x,1);
            even.update(1,1,n,x);
            odd.update(1,1,n,x);
//            even.display();
//            odd.display();
        }
        else if(type==1){
            cout<<even.query(1,1,n,x,y)<<endl;
        }
        else{
            cout<<odd.query(1,1,n,x,y)<<endl;
        }
    }
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
