class MaxHeap {
  constructor() {
    this.arr = [];
  }

  isEmpty = () => {
    return this.arr.length === 0;
  };

  getLeftChildIndex = (index) => {
    return index * 2 + 1;
  };

  getRightChildIndex = (index) => {
    return index * 2 + 2;
  };

  hasLeftChild = (index) => {
    return this.getLeftChildIndex(index) < this.arr.length;
  };

  hasRightChild = (index) => {
    return this.getRightChildIndex(index) < this.arr.length;
  };

  getParentIndex = (index) => {
    return Math.floor((index - 1) / 2);
  };

  swap(indexA, indexB) {
    const temp = this.arr[indexA];
    this.arr[indexA] = this.arr[indexB];
    this.arr[indexB] = temp;
  }

  bubbleDown = (index) => {
    const heapSize = this.arr.length;

    while (index < heapSize) {
      const leftChildIndex = this.getLeftChildIndex(index);
      const rightChildIndex = this.getRightChildIndex(index);
      let biggerChildIndex = index;

      if (
        leftChildIndex < heapSize &&
        this.arr[leftChildIndex] > this.arr[biggerChildIndex]
      ) {
        biggerChildIndex = leftChildIndex;
      }

      if (
        rightChildIndex < heapSize &&
        this.arr[rightChildIndex] > this.arr[biggerChildIndex]
      ) {
        biggerChildIndex = rightChildIndex;
      }

      if (biggerChildIndex === index) {
        break;
      }

      this.swap(index, biggerChildIndex);
      index = biggerChildIndex;
    }
  };

  bubbleUp = (index) => {
    while (index > 0) {
      const parentIndex = this.getParentIndex(index);

      if (this.arr[parentIndex] < this.arr[index]) {
        this.swap(parentIndex, index);
        index = parentIndex;
      } else {
        break;
      }
    }
  };

  insert = (value) => {
    this.arr.push(value);
    this.bubbleUp(this.arr.length - 1);
  };

  remove = () => {
    if (this.isEmpty()) {
      return null;
    }

    const removedItem = this.arr[0];
    const lastItem = this.arr.pop();

    if (this.isEmpty()) {
      return removedItem;
    }

    this.arr[0] = lastItem;
    this.bubbleDown(0);

    return removedItem;
  };

  peek = () => {
    return this.arr[0];
  };
}

const maxHeap = new MaxHeap(9);

[15, 10, 3, 8, 12, 9, 4, 1, 24].forEach((value) => maxHeap.insert(value));

console.log(maxHeap.arr);

console.log("Removed = ", maxHeap.remove());

console.log(maxHeap.arr);

while (!maxHeap.isEmpty()) {
  console.log("Top = ", maxHeap.remove());
}
