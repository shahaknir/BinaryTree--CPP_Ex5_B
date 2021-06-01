//
// Created by shahak on 31/05/2021.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

#include "sources/BinaryTree.hpp"
#include "doctest.h"

using namespace ariel;

TEST_CASE("Initialize trees of different kinds"){
    CHECK_NOTHROW(BinaryTree <string> treeOfString);
    CHECK_NOTHROW(BinaryTree <int> treeOfInt);
    CHECK_NOTHROW(BinaryTree <double> treeOfDouble);
    CHECK_NOTHROW(BinaryTree <char> treeOfChar);
}

TEST_CASE("String tree"){
    BinaryTree <string> treeOfString;
    string root = "root";
    string lson = "this is the story of:";
    string rson = "right son";

    CHECK_NOTHROW(treeOfString.add_root(root));
    CHECK_NOTHROW(treeOfString.add_left(root, lson));
    CHECK_NOTHROW(treeOfString.add_right(root, rson));
    CHECK_NOTHROW(treeOfString.add_right(lson, "winnie"));
    CHECK_NOTHROW(treeOfString.add_left(rson, "winnie"));
    CHECK_NOTHROW(treeOfString.add_right("winnie", "the pooh"));
    // Sense having 2 nodes with the same data - this tests come to check whether the Node was
    // added to the propitiate Node


    /*
     *
     *
     *
     *
     *
     *
     */

}

TEST_CASE("Int tree"){
    BinaryTree <int> treeOfInt;
    int a= 1, b=2, c=3,d=4, e=5, f=6, g=7, h=8;
    std::vector<int> postOrder = {4, 7, 8, 5, 2, 1, 6, 3};
    std::vector<int> inOrder = {4, 2, 7, 5, 8, 1, 3, 6};
    std::vector<int> preOrder = {1, 2, 4, 5, 7, 8, 3, 6};

    CHECK_NOTHROW(treeOfInt.add_root(a));
    CHECK_NOTHROW(treeOfInt.add_right(a, c));
    CHECK_NOTHROW(treeOfInt.add_left(a, b));

    CHECK_NOTHROW(treeOfInt.add_right(b, e));
    CHECK_NOTHROW(treeOfInt.add_left(b, d));

    CHECK_NOTHROW(treeOfInt.add_right(c, f));

    CHECK_NOTHROW(treeOfInt.add_right(e, h));
    CHECK_NOTHROW(treeOfInt.add_left(e, g));

    u_int i=0;
    for(auto it = treeOfInt.begin_preorder(); it!=treeOfInt.end_preorder(); it++){
        CHECK_EQ(*it, preOrder.at(i));
        i++;
    }
    i=0;
    for(auto it = treeOfInt.begin_inorder(); it!=treeOfInt.end_inorder(); it++){
        CHECK_EQ(*it, inOrder.at(i));
        i++;
    }
    i=0;
    for(auto it = treeOfInt.begin_postorder(); it!=treeOfInt.end_postorder(); it++){
        CHECK_EQ(*it, postOrder.at(i));
        i++;
    }
    CHECK_NOTHROW(cout<<treeOfInt<<endl);
    /*
     *          a
     *        /   \
     *      b       c
     *    /   \      \
     *   d     e      f
     *        /  \
     *       g    h
     *
     */

}

TEST_CASE("Double tree"){
    BinaryTree <double> treeOfDouble;
    double a= 0.1, b=2.564, c=38.4,d=4.0, e=0.5, f=6.6, g=7.95, h=8.11;
    std::vector<double> postOrder = {4.0, 7.95, 8.11, 0.5, 2.564, 0.1, 6.6, 38.4};
    std::vector<double> inOrder = {4.0, 2.564, 7.95, 0.5, 8.11, 0.1, 38.4, 6.6};
    std::vector<double> preOrder = {0.1, 2.564, 4.0, 0.5, 7.95, 8.11, 38.4, 6.6};

            CHECK_NOTHROW(treeOfDouble.add_root(a));
            CHECK_NOTHROW(treeOfDouble.add_right(a, c));
            CHECK_NOTHROW(treeOfDouble.add_left(a, b));

            CHECK_NOTHROW(treeOfDouble.add_right(b, e));
            CHECK_NOTHROW(treeOfDouble.add_left(b, d));

            CHECK_NOTHROW(treeOfDouble.add_right(c, f));

            CHECK_NOTHROW(treeOfDouble.add_right(e, h));
            CHECK_NOTHROW(treeOfDouble.add_left(e, g));

    u_int i=0;
    for(auto it = treeOfDouble.begin_preorder(); it!=treeOfDouble.end_preorder(); it++){
                CHECK_EQ(*it, preOrder.at(i));
        i++;
    }
    i=0;
    for(auto it = treeOfDouble.begin_inorder(); it!=treeOfDouble.end_inorder(); it++){
                CHECK_EQ(*it, inOrder.at(i));
        i++;
    }
    i=0;
    for(auto it = treeOfDouble.begin_postorder(); it!=treeOfDouble.end_postorder(); it++){
                CHECK_EQ(*it, postOrder.at(i));
        i++;
    }


}
