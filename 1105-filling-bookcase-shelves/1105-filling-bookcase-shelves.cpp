class Solution {
public:
    int n;
    int WIDTH;
    int t[1001][1001];
    
    int solve(vector<vector<int>>& books,int i, int remWd, int MaxHt){
        if(i>=n){
            return MaxHt;
        }
        
        if(t[i][remWd]!=-1){
            return t[i][remWd];
        }
        
        int bookW = books[i][0];
        int bookH = books[i][1];
        
        int keep = INT_MAX;
        int skip = INT_MAX;
        
        if(bookW <= remWd){
            keep = solve(books, i+1, remWd - bookW, max(MaxHt, bookH));
        }
        
        skip = MaxHt + solve(books, i+1, WIDTH - bookW, bookH);
        
         return t[i][remWd] = min(keep, skip);
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(t, -1, sizeof(t));
        n = books.size();
        WIDTH = shelfWidth;
        
        int remWd = shelfWidth;
        return solve(books, 0, remWd, 0);
        
    }
};