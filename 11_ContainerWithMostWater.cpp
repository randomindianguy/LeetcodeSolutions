class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_area = 0;
        while(l < r){
            int lh = height[l];
            int rh = height[r];
            max_area = max(max_area, (r-l)*min(rh,lh));
            //finding the max of max_area and the product of difference between the two ends
            //and min of the two heights
            if(lh < rh) l++;  //if left height is smaller than right, then move left by one.
            else r--; //else decrease right by one.
    }
        return max_area;
    }
};