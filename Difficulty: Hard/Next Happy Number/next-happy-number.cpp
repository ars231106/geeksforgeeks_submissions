class Solution {
  public:

    int sum(int n){

        int ans=0;

        while(n>0){

            int digit=n%10;
            ans+=digit*digit;
            n/=10;
        }

        return ans;
    }

    bool happy(int n){

        while(n!=1 && n!=4)
            n=sum(n);

        return n==1;
    }

    int nextHappy(int n) {

        n++;

        while(true){

            if(happy(n))
                return n;

            n++;
        }
    }
};