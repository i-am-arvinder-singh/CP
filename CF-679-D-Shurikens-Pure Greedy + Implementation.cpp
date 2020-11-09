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

void terminate_(){
	cout<<"NO"<<endl;
	exit(EXIT_SUCCESS);
}

void solve()
{
    int n;
	cin>>n;
	set<int> total,available,trans;
	for(int i=1;i<=n;i++) available.insert(i);
	int cnt = 0;
	int bound = -1;
	vector<int> neg;
	vector<char> sign;
	set<int> posPos;
	map<int,int> my;
	vector<int> vecPos;
	for(int i=0;i<2*n;i++){
		char ch;
		cin>>ch;
		sign.pb(ch);
		if(ch=='-'){
			int x;
			cin>>x;
			neg.pb(x);
			my[x]=i;
		}
		else{
			posPos.insert(i);
			vecPos.pb(i);
		}
	}
	map<int,int> posPosVal;
	for(int i=1;i<=n;i++){
		if(!posPos.empty()){
			auto it = posPos.lower_bound(my[i]);
			if(it==posPos.end()) it--;
			if(it==posPos.begin() && *it>my[i]) terminate_(); 
			else if(*it>my[i]) it--;
			posPosVal[*it] = i;
			posPos.erase(it);
		}
		else terminate_();
	}

	vector<int> toCompare;
	for(auto pos:vecPos){
		toCompare.pb(posPosVal[pos]);
	}

	int id=0;
	vector<int> ans;
	stack<int> st;
	id = (int)neg.size()-1;
	for(int i=2*n-1;i>=0;i--){
		char ch = sign[i];
		if(ch=='-'){
			st.push(neg[id--]);
		}
		else{
			ans.push_back(st.top());
			st.pop();
		}
	}
	reverse(ans.begin(),ans.end());
	
	for(int i=0;i<(int)ans.size();i++){
		if(ans[i]!=toCompare[i]) terminate_();
	}
	cout<<"YES"<<endl;
	for(auto ele:ans) cout<<ele<<" ";

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