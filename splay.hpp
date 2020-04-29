/**
 * Generic Splay Trees
 * 
 * A lightweight generic implementation of Splay Trees.
 * 
 */

template<typename ndt>
class Node
{
    public:
    Node(const ndt& data) : data_(data),left_(nullptr),right_(nullptr),parent_(nullptr){}

    template<typename dt>
    friend class splay;
    
    private:
    ndt data_;
    Node<ndt> * left_;
    Node<ndt> * right_;
    Node<ndt> * parent_;
};

template<typename dt>
class splay
{
    public:

    enum traversal{inorder,preorder,postorder};
    typedef Node<dt> node;

    explicit splay() : size_(0),root_(nullptr),it_type_(inorder) {}

    ~splay()
	{
		destroy_splay_tree(root_);
	}

    class Iterator
    {
        public:

        //Iterator Constructor
        explicit Iterator(splay<dt> &outer, node* it_node = nullptr) : it_outer_(outer), it_node_(it_node){}
        
        //Iterator Class Public Methods

        bool operator==(const Iterator& rhs) const
        {
            return it_node_==rhs.it_node_;
        }
        bool operator!=(const Iterator& rhs) const
        {
            return !(*this==rhs);
        }
        Iterator& operator++() //pre increment
        {
            if(it_outer_.it_type_ == inorder)
            {
                set_inorder_successor(); //Sets value of it_node_ to inorder successor
            }
            else if(it_outer_.it_type_ == preorder)
            {
                set_preorder_successor(); //Sets value of it_node_ to preorder successor
            }
            else if(it_outer_.it_type_ == postorder)
            {
                set_postorder_successor(); //Sets value of it_node_ to preorder successor
            }
            return *this;
        }

        Iterator& operator--() //pre increment
        {
            if(it_outer_.it_type_ == inorder)
            {
                set_inorder_predecessor();
            }
        }



        Iterator operator++(int) //post increment
        {
            Iterator temp(it_outer_,*this); //Using default copy constructor
            return ++(*this);
            return temp;
        }
        dt operator*()
        {
            return it_node_->data_;
        }

        private:
        node* it_node_; //The current node in the iterator. LHS value
        splay<dt> &it_outer_;

        //Iterator Class Private Methods

        /**
         * Setting it_node_ as the inorder successor
         * 
         * If the current node has a non-null right child,
         * - Take a step down to the right
         * - Then run down to the left as far as possible
         * 
         * If the current node has a null right child,
         * - move up the tree until we have moved over a left child link
         */
        void set_inorder_successor()
        {
            if(it_node_->right_)
		    {
			    it_node_ = it_node_->right_;
			    while(it_node_->left_)
                {
                    it_node_ = it_node_->left_;
                }
            }
		    else
		    {
                //Keep running loop till current node is left child of parent
                while (it_node_->parent_ != nullptr && it_node_ != it_node_->parent_->left_)
                {
                    it_node_ = it_node_->parent_;
                }

                // Parent is inorder successor
                it_node_ = it_node_->parent_;
            }
        }


        void set_inorder_predecessor()
        {
            int flag = 1;
            if(it_node_->left_)
            {
                it_node_ = it_node_->left_;
                while(it_node_->right_)
                {
                    it_node_ = it_node_->right_;
                }
            }
            else
            {
                if(it_node_->parent_)
                {
                    while(it_node_->parent_)
                    {
                        if(it_node_->parent_->right_ == it_node_)
                        {
                            it_node_ = it_node_->parent_;
                            flag = 0;
                            break;
                            // return *this;
                        }
                        else
                            it_node_ = it_node_->parent_;
                    }               
                }   
                if(flag)
                    it_node_ = nullptr;
                        
            }
            // return *this;
        
        }
         /**
         * Setting it_node_ as the preorder successor
         * 
         * For the current node,
         * - if it has a left child, then its left child is preorder successor
         * - if it does not have a left child but has a right child, then its right child is preorder successor
         * - Then run down to the left as far as possible
         * 
         * If there is no left or right child, i.e. is a leaf node, then
         * - search for nearest ancestor which has value greater than current value, and has a right child.
         * -- if such an ancestor exists, then its right child is successor,
         * -- else there is no successor.
         * 
         */
        void set_preorder_successor()
        {
            if(it_node_->left_)
            {
                //has a left child
                it_node_ = it_node_->left_; 
            }
            else if(it_node_->right_)
            {
                //has a right child
                it_node_ = it_node_->right_; 
            }
            else 
            { 
                //is a leaf node
                node *temp = it_node_->parent_; 
                while(temp){ 
                    if(it_node_->data_ < temp->data_ && temp->right_) // find ancestor with value greator than current node value and which has a right ancestor
                    {
                        break; 
                    }
                    temp = temp->parent_; 
                } 
                if(temp)
                {
                    it_node_ = temp->right_;
                }
                else
                {
                    it_node_ = nullptr;
                }
            } 
        }

