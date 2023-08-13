class MinHeap {
  constructor(array) {
    this.heap = this.buildHeap(array);
  }

  // O(n) time | O(1) space
  buildHeap(array) {
    const firstParentIdx = Math.floor((array.length - 2) / 2);
    for (let currentIdx = firstParentIdx; currentIdx >= 0; currentIdx--) {
      this.siftDown(currentIdx, array.length - 1, array);
    }
    return array;
  }

  // O(log(n)) time | O(1) space
  siftDown(currentIdx, endIdx) {
    let childOneIdx = currentIdx * 2 + 1;
    while (childOneIdx <= endIdx) {
      const childTwoIdx =
        currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
      let idxToSwap;
      if (childTwoIdx !== -1 && this.heap[childTwoIdx] < this.heap[childOneIdx]) {
        idxToSwap = childTwoIdx;
      } else {
        idxToSwap = childOneIdx;
      }

      if (this.heap[idxToSwap] < this.heap[currentIdx]) {
        this.swap(currentIdx, idxToSwap);
        currentIdx = idxToSwap;
        childOneIdx = currentIdx * 2 + 1;
      }
    }
  }

  // O(log(n)) time | O(1) space
  siftUp(currentIdx) {
    let parentIdx = Math.floor((currentIdx - 1) / 2);

    while (currentIdx > 0 && this.heap[currentIdx] < this.heap[parentIdx]) {
      this.swap(currentIdx, parentIdx);
      currentIdx = parentIdx;
      parentIdx = Math.floor((currentIdx - 1) / 2);
    }
  }

  // O(1)  time | O(1) space
  peek() {
    return this.heap[0];
  }

  // O(log(n)) time | O(1) space
  remove() {
    this.swap(0, this.heap.length - 1);
    const valueToRemove = this.heap.pop();
    this.siftDown(0, this.heap.length - 1);
    return valueToRemove;
  }

  // O(log(n)) time | O(1) space
  insert(value) {
    this.heap.push(value);
    this.siftUp(this.heap.length - 1);
  }

  swap(i, j) {
    [this.heap[i],this.heap[j]] = [this.heap[j], this.heap[i]];
  }
}
