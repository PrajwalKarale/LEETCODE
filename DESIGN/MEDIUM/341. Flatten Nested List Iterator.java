/*
 * @lc app=leetcode id=341 lang=java
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
/*
    Logic:
        1. Whenever we are asked Flattening operation at that time we have to proceed using Recursion or by using Stack
    Space Complexity:
        1. O(n) since we are using stack as an auxiliary space
*/
public class NestedIterator implements Iterator<Integer> {
    Stack<NestedInteger> st = new Stack<NestedInteger>();
    public NestedIterator(List<NestedInteger> nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; i--){
            st.push(nestedList.get(i));
        }
    }

    @Override
    public Integer next() {
        int num = st.peek().getInteger();
        st.pop();
        return num;
    }

    @Override
    public boolean hasNext() {
        if(st.empty()){
            return false;
        }
        while(!st.isEmpty()){
            NestedInteger current = st.peek();
            if(current.isInteger()){
                return true;
            }
            st.pop();
            List<NestedInteger> list = new ArrayList<>();
            list = current.getList();
            for(int i = list.size() - 1; i >= 0; i--){
                st.push(list.get(i));
            }
        }
        return false;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
