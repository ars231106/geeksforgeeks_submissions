class Solution {
  public:
    int gcd(int a, int b) {
        if(b == 0){
            return a;
        }
        int result = gcd(b, a % b);
        return result;
    }
};
