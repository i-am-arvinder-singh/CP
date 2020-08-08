class Solution {
public:
    int n,m;
    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        return f(s,p,0,0);
    }
    bool f(string &s, string &p, int i, int j){
        if(j==m) return i==n;
        if(j==m-1 || p[j+1]!='*') return (i<n && (s[i]==p[j]||p[j]=='.')) && f(s,p,i+1,j+1);
        else if(p[j+1]=='*' && f(s,p,i,j+2)) return true;
        while(i<n && (s[i]==p[j] || p[j]=='.')){
            if(f(s,p,i+1,j+2)) return true;
            i++;
        }
        return false;
    }
};