class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> lower;
        stack<int> upper;
        
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        
        int lowerBound, upperBound;
        
        for(int i = 0; i<arr.size(); i++){
            //condition 1: less than lower bound
            if(arr[i] < lower.top()){
                return false;
            }
            
            
            //condition 2: greater than upperbound
            while(arr[i] > upper.top()){
                upper.pop();
                lower.pop();
            }
            
            //condition 3: in range
            lowerBound = lower.top();
            upperBound = upper.top();
            
            lower.push(arr[i]);
            upper.push(upperBound);
            
            lower.push(lowerBound);
            upper.push(arr[i]);
            
        }
       
       return true; 
        
    }
};