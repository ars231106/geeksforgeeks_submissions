/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        vector<int> ans;
        queue<Node*> q;

        if(root == NULL)
            return ans;

        q.push(root);
        ans.push_back(root->data);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp->left != NULL){
                ans.push_back(temp->left->data);
                q.push(temp->left);
            }

            if(temp->right != NULL){
                ans.push_back(temp->right->data);
                q.push(temp->right);
            }
        }

        return ans;
    }
};