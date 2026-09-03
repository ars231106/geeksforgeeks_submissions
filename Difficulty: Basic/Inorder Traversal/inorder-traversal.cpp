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
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        stack<bool> vis;

        if(root == NULL){
            return ans;
        }

        st.push(root);
        vis.push(0);

        while(!st.empty()){
            Node* temp = st.top();
            st.pop();

            bool flag = vis.top();
            vis.pop();

            if(flag == 0){
                if(temp->right != NULL){
                    st.push(temp->right);
                    vis.push(0);
                }

                st.push(temp);
                vis.push(1);

                if(temp->left != NULL){
                    st.push(temp->left);
                    vis.push(0);
                }
            }
            else{
                ans.push_back(temp->data);
            }
        }

        return ans;
    }
};