/*
 * @lc app=leetcode.cn id=1600 lang=cpp
 *
 * [1600] 皇位继承顺序
 */

// @lc code=start
class ThroneInheritance {
public:
    string king;
    unordered_set<string> dead;
    unordered_map<string, vector<string>> relations;
    vector<string> order;
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        relations[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.emplace(name);
    }
    
    vector<string> getInheritanceOrder() {
        order = {};
        helper(king);
        return order;
    }

    void helper(string parent) {
        if (!dead.count(parent)) order.push_back(parent);
        for (auto child : relations[parent]) {
            helper(child);
        }

    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
// @lc code=end

