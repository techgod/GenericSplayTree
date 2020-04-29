#include<iostream>
#include "splay.hpp"

using namespace std;

int main()
{
    #if 0       //testcase 1
    splay<int> s;

    /**
     * The value class of splay has to support the following:
     * - Default Constructor for default value
     * - Comparision operation (e.g. <, = , >)
     */
    
    s.insert(5);
    s.insert(7);
    s.insert(4);
    s.insert(6);
    #endif
    #if 0           //testcase 2
    splay<int> s;

    s.insert(10);
    s.insert(30);
    s.insert(22);
    s.insert(18);
    s.insert(16);
    s.insert(17);
    #endif
    #if 1       //testcase 3
    splay<int> s;

    // s.insert(10);
    s.insert(10);
    s.insert(16);
    s.insert(5);
    s.insert(15);
    s.insert(18);
    #endif

    //Default (Inorder) Traversal
    cout<<"Inorder traversal: ";
    for(auto i = s.begin(); i!=s.end(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    cout<<"Inorder backward traversal: ";
    for(auto i = s.rbegin(); i!=s.rend(); --i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    
    //Preorder Traversal
    cout<<"Preorder traversal: ";
    for(auto i = s.begin_pre(); i!=s.end_pre(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    //Postorder Traversal
    cout<<"Postorder traversal: ";
    for(auto i = s.begin_post(); i!=s.end_post(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    /*
    auto res = s.find(10);
    if(res!=s.end())
    {
        cout<<"Element found."<<"\n";
    }
    else
    {
        cout<<"Element not found! "<<"\n";
    }

    cout<<"Size of splay tree: "<<s.size()<<"\n";

    s.erase(10);
    s.erase(18);

    cout<<"Size of splay tree after deleteing two elements: "<<s.size()<<"\n";

    for(auto i = s.begin(); i!=s.end(); ++i)cout<<*i<<" "; //Print Inorder

    cout<<"\n";
    */

    return 0;
}