        /**
         * Setting it_node_ as the postorder successor
         * 
         * For the current node,
         * - if it is the root, then there is no postorder successor (root should be last)
         * - if given node is right child, or right child of parent is null, then parent is successor
         * - if given node is left child of parent and right child exists. then find sucessor in right sub tree
         * 
         */
        void set_postorder_successor()
        {
            if (it_node_->parent_ == nullptr) //root
            {
                it_node_ = nullptr; 
            }
            else if (it_node_ == it_node_->parent_->right_ || it_node_->parent_->right_ == nullptr)
            {
                //if right child of parent or parent doesn't have a right child
                it_node_ = it_node_->parent_; 
            }    
            else
            {
                //basically current node is left child, and right sub tree exists
                it_node_ = find_post_successor_in_rst(it_node_->parent_->right_);
            }
        }

        node* find_post_successor_in_rst(node* rst_root) 
            {
                if (rst_root == nullptr) 
                {
                    return nullptr;
                }

                if(rst_root->left_ == nullptr && rst_root->right_ == nullptr)
                {
                    //leaf node -- no lst or rst
                    return rst_root;
                }

                //if root node doesn't have a left child
                if (rst_root->left_ == nullptr)
                {
                    //no lst or rst
                    return find_post_successor_in_rst(rst_root->right_);
                }
                else
                {
                    while(rst_root->left_ != nullptr)
                    {
                        //rst has a left child. find leftmost child
                        rst_root=rst_root->left_;
                    }
                    return rst_root;
                }
        }
        
    };

    //Splay Class Public Methods

    //Default traversal is inorder
    Iterator begin()
    {
        return begin_in();
    }
    Iterator end()
    {
        return end_in();
    }
    Iterator rbegin()
    {
        return rbegin_in();
    }
    Iterator rend()
    {
        return rend_in();
    }

    Iterator rbegin_in()
    {
        it_type_ = inorder;        
        if(root_ == nullptr)
        {
            return Iterator(*this,nullptr);
        }
        node *temp = root_;
        while(temp->right_ != nullptr)
        {
            temp = temp->right_;
        }

        return Iterator(*this,temp);

    }

    Iterator begin_in()
    {
        //Inorder
        //Begins with the left most leaf node

        it_type_ = inorder;

        if(root_ == nullptr)
        {
            return Iterator(*this,nullptr);
        }

        node *temp = root_;
        while(temp->left_ != nullptr)
        {
            temp = temp->left_;
        }

        return Iterator(*this,temp);
    }

    Iterator begin_pre()
    {
        //Preorder
        //Begins with the root node

        it_type_ = preorder;

        return Iterator(*this,root_);
    }

    Iterator begin_post()
    {
        //Postorder

        it_type_ = postorder;

        if(root_ == nullptr)
        {
            return Iterator(*this,nullptr);
        }

        return Iterator(*this,preorder_helper(root_));
    }

    Iterator end_in()
    {
        return Iterator(*this,nullptr);
    }
    Iterator rend_in()
    {
        return Iterator(*this,nullptr);
    }

    Iterator end_pre()
    {
        return Iterator(*this,nullptr);
    }

    Iterator end_post()
    {
        return Iterator(*this,nullptr);
    }

    void insert(const dt &data)
    {
        node *temp = new node(data);
        insert_node(temp);
    }

    Iterator find(const dt &data)
    {
        return Iterator(*this,search_node(root_,data));
    }

    unsigned int size()
    {
        return size_;
    }

    bool empty() 	
    {	
        return (size_ == 0);	
    }

    void erase(const dt &data) 
    {
        delete_node(data);
    }

    private:

    // Splay Class Variables
    node *root_; //Root element of the splay tree
    unsigned int size_; //Size of the splay tree
    traversal it_type_;

