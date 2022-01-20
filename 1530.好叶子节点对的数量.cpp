/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 *
 * [1530] 好叶子节点对的数量
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
    int ret = 0;
    vector<int> helper(TreeNode* root, int d) {
        vector<int> p = {};
        if (!root) return p;
        vector<int> left = helper(root -> left, d);
        vector<int> right = helper(root -> right, d);
        if (left.size() == 0 && right.size() == 0) {
            p.push_back(1);
            return p;
        }
        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                if (left[i] + right[j] <= d) ret++;
            }
        }
        for (int i = 0; i < left.size(); i++) {
            left[i]++;
            p.push_back(left[i]);
        }
        for (int i = 0; i < right.size(); i++) {
            right[i]++;
            p.push_back(right[i]);
        }
        return p;
    }
    int countPairs(TreeNode* root, int distance) {
        ret = 0;
        helper(root, distance);
        return ret;
    }
};
// @lc code=end

