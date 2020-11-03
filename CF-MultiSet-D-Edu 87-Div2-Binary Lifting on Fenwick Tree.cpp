#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
//#define int             long long
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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini mx=1e6+50;
int n,q;

struct ft{
    int b[mx]={};
    void update(int i, int x){ // Index from where we want to update
                                // and the value up which we want to
                                // update
        for(++i;i<mx;i+=i&-i){
            b[i]+=x;
        }
    }
    //Also query will be of 1 to i nature
    int query (int i){
        int sum=0;
        for(;i;i-=i&-i){
            sum+=b[i];
        }
        return sum;
    }
    //Binary Lifting below
    int Find(int k){//log2(mx)<20
        int curr=0, ans=0, prevsum=0;
        for(int i=19;i>=0;i--){
            if((curr+(1<<i))<mx && b[curr+(1<<i)]+prevsum<k){
                ans=curr+(1<<i);
                curr=ans;
                prevsum+=b[curr];
            }
        }
        return (ans+1);
    }
}f;

void solve()
{
    //IMPORTANT POINTS TO KEEP IN MIND:
    //update operation has 0 based indexing for i
    //query operation is 1 based indexing

    cin>>n>>q;
    int x;
    fl(i,0,n){
        cin>>x;
        f.update(x-1,1);
    }
    while(q--){
        int x;
        cin>>x;
        if(x>0) f.update(x-1,1);
        else{
            x*=(-1);
            int low = f.Find(x);
            f.update(low-1,-1);
        }
    }
    int ans = f.query(mx-1);
    if(ans==0) cout<<0<<endl;
    else{
        cout<<f.Find(1)<<endl;
    }
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
