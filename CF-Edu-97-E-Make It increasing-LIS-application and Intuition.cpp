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
	int n,k;
	cin>>n>>k;
	vector<int> v(n+2),idx(k+2);
	v[0]=-inf;
	v[n+1]=inf;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=0;i<n+2;i++) v[i]-=i;
	for(int i=1;i<=k;i++) cin>>idx[i];
	idx[0] = 0, idx[k+1] = n+1;
	int ans = 0;
	for(int i=0;i<k+1;i++){
		int left = idx[i], right = idx[i+1];
		if(v[left]>v[right]){
			cout<<-1<<endl;
			return;
		}
		vector<int> lis;//This lis is increasing sequence instead of stricly increasing sequence
		for(int j=left+1;j<right;j++) if(v[left]<=v[j] && v[j]<=v[right]){
			auto it = upper_bound(lis.begin(),lis.end(),v[j]);
			if(it==lis.end()) lis.pb(v[j]);
			else *it = v[j];
		}
		ans+=(((right-1)-(left+1)+1)-(int)lis.size());
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
