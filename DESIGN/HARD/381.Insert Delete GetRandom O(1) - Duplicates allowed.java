/*
 * @lc app=leetcode id=381 lang=java
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
class RandomizedCollection {
    List<Integer> list;
    Map<Integer, Set<Integer>> numIndex;
    Random random;
    public RandomizedCollection() {
        list = new ArrayList<>();
        numIndex = new HashMap<>();
        random = new Random();
    }
    
    public boolean insert(int val) {
        boolean response = !numIndex.containsKey(val);
        if(numIndex.containsKey(val) == false){
            numIndex.put(val, new HashSet<Integer>());
        }
        numIndex.get(val).add(list.size());
        list.add(val);
        return response;
    }
    
    public boolean remove(int val) {
        if(numIndex.containsKey(val) == false){
            return false;
        }
        Set<Integer> indexSet = numIndex.get(val);
        int indexToBeRemoved = indexSet.iterator().next();
        if(indexSet.size() == 1){
            numIndex.remove(val);
        }else{
            indexSet.remove(indexToBeRemoved);
        }
        int lastIndex = list.size() - 1;
        if(indexToBeRemoved != lastIndex){
            int lastVal = list.get(lastIndex);
            Set<Integer> lastIndexSet = numIndex.get(lastVal);
            lastIndexSet.add(indexToBeRemoved);
            lastIndexSet.remove(lastIndex);
            list.set(indexToBeRemoved, lastVal);
        }
        list.remove(lastIndex);
        return true;
    }
    
    public int getRandom() {
        return list.get(random.nextInt(list.size()));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
// @lc code=end

