
class Solution {
public:

bool canWePlace(vector<int> &vec, int dist, int cows){
    int cnt=1, last=vec[0];
    for(int i=1;i<vec.size();i++){
        if(vec[i]-last>=dist){
            cnt++;
        if(cnt>=cows) return true;
            last=vec[i];
        }
    }
    
    return false;
}

    int solve(int N, int C, vector<int> &vec) {
    
        sort(vec.begin(), vec.end());
        // int ans=-1;
        int low=1, high= vec[N-1]- vec[0];
        while(low<=high){
            int mid= low+(high-low)/2;
            if(canWePlace(vec,mid,C)){
                // ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
                // break;
            }
        }
        return high;
    }
};
