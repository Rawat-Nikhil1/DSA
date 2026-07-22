class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        vector<char> vowels;

        for (char ch : s) {
            if (isVowel(ch))
                vowels.push_back(ch);
        }

        reverse(vowels.begin(), vowels.end());

        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};