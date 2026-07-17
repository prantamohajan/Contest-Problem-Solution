#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    void populateParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if (!root || !target) return result;
        
        if (k == 0) {
            result.push_back(target->val);
            return result;
        }

        unordered_map<TreeNode*, TreeNode*> parent_track;
        populateParents(root, parent_track);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited.insert(target);
        int current_level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (current_level == k) break;
            current_level++;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();
                
                if (current->left && visited.find(current->left) == visited.end()) {
                    q.push(current->left);
                    visited.insert(current->left);
                }
                if (current->right && visited.find(current->right) == visited.end()) {
                    q.push(current->right);
                    visited.insert(current->right);
                }
                if (parent_track.count(current) && visited.find(parent_track[current]) == visited.end()) {
                    q.push(parent_track[current]);
                    visited.insert(parent_track[current]);
                }
            }
        }

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        
        return result;
    }
};