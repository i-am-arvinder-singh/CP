#include<bits/stdc++.h>
using namespace std;

int nextState(string pat, int m, int state, int c)
{
    if(state<m && c==pat[state]) return state+1;
    for(int nx = state; nx>0; nx--){
        if(pat[nx-1]==c){
            int i = 0;
            for(i=0;i<nx-1;i++)
                if(pat[i]!=pat[state-(nx-1)+i])
                    break;
            if(i==nx-1) return nx;
        }
    }
    return 0;
}

void find_trans(string pat, vector<vector<int>> &trans, int m)
{
    for(int state = 0; state<=m; state++)
        for(int c = 0; c<256; c++) //comparing all 256 ASCII characters
            trans[state][c] = nextState(pat, m, state, c);
}

void find_(string text, string pat)
{
    int m = pat.length() , n = text.length();
    //Creating a transition table for jumps
    vector<vector<int>> trans(m+1,vector<int> (256));//500->represents the no. of characters
    find_trans(pat,trans,m);//function call to generate answer for transition table.
    int state = 0;//0->represents initial state
    for(int i=0;i<n;i++){
        state = trans[state][text[i]];//Reading current literal and taking current state
        if(state==m) cout<<"Match found at index= "<<i-(m-1)<<endl;
    }
}

//Below is the driver program
int main()
{
    string text, pat;
    //Where text-> text to be scanned for the match
    cin>>text>>pat;
    //User input
    find_(text,pat);//function to generate answer as per the algorithm
}
