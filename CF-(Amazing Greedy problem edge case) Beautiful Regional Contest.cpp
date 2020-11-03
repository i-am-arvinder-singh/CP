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
    int n,x;
    cin>>n;
    map<int,int,greater<int>> m;
    for(int i=0;i<n;i++){
        cin>>x;
        m[x]++;
    }
    vi v;
    int sum=0;
    auto it = m.begin();
    while((sum+it->ss)<=(n/2) && it!=m.end()){
        v.pb(it->ss);
        sum+=(it->ss);
        it++;
    }
    if(v.size()>=3){
        int g= *v.begin(),s=0,b=0;
        auto itv = v.begin()+1;
        while(s<=g && itv!=v.end()){
            s+= (*itv);
            itv++;
        }
        while(itv!=v.end()){
            b+= (*itv);
            itv++;
        }
        if(g>0 && b>0 && s>0 && g<b && g<s &&(g+b+s)<=(n/2))
            cout<<g<<" "<<s<<" "<<b<<endl;
        else
            cout<<"0 0 0\n"<<endl;
    }
    else{
        cout<<"0 0 0\n";
    }
}

int32_t main()
{
	omniphantom
	w(t) solve();
	return 0;
}
