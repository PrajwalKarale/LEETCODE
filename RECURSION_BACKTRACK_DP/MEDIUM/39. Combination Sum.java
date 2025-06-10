/*
    Logic:
        1. Pick or Not Pick. 
    Time Complexity:
        1. T.C -> 2^t * k
    Space Complexity:
        1. S.C -> O(t) where t is the target.
*/
class Solution {
    private void helper(int [] candidates, int target, List<List<Integer>> result, int index, List<Integer>temp){
        if(index == candidates.length){
            if(target == 0){
                result.add(new ArrayList<Integer>(temp));
            }
            return;
        }
        //Picking the element
        if(candidates[index] <= target){
            temp.add(candidates[index]);
            helper(candidates, target - candidates[index], result, index, temp);
            temp.remove(temp.size() - 1);
        }
        //Not Pick
        helper(candidates, target, result, index + 1, temp);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int n = candidates.length;
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        helper(candidates, target, result, 0, new ArrayList<Integer>());
        return result;
    }
}
