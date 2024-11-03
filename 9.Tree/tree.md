## Tree transversal tecnhiques from GeeksForGeeks
### DFS - Depth First Search
#### inorder Left -> Root -> Right
//Inorder traversal gives nodes in non-decreasing order
// To get nodes of BST in non-increasing order, a variation of inorder traversal where inorder traversal is reversed can be used.
#### preorder Root ->n Left -> Right
// Preorder traversal is used to create a copy of the tree
// Preorder traberssal is also used to get prefix expressions on an expression tree.
####  postorder Left -> Right -> Root
//Postorder is used to delete the tree.
//Postorder traversal is also useful to get the postfix ezpression of an expression tree.
//Postorder traversal can help in garbage collection algorithms, particulary in system where manual memory managment is used.

### BFS Breadth First Search
#### Levelorder
// Level Order Traversal is mainly used as Breadth First Search to search or process nodes level-by-level.

### FAQs (Frquently Asked Questions) on Tree Traversal Techniques:
1. What are tree traversal techniques?

Tree traversal techniques are methods used to visit and process all nodes in a tree data structure. They allow to acess each node exactly once in a sytematic manner.


2. What are common types of tree traversal?

The common types of tree traversal are: Inorder traversal, Preorder traversal, Postorder traversal and Level order traversal (Breadth First Search).

3. What is Inorder traversal?

Inorder traversal is a depth-first traversal where nodes are visited in the order: left subtree, current node, right subtree.


4. What is Preorder traversal?

Preorder traversal is a depth-first traversal where nodes are visited int the order: current node, left subtree, right subtree.

5. What is Postorder traversal?

Postorder traversal is a depth-first traversal where nodes are visited in the order: left subtree, right subtree, current node.

6. What is level order traversal?

Level order traversal also known as Breadth First Search BFS, vissits nodes level-by-level, starting from the root moving to the next level before traversing depper.


7. When should I use each traversal technique?

Inorder traversal is often used for binary search trees to get nodes in sorted order.

Preorder traversal is useful to create a copy of tree.

Postorder traversal is commonly used in expression trees to evaluate expressions.

Level order traversal is helpful for finding shortest path between nodes.

8. How do I implement tree traversal algorithms?

Tree traversal algorithm can be implemented recursively or iteratively, depending on specific requirement or programming language being used.

9. Can tree traversal algorithms be applied to other tree-like structures?

Yes, tree traversal algorithms can be adapted to traverse other tree-like structures such binary heaps, n-ary trees, and graphs represented as trees.
