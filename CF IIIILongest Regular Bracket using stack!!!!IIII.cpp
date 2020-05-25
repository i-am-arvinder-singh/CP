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
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             100000000
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

ini mx=1e6+5;
int E[mx], S[mx], F[mx];

int32_t main()
{
	fio;
	string s;
	stack<int> st;
	cin>>s;

	int cnt1=0;

	fl(i,0,s.size()){
	    char ch=s[i];
	    if(ch=='('){
            st.push(i);
        }
        else{
            if(st.empty()){
                S[i]=E[i]=-1;//Mark
            }
            else{
                int id=st.top();
                st.pop();

                S[i]=E[i]=id;

                if(id>0 && s[id-1]==')' && S[id-1]!=-1){
                    E[i]=E[id-1];
                }
                cnt1=max(cnt1,i-E[i]+1);
                F[i-E[i]+1]++;
            }
        }
	}
	if(cnt1!=0)
        cout<<cnt1<<" "<<F[cnt1]<<endl;
    else
        cout<<0<<" "<<1<<endl;
	return 0;
}
