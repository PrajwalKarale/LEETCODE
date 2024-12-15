auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    string checkIPV4(string queryIP){
        queryIP.push_back('.');
        stringstream ss(queryIP);
        string block;
        int count = 0;
        while(getline(ss, block, '.')){
            count++;
            if(block.length() > 3 || block.length() == 0){
                return "Neither";
            }
            if(block[0] == '0' && block.length() != 1){
                return "Neither";
            }
            for(char &ch: block){
                if(!isdigit(ch)){
                    return "Neither";
                }
            }
            if(stoi(block) > 255){
                return "Neither";
            }
        }
        return (count == 4 && ss.eof()) ? "IPv4" : "Neither";
    }
    string checkIPV6(string queryIP){
        queryIP.push_back(':');
        stringstream ss(queryIP);
        string block;
        int count = 0;  
        while(getline(ss, block, ':')){
            count++;
            if(block.length() > 4 || block.length() == 0){
                return "Neither";
            }
            for(char &ch: block){
                if(!isxdigit(ch)){
                    return "Neither";
                }
            }
        }
        return (count == 8 && ss.eof()) ? "IPv6" : "Neither";
    }
    string validIPAddress(string queryIP) {
        string result = "";
        int delimiterCount = 0;
        for(char &ch: queryIP){
            if(ch == '.' || ch == ':'){
                delimiterCount += 1;
            }
        }
        if(delimiterCount == 3){
            result = checkIPV4(queryIP);
        }else{
            result = checkIPV6(queryIP);
        }
        return result;
    }
};
