/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Box {
  public:
    int size;
    bool isValidBST;
    int min_val;
    int max_val;

    Box(int size, bool isValidBST, int min_val, int max_val){
        this->size = size;
        this->isValidBST = isValidBST;
        this->min_val = min_val;
        this->max_val = max_val;
    }
};

class Solution {
  public:
    Box solve(Node* root){
        if(root == NULL){
            return Box(0,true,INT_MAX,INT_MIN);
        }

        Box leftside = solve(root->left);
        Box rightside = solve(root->right);

        if(leftside.isValidBST && rightside.isValidBST &&
           root->data > leftside.max_val &&
           root->data < rightside.min_val){

            int size = leftside.size + rightside.size + 1;
            int min_val = min(root->data,leftside.min_val);
            int max_val = max(root->data,rightside.max_val);

            return Box(size,true,min_val,max_val);
        }

        return Box(max(leftside.size,rightside.size),false,INT_MIN,INT_MAX);
    }

    int largestBst(Node *root) {
        Box result = solve(root);
        return result.size;
    }
};