/**
 * Generic Splay Trees
 * 
 * Example Implementation
 * This test file provides examples to use all methods of the splay tree library.
 * 
 * To better visualize the splay tree, you can try using this tool, https://www.cs.usfca.edu/~galles/visualization/SplayTree.html
 */

#include<iostream>
#include "splay.hpp"

using namespace std;


// Sample User Defined Class
class Year
{
    //This class only compares the year. Example taken for simplicity.
    public:
    Year():yyyy_(0) {} 
    Year(int yyyy) : yyyy_(yyyy) { }
    bool operator<(const Year& rhs)
    {
        return yyyy_<rhs.yyyy_;
    }
    bool operator>(const Year& rhs)
    {
        return yyyy_>rhs.yyyy_;
    }
    bool operator==(const Year& rhs)
    {
        return yyyy_==rhs.yyyy_;
    }
    bool operator!=(const Year& rhs)
    {
        return !(*this==rhs);
    }
    friend ostream& operator<<(ostream& os, const Year& y);

    private:
    int yyyy_;
    
};

ostream& operator<<(ostream& os, const Year& y)
{
        os << y.yyyy_;
        return os;
}



int main()
{

    //Example 1
    //Insertion and Iterator Traversal
    #if 1

    splay<int> s;
    s.insert(10);
    s.insert(30);
    s.insert(22);
    s.insert(18);
    s.insert(16);
    s.insert(17);
    
    cout<<"Inorder forward traversal:  ";
    for(auto i = s.begin(); i!=s.end(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    cout<<"Inorder reverse traversal:  ";
    for(auto i = s.rbegin(); i!=s.rend(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    
    cout<<"Preorder traversal:         ";
    for(auto i = s.begin_pre(); i!=s.end_pre(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    cout<<"Postorder traversal:        ";
    for(auto i = s.begin_post(); i!=s.end_post(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    #endif

    //Example 2
    //Search
    #if 0

    splay<int> s;
    s.insert(10);
    s.insert(30);
    s.insert(22);
    s.insert(18);
    s.insert(16);
    s.insert(17);

    cout<<"Inorder traversal before searching :";
    for(auto i = s.begin(); i!=s.end(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    if(s.find(22)!=s.end())
    {
        cout<<"Find Result: 22 is present in the splay tree.\n";
    }
    else
    {
        cout<<"Find Result: 22 is not present in the splay tree.\n";    
    }
    
    cout<<"Inorder traversal after searching for 22: ";
    for(auto i = s.begin(); i!=s.end(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    #endif


    //Example 3
    //Copy Constructor, Equality Check and Deletion
    #if 0

    splay<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(22);
    s1.insert(18);
    s1.insert(16);
    s1.insert(17);

    splay<int> s2(s1);

    cout<<"Inorder traversal of s1 before deletion :";
    for(auto i = s1.begin(); i!=s1.end(); ++i) cout<<*i<<" "; cout<<"\n";
    cout<<"Inorder traversal of s2 before deletion :";
    for(auto i = s2.begin(); i!=s2.end(); ++i) cout<<*i<<" "; cout<<"\n";

    s1.erase(16);
    cout<<"Deleted 16 from s1. "<<"\n";

    cout<<"Inorder traversal of s1 after deletion from s1:";
    for(auto i = s1.begin(); i!=s1.end(); ++i) cout<<*i<<" "; cout<<"\n";
    cout<<"Inorder traversal of s2 after deletion from s1:";
    for(auto i = s2.begin(); i!=s2.end(); ++i) cout<<*i<<" "; cout<<"\n";

    #endif


    //Example 4
    //Using other inbuilt data types and remaining methods
    #if 0

    splay<char> s;
    s.insert('a');
    s.insert('f');
    s.insert('e');
    s.insert('b');
    s.insert('d');
    s.insert('c');

    cout<<"Inorder traversal of s: ";
    for(auto i = s.begin(); i!=s.end(); ++i) cout<<*i<<" "; cout<<"\n";    

    cout<<boolalpha;

    cout<<"Is s empty? "<<s.empty()<<"\n";
    cout<<"Size of s: "<<s.size()<<"\n";

    s.clear();

    cout<<"s is cleared."<<"\n";

    cout<<"Is s empty? "<<s.empty()<<"\n";
    cout<<"Size of s: "<<s.size()<<"\n";
    #endif

    //Example 5
    //Using user defined type as splay value class
    //User defined types has to support comparision (<, ==, >)
    #if 0

    splay<Year> y;

    Year y1(2004);
    Year y2(2000);
    Year y3(2012);
    Year y4(2008);
    Year y5(2016);
    Year y6(2020);

    y.insert(y1);
    y.insert(y2);
    y.insert(y3);
    y.insert(y4);
    y.insert(y5);
    y.insert(y6);


    cout<<"Inorder traversal of s: ";
    for(auto i = y.begin(); i!=y.end(); ++i) cout<<*i<<" "; cout<<"\n";    
    cout<<boolalpha;

    cout<<"Is s empty? "<<y.empty()<<"\n";
    cout<<"Size of s: "<<y.size()<<"\n";

    y.clear();

    cout<<"s is cleared."<<"\n";

    cout<<"Is s empty? "<<y.empty()<<"\n";
    cout<<"Size of s: "<<y.size()<<"\n";

    #endif
        
    return 0;
}