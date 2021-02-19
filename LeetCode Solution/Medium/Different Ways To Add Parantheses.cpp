class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> v;
        int n = input.size();
        for(int i=0;i<n;i++){
            char ch = input[i];
            if(ch=='*' || ch=='-' || ch=='+'){
                string a = input.substr(0,i);
                string b = input.substr(i+1);
                vector<int> a_ = diffWaysToCompute(a);
                vector<int> b_ = diffWaysToCompute(b);
                for(auto x:a_){
                    for(auto y:b_){
                        if(ch=='-'){
                            v.push_back(x-y);
                        }
                        else if(ch=='+'){
                            v.push_back(x+y);
                        }
                        else if(ch=='*'){
                            v.push_back(x*y);
                        }
                    }
                }
            }
            
        }
        if(v.size()==0) v.push_back(std::stoi(input));
        return v;
    }
};