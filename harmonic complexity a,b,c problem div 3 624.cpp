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

int32_t main()
{
	fio;
	w(t){
	    int a,b,c,i,j,k,A,B,C,res=0,ans=inf,ans_c;
	    cin>>a>>b>>c;
	    for(i=1;i<=2*a;i++){
            for(j=i;j<=2*b;j+=i){
                for(k=0;k<2;k++){
                    ans_c = j*(c/j)+ (k*j);
                    res = abs(i-a)+abs(j-b)+abs(ans_c-c);
                    if(res<ans){
                        ans=res;
                        A=i;
                        B=j;
                        C=ans_c;
                    }
                }
            }
	    }
	    cout<<ans<<endl;
	    cout<<A<<" "<<B<<" "<<C<<endl;
	}
	return 0;
}
