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
//#define mod             100000000
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

ini mx=2e5+5;
int a[mx],n,d,tmp[mx];

bool valid()
{
    fl(i,1,n+1) if(abs(a[i]-i)%d) return false;
    return true;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{

    int i, j, k;

    int inv_count = 0;



    i = left; /* i is index for left subarray*/

    j = mid; /* j is index for right subarray*/

    k = left; /* k is index for resultant merged subarray*/

    while ((i <= mid - 1) && (j <= right)) {

        if (arr[i] <= arr[j]) {

            temp[k++] = arr[i++];

        }

        else {

            temp[k++] = arr[j++];


            inv_count = inv_count + (mid - i);

        }

    }


    while (i <= mid - 1)

        temp[k++] = arr[i++];


    while (j <= right)

        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)

        arr[i] = temp[i];



    return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{

    int mid, inv_count = 0;

    if (right > left) {


        mid = (right + left) / 2;


        inv_count += _mergeSort(arr, temp, left, mid);

        inv_count += _mergeSort(arr, temp, mid + 1, right);


        inv_count += merge(arr, temp, left, mid + 1, right);

    }

    return inv_count;
}

int mergeSort(int arr[], int array_size)
{

    int temp[array_size];

    return _mergeSort(arr, temp, 0, array_size - 1);
}



void solve()
{
    cin>>n>>d;
    fl(i,1,n+1) cin>>a[i];
    if(!valid()){
        cout<<-1<<endl;
        return;
    }
    int ans=0;
    fl(i,1,d+1){
        int cnt=0;
        for(int j=i;j<=n;j+=d){
            tmp[cnt++]=a[j];
        }
        ans+=mergeSort(tmp,cnt);
    }
    cout<<ans<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
