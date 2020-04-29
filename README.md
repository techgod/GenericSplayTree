# Generic Splay Tree
Implementation of a Generic Splay Tree in C++.

###### What's a Splay Tree?
A splay tree is a self-balancing binary search tree with the additional property that recently accessed elements are quick to access again. It performs basic operations such as insertion, look-up and removal in O(log n) amortized time.

To see how splay trees work, check out this [Splay Trees Visualization.](https://www.cs.usfca.edu/~galles/visualization/SplayTree.html)

### Member Functions

|Iterators | |
|-----|-----|
| begin | Return iterator to beginning (default traversal is inorder) |
| end | Return iterator to end (default traversal is inorder) |
| rbegin | Return reverse iterator to reverse beginning (default traversal is inorder) |
| rend | Return reverse iterator to reverse end  (default traversal is inorder) |
| begin_in | Return iterator to beginning (inorder traversal) |
| end_in | Return iterator to end (inorder traversal) |
| rbegin_in |  Return reverse iterator to reverse beginning (inorder traversal) |
| rend_in | Return reverse iterator to reverse end (inorder traversal) |
| begin_pre | Return iterator to beginning (default inorder traversal) |
| end_pre | Return iterator to end (default inorder traversal) |
| begin_post | Return iterator to beginning (default inorder traversal) |
| end_post | Return iterator to end (default inorder traversal) |

<br>

|Capacity | |
|-----|-----|
| size | Return size |
| empty | Test whether splay tree is empty |

<br>


|Modifiers | |
|-----|-----|
| insert | Insert an element by value |
| erase | Test whether splay tree is empty |
| clear | Clear enitre contents of splay tree |

<br>

### Setup
- Add ```splay.hpp``` to the same directory as where it is being used
- Use  ```#include "splay.h"```  preprocessing directive in the file where the splay tree is being used
<br>

### Usage
- Usage is similar and in line with other STL containers.
- See ```examples.cpp``` for examples on how to use the ```splay``` class.    
