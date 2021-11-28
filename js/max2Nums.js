/* Find 2 non equal max nums from array */

const max2Nums = (nums) => {
  let max1 = -Infinity;
  let max2 = -Infinity;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > max1) {
      if (max2 !== max1) {
        max2 = max1;
      }
      max1 = nums[i];
    } else if (nums[i] > max2 && nums[i] !== max1) {
      max2 = nums[i];
    }
  }

  return [max1, max2];
};