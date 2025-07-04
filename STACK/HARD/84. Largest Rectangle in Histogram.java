/*
    Logic: 
        1. While We are on heights[i] we will check the next smaller element and the previous smaller element.
        2. We are calculating the previous smaller element and next smaller element to find out the width.
    Time Complexity:
        1. T.C -> O(n)
    Time Complexity:
        1. S.C -> O(3n) since we are using auxiliary space for nse, pse and stack.

*/
class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int [] pse = new int[n];
        int [] nse = new int[n];
        Stack <Integer> st = new Stack<>();
        for(int i = 0; i < n; i++){
            while(!st.isEmpty() && heights[i] <= heights[st.peek()]){
                st.pop();
            }
            pse[i] = st.isEmpty() ? -1: st.peek();
            st.push(i);
        }
        st.clear();
        for(int i = n-1; i >= 0; i--){
            while(!st.isEmpty() && heights[i] <= heights[st.peek()]){
                st.pop();
            }
            nse[i] = st.isEmpty() ? n: st.peek();
            st.push(i);
        }
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int height = heights[i];
            int width = nse[i] - pse[i] - 1;
            int area = (height * width);
            maxArea = Math.max(maxArea, area);
        }
        return maxArea;
    }
}
