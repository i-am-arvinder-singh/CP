bool isround(int x)
{
    if(x>=0){
        string s = to_string(x);
        int l=0,r=s.size()-1;
//        cout<<"***"<<s[l]<<" "<<s[r]<<endl;
        if(s[l]==s[r]) return true;
        else return false;
    }
    return false;
}