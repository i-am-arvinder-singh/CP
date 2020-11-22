#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

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

// Taken in the following fashion
// X0->X1->move onto next line
// X2->X3
vector<vector<pii>> findAns(vector<vector<int>> &,vector<pii> &);

vector<vector<pii>> findTwoDia(vector<vector<int>> &grid, vector<pii> &coor,int x,int y){
	vector<vector<pii>> ans;
	if(x==0){
		grid[coor[1].ff][coor[1].ss]=1;
		grid[coor[2].ff][coor[2].ss]=1;
		grid[coor[0].ff][coor[0].ss]=0;
		vector<pii> t;
		t.pb(coor[0]);
		t.pb(coor[1]);
		t.pb(coor[2]);
		ans.pb(t);
		vector<vector<pii>> tt = findAns(grid,coor);
		for(auto w:tt) ans.pb(w);
		return ans;
	}
	else if(x==1){
		grid[coor[3].ff][coor[3].ss]=1;
		grid[coor[0].ff][coor[0].ss]=1;
		grid[coor[1].ff][coor[1].ss]=0;
		vector<pii> t;
		t.pb(coor[0]);
		t.pb(coor[1]);
		t.pb(coor[3]);
		ans.pb(t);
		vector<vector<pii>> tt = findAns(grid,coor);
		for(auto w:tt) ans.pb(w);
		return ans;
	}
}

vector<vector<pii>> findOne(vector<vector<int>> &grid, vector<pii> &coor){
	vector<vector<pii>> ans;
	if(grid[coor[0].ff][coor[0].ss]==1){
		grid[coor[1].ff][coor[1].ss]=1;
		grid[coor[2].ff][coor[2].ss]=1;
		grid[coor[0].ff][coor[0].ss]=0;
		vector<pii> t;
		t.pb(coor[0]);
		t.pb(coor[1]);
		t.pb(coor[2]);
		ans.pb(t);
		vector<vector<pii>> tt = findAns(grid,coor);
		for(auto p:tt) ans.pb(p);
		return ans;
	}
	else if(grid[coor[1].ff][coor[1].ss]==1){
		grid[coor[3].ff][coor[3].ss]=1;
		grid[coor[0].ff][coor[0].ss]=1;
		grid[coor[1].ff][coor[1].ss]=0;
		vector<pii> t;
		t.pb(coor[0]);
		t.pb(coor[1]);
		t.pb(coor[3]);
		ans.pb(t);
		vector<vector<pii>> tt = findAns(grid,coor);
		for(auto p:tt) ans.pb(p);
		return ans;
	}
	else if(grid[coor[2].ff][coor[2].ss]==1){
		grid[coor[3].ff][coor[3].ss]=1;
		grid[coor[0].ff][coor[0].ss]=1;
		grid[coor[2].ff][coor[2].ss]=0;
		vector<pii> t;
		t.pb(coor[0]);
		t.pb(coor[3]);
		t.pb(coor[2]);
		ans.pb(t);
		vector<vector<pii>> tt = findAns(grid,coor);
		for(auto p:tt) ans.pb(p);
		return ans;
	}
	else if(grid[coor[3].ff][coor[3].ss]==1){
		grid[coor[1].ff][coor[1].ss]=1;
		grid[coor[2].ff][coor[2].ss]=1;
		grid[coor[3].ff][coor[3].ss]=0;
		vector<pii> t;
		t.pb(coor[3]);
		t.pb(coor[1]);
		t.pb(coor[2]);
		ans.pb(t);
		vector<vector<pii>> tt = findAns(grid,coor);
		for(auto p:tt) ans.pb(p);
		return ans;
	}
}

