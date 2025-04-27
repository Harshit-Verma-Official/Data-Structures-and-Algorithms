class ListNode {
  value = undefined;
  prev = null;
  next = null;

  constructor(value) {
    this.value = value;
  }
}

class DoubleLinkedList {
  _head = null;
  _tail = null;
  _size = 0;

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
    const newNode = new ListNode(value);

    if (this.isEmpty()) {
      this._head = newNode;
      this._tail = newNode;
      this._size += 1;
      return;
    }

    this._tail.next = newNode;
    newNode.prev = this._tail;
    this._tail = newNode;
    this._size += 1;
  }

  // O(1)
  prepend(value) {
    const newNode = new ListNode(value);

    if (this.isEmpty()) {
      this._head = newNode;
      this._tail = newNode;
      this._size += 1;
      return;
    }

    newNode.next = this._head;
    this._head.prev = newNode;
    this._head = newNode;
    this._size += 1;
  }

  // O(N)
  insert(index, value) {
    if (index < 0 || index > this._size) {
      throw new Error("Invalid index provided");
    }

    if (this.isEmpty() || index === this._size) {
      this.append(value);
      return;
    }

    if (index === 0) {
      this.prepend(value);
      return;
    }

    const newNode = new ListNode(value);
    let iterator = this._head;

    for (let i = 1; i < index; i += 1) {
      iterator = iterator.next;
    }

    newNode.next = iterator.next;
    iterator.next.prev = newNode;
    iterator.next = newNode;
    newNode.prev = iterator;
    this._size += 1;
  }

  // O(N)
  get(index) {
    if (index < 0 || index >= this._size) {
      throw new Error("Invalid index provided");
    }

    if (index === 0) {
      return this._head.value;
    }

    if (index === this._size - 1) {
      return this._tail.value;
    }

    const midIndex = Math.floor((this._size - 1) / 2);
    const direction = index < midIndex ? "ltr" : "rtl";
    let iterator = null;

    if (direction === "ltr") {
      for (let i = 0; i <= index; i += 1) {
        iterator = iterator ? iterator.next : this._head;
      }
    } else {
      for (let i = this._size - 1; i >= index; i -= 1) {
        iterator = iterator ? iterator.prev : this._tail;
      }
    }

    return iterator.value;
  }

  // O(N)
  set(index, value) {
    if (index < 0 || index >= this._size) {
      throw new Error("Invalid index provided");
    }

    if (index === 0) {
      return (this._head.value = value);
    }

    if (index === this._size - 1) {
      return (this._tail.value = value);
    }

    const midIndex = Math.floor((this._size - 1) / 2);
    const direction = index < midIndex ? "ltr" : "rtl";
    let iterator = null;

    if (direction === "ltr") {
      for (let i = 0; i <= index; i += 1) {
        iterator = iterator ? iterator.next : this._head;
      }
    } else {
      for (let i = this._size - 1; i >= index; i -= 1) {
        iterator = iterator ? iterator.prev : this._tail;
      }
    }

    iterator.value = value;
  }

  // O(N)
  remove(index) {
    if (index < 0 || index >= this._size) {
      throw new Error("Invalid index provided");
    }

    if (index === 0) {
      this._head = this._head.next;

      if (this._head) {
        this._head.prev = null;
      }
      this._size -= 1;
      return;
    }

    if (index === this._size - 1) {
      this._tail = this._tail.prev;
      this._tail.next = null;
      this._size -= 1;
      return;
    }

    let iterator = this._head;

    for (let i = 1; i < index; i += 1) {
      iterator = iterator.next;
    }

    const nodeToBeRemoved = iterator.next;
    iterator.next = nodeToBeRemoved.next;
    iterator.next.prev = iterator;
    this._size -= 1;
  }

  // O(N)
  removeByValue(value) {
    if (this.isEmpty()) {
      return;
    }

    if (value === this._head.value) {
      this.remove(0);
      return;
    }

    if (value === this._tail.value) {
      this.remove(this._size - 1);
      return;
    }

    let prevPointer = null;
    let currentPointer = this._head;

    while (currentPointer && currentPointer.value !== value) {
      prevPointer = currentPointer;
      currentPointer = currentPointer.next;
    }

    if (currentPointer) {
      prevPointer.next = currentPointer.next;
      currentPointer.next.prev = prevPointer;
      this._size -= 1;
    }
  }

  // O(N)
  indexOf(value) {
    if (this.isEmpty()) {
      return -1;
    }

    let iterator = this._head;
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
    let iterator = this._head;

    while (iterator !== null) {
      array.push(iterator.value);
      iterator = iterator.next;
    }

    return array;
  }

  // O(1)
  clear() {
    this._head = null;
    this._tail = null;
    this._size = 0;
  }
}

const list = new DoubleLinkedList();

list.append(10);
list.append(20);
list.append(30);
list.append(40);
list.append(50);

list.removeByValue(60);

console.log(list.toArray());
