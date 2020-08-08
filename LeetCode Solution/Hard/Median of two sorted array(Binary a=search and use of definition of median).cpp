class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        if(num1.size()>num2.size()) return findMedianSortedArrays(num2,num1);
        int len1 = num1.size();
        int len2 = num2.size();
        int left = 0, right = len1;//left|| right denotes partition 
        while(left<=right){
            int par1 = (left+right)>>1;
            int par2 = (len1+len2+1)/2-par1;//partition
            int inf = INT_MAX;
            
            int left1 = (par1==0)?-inf:num1[par1-1];
            int right1 = (par1==len1)?inf:num1[par1];
            
            int left2 = (par2==0)?-inf:num2[par2-1];
            int right2 = (par2==len2)?inf:num2[par2];
            
            if(left1<=right2 && left2<=right1){
                if((len1+len2)&1) return (double)max(left1,left2);
                else return (double)(max(left1,left2)+min(right1,right2))/2.0;
            }
            else if(left1>right2) right = par1-1;
            else if(right1<left2) left = par1+1; 
        }
        return 0.0;
    }
};