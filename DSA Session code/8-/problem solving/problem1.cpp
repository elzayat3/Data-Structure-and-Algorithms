#include <string>


#include <vector>

using namespace std;

class Solution {
public:

    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "", str2 = "";

        for (const string& str:word1) 
        {
            str1 += str;
        }
        for (const string& str:word2)
        {
            str2 += str;

        } 

        return str1 == str2;
    }
};