    // Splay Class Private Methods
    /**
     * Helper method to find start element of preorder traversal
     *  
     * @param root : root element
     * @return : pointer node which is the first element of the preorder traversal
     */
    node* preorder_helper(node* root) 
    {
        while(root->left_ != nullptr)
        {
            //finds leftmost child
            root=root->left_;
        }

        // If this is a leaf node, this is the first element in preorder
        if (root->right_ == nullptr) 
        {
            return root;
        }
        
        //There is a right subtree - recursively explore that
        else
        {
            return preorder_helper(root->right_);
        }
    }

    /**
     * Insert Node into Splay Tree
     *
     * Inserts node based on value (follows BST property).
     * Once inserted, element is splayed to the top.
     *  
     * @param n : the node to be inserted into the tree
     * @return : nothing (void)
     */
   void insert_node(node *n) 
   {
        node *prev = nullptr;
        node *curr = root_;
    
        //Find appropriate leaf node
        while(curr != nullptr) 
        {
            prev = curr;

            if(n->data_ < curr->data_)
            {
                curr = curr->left_;
            }
            else
            {
                curr = curr->right_;
            }
        }

        // Assign Parent
        n->parent_ = prev;

        if(n->parent_ == nullptr) 
        {
            //n turns out to be the root
            root_ = n;
        }
        else if(n->data_ < n->parent_->data_)
        {
            // make n as left child of parent.
             n->parent_->left_ = n;
        }
        else
        {
            // make n as right child of parent.
            n->parent_->right_ = n;
        }

        //Incremenet size
        ++size_;

        // Splay element to the top
        splayify(root_,n);
    }

    void destroy_splay_tree(node *root)
    {
        if(root == nullptr)
        {	
            size_ = 0;
            return;
        }
        destroy_splay_tree(root->left_);
        destroy_splay_tree(root->right_);
        delete root;
    }

    // Splay Class - Splay Tree Specific Private Methods


    /**   
     * Types of Rotations in Splay Trees
     * 
     * 				y                                     x
     * 	           / \     Zig (Right Rotation)          /  \
     * 	          x   T3   – - – - – - – - - ->         T1   y 
     * 	         / \       < - - - - - - - - -              / \
     * 	        T1  T2     Zag (Left Rotation)            T2   T3
     */


    /**
     * Zig : Right rotation
     * 
     * Rotating towards the right. Please look at the diagram on top.
     * 
     * @param y : the node about which rotation is done
     * @return : nothing (void)
     */
    void zig(node* &root, node *y) 
    {
        node *x = y->left_;
        y->left_ = x->right_;

        if(x->right_ != nullptr) 
        {
            x->right_->parent_ = y;
        }
        x->parent_ = y->parent_;

        if(y->parent_ == nullptr) 
        {
            //y is root
            root = x;
        }
        else if(y == y->parent_->right_) 
        { 
            //y is left child
            y->parent_->right_ = x;
        }
        else 
        { 
            //y is right child
            y->parent_->left_ = x;
        }
        x->right_ = y;
        y->parent_ = x;
    }


    /**
     * Zag : Left rotation
     * 
     * Rotating towards the left. Please look at the diagram on top.
     * 
     * @param x : the node about which rotation is done
     * @return : nothing (void)
     */
    void zag(node* &root, node *x) 
    {
        node *y = x->right_;
        x->right_ = y->left_;
        if(y->left_ != nullptr) 
        {
            y->left_->parent_ = x;
        }
        y->parent_ = x->parent_;
        if(x->parent_ == nullptr) 
        { 
            //x is root
            root = y;
        }
        else if(x == x->parent_->left_) 
        { 
            //x is left child
            x->parent_->left_ = y;
        }
        else 
        { 
            //x is right child
            x->parent_->right_ = y;
        }
        y->left_ = x;
        x->parent_ = y;
    }

