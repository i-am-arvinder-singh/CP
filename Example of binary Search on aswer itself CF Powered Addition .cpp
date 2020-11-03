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
#define LEFT(n) (2*n)dfs
#define RIGHT(n) (2*n+1)
#define PARENT(n) (n/2)

bool poss(int mid, int inp[], int n)
{
    int x=0;
    fl(i,0,mid) x|=(1ll<<i);
    int modif[n];
    fl(i,0,n) modif[i]=inp[i];
    fl(i,1,n){
        if(modif[i-1]>x+modif[i])
            return false;
        modif[i]=max(modif[i],modif[i-1]);
    }
    return true;
}

void solve()
{
    int n;
    cin>>n;
    int inp[n];
    fl(i,0,n) cin>>inp[i];
    //Performing binary search on answer since it is possible this way due to the nature of the problem
    int low=0,high=35,mid,ans;
    while(low<=high){
        mid = (low+high)>>1;
//        if(low==high) ans=mid;
//        cout<<"HELLO? "<<mid<<endl;
        if(poss(mid,inp,n)){
            high=mid-1;
//            ans=mid;
        }
        else
            low=mid+1;
    }
    cout<<low<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
