/*
  Given a set of non-negative integers, and a value sum, 
  determine if there is a subset of the given set with sum equal to given sum. 

  Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
  Output: True  
  There is a subset (4, 5) with sum 9.

  Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
  Output: False
  There is no subset that add up to 30.

*/

const subsetSumRecursive = (arr, sum) => {
  let n = arr.length;
  const dp = Array(n + 1);

  for (let i = 0; i <= n; i++)
    dp[i] = Array(sum + 1);

  for (let i = 0; i <= n; i++) dp[i][0] = true;
  for (let i = 0; i <= sum; i++) dp[0][i] = false;

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= sum; j++) {
      dp[i][j] = dp[i - 1][j];

      if (j >= arr[i - 1]) {
        dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
      }
    }
  }

  return dp[n][sum];
};