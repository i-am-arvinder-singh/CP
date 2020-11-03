#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> v;

void f(int no_of_pegs, int A, int B, int C)
{
    if(no_of_pegs==1){
        v.push_back({C,A});
        return;
    }
    f(no_of_pegs-1,B,A,C);
    v.push_back({C,A});
    f(no_of_pegs-1,A,C,B);
}

void solve()
{
    v.clear();
    int no_of_pegs, move_no;
    cin>>no_of_pegs>>move_no;
    f(no_of_pegs,3,2,1);
    cout<<v[move_no-1].first<<" "<<v[move_no-1].second<<endl;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}