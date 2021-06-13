export const nonintersectSections = (sections) => {
  let res = [];
  let lastR = - 1;
  
  const sortF = (a, b) => a[1] - b[1];
  const nsects = [...sections]
  nsects.sort(sortF);

  for (let ns of nsects) 
    if (ns[0] > lastR) { 
      res.push(ns); lastR = ns[1];
    }

  return res;
};
