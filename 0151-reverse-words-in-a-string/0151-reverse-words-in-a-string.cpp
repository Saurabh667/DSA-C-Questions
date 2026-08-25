class Solution {
public:
    string reverseWords(string s) {
        string out = "";
        string word = "";

        for (char w : s) {
            if (w == ' ') {
                if (!word.empty()) {
                    if (!out.empty())
                        out = word + " " + out;
                    else
                        out = word;

                    word = "";
                }
            }
            else {
                word.push_back(w);
            }
        }
        if (!word.empty()) {
            if (!out.empty())
                out = word + " " + out;
            else
                out = word;
        }

        return out;
    }
};