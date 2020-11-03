
//Credits : Errichto

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
#define tup             tuple<int,int,int
#define LEFT(x)         2*x+1
#define RIGHT(x)         2*x+2

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void terminate_()
{
    cout<<-1<<endl;
    exit(EXIT_SUCCESS);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> ones,others;
    vector<pii> answer;
    vector<int> h(n);
    int next = n;
    for(int i=n-1;i>=0;i--){
        int cur  = v[i];
        if(cur==0) continue;
        int pair = -1;
        if(cur==2){
            if(ones.empty()) terminate_();
            pair = ones.back();
            ones.pop_back();
        }
        else if(cur==3){
            if(others.empty()){
                if(ones.empty()) terminate_();
                pair = ones.back();
                ones.pop_back();
            }
            else{
                pair = others.back();
                others.pop_back();
            }
        }
        if(cur==1) ones.pb(i);
        else if(cur>=2) others.push_back(i);
        if(cur==1){
            assert(pair==-1);
            h[i] = next--;
            answer.pb({h[i],i+1});
        }
        else if(cur==2){
            h[i] = h[pair];
            answer.pb({h[i],i+1});
        }
        else if(cur==3){
            h[i] = next--;
            answer.pb({h[i],i+1});
            answer.pb({h[i],pair+1});
        }
    }
    cout<<answer.size()<<endl;
    for(auto [x,y]:answer) cout<<x<<" "<<y<<endl;
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

