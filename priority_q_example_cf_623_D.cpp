#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define ff              first
#define int             long long
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define fio          ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
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

int32_t main()
{
	fio;
	int n,i,loc;
	cin>>n;
	pii arr[n];
	for(i=0;i<n;i++) cin>>arr[i].first;
	for(i=0;i<n;i++) cin>>arr[i].second;
	sort(arr,arr+n);
	priority_queue<int> q;
	int s=0,ans=0;
	i=0;
	while(i<n || !q.empty()){
        if(q.empty()) loc = arr[i].first;
        else loc++;
        while(i<n && arr[i].first==loc){
            q.push(arr[i].second);
            s+=arr[i].second;
            i++;
        }
        s-=q.top();
        q.pop();
        ans+=s;
	}
	cout<<ans;
	return 0;
}
