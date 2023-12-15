// counter to balance the tree

class UF {
  constructor(N) {
    this.parent = new Array.from({ length: N }, (_, i) => i);
    this.count = new Array(N).fill(1);
  }

  find(x) {
    if (this.parent[x] != x) this.parent[x] = this.find(this.parent[x]);
    return this.parent[x];
  }

  union(x, y) {
    const xp = this.find(x),
      yp = this.find(y);
    if (xp == yp) return;

    if (this.count[xp] < this.count[yp]) {
      this.parent[xp] = yp;
      this.count[yp] += this.count[xp];
    } else {
      this.parent[yp] = xp;
      this.count[xp] += this.count[yp];
    }
  }
}
