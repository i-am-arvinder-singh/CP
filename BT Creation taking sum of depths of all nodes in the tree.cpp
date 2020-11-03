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

ini MxN=5e3+5;
int n,d,nc[MxN],p[MxN];
vi w[MxN];

void solve()
{
    cin>>n>>d;
    string yes="YES\n",no="NO\n";
    int i,ub_d,lb_d,temp;
    ub_d=(n*(n-1))/2;
    lb_d=0;
    for(i=1;i<=n;i++){
        temp=i;
        while(temp>0){
            temp/=2;
            if(temp!=0)
                lb_d++;
//            cout<<lb_d<<" ";
        }
    }
//    cout<<endl;
//    cout<<"LOWER BOUND:"<<lb_d<<endl;
    if(!(lb_d<=d && d<=ub_d)){
        cout<<no;
        return;
    }
    for(i=0;i<n;i++){
        nc[i]=1;
        p[i]=i-1;
        w[i].pb(i);
    }
    int s=ub_d,u=n-1,a,v;
    while(s>d){
        nc[u]=0;
        a=0;
        while(a+1<u && !w[a].size()){
            a++;
        }
        if(u-a-1>s-d){
            p[u]=u-1-(s-d);
            break;
        }
        v=w[a].back();
        p[u]=v;
        nc[v]++;
        s-=(u-a-1);
        if(nc[v]>=2){
            w[v].pop_back();
        }
        w[a+1].push_back(u);
        u--;
    }
    cout<<yes;
    for(i=1;i<n;i++){
        cout<<p[i]+1<<" ";
    }
    cout<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
