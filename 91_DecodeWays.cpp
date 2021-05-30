class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0 || s[0] == '0') return 0;  //if string is empty, or the first character is 0, return 0
        if(n == 1) return 1; //if string has 1 element and is not zero, return 1.
        int count1 = 1, count2 = 1; //initializing counts 
        for(int i = 1; i < n; i++){
            int d = s[i] - '0'; //getting the first postition in int form
            int dd = (s[i-1]-'0')*10 + d; //getting the tenth position in int form
            int count = 0; //declaring & initializing variable count
            if(d > 0) count += count2; //checking if the first position is greater than 0, and adding
            if(dd <= 26 && dd>= 10) count += count1; //if the tenth position is greater than 10, and smaller than 26
                                                     //add count1 to count
            count1 = count2;    //replace count1 with count2
            count2 = count;     //replace count2 with count
        }
        return count2;  //return count as it has the newest updated value.
    }
};