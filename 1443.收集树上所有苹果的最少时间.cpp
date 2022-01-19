/*
 * @lc app=leetcode.cn id=1443 lang=cpp
 *
 * [1443] 收集树上所有苹果的最少时间
 */

// @lc code=start
class Solution {
public:
    
    unordered_map<int, bool> visited;
    
    int dfs(int cur, int cost, vector<bool>& hasApple, vector<vector<int>>& g) {
        if (visited[cur]) return 0;
        visited[cur] = true;
        int childCost = 0;
        for (auto i : g[cur]) childCost += dfs(i, 2, hasApple, g);
        if (childCost == 0 && !hasApple[cur]) return 0;
        return childCost + cost;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n, vector<int>());
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(0, 0, hasApple, g);
    }
};
// @lc code=end

