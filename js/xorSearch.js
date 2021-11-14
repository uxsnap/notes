/* 
    Have an array with duplicate nums and only one element without. Find that element  

    Example: [1, 2, 3, 3, 2, 4, 1] -> 4;
*/

/* 
  Solution: 
    bit representation for every number from example and the XOR sum from it:
    [1, 2, 3, 3, 2, 4, 1]
     0 ⊕ 0 ⊕ 0 ⊕ 0 ⊕ 0 ⊕ 1 ⊕ 0  -> 1
     0 ⊕ 1 ⊕ 1 ⊕ 1 ⊕ 1 ⊕ 0 ⊕ 0  -> 0  --> 4
     1 ⊕ 0 ⊕ 1 ⊕ 1 ⊕ 0 ⊕ 0 ⊕ 0  -> 0

*/

function xorSearch(array) {
  let num = array[0];

  for (let i = 1; i < array.length; i++) {
    num ^= array[i];
  }

  return num;
}