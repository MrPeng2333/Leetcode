/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 *
 * [1261] 在受污染的二叉树中查找元素
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
class FindElements {
public:
    unordered_set<int> set;
    void recover(TreeNode* root, int val = 0) {
        if (!root) return;
        root -> val = val;
        set.emplace(val);
        recover(root -> left, (val << 1) + 1);
        recover(root -> right, (val << 1) + 2);
    }
    FindElements(TreeNode* root) {
        recover(root);
    }
    
    bool find(int target) {
        return set.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

