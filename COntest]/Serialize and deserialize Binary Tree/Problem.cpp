#include <vector>
#include <queue>

using namespace std;

TreeNode* deserialize(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

vector<int> serialize(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current) {
            result.push_back(current->val);
            q.push(current->left);
            q.push(current->right);
        } else {
            result.push_back(-1);
        }
    }

    while (!result.empty() && result.back() == -1) {
        result.pop_back();
    }

    return result;
}