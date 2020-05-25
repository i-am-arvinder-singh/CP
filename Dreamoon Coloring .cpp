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
	int n,m;
	cin>>n>>m;
	int inp[m],suff[m],sum=0,ans[m];
	fl(i,0,m){
	    cin>>inp[i];
	    sum+=inp[i];
	}
	if(sum<n) {
         cout<<-1;
         return 0;
	}
	suff[m-1]=inp[m-1];
	bfl(i,m-1,0) suff[i]=suff[i+1]+inp[i];
//	cout<<inp[0]<<"****"<<endl;
	fl(i,0,m){
	    ans[i]=max(i+1,n-suff[i]+1);
	    if(i+1+inp[i]-1>n){
            cout<<-1<<endl;
//            cout<<"i: "<<i<<" "<<inp[i]<<endl;
            return 0;
	    }
	}
	fl(i,0,m) cout<<ans[i]<<" ";
	return 0;
}
