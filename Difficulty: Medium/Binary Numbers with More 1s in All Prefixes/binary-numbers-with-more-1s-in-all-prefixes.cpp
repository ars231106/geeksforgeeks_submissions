class Solution {
  public:

    void find(vector<string>& ans, string temp, int n, int zero, int one){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back('1');
        find(ans, temp, n, zero, one + 1);
        temp.pop_back();


        if(zero < one){
            temp.push_back('0');
            find(ans, temp, n, zero + 1, one);
            temp.pop_back();
        }


    }
    vector<string> nBitBinary(int n) {
        vector<string> ans;
        string temp;
        find(ans, temp, n, 0, 0);
        return ans;


    }
};