// Examples:

// [1,4,5,2,3,9,8,11,0] => "0-5,8-9,11"
// [1,4,3,2] => "1-4"
// [1,4] => "1,4"

export const stringRange = (arr) => {
  const sorted = [...arr];
  sorted.sort((a, b) => a - b);

  const groups = [];

  let groupStart = null;
  let prev = null;
  for (let n of sorted) {
    if (prev === null) {
      groupStart = n;
      prev = groupStart;
    } else if (prev === n - 1) {
      prev = n;
    } else {
      groups.push(`${groupStart}-${prev}`)
      groupStart = n;
      prev = n;
    }
  }

  if (prev) groups.push(
    groupStart + (groupStart !== prev ? '-' + prev : '')
  );

  return groups.join(', ');
};