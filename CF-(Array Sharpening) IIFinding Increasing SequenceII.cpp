#include<bits/stdc++.h>
using namespace std;

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
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define yes             "Yes\n"
#define no             "No\n"



void solve()
{
    int n;
    cin>>n;
    int a[n];
    fl(i,0,n) cin>>a[i];
    int i=-1,j=n;
    fl(k,0,n){
        if(a[k]<k) break;
        i=k;
    }
    bfl(k,n,0){
        if(a[k]<(n-1-k)) break;
        j=k;
    }
    if(j<=i) cout<<yes;
    else cout<<no;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}