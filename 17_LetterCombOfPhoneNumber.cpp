class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        vector<string> dict {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        //initialize the letters attached to each number.
        helper(digits, res, dict, "", 0); //call function
        return res;
    }
    
    void helper(string digits, vector<string>& res, vector<string>& dict, string path, int pos){
        if(pos == digits.size()){ //if position == number of digits, then push path to result.
            res.push_back(path);
            return;
        }
        string str = dict[digits[pos] - '0']; //to make numbers to ascii
        for(int i = 0; i < str.size(); i++){ 
            path.push_back(str[i]); //push string to path
            helper(digits, res, dict, path, pos+1); //call function
            path.pop_back(); //pop from back.
        }
    }
};