#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin,str);

    stringstream s;
    s<<str;// This method could be used to insert or we could simply write s(str) in above as well
    int c=0;
    string word;
    while(s>>word)
        c++;
    cout<<c<<endl;
    return 0;
}
