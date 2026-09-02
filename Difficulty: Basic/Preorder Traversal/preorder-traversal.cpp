/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        stack<Node*> st;
        vector<int> ans;
        st.push(root);
        
        while(!st.empty()){
            Node* temp = st.top();
            st.pop();
            
            ans.push_back(temp -> data);
            
            if(temp -> right != NULL){
                st.push(temp -> right);
            }
            
            if(temp -> left != NULL){
                st.push(temp -> left);
            }
        }
        
        return ans;
    }
};