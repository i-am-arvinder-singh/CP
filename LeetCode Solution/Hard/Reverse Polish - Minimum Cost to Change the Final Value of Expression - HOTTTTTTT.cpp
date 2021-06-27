struct Node{
    // Node(char ch_){
    //     ch=ch_;
    // }
    char ch=' ';
    int cnt0=INT_MAX;
    int cnt1=INT_MAX;
};

class Solution {
public:
    int minOperationsToFlip(string expression) {
        stack<char> st;
        vector<char> v;
        for(auto ele:expression){
            if(ele=='&' || ele=='|'){
                while(!st.empty() && st.top()!='('){
                    v.push_back(st.top());
                    st.pop();
                }
                st.push(ele);
            }
            else if(ele=='(')
                st.push(ele);
            else if(ele==')'){
                while(!st.empty() && st.top()!='('){
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else{
                st.push(ele);
            }
        }
        
        
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        
        int n = v.size();
        
        
        
        vector<Node> dp(n);
        stack<Node> node_stack;
        
        // for(auto ele:v)
        //     cout<<ele<<" ";
        
        for(int i=0;i<n;i++){
            if(v[i]=='1'){
                dp[i].ch='1';
                dp[i].cnt0=1;
                dp[i].cnt1=0;
                node_stack.push(dp[i]);
            }
            else if(v[i]=='0'){
                dp[i].ch='0';
                dp[i].cnt0=0;
                dp[i].cnt1=1;
                node_stack.push(dp[i]);
            }
            else if(v[i]=='|'){
                Node v1 = node_stack.top();
                node_stack.pop();
                Node v2 = node_stack.top();
                node_stack.pop();
                
                Node newNode;
                newNode.ch='|';
                //0|0
                newNode.cnt0=v1.cnt0+v2.cnt0;
                //0|1
                newNode.cnt1=v1.cnt0+v2.cnt1;
                //1|0
                newNode.cnt1=min(newNode.cnt1,v1.cnt1+v2.cnt0);
                //1|1
                newNode.cnt1=min(newNode.cnt1,v1.cnt1+v2.cnt1);
                
                //0&0
                newNode.cnt0=min(newNode.cnt0,v1.cnt0+v2.cnt0+1);
                //0&1
                newNode.cnt0=min(newNode.cnt0,v1.cnt0+v2.cnt1+1);
                //1&0
                newNode.cnt0=min(newNode.cnt0,v1.cnt1+v2.cnt0+1);
                //1&1
                newNode.cnt1=min(newNode.cnt1,v1.cnt1+v2.cnt1+1);
                
                node_stack.push(newNode);
            }
            else if(v[i]=='&'){
                Node v1 = node_stack.top();
                node_stack.pop();
                Node v2 = node_stack.top();
                node_stack.pop();
                
                Node newNode;
                newNode.ch='&';
                //0|0
                newNode.cnt0=v1.cnt0+v2.cnt0+1;
                //0|1
                newNode.cnt1=v1.cnt0+v2.cnt1+1;
                //1|0
                newNode.cnt1=min(newNode.cnt1,v1.cnt1+v2.cnt0+1);
                //1|1
                newNode.cnt1=min(newNode.cnt1,v1.cnt1+v2.cnt1+1);
                
                //0&0
                newNode.cnt0=min(newNode.cnt0,v1.cnt0+v2.cnt0);
                //0&1
                newNode.cnt0=min(newNode.cnt0,v1.cnt0+v2.cnt1);
                //1&0
                newNode.cnt0=min(newNode.cnt0,v1.cnt1+v2.cnt0);
                //1&1
                newNode.cnt1=min(newNode.cnt1,v1.cnt1+v2.cnt1);
                
                node_stack.push(newNode);
            }
            
        }
        
        Node t = node_stack.top();
        return max(t.cnt0,t.cnt1);
    }
};









