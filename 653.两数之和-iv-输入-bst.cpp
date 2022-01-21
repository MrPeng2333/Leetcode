/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        TreeNode* t1 = root;
        TreeNode* t2 = root;
        while(1) {
            while (t1) {
                left.push_back(t1);
                t1 = t1 -> left;
            }
            while (t2) {
                right.push_back(t2);
                t2 = t2 -> right;
            }
            if (left.empty() || right.empty()) break;
            t1 = left.back();
            t2 = right.back();
            int sum = t1 -> val + t2 -> val;
            if (sum == k) {
                return t1 == t2 ? false : true;
            }
            if (sum < k) {
                t1 = t1 -> right;
                left.pop_back();
                t2 = nullptr;
            } else {
                t2 = t2 -> left;
                right.pop_back();
                t1 = nullptr;
            }
        }
        return false;
    }
};
// @lc code=end

