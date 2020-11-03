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

const int N = 2e5+10;
pair<int,int> p[N];
priority_queue<int> q;

int32_t main(){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin >> p[i].first;
    for(int i=0;i<n;i++) cin >> p[i].second;

    int locate = 0 , ans = 0 , s = 0 ;
    sort(p,p+n);
    cout<<endl;
    fl(i,0,n) cout<<p[i].ff<<" ";
    cout<<endl;
    fl(i,0,n) cout<<p[i].ss<<" ";
    cout<<endl;
    for(int i=0 ; i<n || !q.empty() ; locate++)
        {
        locate = (q.empty()) ? p[i].first : locate;
        cout<<endl;
        while( i<n && locate==p[i].first )
           {

            q.push(p[i].second);
            s += p[i].second;
            ++i;
            cout<<q.top()<<" "<<p[i].first<<":";
           }
        cout<<endl;
        cout<<q.top()<<" "<<q.size()<<"?";
        s -= q.top();
        q.pop();
        ans += s;
        cout<<q.top()<<" "<<q.size()<<"?"<<" "<<ans<<endl;
        }
cout << ans << endl;

return 0;
}
