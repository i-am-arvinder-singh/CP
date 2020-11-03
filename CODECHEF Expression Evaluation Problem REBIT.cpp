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


string s;

int power(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x%mod;
        y = y>>1;
        x = x*x % mod;
        x%=mod;
        res%=mod;
    }
    return res%mod;
}

int cnt()
{
    int cnt=0;
    for(auto x: s)
        if(x=='#')
            cnt++;
    return cnt;
}

int add(int &a, int b)
{
    return a=(a+b)%mod;
}

vi operate(vi a, vi b, char op)
{
    vi res(4,0);
    //0->0
    //1->1
    //2->a
    //3->A
    if(op == '|'){
        add(res[0],(a[0]*b[0])%mod);
        add(res[1],(a[1]*b[0])%mod);
        add(res[2],(a[2]*b[0])%mod);
        add(res[3],(a[3]*b[0]%mod));

        add(res[1],(a[0]*b[1])%mod);
        add(res[1],(a[1]*b[1])%mod);
        add(res[1],(a[2]*b[1])%mod);
        add(res[1],(a[3]*b[1]%mod));

        add(res[2],(a[0]*b[2])%mod);
        add(res[1],(a[1]*b[2])%mod);
        add(res[2],(a[2]*b[2])%mod);
        add(res[1],(a[3]*b[2]%mod));

        add(res[3],(a[0]*b[3])%mod);
        add(res[1],(a[1]*b[3])%mod);
        add(res[1],(a[2]*b[3])%mod);
        add(res[3],(a[3]*b[3]%mod));
    }

    else if(op == '^'){
        add(res[0],(a[0]*b[0])%mod);
        add(res[1],(a[1]*b[0])%mod);
        add(res[2],(a[2]*b[0])%mod);
        add(res[3],(a[3]*b[0]%mod));

        add(res[1],(a[0]*b[1])%mod);
        add(res[0],(a[1]*b[1])%mod);
        add(res[3],(a[2]*b[1])%mod);
        add(res[2],(a[3]*b[1]%mod));

        add(res[2],(a[0]*b[2])%mod);
        add(res[3],(a[1]*b[2])%mod);
        add(res[0],(a[2]*b[2])%mod);
        add(res[1],(a[3]*b[2]%mod));

        add(res[3],(a[0]*b[3])%mod);
        add(res[2],(a[1]*b[3])%mod);
        add(res[1],(a[2]*b[3])%mod);
        add(res[0],(a[3]*b[3]%mod));
    }

    else {
        add(res[0],(a[0]*b[0])%mod);
        add(res[0],(a[1]*b[0])%mod);
        add(res[0],(a[2]*b[0])%mod);
        add(res[0],(a[3]*b[0]%mod));

        add(res[0],(a[0]*b[1])%mod);
        add(res[1],(a[1]*b[1])%mod);
        add(res[2],(a[2]*b[1])%mod);
        add(res[3],(a[3]*b[1]%mod));

        add(res[0],(a[0]*b[2])%mod);
        add(res[2],(a[1]*b[2])%mod);
        add(res[2],(a[2]*b[2])%mod);
        add(res[0],(a[3]*b[2]%mod));

        add(res[0],(a[0]*b[3])%mod);
        add(res[3],(a[1]*b[3])%mod);
        add(res[0],(a[2]*b[3])%mod);
        add(res[3],(a[3]*b[3]%mod));
    }

    return res;
}

vi Res()
{
    vi t(4,1);
    stack<vi> st;
    stack<char> op_st, par_st;

    for(auto x: s){
        if(x=='(') par_st.push(x);
        else if(x=='|'||x=='&'||x=='^') op_st.push(x);
        else if(x=='#') st.push(t);
        else{
            vi a=st.top();
            st.pop();

            vi b=st.top();
            st.pop();

            char op = op_st.top();
            op_st.pop();
            par_st.pop();

            st.push(operate(a,b,op));
        }
    }

    return st.top();
}

void solve()
{
    cin>>s;
    vi res = Res();
    int d =power(power(4,cnt()),mod-2);
    fl(i,0,4)
        cout<<(res[i]*d)%mod<<" ";
    cout<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
