const evenThenOdd = (nums) => {
	let left = 0;
  let right = nums.length - 1;
  
  while (left <= right) {
  	if (nums[left] % 2 === 0) left++;
    else if (nums[right] % 2 === 1) right--;
    else {
    	let temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
    }
  }
  
  return nums;
};
