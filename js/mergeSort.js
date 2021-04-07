const mergeSort = (arr) => {
  if (arr.length < 2) return arr;
  const [l , r, mid] = [0, arr.length, Math.floor(arr.length / 2)];

  return merge(
    mergeSort(arr.slice(l, mid)),
    mergeSort(arr.slice(mid, r))
  );
};

const  merge = (left, right) => {
  const result = [];
  let i = 0, j = 0;

  while (i < left.length && j < right.length) {
    result.push(left[i] < right[j] ? left[i++] : right[j++]);
  }

  return [...result, ...left.slice(i), ...right.slice(j)];
};


if (process.argv.length > 2) {
  console.log(
    mergeSort(process.argv.slice(2,))
  )
}


module.exports = mergeSort;
