#include<iostream>
#include "splay.hpp"

using namespace std;

int main()
{
    splay<int> s;

    /**
     * The value class of splay has to support the following:
     * - Default Constructor for default value
     * - Comparision operation (e.g. <, = , >)
     */
    

    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(7);
    s.insert(8);
    s.insert(4);

    //Default (Inorder) Traversal
    cout<<"Inorder traversal: ";
    for(auto i = s.begin(); i!=s.end(); ++i)
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

    auto res = s.find(3);
    if(res!=s.end())
    {
        cout<<"Element found."<<"\n";
    }
    else
    {
        cout<<"Element not found! "<<"\n";
    }
    
    s.erase(5);
    s.erase(3);

    for(auto i = s.begin(); i!=s.end(); ++i)cout<<*i<<" "; //Print Inorder

    cout<<"\n";

    return 0;
}