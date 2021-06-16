/**
  * Created by shahak on 31/05/2021.
  */

#pragma once
#include <iostream>
#include <list>
#include <map>

#include <stack>

namespace ariel {

    template<typename T> class BinaryTree {
        // using iterator = typename std::list<T>::iterator;

        struct Node {
            T node;
            Node *right, *left, *parent;
            explicit Node(T node): node(node), right(nullptr), left(nullptr){}
        };

        class iterator {
        private:
            Node* curr_node;
        public:
            explicit iterator(Node* n = nullptr):curr_node(n) {}

//                    ~iterator() {
//                        delete (curr_node);
//                    }

            iterator& operator++ (){
                return *this;
            }
            iterator operator++ (int a){
                iterator t{curr_node};
                return t;
            }

            bool operator!= (const iterator& other){
//                        if(this->curr_node == other){
//                            return true;
//                        }
                return false;
            }

            const T& operator* () const {

                return curr_node->node;
            }
            const T* operator->() const { return &(curr_node->node); }
            // friend std::ostream& operator <<(std::ostream& os, const iterator& it) {return os << "*it = " << curr_node_ptr << std::endl;}
        };

    protected:
        Node* root;
        std::map<T, Node*> node_map;

    public:
        /**
         * add_root - add the head of the tree
        */
        BinaryTree& add_root(T root){
//                Node r = Node(root);
//                this->root = *r;
//                this->node_map.template insert(root,r);
            return *this;
        }

        /**
         * add_right - add the right child to some node in the tree
        */
        BinaryTree& add_right(T node, T rChild){

//                if(!this->node_map.at(node)){
//                    throw invalid_argument{"The parent is un non to the tree"};
//                }
//                Node rchild = Node(rChild);
//                Node* temp = node_map.at(node);
//                temp->right = rchild;
            return *this;
        }
        /**
         * add_left - add the left child to some node in the tree
        */
        BinaryTree& add_left(T node, T lChild){
//                if(!this->node_map.at(node)){
//                    throw invalid_argument{"The parent is un non to the tree"};
//                }
//                Node lchild = Node(lChild);
//                Node* temp = node_map.at(node);
//                temp->left = lchild;
            return *this;
        }

        /**
         * postorder
        */
        class postorder : public iterator{
        protected:
            Node * post_start = nullptr;
            stack<Node*> post_stack;

        public:
            postorder(Node* ptr = nullptr){
                post_start = ptr;
                if(post_start != nullptr){
                    stack<Node*> start;
                    start.push(post_start);
                    while(!start.empty()){
                        Node* temp_node = start.top();
                        start.pop();
                        post_stack.push(temp_node);
                        if(temp_node->left != nullptr){
                            start.push(temp_node->left);
                        }
                        if(temp_node->right != nullptr){
                            start.push(temp_node->right);
                        }
                    }
                    this->post_start = post_stack.top();
                    }else {
                    this->post_start = nullptr;
                }

            }

        };
        iterator begin_postorder(){
            return iterator{root};
        }
        iterator* end_postorder(){return nullptr;}

        /**
         * preorder
        */
        iterator begin_preorder(){return iterator{root};}
        iterator* end_preorder(){return nullptr;}
        /**
         * inorder
        */
        iterator begin_inorder(){return iterator{root};}
        iterator* end_inorder(){return nullptr;}

        /**
         * iter normal
        */
        iterator begin(){return iterator{root};}
        iterator* end(){return nullptr;}

        friend std::ostream& operator<<(std::ostream& out, BinaryTree<T> const &tree){
            return out << "Printing tree" << std::endl;
        }
    };
};