class TreeNode {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

const levelOrderTraversal = (root) => {
  if (!root) return;

  const queue = [root];

  while (queue.length) {
    const top = queue.shift();

    if (top.left) {
      console.log(`${top.data} -> left child : ${top.left.data}`);
      queue.push(top.left);
    }

    if (top.right) {
      console.log(`${top.data} -> right child : ${top.right.data}`);
      queue.push(top.right);
    }
  }
};

const inorder = (root) => {
  if (!root) return;

  inorder(root.left);
  console.log(root.data);
  inorder(root.right);
};

const insertNode = (root, data) => {
  const newNode = new TreeNode(data);

  if (!root) {
    return newNode;
  }

  let prevNode = null;
  let currentNode = root;

  while (currentNode) {
    prevNode = currentNode;

    currentNode =
      data < currentNode.data ? currentNode.left : currentNode.right;
  }

  if (data < prevNode.data) {
    prevNode.left = newNode;
  } else {
    prevNode.right = newNode;
  }

  return root;
};

const search = (root, data) => {
  if (!root) return false;

  let pointer = root;

  while (pointer) {
    if (pointer.data === data) return true;

    pointer = data < pointer.data ? pointer.left : pointer.right;
  }

  return false;
};

const getLeftMostNode = (root) => {
  let pointer = root;

  while (pointer.left) {
    pointer = pointer.left;
  }

  return pointer;
};

const deleteNode = (root, data) => {
  if (!root) return root;

  if (data < root.data) {
    root.left = deleteNode(root.left, data);
  } else if (data > root.data) {
    root.right = deleteNode(root.right, data);
  } else {
    if (root.right) {
      const successor = getLeftMostNode(root.right);
      root.data = successor.data;
      root.right = deleteNode(root.right, successor.data);
    } else if (root.left) {
      return root.left;
    } else {
      return null;
    }
  }

  return root;
};

let root = new TreeNode(20);
insertNode(root, 17);
insertNode(root, 30);
insertNode(root, 12);
insertNode(root, 19);
insertNode(root, 29);
insertNode(root, 38);
insertNode(root, 8);
insertNode(root, 13);
insertNode(root, 18);

root = deleteNode(root, 17);
// root = deleteNode(root, 18);
// root = deleteNode(root, 12);

levelOrderTraversal(root);
