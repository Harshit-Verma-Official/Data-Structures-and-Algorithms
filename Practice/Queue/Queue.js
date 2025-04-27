class Queue {
  _capacity = 0;
  _front = 0;
  _size = 0;

  constructor(initialCapacity = 0) {
    this.queue = new Array(initialCapacity);
    this._capacity = initialCapacity;
  }

  isEmpty() {
    return this._size === 0;
  }

  isFull() {
    return this._size === this._capacity;
  }

  enqueue(value) {
    if (this.isFull()) throw new Error("Queue overflow");

    const rear = (this._front + this._size) % this._capacity;

    this.queue[rear] = value;
    this._size += 1;
  }

  dequeue() {
    if (this.isEmpty()) throw new Error("Queue underflow");

    const frontValue = this.queue[this._front];

    this._front = (this._front + 1) % this._capacity;
    this._size -= 1;

    return frontValue;
  }

  peek() {
    if (this.isEmpty()) return undefined;

    return this.queue[this._front];
  }

  size() {
    return this._size;
  }
}

const queue = new Queue(5);

queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);
queue.enqueue(40);
queue.enqueue(50);

while (!queue.isEmpty()) {
  console.log(queue.dequeue());
}
