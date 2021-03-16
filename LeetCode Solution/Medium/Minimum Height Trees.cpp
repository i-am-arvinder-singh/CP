class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        vector<int> ans;
        vector<vector<int>> edges(n);
        for(int i=0;i<e.size();i++){
            edges[e[i][0]].push_back(e[i][1]);
            edges[e[i][1]].push_back(e[i][0]);
        }
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        int leaf = 0;
        int gmax = 0;
        std::function<void(int,int,int)> dfs1 = [&](int node, int p, int m){
            bool isLeaf = true;
            for(auto child:edges[node]){
                if(child==p) continue;
                isLeaf = false;
                dfs1(child,node,m+1);
            }
            if(isLeaf){
                if(m>gmax){
                    gmax=m;
                    leaf=node;
                }
            }
        };
        dfs1(0,-1,0);
        vector<int> label(n);
        std::function<int(int,int)> dfs2 = [&](int node, int p){
            int ret = 0;
            for(auto child:edges[node]){
                if(child==p) continue;
                ret=max(ret,dfs2(child,node));
            }
            return label[node] = ret+1;
        };
        dfs2(leaf,-1);
        int max_val = INT_MIN;
        for(int i=0;i<n;i++){
            max_val=max(max_val,label[i]);
        }
        vector<int> dia;
        std::function<void(int,int,int)> dfs3 = [&](int node, int p, int m){
            dia.push_back(node);
            int child_node;
            bool check_child = true;
            for(auto child:edges[node]){
                if(child==p) continue;
                check_child=false;
                if(label[child]==m) child_node = child;
            }
            if(!check_child) dfs3(child_node,node,m-1);
        };
        dfs3(leaf,-1,max_val-1);
        int dia_size = dia.size();
        if(dia_size&1){
            ans.push_back(dia[dia_size/2]);
        } else {
            int a = dia_size/2;
            int b = a-1;
            ans.push_back(dia[b]);
            ans.push_back(dia[a]);
        }
        return ans;
    }
};