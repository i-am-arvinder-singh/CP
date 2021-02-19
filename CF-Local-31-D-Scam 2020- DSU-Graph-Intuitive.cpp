#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
// using namespace __gnu_pbds;

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
#define all(v)			v.begin(),v.end()

const double pi = acos(-1.0); 

#define PRINT(x)		{print(x); return;}
#define FOR(v)			fl(i,0,(int)v.size())   read(v[i]);
#define FOR1(v)			fl(i,1,(int)v.size()+1) read(v[i]);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<endl;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "  , ";
	err(++it, args...);
}

template<typename... T>
void print(T...args){
	((cout<<args<<" "),...);
}

template<typename... T>
void read(T&...args){
	((cin>>args),...);
}

void solve()
{
	int n;
	read(n);
	map<string,int> my;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		my[s]=i+1;
	}
	int m;
	read(m);
	vector<pii> edges;
	for(int i=0;i<m;i++){
		string x,y;
		cin>>x>>y;
		edges.pb({my[x],my[y]});
	}
	vector<int> p(n+2);
    for(int i=1;i<=n;i++){
        p[i]=-i;
    }

    std::function<int(int)> f =  [&](int a)
    {
        if(p[a]<0) return a;
        return p[a] = f(p[a]);//Like dp // path compression
    };

    std::function<int(int,int)> u = [&](int a, int b)
    {
        a=f(a),b=f(b);
        if(a==b) return -1;
        p[b]=a;
        return 1;
    };

	int k;
	read(k);
	for(int i=0;i<k;i++){
		string x,y;
		cin>>x>>y;
		u(f(my[x]),f(my[y]));
	}

	int ans1 = 0;
	for(int i=0;i<n;i++) {
		ans1+=(f(i+1)==i+1);
	}
	set<pii> st;
	for(int i=0;i<m;i++){
		auto &[x,y] = edges[i];
		if(f(x)!=f(y)){
			st.insert({f(x),f(y)});
		}
	}
	cout<<ans1<<" "<<st.size()<<endl;
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