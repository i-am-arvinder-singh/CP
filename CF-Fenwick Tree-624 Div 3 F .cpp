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

ini mx=3e5;
int n;

//We are creating fenwick tree as a structure since we require
//two such fenwick trees for our operation which determines such
//pairs

struct ft{
    //It will have two operations update and query
    // These are the only ones we require for the program

    // The logarithmic complexity of query and update is because
    //of the binary base 2 nature of the construct of this data
    // structure i.e., Fenwick tree

    int a[mx];
    void update(int i, int x){ // Index from where we want to update
                                // and the value up which we want to
                                // update
        for(++i;i<=n;i+=i&-i){
            a[i]+=x;
        }
    }
    //Also query will be of 1 to i nature
    int query (int i){
        int sum=0;
        for(;i;i-=i&-i){
            sum+=a[i];
        }
        return sum;
    }
}f0,f1;

int32_t main()
{
	fio;
	array<int,2> a[mx];
	cin>>n;
	vi v;
	fl(i,0,n) cin>>a[i][0];
	fl(i,0,n){
	    cin>>a[i][1];
	    v.pb(a[i][1]);
	}
	sort(v.begin(),v.end());
	sort(a,a+n);
	int ans=0;
	fl(i,0,n){
	    int p =lower_bound(v.begin(),v.end(),a[i][1])-v.begin();
	    ans+=f0.query(p+1)*a[i][0]-f1.query(p+1);
	    f0.update(p,1);
	    f1.update(p,a[i][0]);
	}
	cout<<ans<<endl;
	return 0;
}