vector<vector<pii>> findAns(vector<vector<int>> &grid, vector<pii> &coor){
	int cnt = 0;
	vector<vector<pii>> ans;
	for(auto [x,y]:coor) cnt+=grid[x][y];
	vector<int> X(4);
	for(int i=0;i<4;i++) X[i]=grid[coor[i].ff][coor[i].ss];
	if(cnt==0){
		return ans;
	}
	else if(cnt==1){
		ans = findOne(grid,coor);
		return ans;
	}
	else if(cnt==2){
		if(X[0]==1 && X[1]==1){
			vector<pii> t;
			grid[coor[0].ff][coor[0].ss]=0;
			grid[coor[2].ff][coor[2].ss]=1;
			grid[coor[3].ff][coor[3].ss]=1;
			t.pb(coor[0]);
			t.pb(coor[2]);
			t.pb(coor[3]);
			ans.pb(t);
			vector<vector<pii>> tt = findAns(grid,coor);
			for(auto w:tt) ans.pb(w);
			return ans;
		}
		else if(X[1]==1 && X[3]==1){
			vector<pii> t;
			grid[coor[1].ff][coor[1].ss]=0;
			grid[coor[2].ff][coor[2].ss]=1;
			grid[coor[0].ff][coor[0].ss]=1;
			t.pb(coor[1]);
			t.pb(coor[2]);
			t.pb(coor[0]);
			ans.pb(t);
			vector<vector<pii>> tt = findAns(grid,coor);
			for(auto w:tt) ans.pb(w);
			return ans;
		}
		else if(X[3]==1 && X[2]==1){
			vector<pii> t;
			grid[coor[0].ff][coor[0].ss]=1;
			grid[coor[1].ff][coor[1].ss]=1;
			grid[coor[3].ff][coor[3].ss]=0;
			t.pb(coor[0]);
			t.pb(coor[1]);
			t.pb(coor[3]);
			ans.pb(t);
			vector<vector<pii>> tt = findAns(grid,coor);
			for(auto w:tt) ans.pb(w);
			return ans;
		}
		else if(X[0]==1 && X[2]==1){
			vector<pii> t;
			grid[coor[0].ff][coor[0].ss]=0;
			grid[coor[1].ff][coor[1].ss]=1;
			grid[coor[3].ff][coor[3].ss]=1;
			t.pb(coor[0]);
			t.pb(coor[1]);
			t.pb(coor[3]);
			ans.pb(t);
			vector<vector<pii>> tt = findAns(grid,coor);
			for(auto w:tt) ans.pb(w);
			return ans;
		}
		else if(X[0]==1 && X[3]==1){
			ans = findTwoDia(grid,coor,0,3);
		}	
		else if(X[1]==1 && X[2]==1){
			ans = findTwoDia(grid,coor,1,2);
		}
		return ans;
	}
	else if(cnt==3){
		vector<pii> t;
		for(int i=0;i<4;i++){
			int x = coor[i].ff, y = coor[i].ss;
			if(grid[x][y]==1){
				t.pb(coor[i]);
				grid[x][y]=0;
			}
		}
		ans.pb(t);
		return ans;
	}
	else{
		vector<pii> t;
		for(int i=0;i<3;i++){
			int x = coor[i].ff, y = coor[i].ss;
			t.pb(coor[i]);
			grid[x][y]=0;
		}
		vector<vector<pii>> tt = findAns(grid,coor);
		ans.pb(t);
		for(auto w:tt) ans.pb(w);
		return ans;
	}

}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> grid(n,vector<int>(m));
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		for(int j=0;j<m;j++) grid[i][j]=(t[j]=='1')?1:0;
	}
	vector<vector<pii>> ans;
	for(int i=0;i<n-2;i++){
		for(int j=0;j<m;j++){
			if(j+1<m){
				if(grid[i][j]){
					vector<pii> coor;
					coor.pb({i,j});
					coor.pb({i+1,j+1});
					coor.pb({i+1,j});
					grid[i][j]^=1;
					grid[i+1][j+1]^=1;
					grid[i+1][j]^=1;
					ans.pb(coor);
				}
			}
			else{
				if(grid[i][j]){
					vector<pii> coor;
					coor.pb({i,j});
					coor.pb({i+1,j-1});
					coor.pb({i+1,j});
					grid[i][j]^=1;
					grid[i+1][j-1]^=1;
					grid[i+1][j]^=1;
					ans.pb(coor);
				}
			}
		}
	}
	if(m&1){
		if(grid[n-2][0]==0||grid[n-1][0]==0){
			for(int i=0;i+1<m;i+=2){
				vector<pii> coor;
				coor.pb({n-2,i});
				coor.pb({n-2,i+1});
				coor.pb({n-1,i});
				coor.pb({n-1,i+1});
				auto tt = findAns(grid,coor);
				for(auto p:tt) ans.pb(p);
			}
			vector<pii> coor;
			coor.pb({n-2,m-2});
			coor.pb({n-2,m-1});
			coor.pb({n-1,m-2});
			coor.pb({n-1,m-1});
			auto tt = findAns(grid,coor);
			for(auto p:tt) ans.pb(p);
		}
		else if(grid[n-2][m-1]==0||grid[n-1][m-1]==0){
			for(int i=m-1;i-1>=0;i-=2){
				vector<pii> coor;
				coor.pb({n-2,i-1});
				coor.pb({n-2,i});
				coor.pb({n-1,i-1});
				coor.pb({n-1,i});
				auto tt = findAns(grid,coor);
				for(auto p:tt) ans.pb(p);
			}
			vector<pii> coor;
			coor.pb({n-2,0});
			coor.pb({n-2,1});
			coor.pb({n-1,0});
			coor.pb({n-1,1});
			auto tt = findAns(grid,coor);
			for(auto p:tt) ans.pb(p);
		}
		else{
			for(int i=0;i+1<m;i+=2){
				vector<pii> coor;
				coor.pb({n-2,i});
				coor.pb({n-2,i+1});
				coor.pb({n-1,i});
				coor.pb({n-1,i+1});
				auto tt = findAns(grid,coor);
				for(auto p:tt) ans.pb(p);
			}
			vector<pii> coor;
			coor.pb({n-2,m-2});
			coor.pb({n-2,m-1});
			coor.pb({n-1,m-2});
			coor.pb({n-1,m-1});
			auto tt = findAns(grid,coor);
			for(auto p:tt) ans.pb(p);
		}
	}
	else{
		for(int i=0;i+1<m;i+=2){
			vector<pii> coor;
			coor.pb({n-2,i});
			coor.pb({n-2,i+1});
			coor.pb({n-1,i});
			coor.pb({n-1,i+1});
			auto tt = findAns(grid,coor);
			for(auto p:tt) ans.pb(p);
		}
	}
	cout<<ans.size()<<endl;
	for(auto t:ans){
		for(auto [x,y]:t) cout<<x+1<<" "<<y+1<<" ";
		cout<<endl;
	}
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
 