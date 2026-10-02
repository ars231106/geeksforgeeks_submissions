class Solution {
public:
    void inorder_traversal(Node* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }

        inorder_traversal(root->left, inorder);
        inorder.push_back(root->data);
        inorder_traversal(root->right, inorder);
    }

    bool isBST(Node* root) {
        vector<int> inorder;
        inorder_traversal(root, inorder);

        for(int i = 1; i < inorder.size(); i++){
            if(inorder[i] <= inorder[i-1]){
                return false;
            }
        }

        return true;
    }
};