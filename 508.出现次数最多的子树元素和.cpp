/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, unordered_map<int, int> &map, int &maxCount) {
        if (!root) return 0;
        root -> val = root -> val + helper(root -> left, map, maxCount) + helper(root -> right, map, maxCount);
        map[root -> val]++;
        maxCount = max(maxCount, map[root -> val]);
        return root -> val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ret;
        unordered_map<int, int> map;
        int maxCount = 0;
        if (!root) return ret;
        helper(root, map, maxCount);
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            if (it -> second == maxCount) ret.push_back(it -> first);
        }
        return ret;
    }
};
// @lc code=end

