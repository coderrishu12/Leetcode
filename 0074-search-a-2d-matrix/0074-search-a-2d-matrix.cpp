class Solution {
public:
    bool lowerBound(vector<int>& arr, int n, int x){
        int low=0, high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]==x) return true;
            if(arr[mid]<x) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        int n=matrix.size();
        for(int i=0;i<n;i++){
            if(lowerBound(matrix[i],m, target)) return true;;
        }
        return false;
    }
};