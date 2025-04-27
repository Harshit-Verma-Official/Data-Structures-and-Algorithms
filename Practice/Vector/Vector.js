class Vector {
  _capacity = 1;
  _array = [];
  _index = 0;
  _initialCapacity = 1;

  constructor(initialCapacity = 1) {
    this._array = new Array(initialCapacity);
    this._capacity = initialCapacity;
    this._initialCapacity = initialCapacity;
  }

  increaseCapacity() {
    const newCapacity = this._capacity * 2;
    const bigArray = new Array(newCapacity);

    for (let i = 0; i < this.size(); i += 1) {
      bigArray[i] = this._array[i];
    }

    this._array = bigArray;
    this._capacity = newCapacity;
  }

  size() {
    return this._index;
  }

  capacity() {
    return this._capacity;
  }

  _isFull() {
    return this.size() === this.capacity();
  }

  isEmpty() {
    return this._index === 0;
  }

  _isValidIndex(index) {
    return index >= 0 && index < this._index;
  }

  get(index) {
    if (!this._isValidIndex(index)) throw new Error("Invalid index provided");

    return this._array[index];
  }

  set(index, value) {
    if (!this._isValidIndex(index)) throw new Error("Invalid index provided");

    this._array[index] = value;
  }

  push(item) {
    if (this._isFull()) {
      this.increaseCapacity();
    }

    this._array[this._index] = item;
    this._index += 1;
  }

  pop() {
    if (this.isEmpty()) return undefined;

    const poppedItem = this._array[this._index - 1];

    this._index -= 1;

    return poppedItem;
  }

  _expandAndInsert(index, value) {
    const newCapacity = this._capacity * 2;
    const bigArray = new Array(newCapacity);

    for (let i = 0; i < index; i += 1) {
      bigArray[i] = this._array[i];
    }

    bigArray[index] = value;

    for (let i = index; i < this.size(); i += 1) {
      bigArray[i + 1] = this._array[i];
    }

    this._array = bigArray;
    this._capacity = newCapacity;
    this._index += 1;
  }

  _shiftAndInsert(index, value) {
    for (let i = this.size(); i > index; i -= 1) {
      this._array[i] = this._array[i - 1];
    }
    this._array[index] = value;
    this._index += 1;
  }

  insert(index, value) {
    // allow to add as the last element of the array
    if (index < 0 || index > this._index)
      throw new Error("Invalid index provided");

    // adding as the last element
    if (index === this._index) {
      this.push(value);
      return;
    }

    if (this._isFull()) {
      this._expandAndInsert(index, value);
    } else {
      this._shiftAndInsert(index, value);
    }
  }

  remove(index) {
    if (!this._isValidIndex(index)) throw new Error("Invalid index provided");

    const removedValue = this._array[index];

    for (let i = index; i < this.size(); i += 1) {
      this._array[i] = this._array[i + 1];
    }

    this._index -= 1;

    return removedValue;
  }

  indexOf(value) {
    for (let i = 0; i < this.size(); i += 1) {
      if (this._array[i] === value) return i;
    }

    return -1;
  }

  contains(value) {
    return this.indexOf(value) !== -1;
  }

  clear() {
    this._array = Array(this._initialCapacity);
    this._capacity = this._initialCapacity;
    this._index = 0;
  }

  toArray() {
    return [...this._array.slice(0, this.size())];
  }

  toString() {
    return `[ ${this._array.slice(0, this.size()).join(", ")} ]`;
  }
}

const v = new Vector(2);
v.push(1);
v.push(2);
v.insert(1, 99);
console.log(v.toString()); // [ 1, 99, 2 ]
v.remove(0);
console.log(v.toString()); // [ 99, 2 ]
