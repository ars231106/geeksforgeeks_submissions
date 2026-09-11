class Solution {
  public:

    int priority(char x){
        if(x=='^')
            return 3;

        if(x=='*' || x=='/')
            return 2;

        if(x=='+' || x=='-')
            return 1;

        return 0;
    }

    string infixToPostfix(string& s) {

        string ans="";
        stack<char> st;

        for(int i=0;i<s.size();i++){

            if((s[i]>='a' && s[i]<='z') ||
               (s[i]>='A' && s[i]<='Z') ||
               (s[i]>='0' && s[i]<='9')){

                ans+=s[i];
            }

            else if(s[i]=='('){
                st.push(s[i]);
            }

            else if(s[i]==')'){

                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }

                st.pop();
            }

            else{

                while(!st.empty() &&
                      st.top()!='(' &&
                      (priority(st.top())>priority(s[i]) ||
                      (priority(st.top())==priority(s[i]) && s[i]!='^'))){

                    ans+=st.top();
                    st.pop();
                }

                st.push(s[i]);
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};