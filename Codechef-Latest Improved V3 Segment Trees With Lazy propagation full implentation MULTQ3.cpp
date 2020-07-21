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
    vi seg[3],lzy;
public:
    segmentTree(int n)
        : n(n)
    {
        fl(i,0,3)
        seg[i].resize(4*n+5,0);
        lzy.resize(4*n+5,0);//Lazy stores the no. of cyclic shifts
    }
    void build(int id, int ss, int se)
    {
        if(ss==se){
            seg[0][id]=1;
            seg[1][id]=0;
            seg[2][id]=0;
            return;
        }
        int mid = (ss+se)>>1ll;
        build(2*id,ss,mid);
        build(2*id+1,mid+1,se);
        seg[0][id]=seg[0][2*id]+seg[0][2*id+1];
        seg[1][id]=seg[1][2*id]+seg[1][2*id+1];
        seg[2][id]=seg[2][2*id]+seg[2][2*id+1];
    }
    void shift(int id)
    {
        int val = seg[0][id];
        seg[0][id]=seg[1][id];
        seg[1][id]=seg[2][id];
        seg[2][id]=val;
    }
    int query(int id, int ss, int se, int qs, int qe)
    {
        //In lazy the only thing we need to check is, that is lzy[id]!=0
        if(lzy[id]!=0){
            int upd=lzy[id];
            lzy[id]=0;
            if(ss!=se){//This will mean that the left and the right child exists
                lzy[2*id]+=upd,lzy[2*id+1]+=upd;
            }
            upd%=3;
            fl(i,0,upd) shift(id);
        }
        if(qe<ss || se<qs) return 0;
        if(qs<=ss && se<=qe) return seg[0][id];
        int mid = (ss+se)>>1ll;
        return query(2*id,ss,mid,qs,qe)+query(2*id+1,mid+1,se,qs,qe);
    }
    void update(int id , int ss, int se, int qs, int qe, int val)
    {
        if(lzy[id]!=0){
            int upd=lzy[id];
            lzy[id]=0;
            if(ss!=se){//This will mean that the left and the right child exists
                lzy[2*id]+=upd,lzy[2*id+1]+=upd;
            }
            upd%=3;
            fl(i,0,upd) shift(id);
        }
        if(qe<ss || se<qs) return;
        if(ss>=qs && se<=qe){
            shift(id);
            if(ss!=se){
                lzy[2*id]+=val,lzy[2*id+1]+=val;
            }
            return;
        }
        int mid = (ss+se)>>1ll;
        update(2*id,ss,mid,qs,qe,val);
        update(2*id+1,mid+1,se,qs,qe,val);
        seg[0][id]=seg[0][2*id]+seg[0][2*id+1];
        seg[1][id]=seg[1][2*id]+seg[1][2*id+1];
        seg[2][id]=seg[2][2*id]+seg[2][2*id+1];
    }
};

void solve()
{
    int n,q;
    cin>>n>>q;
    vi v(n+1,0);
    segmentTree s(n);
    s.build(1,1,n);
    while(q--){
        int type,x,y;
        cin>>type>>x>>y;
        x++,y++;
        if(type==0){//Increase the numbers by 1
            s.update(1,1,n,x,y,1);
        }
        else{//Query
            cout<<s.query(1,1,n,x,y)<<endl;
        }
    }
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
