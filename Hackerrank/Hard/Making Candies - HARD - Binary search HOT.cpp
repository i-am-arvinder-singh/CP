#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumPasses function below.
long minimumPasses(long m, long w, long p, long n) {
    ////////////////////////////////////SOLUTION STARTS HERE /////////////////////////////////////////
    long left = 0, right = 1e13;
    long ans, down = 1000000;
    
    std::function<bool(long)> f = [&](long mid){
        long m_ = m, w_ = w;
        long passes = 0;
        long track=0;
        while(track<=n){
            if(m_>=down && w_>=down) return 1+passes<=mid;
            //check whether with current m_ and w_ you can reach n with given mid or not
            long temp = n - track;
            // cout<<"********** "<<n<<" "<<track<<" "<<temp<<endl;
            temp = (temp+(m_*w_)-1)/(m_*w_);
            // cout<<"$$$$$$$$$$ "<<m_*w_<<" "<<temp<<endl;
            if(temp+passes<=mid) return true;
            //passes required to reach p
            
            temp = p-track;
            // cout<<"Before: "<<track<<" "<<" Req:  "<<temp<<endl;
            temp = (temp+(m_*w_)-1)/(m_*w_);
            // cout<<"After: "<<track<<" "<<" Req pass :  "<<temp<<" @ "<<m_*w_<<endl;
            passes+=temp;
            if(passes>mid) return false;
            track+=(m_*w_*temp);
            track-=p;
            if(track>n) return false;
            if(m_<w_) m_++;
            else      w_++;
            
            if(track>=p){
                long t = track/p;
                track-=(t*p);
                if(m_<w_){
                    long qq = w_-m_;
                    m_+=min(qq,t);
                    t-=min(qq,t);
                    m_+=(t-(t/2));
                    w_+=(t/2);
                }
                else{
                    long qq = m_-w_;
                    w_+=min(qq,t);
                    t-=min(qq,t);
                    w_+=(t-(t/2));
                    m_+=(t/2);
                }
            }
            
            // cout<<"&&&&&&&& "<<m_<<" "<<w_<<endl;
            
        }
        
        return false;
        
    };
    
    // cout<<f(1000000000000ll)<<endl;
    // cout<<f(999999999999ll)<<endl;
    // cout<<f(2ll)<<endl;
    
    while(left<=right){
        long mid = left + (right-left)/2;
        cout<<mid<<" "<<f(mid)<<endl;
        if(f(mid)){
            ans=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    
    return ans;
    ////////////////////////////////////SOLUTION  ENDS HERE /////////////////////////////////////////
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string mwpn_temp;
    getline(cin, mwpn_temp);

    vector<string> mwpn = split_string(mwpn_temp);

    long m = stol(mwpn[0]);

    long w = stol(mwpn[1]);

    long p = stol(mwpn[2]);

    long n = stol(mwpn[3]);

    long result = minimumPasses(m, w, p, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
