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
#define RIGHT(x)        2*x+2

#define PRINT(x)		{print(x); return;}
#define FOR(v)			fl(i,0,(int)v.size()) read(v[i]);

const double pi = acos(-1.0);

template<typename... T>
void print(T&...args){
	((cout<<args<<endl),...);
}

template<typename... T>
void read(T&...args){
	((cin>>args),...);
}

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	FOR(v);
	int mn = v[0];
	for(int i=0;i<n-1;i++){
		if(v[i]<=v[i+1]) continue;
		else{
			int d = v[i]-v[i+1];
			if(mn-d>=0) mn-=d;
			else PRINT("NO");
		}
	}
	PRINT("YES");
}

int32_t main()
{
	omniphantom
	#if 1
	w(t)
	#endif // 0
    solve();
	return 0;
}
