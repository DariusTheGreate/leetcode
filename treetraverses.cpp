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
#include <stack>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> stack;
        
        TreeNode* node = root;
        while(node || stack.size()){
            if(node){
                result.push_back(node -> val);
                stack.push(node);
                node = node->left;
            }
            else{
                node = stack.top();
                stack.pop();
                node = node -> right;
            }
            
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> history;
        TreeNode* current = root;
        while(current || history.size()){
            if(current){
                history.push(current);
                current = current -> left;
            }
            else{
                current = history.top();
                history.pop();
                result.push_back(current->val);
                current = current -> right;
            }
        }
        
        return result;
    }
private:
    vector<int> traverse;
};