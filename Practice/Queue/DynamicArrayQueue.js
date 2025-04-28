class DynamicArrayQueue {
  _queue = [];
  _front = 0;
  _size = 0;
  _capacity = 0;

  isFull() {
    return this._size === this._capacity;
  }

  isEmpty() {
    return this._size === 0;
  }

  size() {
    return this._size;
  }

  capacity() {
    return this._capacity;
  }

  increaseCapacity() {
    const newCapacity = Math.max(1, this._capacity * 2);
    const newQueue = new Array(newCapacity);

    for (let i = 0; i < this._size; i += 1) {
      const index = (this._front + i) % this._capacity;
      newQueue[i] = this._queue[index];
    }

    this._queue = newQueue;
    this._capacity = newCapacity;
    this._front = 0;
  }

  enqueue(value) {
    if (this.isFull()) {
      this.increaseCapacity();
    }

    const rear = (this._front + this._size) % this._capacity;
    this._queue[rear] = value;
    this._size += 1;
  }

  dequeue() {
    if (this.isEmpty()) {
      throw new Error("Queue underflow");
    }

    const dequeuedItem = this._queue[this._front];

    this._front = (this._front + 1) % this._capacity;
    this._size -= 1;

    return dequeuedItem;
  }
}

const queue = new DynamicArrayQueue();

queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);
queue.enqueue(40);
queue.enqueue(50);
queue.enqueue(60);
queue.enqueue(70);
queue.enqueue(80);
queue.enqueue(90);

console.log("capacity ", queue.capacity());
console.log("size ", queue.size());

while (!queue.isEmpty()) {
  console.log(queue.dequeue());
}
