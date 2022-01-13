/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    unordered_map<int, int> prefix;
    int helper(TreeNode* root, int target, int currSum = 0) {
       if (!root) return 0;
       currSum += root -> val;
       int ret = 0;
       if (prefix.count(currSum - target)) ret = prefix[currSum - target];
       prefix[currSum]++;
       ret += helper(root -> left, target, currSum);
       ret += helper(root -> right, target, currSum);
       prefix[currSum]--;
       return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return helper(root, targetSum);
    }
};
// @lc code=end

