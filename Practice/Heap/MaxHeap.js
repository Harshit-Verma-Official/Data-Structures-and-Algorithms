class MaxHeap {
  constructor() {
    this.arr = [];
  }

  isEmpty() {
    return this.arr.length === 0;
  }

  peek() {
    return this.arr[0];
  }

  getLeftChildIndex(index) {
    return index * 2 + 1;
  }

  getRightChildIndex(index) {
    return index * 2 + 2;
  }

  hasLeftChild(index) {
    return this.getLeftChildIndex(index) < this.arr.length;
  }

  hasRightChild(index) {
    return this.getRightChildIndex(index) < this.arr.length;
  }

  getLeftChild(index) {
    return this.arr[this.getLeftChildIndex(index)];
  }

  getRightChild(index) {
    return this.arr[this.getRightChildIndex(index)];
  }

  getParentIndex(index) {
    return Math.floor((index - 1) / 2);
  }

  isGreaterThanParent(index) {
    return this.arr[index] > this.arr[this.getParentIndex(index)];
  }

  isValidParent(index) {
    if (!this.hasLeftChild(index)) {
      return true;
    }

    const currentValue = this.arr[index];
    let isValid = currentValue >= this.getLeftChild(index);

    if (this.hasRightChild(index)) {
      isValid &&= currentValue >= this.getRightChild(index);
    }

    return isValid;
  }

  getBiggerChildIndex(index) {
    if (!this.hasLeftChild(index)) {
      return index;
    }

    if (!this.hasRightChild(index)) {
      return this.getLeftChildIndex(index);
    }

    return this.getLeftChild(index) > this.getRightChild(index)
      ? this.getLeftChildIndex(index)
      : this.getRightChildIndex(index);
  }

  swap(sourceIndex, targetIndex) {
    const temp = this.arr[sourceIndex];
    this.arr[sourceIndex] = this.arr[targetIndex];
    this.arr[targetIndex] = temp;
  }

  bubbleUp() {
    let currentIndex = this.arr.length - 1;

    while (currentIndex > 0 && this.isGreaterThanParent(currentIndex)) {
      const parentIndex = this.getParentIndex(currentIndex);
      this.swap(currentIndex, parentIndex);
      currentIndex = parentIndex;
    }
  }

  bubbleDown() {
    let currentIndex = 0;

    while (
      currentIndex < this.arr.length &&
      !this.isValidParent(currentIndex)
    ) {
      const biggerChildIndex = this.getBiggerChildIndex(currentIndex);
      this.swap(currentIndex, biggerChildIndex);
      currentIndex = biggerChildIndex;
    }
  }

  insert(value) {
    this.arr.push(value);
    this.bubbleUp();
  }

  remove() {
    if (this.isEmpty()) return undefined;

    const removedValue = this.arr[0];
    const lastValue = this.arr.pop();

    if (this.isEmpty()) {
      return removedValue;
    }

    this.arr[0] = lastValue;
    this.bubbleDown();

    return removedValue;
  }
}

const maxHeap = new MaxHeap();

[15, 10, 3, 8, 12, 9, 4, 1, 24].forEach((value) => maxHeap.insert(value));

console.log(maxHeap.arr);

console.log("Removed = ", maxHeap.remove());

console.log(maxHeap.arr);

while (!maxHeap.isEmpty()) {
  console.log("Top = ", maxHeap.remove());
}
