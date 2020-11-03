#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              insert
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

int n,m,k;

void solve()
{
    cin>>n>>m>>k;
    int a[n];
    fl(i,0,n) cin>>a[i];
    //Trim k
    //since it is only worth to control people's choice ahead of me
    k=min(k,m-1);
    //x->Number of people I force to take the first element(ofc I control them)
    //y->Number of non-controllable friends who choose the first element
    //a[x+y] and a[n-(m-(x+y))]
    //I control k people
    //How many people I don't control = (m-1)-k

    //Starting from 0 people that I control and taking it
    //all the way to k people I control

    //Similarly starting from 0 people that I don't control and taking it
    //all the way to (m-1)-k people that I don't control

    //Basically we parameterize everything to apply a brute force solution
    //This is where greedy comes in play

    //Had it been dp solution we would have memoized it
    int ans=0;
    for(int x=0;x<=k;x++){
        int tmp=inf;
        for(int y=0;y<=(m-1)-k;y++){
            //for all j's we chose maximum
            //then naturally minimize it
            tmp=min(tmp,max(a[x+y],a[n-(m-(x+y))]));//Being greedy here
            //Choosing maximum and minimizing this maxima
        }
        ans=max(tmp,ans);
    }
    cout<<ans<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}