/*
 * @lc app=leetcode id=904 lang=java
 *
 * [904] Fruit Into Baskets
 */
/*
    Logic: Sliding Window
    Time Complexity:
        1. O(n) where n = fruits.length
    Space Complexiy:
        1. Since we are using auxiliary space as a HashMap it is O(n)
*/
// @lc code=start
class Solution {
    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        int left = 0;
        int right = 0;
        int totalFruits = 0;
        Map<Integer, Integer> fruitsCount = new HashMap<Integer, Integer>();
        while(right < n){
            fruitsCount.put(fruits[right], fruitsCount.getOrDefault(fruits[right], 0) + 1);
            if(fruitsCount.size() > 2){
                fruitsCount.put(fruits[left], fruitsCount.get(fruits[left]) - 1);
                if(fruitsCount.get(fruits[left]) == 0){
                    fruitsCount.remove(fruits[left]);
                }
                left++;
            }
            totalFruits = Math.max(totalFruits, right - left + 1);
            right++;
        }
        return totalFruits;
    }
}
// @lc code=end

