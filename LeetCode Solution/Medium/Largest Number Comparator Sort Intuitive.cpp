class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a, int b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            string t1 = s1;
            t1+=s2;
            string t2 = s2;
            t2+=s1;
            if(t1>t2) return true;
            else return false;
        });
        string ans;
        for(auto ele:nums) ans+=to_string(ele);
        int n = ans.length();
        int i = 0;
        while(i+1<n && ans[i]=='0') i++;
        ans=ans.substr(i);
        return ans;
    }
};