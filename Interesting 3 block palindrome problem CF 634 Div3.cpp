#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define ff              first
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

ini mx=3e5;
int inp[mx];
int freq[205];
int cnt[mx][205];
vi stck[205];

void solve()
{
    int i,n,j;
    cin>>n;
    int ans=0;
    for(i=1;i<=n;i++){
        cin>>inp[i];
        freq[inp[i]]++;
        //Counting odd number of maximum characters below only that particular character
        ans=max(ans,freq[inp[i]]-(1-freq[inp[i]]%2));
        for(j=1;j<=200;j++){
            cnt[i][j]=cnt[i-1][j]+(inp[i]==j);
        }
        stck[inp[i]].pb(i);//Number and index of that number mapping
    }
    for(i=1;i<=200;i++)
        for(j=1;j<=n;j++)
            if(stck[i].size()>=2*j){
                int a=stck[i][j-1];
                int b=stck[i][stck[i].size()-j];
                int check=0;
                for(int k=1;k<=200;k++)
                    check=max(check,cnt[b-1][k]-cnt[a][k]);
                ans=max(ans,check+2*j);
            }
            else
                break;
    cout<<ans<<endl;
    for(i=1;i<=200;i++) stck[i].clear();
    memset(freq,0,sizeof(freq));
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
