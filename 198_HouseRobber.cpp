class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)  //if the vector is empty, then return null
            return {};
        if(nums.size() == 1)  //if size of vector = 1, then return first element.
            return nums[0];
        vector<int> dp(nums.size(), 0); //initializing a dp
        dp[0] = nums[0];            // putting the first element of the nums vector in the dp.
        dp[1] = max(nums[0], nums[1]); //second element in dp will be the max of the first and second element in nums vector,
        for(int i = 2; i < nums.size(); i++) 
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); //since the question mentions that the robber cannot rob two adjacent houses
                                                         //we use this to determine which sequence of houses will provide for the maximum output.
        return dp[nums.size() - 1];  //we return the last element in the dp because that's where the max amount is stored.
    }
};