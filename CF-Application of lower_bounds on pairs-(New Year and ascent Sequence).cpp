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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)


void solve()
{
    int n;
    vt(pii) p;
    cin>>n;
    int ans = n*n;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        vi v(input);
        for(int i=0;i<input;i++) cin>>v[i];
        //is_sorted returns true if the elements are sorted in non decreasing fashion
        //we want elements to be arranged in the following type:

        // 5 5 5 4 3 3 2 1 1 ...
        //Above sequence is in non - increasing order
        // Above is exactly what we are searching for

        // reverse of the above is non - decreasing sequence
        // That is exactly what we want

        //Implementation below
        reverse(v.begin(),v.end());
        if(is_sorted(v.begin(),v.end())){
            p.pb({v[0],v.back()});//Smaller first
        }
    }
    sort(p.begin(),p.end());
    for(int i=0;i<sz(p);i++){
        ans-= (p.end()-lower_bound(p.begin(),p.end(),make_pair(p[i].ss,(int)-5)));
    }
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
