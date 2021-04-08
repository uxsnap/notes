// Returns array with same elements from 2 arrays

// Example : a1 = [1, 2, 3], a2 = [3, 4] ==> result = [3];  


// Random arrays of length with 10000 in 100 cycles ~~  1842 ms 
const intersection = (a1, a2) => {
  const hashMap = [];
  const result = [];
  for (let i = 0; i < a1.length; i++)
    hashMap[a1[i]] = 1;
  for (let i = 0; i <  Math.max(a1.length, a2.length); i++) {
    if (hashMap[a2[i]]) result.push(a2[i]);
  }

  return result;
}

// Random arrays of length with 10000 in 100 cycles ~~  9034 ms
const slowIntersection = (a1, a2) => 
 a1.filter((item) => a2.includes(item));

const generateArr = (n) => {
  const res = [];
  for (let i = 0; i < n; i++)
    res.push(Math.random());
  return res;
};


module.exports = { intersection, slowIntersection };