class TreeNode {
  left = null;
  right = null;
  data = null;

  constructor(data) {
    this.data = data;
  }
}

const printTreeLevels = (levels) => {
  for (const level of levels) {
    console.log(level);
  }
};

const levelOrder = (root) => {
  if (!root) return [];

  const levels = [];
  const queue = [root];

  while (queue.length) {
    const totalItemsToTraverse = queue.length;
    const currentLevel = [];

    for (let i = 0; i < totalItemsToTraverse; i += 1) {
      const top = queue.shift();

      currentLevel.push(top.data);

      if (top.left) {
        queue.push(top.left);
      }

      if (top.right) {
        queue.push(top.right);
      }
    }

    levels.push(currentLevel);
  }

  return levels;
};

const printParentWithChildren = (root) => {
  if (!root) return;

  const queue = [root];

  while (queue.length) {
    const current = queue.shift();

    if (current.left) {
      console.log(`${current.data} -> Left Child: ${current.left.data}`);
      queue.push(current.left);
    }

    if (current.right) {
      console.log(`${current.data} -> Right Child: ${current.right.data}`);
      queue.push(current.right);
    }
  }
};

const preorder = (root, ans = []) => {
  if (!root) return ans;

  ans.push(root.data);
  preorder(root.left, ans);
  preorder(root.right, ans);

  return ans;
};

const inorder = (root, ans = []) => {
  if (!root) return ans;

  inorder(root.left, ans);
  ans.push(root.data);
  inorder(root.right, ans);

  return ans;
};

const postorder = (root, ans = []) => {
  if (!root) return ans;

  postorder(root.left, ans);
  postorder(root.right, ans);
  ans.push(root.data);

  return ans;
};

const insertNode = (root, data) => {
  const newNode = new TreeNode(data);

  if (!root) {
    return newNode;
  }

  const queue = [root];

  while (queue.length) {
    const top = queue.shift();

    if (top.left) {
      queue.push(top.left);
    } else {
      top.left = newNode;
      break;
    }

    if (top.right) {
      queue.push(top.right);
    } else {
      top.right = newNode;
      break;
    }
  }

  return root;
};

const searchDFS = (root, data) => {
  if (!root) return false;

  return (
    root.data === data ||
    searchDFS(root.left, data) ||
    searchDFS(root.right, data)
  );
};

const deleteNode = (root, data) => {
  if (!root) return root;

  let targetNode = null;
  let queue = [root];

  while (queue.length) {
    const topNode = queue.shift();

    if (topNode.data === data) {
      targetNode = topNode;
      break;
    }

    if (topNode.left) {
      queue.push(topNode.left);
    }

    if (topNode.right) {
      queue.push(topNode.right);
    }
  }

  if (!targetNode) {
    return root;
  }

  let lastParent = null;
  let lastNode = null;
  queue = [{ node: root, parent: null }];

  while (queue.length) {
    const topNode = queue.shift();

    lastParent = topNode.parent;
    lastNode = topNode.node;

    if (topNode.node.left) {
      queue.push({ node: topNode.node.left, parent: topNode.node });
    }

    if (topNode.node.right) {
      queue.push({ node: topNode.node.right, parent: topNode.node });
    }
  }

  targetNode.data = lastNode.data;

  if (lastParent) {
    if (lastParent.left === lastNode) {
      lastParent.left = null;
    } else {
      lastParent.right = null;
    }
  } else {
    return null;
  }

  return root;
};

const root = insertNode(null, 10);
insertNode(root, 20);
insertNode(root, 30);
insertNode(root, 40);
insertNode(root, 50);
insertNode(root, 60);
insertNode(root, 70);

deleteNode(root, 10);

// printTreeLevels(levelOrder(root));
printParentWithChildren(root);
// console.log(preorder(root));
// console.log(inorder(root));
// console.log(postorder(root));
// console.log("Has 300", searchDFS(root, 300));
