// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.



// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        helper(digits, 0, "", res);
        return res;
    }
    
    void helper(string digits, int startIdx, string curSol, vector<string> &res) {
        if(startIdx == digits.size()) {
            res.push_back(curSol);
            return;
        }
        
        string curStr = getStr(digits[startIdx]);
        if(curStr.size() == 0) 
            helper(digits, startIdx+1, curSol, res);
        for(int i = 0; i < curStr.size(); ++i) {
            helper(digits, startIdx+1, curSol+curStr[i], res);
        }
    }
    
    string getStr(char c) {
        switch(c) {
            case '0':
            case '1':
                return "";
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
        }
        return "";
    }
};
