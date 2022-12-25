// Binary tree => Here , binary name itself suggest two numbers 0 or 1 . In a binary tree each node can have utmost two child nodes. Here Utmost meaning whether the 0 , 1 , or 2 child nodes.

// Properties of binary tree =>
// (1) => The maximum number of nodes in a binary tree at level i => 2^i
// (2) => The maximum number of nodes in a binary tree of height h
// (a) => The height of a tree with single node is considered as 1 => 2^h-1
// (b) => The height of a tree with single node is considered as 0 => 2^h+1-1
// (3) => The minimum number of nodes in a binary tree of height h => h+1
// (4) => In a Binary Tree with N nodes, the minimum possible height or the minimum number of levels is => log(n+1)
// (5) => In a Binary Tree with N nodes, the maximum possible height => n-1

// Types of binary tree =>

// (1) => Full/Perfect/Strict => Each node has either 0 or 2 child nodes
// max nodes => 2^h-1
// min nods => 2h+1
// min height => log(n+1)
// max height => ( n-1)/2

// (2) => Complete binary tree => All the levels are completly filled and the last level has nodes as left as possible.
// max nodes => 2^h-1
// min nods => 2^h
// min height => log(n+1)
// max height => logn

// (3) => Perfect binary tree => All the internal nodes has two children and all leaves node are at same level
// A perfect binary tree of height h has 2h + 1 – 1 node.
// A perfect binary tree with n nodes has height log(n + 1) – 1.
// A perfect binary tree of height h has 2h leaf nodes.

// (4) => Degenrate binary tree => A Tree where every internal node has one child. Such trees are performance-wise same as linked list. A degenerate or pathological tree is a tree having a single child either left or right.

// (5) => Skewed Binary Tree => A skewed binary tree is a pathological/degenerate tree in which the tree is either dominated by the left nodes or the right nodes. Thus, there are two types of skewed binary tree: left-skewed binary tree and right-skewed binary tree.