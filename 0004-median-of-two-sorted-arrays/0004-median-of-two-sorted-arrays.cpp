class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int total = n1 + n2;
    int left = (total + 1) / 2;  // index of the left median
    int right = (total + 2) / 2; // index of the right median (for even total)

    int i = 0, j = 0;
    int count = 0;
    int median1 = 0, median2 = 0;

    while (i < n1 || j < n2) {
        if (j >= n2 || (i < n1 && nums1[i] <= nums2[j])) {
            median1 = nums1[i];
            i++;
        } else {
            median1 = nums2[j];
            j++;
        }
        count++;
        if (count == left)
            median2 = median1;
        if (count == right)
            return (median1 + median2) / 2.0;
    }

    return 0.0; // This line should not be reached under normal circumstances


        
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