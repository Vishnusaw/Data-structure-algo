class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();
        string y =s;
        reverse(y.begin(),y.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ans = 0;
                if(s[i] == y[j]){
                    ans = 1 + dp[i+1][j+1];
                }else{
                    ans = max(dp[i+1][j],dp[i][j+1]);
                }
                
                dp[i][j] = ans;
            }
        }
        return n-dp[0][0];
        
    }
};
