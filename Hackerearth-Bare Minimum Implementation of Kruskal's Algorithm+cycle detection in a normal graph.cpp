#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

const int MAX = 1e4+5;
int p[MAX];

vector<pair<pair<int,int>,int>> g;

int f(int a)
{
    if(p[a]<0) return a;
    return p[a]=f(p[a]);
}

void u(int a, int b)
{
    p[b]=a;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=-i;
    }
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g.push_back({{x,y},w});
    }
    sort(g.begin(),g.end(),[&](auto p1, auto p2){
        return p1.ss<p2.ss;
    });
    int ans = 0;
    for(auto e:g){
        auto p = e.ff;
        auto w = e.ss;
        if(f(p.ff)!=f(p.ss)){
            ans+=w;
            u(f(p.ff),f(p.ss));
        }
    }
    cout<<ans<<endl;
}






