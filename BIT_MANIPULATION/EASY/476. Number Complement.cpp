auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int findComplement(int num) {
        if (num == 0) {
            return 1;
        }
        long bitLength = log2(num) + 1;
        long bitmask = long(1 << bitLength) - 1;
        return num ^ bitmask;
    }
};
