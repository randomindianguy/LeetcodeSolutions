class Solution {
public:
    
    //Time Complexity: O(n+m)
    //Space Complexity: O(n+m)
    void setZeroes(vector<vector<int>>& matrix) {
        bool isColZero = false;
        bool isRowZero = false;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i < n; i++)
            if(matrix[i][0] == 0){ //if any of the elements in the first column is 0,
                isColZero = true; //set iscolzero to true and break
                break;
            }
        
        for(int j = 0; j < m; j++)
            if(matrix[0][j] == 0){ //if any of the elements in the first row is 0
                isRowZero = true; //set isrowzero to true and break
                break;
            }
        
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                if(matrix[i][j] == 0){ //if the middle element is zero
                    matrix[i][0] = 0;
                    matrix[0][j] = 0; //set the element of column, and                                                       //element of row to be 0.
                }
        
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0; //if either ith, or jth row/column = 0, set middle element to zero.
        
        if(isColZero)
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0; //check if col is zero, if it's true, then set all elements of col to zero
        if(isRowZero)
            for(int i = 0; i < m; i++)
                matrix[0][i] = 0; //check if row is zero. if true, set all elements of row to be zero.
    }
};
