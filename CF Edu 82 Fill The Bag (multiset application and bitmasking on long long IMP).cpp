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
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define PARENT(n) (n/2)
#define ll              long long

void solve()
{
    ll n,m,sum=0;
    cin>>n>>m;
    int a[m];
    multiset<int> s;
    fl(i,0,m){
        cin>>a[i];
        sum+=a[i];
        int x=0;//0'th index will be inserted as 0 in the multiset
        while(a[i]>1){
            x++;
            a[i]>>=1;
        }
        s.insert(x);//0 index based marking
    }
    if(sum<n){
        cout<<-1<<endl;
        return;
    }
    int ans=0;

    fl(i,0,62){
        if((n>>i)&1){ // if i'th index is marked
            if(s.find(i)!=s.end()){
                s.erase(s.find(i));//If iterator is passed only that particular element will be removed
                // If value is passed all the elements with that particular value is removed
            }
            else{
                int x = *s.begin();
                s.erase(s.begin());
                ans++;
                for(int j=x-1;j>i;j--){
                    ans++;
                    s.insert(j);
                }
            }
        }
        int x = s.count(i);
        if(x&1) s.erase(s.find(i));
        x/=2;
        s.erase(* s.find(i));
        while(x--) s.insert(i+1);
    }
    cout<<ans<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
