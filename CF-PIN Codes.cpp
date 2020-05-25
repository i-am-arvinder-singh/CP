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
    cin>>n;

    vt(string) a(n);
    vi cal(n);
    set<string> have;
    int ans = 0;

    for(string &s:a){
        cin>>s;
        have.insert(s);
    }

    for(int i=0;i<n;i++){
//        if(cal[i]) continue;
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i]){
//                cal[j]=1;
                ans++;
                for(int k=0;a[i]==a[j];){
                    for(char c='0';c<='9';c++){
                        string t = a[j];
                        t[k]=c;

                        if(!have.count(t)){
                            have.insert(t);
                            a[j]=t;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    for(string &s : a){
        cout<<s<<endl;
    }
}

int32_t main()
{
	omniphantom
	w(t) solve();
	return 0;
}
