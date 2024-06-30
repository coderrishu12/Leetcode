class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1=nums1.size(), n2=nums2.size();
        int i =  0,     j=0;
        int idx2 = (n1+n2)/2, idx1= ((n1+n2)/2)-1;
        int k=0;
        int ele1=-1, ele2=-1;
        
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(k==idx1){
                    ele1=nums1[i];
                }else if(k==idx2){
                    ele2=nums1[i];
                }
                i++;
            }else{
                if(k==idx1){
                    ele1=nums2[j];
                }else if(k==idx2){
                    ele2=nums2[j];
                }
                j++;
            }
            k++;
        }
        
        while(i<n1){
            if(k==idx1){
                    ele1=nums1[i];
                }else if(k==idx2){
                    ele2=nums1[i];
                }
                i++;
            k++;
        }
        
        while(j<n2){
            if(k==idx1){
                    ele1=nums2[j];
                }else if(k==idx2){
                    ele2=nums2[j];
                }
                j++;
            k++;
        }
        
        if(((n1+n2)%2)==1){
            return ele2;
        }
        
        return (ele1+ele2)/2.0;
        
        
        // int n1=nums1.size(), n2=nums2.size();
        // int i=0, j=0;
        // vector<int> nums3;
        // while(i<n1 && j<n2){
        //     if(nums1[i]<nums2[j]) nums3.push_back(nums1[i++]);
        //     else nums3.push_back(nums2[j++]);
        // }
        // while(i<n1) nums3.push_back(nums1[i++]);
        // while(j<n2) nums3.push_back(nums2[j++]);
        // int n = (n1 + n2);
        // if(n%2==1){
        //     return nums3[n/2];
        // }
        // return (nums3[n/2] + nums3[n/2-1])/2.0;
    }
};