int maxPathSum(Node* root)
{ 
    // code here
    std::function<int(Node*,Node*,int&)> dfs = [&](Node* now, Node* parent, int &res){
        if(now==NULL) return 0;
        if(now->left==NULL && now->right==NULL) {
            // res=max(res,now->data);
            return now->data;
        }
        if(parent==NULL){
            if(now->left==NULL){
                int t = dfs(now->right,now,res);
                res=max(res,t+now->data);
                return t+now->data;
            }
            else if(now->right==NULL){
                int t = dfs(now->left,now,res);
                res=max(res,t+now->data);
                return t+now->data;
            }
        }
        if(now->right==NULL) return now->data+dfs(now->left,now,res);
        if(now->left==NULL) return now->data+dfs(now->right,now,res);
        int val1 = dfs(now->left,now,res);
        int val2 = dfs(now->right,now,res);
        res=max(res,val1+val2+now->data);
        return max(val1+(now->data),val2+(now->data));
    };
    int ans = -1000000000;
    dfs(root,NULL,ans);
    return ans;
}