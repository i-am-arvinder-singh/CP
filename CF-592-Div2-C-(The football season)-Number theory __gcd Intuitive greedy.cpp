#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

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
#define ppii            pair<pii,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n,p,w,d;
    cin>>n>>p>>w>>d;
    //Credits : invictus123
    //Explanation of approach : (no explained in his code) Provided I get it right
    //Is it possible to have a number which can be factorized and have a factor and when this factor multiplied with the remaining factors of that number yield such a number which does not have a former factor
    //In other words Eg: 3*X = Y and Y%3 != 0
    //Is the above possible?
    //Answer is no and is obvious
    //We exploit this fact
    int g = __gcd(w,d);
    if(p%g!=0){
        cout<<-1<<endl;
        return;
    }
    //Also if p%w i.e., remaining points is not divisible by d we borrow a w from x to it and try to get it divisible
    int Y = p%w;
    while(Y<=p){
        if(Y%d==0) break;
        Y+=w;
    }
    if(Y>p){
        cout<<-1<<endl;
        return;
    }
    int y=Y/d;
    int x=(p-Y)/w;
    if(x+y <= n){
        cout<<x<<" "<<y<<" "<<n-(x+y)<<endl;
        return;
    }
    else{
        cout<<-1<<endl;
        return;
    }
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
