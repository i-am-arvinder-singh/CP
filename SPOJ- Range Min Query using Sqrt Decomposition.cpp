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

ini mx = 100000;
ini sqrsz = 320;

int arr[mx];
int block[sqrsz];
int blk_sz;

//Update function
void upd(int idx, int val)
{
    int bn = idx/blk_sz;
    block[bn] = min(val,block[bn]);
    arr[idx]=val;
}

int query(int l, int r)
{
    int mn = inf;
    while(l<r && l%blk_sz!=0 && l!=0){
        mn=min(mn,arr[l]);
        l++;
    }
    while(l+blk_sz<=r){
        mn=min(mn,block[l/blk_sz]);
        l+=blk_sz;
    }
    while(l<=r){
        mn=min(mn,arr[l]);
        l++;
    }
    return mn;
}

void preprocess(int a[], int n)
{
    int blk_idx = -1;
    int mn;
    blk_sz = sqrt(n);
    fl(i,0,n){
        arr[i]=a[i];
        if(i%blk_sz==0){
            mn = inf;
            blk_idx++;
        }
        mn=min(mn,arr[i]);
        block[blk_idx]=mn;
    }
}

int32_t main()
{
	fio;
	int n;
	cin>>n;
	int a[n];
	fl(i,0,n) cin>>a[i];
	preprocess(a,n);
//	fl(i,0,sqrsz)
//        cout<<block[i]<<" ";
//    cout<<endl;
	int q;
	cin>>q;
	while(q--){
        int a,b;
        cin>>a>>b;
        cout<<query(a,b)<<endl;
	}
	return 0;
}
