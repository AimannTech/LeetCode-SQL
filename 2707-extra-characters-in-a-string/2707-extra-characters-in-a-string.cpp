class Solution {
public:
    unordered_map<string, int> mp;
    int solve(int i, int prev, string &s, vector<vector<int>> &dp)
    {
        int case1 = 1e9, case2 = 1e9;
        string temp = s.substr(prev, i - prev + 1);
        if(i == s.size() - 1)
        {
            if(mp[temp])
                return 0;
            
            return (i - prev + 1);
        }
        
        if(dp[i][prev] != -1)
            return dp[i][prev];
        
        if(mp[temp])
        {
            case1 = solve(i + 1, i + 1, s, dp);
            case2 = solve(i + 1, prev, s, dp);
            return dp[i][prev] = min(case1, case2);
        }
        else
        {
            case1 = (i - prev + 1) + solve(i + 1, i + 1, s, dp);
            case2 = solve(i + 1, prev, s, dp);
            return dp[i][prev] = min(case1, case2);
        }
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        mp.clear();
        for(auto word : dictionary)
            mp[word]++;
        
        return solve(0, 0, s, dp);
    }
};