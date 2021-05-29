class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(s, res, path, 0); //passing res and path vector, along with a starting position and the initial string. 
        return res;
    }
    
    void helper(string s, vector<vector<string>>& res, vector<string>& path, int pos){
        if(pos >= s.length()){
            res.push_back(path);
            return; //if position is greater than the length of the string, push path into string.
        }
        
        for(int i = pos; i < s.length(); i++){      //for all other cases, 
            if(isPal(s, pos, i)){                   //first check if the string is palidrome.
                path.push_back(s.substr(pos, i-pos+1)); //push into path from inital position to position where pal holds true
                helper(s, res, path, i+1); //call helper and move to next index
                path.pop_back();    // pop all those that are left over.
            }
        }
    }
    
    bool isPal(string s, int start, int end){ //function checks whether string is palindrome and returns bool
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};