# Generic Splay Tree
Implementation of a Generic Splay Tree in C++.

### Member Functions

|Iterators | |
|-----|-----|
| begin | Return iterator to beginning (default traversal is inorder) |
| end | Return iterator to end (default traversal is inorder) |
| begin_in | Return iterator to beginning (inorder traversal) |
| end_in | Return iterator to end (inorder traversal) |
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
- See ```test.cpp``` for examples on how to use the ```splay``` class.    
