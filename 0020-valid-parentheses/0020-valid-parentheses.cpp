class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        int n = str.size();

        for (int i = 0; i < n; i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(str[i]);
            }

            else {
                if (st.size() == 0)
                    return false;

                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '[' && str[i] == ']')
                    || (st.top() == '{' && str[i]=='}')){
                    st.pop();
                } else{
                    return false;
                }
            }
        }
        return st.size() == 0;

    }
};