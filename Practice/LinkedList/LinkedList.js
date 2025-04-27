class ListNode {
  value = undefined;
  next = null;

  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class LinkedList {
  head = null;
  tail = null;
  _size = 0;

  // O(1)
  _isValidIndex(index) {
    return index >= 0 && index < this._size;
  }

  // O(1)
  isEmpty() {
    return this._size === 0;
  }

  // O(1)
  size() {
    return this._size;
  }

  // O(1)
  append(value) {
    const node = new ListNode(value);

    if (!this.head) {
      this.head = node;
    }

    if (this.tail) {
      this.tail.next = node;
      this.tail = node;
    } else {
      this.tail = node;
    }

    this._size += 1;
  }

  // O(1)
  prepend(value) {
    const newNode = new ListNode(value);

    newNode.next = this.head;
    this.head = newNode;

    if (this.isEmpty()) {
      this.tail = newNode;
    }

    this._size += 1;
  }

  // O(N)
  insert(index, value) {
    if (index < 0 || index > this._size) {
      throw new Error("Invalid index provided");
    }

    if (index === 0) {
      this.prepend(value);
      return;
    }

    if (index === this._size) {
      this.append(value);
      return;
    }

    let iterator = this.head;

    for (let i = 1; i < index; i += 1) {
      iterator = iterator.next;
    }

    const newNode = new ListNode(value);
    const nodeToBeShifted = iterator.next;

    iterator.next = newNode;
    newNode.next = nodeToBeShifted;

    this._size += 1;
  }

  // O(N)
  remove(index) {
    if (!this._isValidIndex(index)) {
      throw new Error("Invalid index provided");
    }

    if (index === 0) {
      const currentHeadNode = this.head;
      this.head = currentHeadNode.next;
      currentHeadNode.next = null;
    } else {
      let iterator = this.head;

      for (let i = 1; i < index; i += 1) {
        iterator = iterator.next;
      }

      const nodeToBeRemoved = iterator.next;
      iterator.next = nodeToBeRemoved.next;
      nodeToBeRemoved.next = null;

      if (iterator.next === null) {
        this.tail = iterator;
      }
    }

    this._size -= 1;
  }

  // O(N)
  removeByValue(value) {
    if (this.isEmpty()) {
      return;
    }

    if (this.head.value === value) {
      this.remove(0);
      return;
    }

    let prevIterator = null;
    let currentIterator = this.head;

    while (currentIterator && currentIterator.value !== value) {
      prevIterator = currentIterator;
      currentIterator = currentIterator.next;
    }

    if (currentIterator) {
      prevIterator.next = currentIterator.next;
      currentIterator.next = null;

      if (prevIterator.next === null) {
        this.tail = prevIterator;
      }

      this._size -= 1;
    }
  }

  // O(N)
  get(index) {
    if (!this._isValidIndex(index)) {
      throw new Error("Invalid index provided");
    }

    let iterator = this.head;

    for (let i = 1; i <= index; i += 1) {
      iterator = iterator.next;
    }

    return iterator.value;
  }

  // O(N)
  set(index, value) {
    if (!this._isValidIndex(index)) {
      throw new Error("Invalid index provided");
    }

    let iterator = this.head;

    for (let i = 1; i <= index; i += 1) {
      iterator = iterator.next;
    }

    iterator.value = value;
  }

  // O(N)
  indexOf(value) {
    if (this.isEmpty()) {
      return -1;
    }

    let iterator = this.head;
    let index = 0;

    while (iterator) {
      if (iterator.value === value) {
        return index;
      }

      iterator = iterator.next;
      index += 1;
    }

    return -1;
  }

  // O(N)
  contains(value) {
    return this.indexOf(value) !== -1;
  }

  // O(N)
  toArray() {
    const array = [];
    let iterator = this.head;

    while (iterator) {
      array.push(iterator.value);
      iterator = iterator.next;
    }

    return array;
  }

  // O(1)
  clear() {
    this.head = null;
    this.tail = null;
    this._size = 0;
  }
}

const list = new LinkedList();

list.append(10);
list.append(20);
list.append(30);
list.append(40);
list.prepend(5);

console.log(list.toArray());
console.log(list.size());
