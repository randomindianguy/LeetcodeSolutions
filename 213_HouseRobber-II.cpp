class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) //if the vector is empty, then return null
            return 0;
        if(n == 1) //if size of vector = 1, then return first element.
            return nums[0];
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1)); /*given in qeustion is the fact that
                                                                the first and last houses are adjacent.
                                                                so we try to mitigate this by checking which has
                                                                 a larger output by starting from the first house
                                                                 ending with the second last, and starting with the 
                                                                 second element and ending with the last.*/
    }
    private: 
    int robber(vector<int>& nums, int l, int r){
        int pre = 0, cur = 0;
        for(int i = l; i <= r; i++){    
            int temp = max(pre + nums[i], cur); //checking the max between the current value and
                                                //a previous value + nums at current index
            pre = cur;  //giving the current value to cur
            cur = temp; //giving the temp value to current
        }
        return cur; //returning the current value as it gives the latest max value.
    }
    
};