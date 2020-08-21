#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n,m;
const int V=10;
int g[V][V];
int g_cnt;

bool isOK(int g[V][V], int v, vector<int> &path, int pos)
{
    if(g[path[pos-1]][v]==0) return false;
    for(int i=0;i<pos;i++){
        if(path[i]==v) return false;
    }
    return true;
}

void hamHelper(int g[V][V], vector<int> &path, int pos)
{
    if(pos==n){
        g_cnt++;
        return;
    }
    for(int v=0;v<n;v++){
        if(isOK(g,v,path,pos)){
            path[pos]=v;
            hamHelper(g,path,pos+1);
            path[pos]=-1;
        }
    }
}

bool hasHam(int g[V][V])
{
    vector<int> path(n,-1);
    for(int i=0;i<n;i++){
        path[0]=i;
        hamHelper(g,path,1);
        path[0]=-1;
    }
}

void solve()
{
    cin>>n>>m;
    g_cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]=0;
    while(m--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x][y]=1;
        g[y][x]=1;
    }
    hasHam(g);
    cout<<g_cnt<<endl;
}

int main()
{
    int t=1;
    while(t--){
        solve();
    }
}
