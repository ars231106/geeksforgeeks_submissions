/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        if(root == NULL){
            return ans;
        }

        st.push(root);

        while(!st.empty()){
            Node* temp = st.top();
            st.pop();

            ans.push_back(temp -> data);

            if(temp -> left != NULL){
                st.push(temp -> left);
            }

            if(temp -> right != NULL){
                st.push(temp -> right);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};