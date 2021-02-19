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


int getSum(int BITree[], int index)
{
	int sum = 0; // Initialize result

	// Traverse ancestors of BITree[index]
	while (index > 0) {
		// Add current element of BITree to sum
		sum += BITree[index];

		// Move index to parent node in getSum View
		index -= index & (-index);
	}
	return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
	// Traverse all ancestors and add 'val'
	while (index <= n) {

		// Add 'val' to current node of BI Tree
		BITree[index] += val;

		// Update index to that of parent in update View
		index += index & (-index);
	}
}

// Converts an array to an array with values from 1 to n
// and relative order of smaller and greater elements remains
// same. For example, {7, -90, 100, 1} is converted to
// {3, 1, 4, 2 }
void convert(vector<int> arr, int n)
{
	// Create a copy of arrp[] in temp and sort the temp array
	// in increasing order
	int temp[n];
	for (int i = 0; i < n; i++)
		temp[i] = arr[i];
	sort(temp, temp + n);

	// Traverse all array elements
	for (int i = 0; i < n; i++) {
		// lower_bound() Returns pointer to the first element
		// greater than or equal to arr[i]
		arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1;
	}
}

// Function to find smaller_right array
vector<int> findElements(vector<int> arr, int n)
{
	// Convert arr[] to an array with values from 1 to n and
	// relative order of smaller and greater elements remains
	// same. For example, {7, -90, 100, 1} is converted to
	// {3, 1, 4, 2 }
	convert(arr, n);

	// Create a BIT with size equal to maxElement+1 (Extra
	// one is used so that elements can be directly be
	// used as index)
	int BIT[n + 1];
	for (int i = 1; i <= n; i++)
		BIT[i] = 0;

	// To store smaller elements in right side
	// and greater elements on left side
	vector<int> smaller_right(n), greater_left(n);

	// Traverse all elements from right.
	for (int i = n - 1; i >= 0; i--) {

		// Get count of elements smaller than arr[i]
		smaller_right[i] = getSum(BIT, arr[i] - 1);

		// Add current element to BIT
		updateBIT(BIT, n, arr[i], 1);
	}

	for (int i = 1; i <= n; i++)
		BIT[i] = 0;

	// Find all left side greater elements
	for (int i = 0; i < n; i++) {

		// Get count of elements greater than arr[i]
		greater_left[i] = i - getSum(BIT, arr[i]);

		// Add current element to BIT
		updateBIT(BIT, n, arr[i], 1);
	}

	// cout << "Greater left: ";

	// // Print greater_left array
	// for (int i = 0; i < n; i++)
	// 	cout << greater_left[i] << " ";
	return greater_left;
}


int n,m;
const int MAX = 1e5+10;
double dp[MAX][2];

bool check(int id,vector<int> &invCnt){
	if(invCnt[n]-invCnt[id])
		return false;
	else return true;
};

double f(int id, int isSorted, vector<pair<int,double>> &pp, vector<int> &invCnt){
	if(dp[id][isSorted]!=-1.0) return dp[id][isSorted];
	if(id>=m){
		if(isSorted) return dp[id][isSorted] = 1.0;
		else return dp[id][isSorted] = 0.0;
	}
	auto &[x,y] = pp[id];
	double a = f(id+1,isSorted||check(x-1,invCnt),pp,invCnt);
	double b = f(id+1,isSorted,pp,invCnt);
	double t = y*a+(1.0-y)*b;
	// error(id,t,y,a,b);
	return dp[id][isSorted] = t;
}

void solve()
{
	read(n,m);
	vector<int> v(n);
	for(int i=0;i<n;i++) read(v[i]);
	vector<pair<int,double>> pp;
	for(int i=0;i<m;i++){
		int x;
		double y;
		read(x,y);
		pp.pb({x,y});
	}
	vector<int> invCnt(n+2,0);
	vector<int> t = findElements(v, n);
	for(int i=0;i<n;i++){
		invCnt[i] = t[i];
	}
	// cout<<"******"<<endl;
	// for(auto ele:invCnt) cout<<ele<<" ";
	// cout<<endl<<"******"<<endl;
	for(int i=1;i<n+1;i++) invCnt[i]=invCnt[i-1]+invCnt[i];
	for(int i=0;i<=m+2;i++){
		for(int j=0;j<2;j++){
			dp[i][j]=-1.0;
		}
	}
	cout<<f(0,is_sorted(all(v)),pp,invCnt)<<endl;
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