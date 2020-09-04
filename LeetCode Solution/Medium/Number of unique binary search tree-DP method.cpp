class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+2,0);
        G[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                G[i]+=(G[j-1]*G[i-j]);
            }
        }
        return G[n];
    }
};