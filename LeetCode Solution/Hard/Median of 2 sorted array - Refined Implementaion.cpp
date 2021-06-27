class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0 && nums2.size()==0)
            return 0;
        if(nums1.size()<nums2.size())
            swap(nums1,nums2);
        int n = nums1.size(), m = nums2.size();
        if(nums1.size()==0){
            if(m&1)
                return nums2[m/2];
            else
                return (nums2[m/2]+nums2[m/2-1])/2.0;
        }
        if(nums2.size()==0){
            if(n&1)
                return nums1[n/2];
            else
                return (nums1[n/2]+nums1[n/2-1])/2.0;
        }
        if(nums1.size()==nums2.size()){
            if(nums2.back()<=nums1[0]){
                float ret = (nums2.back()+nums1[0])/2.0;
                return ret;
            }
            else if(nums1.back()<=nums2[0]){
                float ret = (nums1.back()+nums2[0])/2.0;
                return ret;
            }
        }
        int left = 0, right = nums1.size();
        int total = (n+m+1)/2;
        bool isOdd = (n+m)&1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(mid>=total)
                right=mid-1;
            else{
                int elems = total - (mid+1);
                if(!elems){
                    if(nums1[mid]<=nums2[0]){
                        if(isOdd){
                            return nums1[mid];
                        }
                        else{
                            float ret = (nums1[mid]+min(nums2[0],mid+1<n?nums1[mid+1]:INT_MAX))/2.0;
                            return ret;
                        }
                    }
                    else{
                        right = mid-1;
                    }
                }
                else if(elems>nums2.size()){
                    left = mid+1;
                }
                else{
                    int nums2_id = elems-1;
                    int l1 = nums1[mid];
                    int l2 = nums2[nums2_id];
                    int r1 = mid+1<n?nums1[mid+1]:INT_MAX;
                    int r2 = nums2_id+1<m?nums2[nums2_id+1]:INT_MAX;
                    if(max(l1,l2)<=min(r1,r2)){
                        if(isOdd){
                            return max(l1,l2);
                        }
                        else{
                            float ret = (max(l1,l2)+min(r1,r2))/2.0;
                            return ret;
                        }
                    }
                    else{
                        if(l2>r1){
                            left = mid + 1;
                        }
                        if(l1>r2){
                            right = mid - 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};








