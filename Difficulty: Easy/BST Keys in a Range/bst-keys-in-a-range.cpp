/* Structure of tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    void nodeinrange(Node* root, int &low, int &high, vector<int>& ans){
        if(root == NULL){
            return;
        }
        
        if(root -> data >= low && root -> data <= high){
            ans.push_back(root -> data);
        }
        
        if(low <= root -> data){
            nodeinrange(root -> left, low, high, ans);
        }
        
        if(high >= root -> data){
            nodeinrange(root -> right, low, high, ans);
        }
    }
    
    vector<int> nodesInRange(Node *root, int low, int high) {
        vector<int> ans;
        nodeinrange(root, low, high, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};