class Solution {
public:
    void rev(vector<char>& s, int low, int high) {
        if (low >= high)
            return;

        swap(s[low], s[high]);
        rev(s, low + 1, high - 1);
    }

    void reverseString(vector<char>& s) {
        rev(s, 0, s.size() - 1);
    }
};