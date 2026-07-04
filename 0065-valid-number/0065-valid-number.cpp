class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();

        while (i < n && s[i] == ' ') i++;
        if (i == n) return false;

        if (s[i] == '+' || s[i] == '-') i++;

        bool num = false, dot = false, exp = false;

        while (i < n) {
            char c = s[i];

            if (isdigit(c)) {
                num = true;
            } else if (c == '.') {
                if (dot || exp) return false;
                dot = true;
            } else if (c == 'e' || c == 'E') {
                if (exp || !num) return false;
                exp = true;
                num = false;
                if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-'))
                    i++;
            } else if (c == ' ') {
                while (i < n && s[i] == ' ') i++;
                return i == n && num;
            } else {
                return false;
            }

            i++;
        }

        return num;
    }
};