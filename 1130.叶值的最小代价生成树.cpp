/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
 */

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ret = 0;
        vector<int> st;
        st.push_back(INT_MAX);
        for (int i = 0; i < arr.size(); i++) {
            while (arr[i] > st.back()) {
                int tmp = st.back();
                st.pop_back();
                ret += tmp * min(arr[i], st.back());
            }
            st.push_back(arr[i]);
        }
        for (int i = 2; i < st.size(); i++) 
            ret += st[i] * st[i - 1];
        return ret;
    }
};
// @lc code=end

