#include<bits/stdc++.h>

using namespace std;

int main()
    {
        int n,i;
        cin>>n;

        vector<int> v(n+1);
        for(i=1;i<=n;i++)
            cin>>v[i];
        map <int,int> freq1;
        vector <int> v1(n+1,0);
        for(i=1;i<=n;i++)
        {
            freq1[v[i]]++;
            v1[i]=freq1[v[i]];
        }
        map<int,int> :: iterator itr;
        cout<<endl;
        for(itr=freq1.begin();itr!=freq1.end();itr++)
            cout<<itr->first<<" "<<itr->second<<endl;
        cout<<endl<<endl;
        for(i=1;i<=n;i++)
            cout<<v1[i]<<" ";
        cout<<endl;

        map <int,int> freq2;
        vector <int> v2(n+1,0);
        for(i=n;i>=1;i--)
        {
            freq2[v[i]]++;
            v2[i]=freq2[v[i]];
        }

        cout<<endl;
        for(itr=freq2.begin();itr!=freq2.end();itr++)
            cout<<itr->first<<" "<<itr->second<<endl;
        cout<<endl<<endl;
        for(i=1;i<=n;i++)
            cout<<v2[i]<<" ";
        cout<<endl;

        return 0;
    }
