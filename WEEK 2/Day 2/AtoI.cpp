class Solution {
public:
    int MAX = INT_MAX;
    int MIN = INT_MIN;

    int recursiveAtoi(string s, int index, int sign, long ans) {
        // Base case: if we've processed the entire string or found a non-digit
        if (index >= s.size() || !isdigit(s[index])) {
            return ans * sign;
        }

        // Convert the current character to its integer value
        ans = ans * 10 + (s[index] - '0');
        
        // Check for overflow or underflow
        if (sign == -1 && -ans < MIN) return MIN;
        if (sign == 1 && ans > MAX) return MAX;

        // Recursive call for the next character
        return recursiveAtoi(s, index + 1, sign, ans);
    }

    int myAtoi(string s) {
        if (s.size() == 0) return 0;

        // Step 1: Ignore leading whitespace
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check if the next character is a sign
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Recursively process the digits
        return recursiveAtoi(s, i, sign, 0);
    }
};
