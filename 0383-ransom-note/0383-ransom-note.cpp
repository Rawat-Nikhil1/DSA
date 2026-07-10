class Solution {
public:

    bool note(unordered_map<char,int>need , unordered_map<char,int>have){
        for(auto i : need){
            char c = i.first;
            int fNeed = i.second;
            int fHave = have[c];

            if(fHave < fNeed){
                return false;
            }
        }
        return true;
    }
        

    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>need;
        unordered_map<char,int>have;

        int n = ransomNote.length();
        int m = magazine.length();

        for (int i = 0; i < n; i++){
            need[ransomNote[i]]++;
        }

        for (int i = 0; i < m; i++){
            have[magazine[i]]++;
        }
        return note(need,have);
    }
};