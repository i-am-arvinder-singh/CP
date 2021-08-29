#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
// #define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

ini mx=1e6+5;
int n,q;
int inp[mx],last_visit[mx];

struct Query{
    int l,r,idx;
};

bool cmp(Query x, Query y)
{
    return x.r < y.r;
}

struct BIT{
    int n;
    vi bit_tree;
    BIT(int n):
        n(n),bit_tree(n+3){}
    void update(int x, int value){//Only gets added
        for(;x<=n;x += (x&-x) )
            bit_tree[x]+=value;
    }
    int query(int x){
        int sum=0;
        for(;x>0;x-=(x&-x) )
            sum+=bit_tree[x];
        return sum;
    }
};

struct BIT_mx{
    int n;
    vi tree;
    BIT_mx(int n):
        n(n),tree(4*n){}
    void build(int node,int st,int en)
    {
       if(st==en)
       {
          tree[node]=inp[st];
          return;
       }
       int mid=(st+en)>>1;
       build(2*node,st,mid);
       build(2*node+1,mid+1,en);
       tree[node]=max(tree[2*node],tree[2*node+1]);
    }
    int query(int node,int st,int en,int l,int r)
        {
           if(st>en||st>r||en<l)return INT_MIN;
           if(st>=l&&en<=r)return tree[node];
           int mid=(st+en)/2;
           int p=query(2*node,st,mid,l,r);
           int z=query(2*node+1,mid+1,en,l,r);
           int ans=max(p,z);
           return ans;
        }
};

int32_t main()
{
	fio;
	cin>>n;
	BIT bit(n);
	BIT_mx a(n);
	fl(i,0,n) cin>>inp[i];
    a.build(1,0,n-1);
	cin>>q;
	Query queries[q];
	fl(i,0,q){
	    cin>>queries[i].l>>queries[i].r;
	    queries[i].idx=i;
	}
	sort(queries, queries+q, cmp);
	memset(last_visit,-1,sizeof(last_visit));
    int ans[q];
    int qc=0;
    fl(i,0,n){
        if(last_visit[inp[i]]!=-1)
            bit.update(last_visit[inp[i]]+1,-1);
        last_visit[inp[i]]=i;
        bit.update(i+1,1);
        while(qc<q && queries[qc].r==i){
            ans[queries[qc].idx]=bit.query(queries[qc].r+1)-bit.query(queries[qc].l);
            ans[queries[qc].idx]=a.query(1,0,n-1,queries[qc].l,queries[qc].r)-ans[queries[qc].idx];
            qc++;
        }
    }
    fl(i,0,q){
        cout<<ans[i]<<endl;
    }
	return 0;
}
