struct Node{
    Node* Links[2];

    bool containsKey(int bit){
        return (Links[bit]!=NULL);
    }
    
    void put(int bit, Node* node){
        Links[bit] = node;
    }
    
    Node* get(int bit){
        return Links[bit];
    }

};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    
    
    
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int num){
        Node* node= root;
        int maxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
    
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries){
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> Qlist;
        int n = queries.size();
        for(int i=0;i<n;i++){
            Qlist.push_back({queries[i][1],{ queries[i][0], i}});
        }
        sort(Qlist.begin(), Qlist.end());
        vector<int> ans(n,0);
        int idx = 0;
        int m = nums.size();
        Trie trie;
        for(int i=0;i<n;i++){
            int ai   = Qlist[i].first;
            int xi   = Qlist[i].second.first;
            int qidx = Qlist[i].second.second;
            
            while(idx<m && nums[idx]<=ai){
                trie.insert(nums[idx]);
                idx++;
            }
            
            if (idx == 0) {
                ans[qidx] = -1; 
            } else {
                ans[qidx] = trie.getMax(xi);
            }
        }
        return ans;
    }
};
