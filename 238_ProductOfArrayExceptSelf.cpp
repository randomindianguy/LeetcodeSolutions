class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int pro = 1;
        for(int i = 0; i < n; i++){
            pro *= nums[i];         //finding cumulative product from start->end
            res.push_back(pro); 
        }
        pro = 1;
        for(int i = n-1; i > 0; i--){
            res[i] = res[i-1] * pro;  
            pro *= nums[i];  //finding cumulative product from end->start
        }
        res[0] = pro;       //second element in the result is the product of array 
                            //except first element
        return res;
    }
};