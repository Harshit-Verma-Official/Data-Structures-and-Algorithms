class Stack {
  stack = [];

  // O(1)
  push(value) {
    this.stack.push(value);
  }

  // O(1)
  pop() {
    return this.stack.pop();
  }

  // O(1)
  size() {
    return this.stack.length;
  }

  // O(1)
  top() {
    return this.isEmpty() ? undefined : this.stack.at(-1);
  }

  // O(1)
  isEmpty() {
    return this.stack.length === 0;
  }

  // O(1)
  clear() {
    this.stack = [];
  }

  // O(n)
  toArray() {
    return this.stack.slice();
  }
}

const stack = new Stack();

stack.push(10);
stack.push(20);
stack.push(30);
stack.push(40);

while (!stack.isEmpty()) {
  console.log("top", stack.pop());
}
