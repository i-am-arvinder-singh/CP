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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define PARENT(n) (n/2)

vi era;

void erastos(int n)
{
    era.resize(n+1);
    era[0]=inf;
    era[1]=1;
    int i,j;
    for(i=2;i<=n;i++){
        if(era[i]) continue;
        for(j=i;j<=n;j+=i){
            if(era[j]) continue;
            era[j]=j/i;
        }
    }
    sort(era.begin(),era.end());
}

int32_t main()
{
	fio;
	int n;
	cin>>n;
	erastos(n);
	fl(i,1,n) cout<<era[i]<<" ";
	return 0;
}
