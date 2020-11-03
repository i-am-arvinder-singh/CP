#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
// #define int             long long
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

struct BIT{
    int n;
    vi bit_tree;
    BIT(int n):
        n(n+1),bit_tree(n+3){}
    void update(int x, int value){//Only gets added
        for(;x<=n;x += (x&-x) )
            bit_tree[x]+=value;
    }
    int query(int x){
        int sum=0;
        for(;x>0;x-=(x&-x) )
            sum+=bit_tree[x];
        return sum;
    }
};

int32_t main()
{
	fio;
	int n,q;
	cin>>n>>q;
	BIT a[26](n);
	string s;
	cin>>s;
	fl(i,0,n) a[s[i]-'a'].update(i+1,1);
	while(q--){
        int x,l,r;
        char c;
        cin>>x;
        if(x==2){
            cin>>l>>r;
            int o_cnt=0;
            int seg=r-l+1;
            bool flag=true;
            fl(i,0,26){
                int sum = a[i].query(r)-a[i].query(l-1);
                if(sum>=0)  if(sum%2) o_cnt++;
            }
            if(seg%2 && o_cnt==1)
                cout<<"yes\n";
            else if(seg%2==0 && o_cnt==0)
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
        else{
            cin>>l>>c;
            a[s[l-1]-'a'].update(l,-1);
	        s[l-1]=c;
            a[c-'a'].update(l,1);
        }
	}
	return 0;
}
