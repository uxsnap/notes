export function generateMarkovDict(words, chainDepth = 2) {
  const dict = {};
  for (let i = chainDepth; i < words.length; i++) {
    const key = `${words[i - 2]} ${words[i - 1]}`;
    if (!dict[key])
      dict[key] = [words[i]];
    else
      dict[key] = [...new Set([...dict[key], words[i]])];
  }
  return dict;
}

function getRandomObjKey(obj) {
  const keys = Object.keys(obj);
  return getRandomArrValue(keys);
}

function getRandomArrValue(arr) {
  const ind = Math.floor(Math.random() * arr.length);
  return arr[ind];
}

export function markovSentence(dict, depth = 8) {
  let res = '';
  for (let i = 0; i < depth; i++) {
    const randomKey = getRandomObjKey(dict);
    res += ' ' + randomKey + ' ' + getRandomArrValue(dict[randomKey]);
  }

  return res;
}