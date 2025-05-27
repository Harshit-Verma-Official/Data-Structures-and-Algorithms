class Heap {
  constructor(comparator) {
    this.arr = [];
    this.comparator = comparator || ((root, child) => root >= child);
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

  getParentIndex(index) {
    return Math.floor((index - 1) / 2);
  }

  hasLeftChild(index) {
    return this.getLeftChildIndex(index) < this.arr.length;
  }

  hasRightChild(index) {
    return this.getRightChildIndex(index) < this.arr.length;
  }

  leftChild(index) {
    return this.arr[this.getLeftChildIndex(index)];
  }

  rightChild(index) {
    return this.arr[this.getRightChildIndex(index)];
  }

  getPriorityChildIndex(index) {
    if (!this.hasLeftChild(index)) {
      return index;
    }

    if (!this.hasRightChild(index)) {
      return this.getLeftChildIndex(index);
    }

    return this.comparator(this.leftChild(index), this.rightChild(index))
      ? this.getLeftChildIndex(index)
      : this.getRightChildIndex(index);
  }

  isValidParent(index) {
    if (!this.hasLeftChild(index)) {
      return true;
    }

    const currentValue = this.arr[index];
    let isValid = this.comparator(currentValue, this.leftChild(index));

    if (this.hasRightChild(index)) {
      isValid &&= this.comparator(currentValue, this.rightChild(index));
    }

    return isValid;
  }

  isValidChild(index) {
    const currentValue = this.arr[index];
    const parentValue = this.arr[this.getParentIndex(index)];

    return this.comparator(parentValue, currentValue);
  }

  swap(sourceIndex, targetIndex) {
    const temp = this.arr[sourceIndex];
    this.arr[sourceIndex] = this.arr[targetIndex];
    this.arr[targetIndex] = temp;
  }

  bubbleUp(index) {
    while (index > 0 && !this.isValidChild(index)) {
      const parentIndex = this.getParentIndex(index);
      this.swap(index, parentIndex);
      index = parentIndex;
    }
  }

  bubbleDown(index) {
    while (index < this.arr.length && !this.isValidParent(index)) {
      const biggerChildIndex = this.getPriorityChildIndex(index);
      this.swap(index, biggerChildIndex);
      index = biggerChildIndex;
    }
  }

  insert(value) {
    this.arr.push(value);
    this.bubbleUp(this.arr.length - 1);
  }

  remove() {
    if (this.isEmpty()) {
      return undefined;
    }

    const removedValue = this.arr[0];
    const lastValue = this.arr.pop();

    if (this.isEmpty()) {
      return removedValue;
    }

    this.arr[0] = lastValue;
    this.bubbleDown(0);

    return removedValue;
  }

  replaceTop(value) {
    if (this.isEmpty()) {
      this.arr.push(value);
      return undefined;
    }

    const prevValue = this.arr[0];

    this.arr[0] = value;
    this.bubbleDown(0);

    return prevValue;
  }
}

const maxHeap = new Heap((root, child) => root >= child);

[15, 10, 3, 8, 12, 9, 4, 1, 24].forEach((value) => maxHeap.insert(value));

console.log(maxHeap.arr);

maxHeap.replaceTop(32);

console.log("Removed = ", maxHeap.remove());

console.log(maxHeap.arr);

while (!maxHeap.isEmpty()) {
  console.log("Top = ", maxHeap.remove());
}
