
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
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

    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> que;
        std::vector<std::vector<int>> result;
        std::vector<int> curr_layer;
        if(!root)
            return 
        que.push(root);
        que.push(nullptr);
        while(que.size()){
            TreeNode* curr = que.front();
            que.pop();
            if(curr != nullptr){
                curr_layer.push_back(curr->val);
                if(curr -> left)
                    que.push(curr -> left);
                if(curr -> right)
                    que.push(curr -> right);
            }
            else{
                result.push_back(curr_layer);
                curr_layer.resize(0);
                if(que.size() > 0)
                    que.push(nullptr);
            }
                
        }
            
        return result;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if(!root)
            return result;
        std::queue<TreeNode*> path;
        std::vector<int> layer;
        path.push(root);
        TreeNode* curr;
        while(path.size()){
            int path_size = path.size();
            for(size_t i = 0; i < path_size; ++i){
                curr = path.front();
                path.pop();
                layer.push_back(curr->val);
                
                if(curr->left)
                    path.push(curr->left);
                
                if(curr->right)
                    path.push(curr->right);
                
            }
            
            result.push_back(layer);
            layer.resize(0);
        }
        
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        /*std::vector<int> res;
        std::stack<TreeNode*> path;
        TreeNode* curr = root;
        while(curr || path.size()){
            if(curr){
                path.push(curr);
                curr = curr -> left;
            }
            else{
                curr = path.top();
                path.pop();
                curr = curr -> right;
            }
        }
        return res;*/
        
        std::vector<int> res;
        if(!root)
            return res;
        std::stack<TreeNode*> up_bottom;
        std::stack<TreeNode*> bottom_up;
        up_bottom.push(root);
        while(up_bottom.size()){
            TreeNode* curr = up_bottom.top();
            bottom_up.push(curr);
            up_bottom.pop();
            if(curr -> left)
                up_bottom.push(curr -> left);
            if(curr -> right)
                up_bottom.push(curr->right);
        }
        
        while(bottom_up.size()){
            TreeNode* curr = bottom_up.top();
            bottom_up.pop();
            res.push_back(curr->val);
        }
        
        return res;
    }

    int maxDepthRecur(TreeNode* root) {
        return getMaxDepth(root, 1);
    }
    
    int getMaxDepth(TreeNode* head, int&& val){
        if(!head)
            return val-1;
        std::cout << head -> val << " " << val << "\n";
        return std::max(getMaxDepth(head->left, val+1), getMaxDepth(head->right, val+1));
    }
    
    //kinda bad need to fix this branches
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        std::queue<TreeNode*> nodes;
        TreeNode* curr_left;
        TreeNode* curr_right;
        
        nodes.push(root->left);
        nodes.push(root->right);
        
        while(nodes.size()){
            curr_left = nodes.front();
            nodes.pop();
            curr_right = nodes.front();
            nodes.pop();
            if(curr_left != curr_right && !(curr_left && curr_right))
                return false;
            if(!curr_right && !curr_left)
                continue;
                
            std::cout << curr_left->val << " " << curr_right -> val << "\n";
            
            if(curr_left -> val != curr_right -> val)
                return false;
            
            nodes.push(curr_left -> left);
            nodes.push(curr_right -> right);
            nodes.push(curr_left -> right);
            nodes.push(curr_right -> left);
            
        }
        return true;
    }
};