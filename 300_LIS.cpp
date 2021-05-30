class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lis[n];  //declaring an array of the same size as the vector.
        lis[0] = 1; //initializing the first element of the array as 1 as the first element alone can become an LIS
        for(int i = 1; i < nums.size(); i++){  //therefore, we've to start with the second element in nums
            lis[i] = 1; //straightaway initialzing the cell as 1
            for(int j = 0; j < i; j++){ //we will be comparing the ith element to the jth element. 
                if(nums[i] > nums[j] && lis[i] <= lis[j]) //the two conditions here are to find the LIS,
                                                          // the second condition is there to stop any additional LISs
                                                          //incase we already find one. 
                    lis[i] = 1 + lis[j]; //we increase the count of LIS by one
            }
        }   
        return *max_element(lis, lis+n); //we return the value of the max element in the LIS array.
    }
};