    /**
     * Brings an element to the root while keeping it a BST.
     * 
     * Continue zig or zag rotations, until the node to be splayed up doesn't become the root of the tree.
     * 
     * If a node has both a parent and a grandparent, there can be four types of cases...
     * 
     * Left-Left Case:
     * 
     *               G                        P                           X       
     *              / \                     /   \                        / \      
     *             P  T4      zig(G)       X     G        zig(P)       T1   P     
     *            / \      ============>  / \   / \    ============>       / \    
     *           X  T3                   T1 T2 T3 T4                      T2  G
     *          / \                                                          / \ 
     *         T1 T2                                                        T3  T4 
     * 
     * 
     * Right-Right Case:
     *          G                          P                           X       
     *         /  \                      /   \                        / \      
     *        T1   P         zag(G)     G     X     zag(G)           P   T4
     *            / \    ============> / \   / \    ============>   / \   
     *          T2   X                T1 T2 T3 T4                  G   T3
     *              / \                                          / \ 
     *             T3 T4                                        T1  T2
     * 
     * 
     * Left-Right Case:
     *           G                        G                            X       
     *          / \                     /   \                        /   \      
     *         P   T4      zag(P)      X     T4        zig(G)       P     G     
     *        /  \      ===========>  / \          ============>   / \   /  \    
     *       T1   X                   P  T3                       T1  T2 T3  T4 
     *           / \                 / \                                       
     *          T2  T3              T1   T2                                     
     * 
     * 
     * Right-Left Case:
     *       G                          G                           X       
     *      /  \                      /  \                        /   \      
     *     T1   P        zig(P)     T1    X        zag(G)        G     P
     *         / \   =============>      / \    ============>   / \   / \   
     *        X  T4                    T2   P                 T1  T2 T3  T4
     *       / \                           / \                
     *      T2  T3                        T3  T4  
     * 
     * 
     * @param root : The current root of the tree being splayed.
     * @param n: Node to be splayed to the top of the tree.
     * @return nothing (void)
     * 
     */
    void splayify(node* &root, node *n) {
        while(n->parent_ != nullptr) // i.e. until node is not the root
        { 
            if(n->parent_ == root) 
            {
                // has only parent and no grandparent 
                if(n == n->parent_->left_) 
                {
                    // node is left child
                    zig(root, n->parent_);
                }
                else 
                {
                    // node is right child
                    zag(root, n->parent_);
                }
            }
            else {
                node *p = n->parent_; //parent
                node *g = p->parent_; //grandparent

                if(n->parent_->left_ == n && p->parent_->left_ == p) 
                { 
                    // Zig-Zig i.e. Left Left Case
                    zig(root,g);
                    zig(root,p);
                }
                else if(n->parent_->right_ == n && p->parent_->right_ == p) 
                { 
                    // Zag-Zag i.e. Right Right Case
                    zag(root,g);
                    zag(root,p);
                }
                else if(n->parent_->right_ == n && p->parent_->left_ == p) 
                { 
                    // Zag-Zig i.e. Right Left Case
                    zag(root,p);
                    zig(root,g);
                }
                else if(n->parent_->left_ == n && p->parent_->right_ == p) 
                { 
                    // Zig-Zag i.e. Left Right Case
                    zig(root,p);
                    zag(root,g);
                }
            }
        }
    }


     /**
     * Search for a node.
     * 
     * Find node where element is found.
     * 
     * @param root : The root of the tree/subtree being searched.
     * @param data : The value of the element being searched for
     * @return: the node where the element is found
     */
    node* search_node(node *n,const dt &data) 
    {
        if(n==nullptr)
        {
            return nullptr;
        }
        if(data == n->data_) {
            splayify(root_,n);
            return n;
        }
        else if(data < n->data_)
        {
            //Element in lst
            return search_node(n->left_, data);
        }
        else if(data > n->data_)
        {
            //Element in rst
            return search_node(n->right_, data);
        }
        return nullptr;
    }



     /**
     * Delete a node.
     * 
     * The steps involved for this are as follows,
     * - Search and find the node to be deleted.
     * - The search process spalys the node to the root
     * - Hence the element to be deleted is at the root.
     * - Now, delete the root element. We will have two non connected trees (lst,rst)
     * - Search for the largest element of the left subtree and splay it to the top
     * - Attach rst as right child of this element (being the largest element in the lst, it would not already have a right child when its the root)
     * 
     * @param data : value of element to be deleted.
     * @return: no return (void)
     */
    void delete_node(const dt &data)
    {
        node* root = search_node(root_,data);

        if(root==nullptr)
        {
            return;
        }

        node* lst_root = root->left_;
        if(lst_root != nullptr)
        {
            lst_root->parent_=nullptr;
        }

        node* rst_root = root->right_;
        if(rst_root != nullptr)
        {
            rst_root->parent_=nullptr;
        }

        delete root;
        --size_;

        if(lst_root != nullptr) {
            //Find max (rightmost) value of lst.
            node* maxele = lst_root;
            while(maxele->right_ != nullptr)
            {
                maxele=maxele->right_;
            }
            //Splay this element to the root of lst.
            splayify(lst_root,maxele);
            lst_root->right_ = rst_root;
            root_ = lst_root;
        }
        else
        {
            //There is no lst. Make rst root as splay tree root.
            root_ = rst_root;
        }
    
    }

};

