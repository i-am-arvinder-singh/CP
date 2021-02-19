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
#define mod             1000000007
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
#define RIGHT(x)        2*x+2

const double pi = acos(-1.0);

void solve()
{
    vector<int> a(6);
    for(int i=0;i<6;i++) cin>>a[i];
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(a.begin(),a.end());
    sort(v.begin(),v.end());
    vector<int> check[n];
	set<int> w;
    for(int i=0;i<n;i++){
        vector<int> &temp = check[i];
        for(int j=5;j>=0;j--){
            temp.pb(v[i]-a[j]);
			w.insert(temp.back());
        }
    }
	set<pair<int,pii>> s;// {value,{id,cnt}}
    for(int i=0;i<n;i++) s.insert( make_pair(check[i][0], make_pair(i,0ll) ) );
	int ans = inf;
	for(auto val:w){
		bool flag = false;
		while(s.begin()->ff<val){
			auto temp = *s.begin();
			s.erase(s.begin());
			if(temp.ss.ss==5ll){
				flag = true;
				break;
			}
			s.insert({check[temp.ss.ff][temp.ss.ss+1],{temp.ss.ff,temp.ss.ss+1}});
		}
		if(flag) break;
		ans=min(ans,s.rbegin()->ff-val);
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
