#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n,m;
const int V=10;
int g[V][V];

bool isOK(int g[V][V], int v, vector<int> &path, int pos)
{
    if(g[path[pos-1]][v]==0) return false;
    for(int i=0;i<pos;i++){
        if(path[i]==v) return false;
    } 
    return true;
}

bool hamHelper(int g[V][V], vector<int> &path, int pos)
{
    if(pos==n){
        return true;
    }
    for(int v=1;v<n;v++){
        if(isOK(g,v,path,pos)){
            path[pos]=v;
            if(hamHelper(g,path,pos+1)) return true;
            path[pos]=-1;
        }
    }
    return false;
}

bool hasHam(int g[V][V])
{
    vector<int> path(n,-1);
    path[0]=0;
    if(hamHelper(g,path,1)){
        return true;
    }
    return false;
}

void solve()
{
    cin>>n>>m;
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
    if(hasHam(g)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}