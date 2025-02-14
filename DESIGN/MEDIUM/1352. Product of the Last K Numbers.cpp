/*
    Logic:
        1. Prefix Product approach I will follow to take O(1) time.
        2. We will have to think when num == 0. So the solution here is whenever zero is encounter we have to reset the prefix product array.
        3. Because if when product of last k elements is asked and it contains zero it is gonna be zero.
    Time Complexity:
    Space Complexity:
*/
// @lc code=start
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class ProductOfNumbers {
public:
    vector<int>prefixProduct;
    ProductOfNumbers() {
        prefixProduct = {1};
    }
    
    void add(int num) {
        if(num == 0){
            prefixProduct = {1};
        }else{
            prefixProduct.push_back(prefixProduct[prefixProduct.size() - 1] * num);
        }   
    }
    int getProduct(int k) {
        int n = prefixProduct.size();
        if(k >= n) return 0;
        return prefixProduct[n - 1] / prefixProduct[n - k - 1];
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
