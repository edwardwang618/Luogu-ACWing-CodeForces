using namespace std;

class Solution {
public:
    string replaceSpaces(string &str) {
        string res;
        for (int i = 0; i < str.size(); i++) 
            if (str[i] == ' ') res += "%20";
            else res += str[i];

        return res;
    }
};