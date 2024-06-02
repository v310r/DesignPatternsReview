#pragma once

#include <string>

template <typename T>
struct BinaryTree;


template <typename T>
struct Node
{
    explicit Node(const T& value)
        : value(value)
    {

    }

    Node(const T& value, Node<T>* const left, Node<T>* const right)
        : value(value), left(left), right(right)
    {
        this->left->tree = this->right->tree = tree;
        this->left->parent = this->right->parent = this;
    }

    void setTree(BinaryTree<T>* t)
    {
        tree = t;
        if (left)
        {
            left->setTree(t);
        }

        if (right)
        {
            right->setTree(t);
        }
    }

    Node<T>* left = nullptr;

    Node<T>* right = nullptr;

    Node<T>* parent = nullptr;

    BinaryTree<T>* tree = nullptr;

    T value;
};

template <typename T>
struct BinaryTree
{
    explicit BinaryTree(Node<T>* const root)
        : root{ root }
    {
        root->setTree(this);
    }

    template<typename U>
    struct PreOrderIterator
    {
        Node<U>* current;

        explicit PreOrderIterator(Node<U>* current)
            : current(current)
        {

        }

        bool operator!=(const PreOrderIterator<U>& other)
        {
            return current != other.current;
        }

        Node<U>& operator*()
        {
            return *current;
        }

        PreOrderIterator<U>& operator++()
        {
            if (current->right)
            {
                current = current->right;
                while (current->left)
                {
                    current = current->left;
                }
            }
            else
            {
                Node<T>* p = current->parent;
                while (p && current == p->right)
                {
                    current = p;
                    p = p->parent;
                }

                current = p;
            }

            return *this;
        }
    };

    typedef PreOrderIterator<T> iterator;

    iterator begin()
    {
        Node<T>* n = root;

        if (n)
        {
            while (n->left)
            {
                n = n->left;
            }
        }

        return iterator {n};
    }

    iterator end()
    {
        return iterator {nullptr};
    }

    //class pre_order_traversal
    //{
    //    BinaryTree<T>& tree;

    //public:
    //    pre_order_traversal(BinaryTree<T>& tree) : tree(tree) {}


    //    iterator begin()
    //    {
    //        return tree.begin();
    //    }

    //    iterator end()
    //    {
    //        return tree.end();
    //    }

    //} pre_order;

    Node<T>* root = nullptr;
};
