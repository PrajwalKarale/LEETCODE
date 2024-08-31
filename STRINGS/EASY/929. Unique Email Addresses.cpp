class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        unordered_map<string, int>freq;
        for(string &email: emails){
            int positionOfAt = email.find('@');
            string domain = email.substr(positionOfAt);
            string newEmail = "";
            for(int i = 0; i < positionOfAt; i++){
                if(email[i] == '+'){
                    break;
                }
                if(email[i] == '.'){
                    continue;
                }
                newEmail += email[i];
            }
            newEmail = newEmail + domain;
            freq[newEmail]++;
        }
        return freq.size();
    }
};
