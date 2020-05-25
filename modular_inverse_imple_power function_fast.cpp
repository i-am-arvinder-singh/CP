#include<bits/stdc++.h>
using namespace std;

#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define Shazam          ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define mod             998244353
#define inf             1e18
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int

ini mx=2e5+5;
int inv[mx];

int power(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x%mod;
        y = y>>1;
        x = x*x % mod;
    }
    return res%mod;
}

//refer the below link to understand the best approach
//http://e-maxx.ru/algo/reverse_element
int32_t main()
{
	Shazam;
	int n,m,i;
	cin>>n>>m;
	inv[1]=1;
	fl(i,2,mx){
	    inv[i]=power(i,mod-2)%mod;
//        inv[i]=mod-mod/i*inv[mod%i]%mod;//
	}
	int ans=1;
	ans=ans*power(2,n-3)%mod;
//    cout<<"pow: "<<ans<<"\n";
	fl(i,1,m+1){
	    ans=ans*i%mod;
	}
//    cout<<"m! : "<<ans<<"\n";
	fl(i,1,n){
	    ans=ans*inv[i]%mod;
	}
	fl(i,1,m-(n-1)+1){
	    ans=ans*inv[i]%mod;
	}
//	cout<<ans<<"\n";
	ans*=(n-2)%mod;
	cout<<ans%mod<<"\n";
	return 0;
}
