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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct comp{
    bool operator() (const pair<int, pii> &f2, const pair<int, pii> &f1){
        if(f1.ff>f2.ff) return true;
        else if(f1.ff == f2.ff){
            return f1.ss.ff>f2.ss.ff;
        }
        else return false;
    }
};

void solve()
{
    int n;
    cin>>n;
    if(n==1) cout<<1<<endl;
    else{
        int l,r;
        l=1,r=n;
        priority_queue<pair<int, pii>, vector<pair<int, pii> >, comp > pq;
        pq.push({r-l+1,mp(-l,-r)});
        vi v(n+1,0);
        int i=1;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int len = p.ff;
            l=-p.ss.ff,r=-p.ss.ss;
            int idx;
            if(len&1){
                idx = (l+r)/2;
                v[idx]=i++;
                idx--;
                if(idx>=1 && idx>=l && (idx-l+1)>=1)
                    pq.push({idx-l+1,mp(-l,-idx)});
                idx+=2;
                if(idx<=n && r>=idx && (r-idx+1)>=1)
                    pq.push({r-idx+1,mp(-idx,-r)});
            }
            else{
                idx = (l+r-1)/2;
                v[idx]=i++;
                idx--;
                if(idx>=1 && idx>=l && (idx-l+1)>=1)
                    pq.push({idx-l+1,mp(-l,-idx)});
                idx+=2;
                if(idx<=n && r>=idx && (r-idx+1)>=1)
                    pq.push({r-idx+1,mp(-idx,-r)});
            }
        }
        fl(i,1,n+1) cout<<v[i]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
	omniphantom
	w(t) solve();
	return 0;
}
