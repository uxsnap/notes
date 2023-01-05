export const splitArrIntoArrsByRange = (arr, range) => Array(Math.ceil(arr.length / range))
  .fill()
  .map(
    (_, ind) => arr.slice(ind * range, (ind + 1) * range)
  )
