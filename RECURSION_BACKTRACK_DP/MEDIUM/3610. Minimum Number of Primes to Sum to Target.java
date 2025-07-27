/*
    Logic:
        1. Similar to coin change problem.
        2. First we will make the list of all available primes and then we will apply the login of coin change problem.
        3. Take and Skip logic
    Time Complexity:
        1. T.C -> O(m * n)
    Space Complexity:
        1. S.C -> O(n)
*/
class Solution {
    private int memo[][];
    public int recursion(List<Integer> availablePrimes, int target, int i){
        if(target == 0){
            return 0;
        }
        if(i >= availablePrimes.size() || target < 0){
            return Integer.MAX_VALUE;
        }
        if(target < availablePrimes.get(i)){
            return recursion(availablePrimes, target, i + 1);
        }
        int take = recursion(availablePrimes, target - availablePrimes.get(i), i);
        if(take != Integer.MAX_VALUE){
            take += 1;
        }
        int skip = recursion(availablePrimes, target, i + 1);
        return Math.min(take, skip);
    }
    private int memoization(List<Integer> availablePrimes, int target, int i) {
        if (target == 0) {
            return 0;
        }
        if (i >= availablePrimes.size() || target < 0) {
            return Integer.MAX_VALUE;
        }
        if (memo[i][target] != -1) {
            return memo[i][target];
        }
        if (target < availablePrimes.get(i)) {
            memo[i][target] = memoization(availablePrimes, target, i + 1);
            return memo[i][target];
        }
        int take = memoization(availablePrimes, target - availablePrimes.get(i), i);
        if (take != Integer.MAX_VALUE) {
            take += 1;
        }
        int skip = memoization(availablePrimes, target, i + 1);
        memo[i][target] = Math.min(take, skip);
        return memo[i][target];
    }
    public int tabulation(List<Integer>availablePrimes, int target){
        int numPrimes = availablePrimes.size();
        int[] dp = new int[target + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int prime: availablePrimes){
            for(int i = prime; i <= target; ++i){
                if(prime <= i && dp[i - prime] != Integer.MAX_VALUE){
                    dp[i] = Math.min(dp[i], 1 + dp[i - prime]);
                }
            }
        }
        if(dp[target] == Integer.MAX_VALUE){
            return -1;
        }
        return dp[target];
    }
    public int minNumberOfPrimes(int n, int m) {
        List<Integer> primes = new ArrayList<>();
        int num = 2;
        while(primes.size() < m){
            boolean isPrime = true;
            for(int p: primes){
                if(p * p > num){
                    break;
                }
                if(num % p == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                primes.add(num);
            }
            num++;
        }
        List<Integer>availablePrimes = new ArrayList<>();
        for(int p: primes){
            if(p <= n){
                availablePrimes.add(p);
            }
        }
        if(availablePrimes.isEmpty()){
            return -1;
        }
        // int result = recursion(availablePrimes, n, 0);
        memo = new int[availablePrimes.size()][n + 1];
        for (int[] row : memo) {
            for (int j = 0; j <= n; j++) {
                row[j] = -1;
            }
        }
        // int resultByMemo = memoization(availablePrimes, n, 0);
        int resultByTabulation = tabulation(availablePrimes, n);
        // return result == Integer.MAX_VALUE ? -1 : result;
        // return resultByMemo == Integer.MAX_VALUE ? -1 : resultByMemo;
        return resultByTabulation == -1 ? -1 : resultByTabulation;
    }
}
