#include "BinaryTree.hpp"

BinaryTree::BinaryTree(int payload)
{
    this->payload = payload;
    this->leftChild = 0;
    this->rightChild = 0;
}

void BinaryTree::displayInOrder(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }

    displayInOrder(node->left);
    cout << node->data << " ";
    displayInOrder(node->right);
}
        
void BinaryTree::displayPreOrder(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }

    cout << node->data << " ";
    displayPreOrder(node->left);
    displayPreOrder(node->right);
}

void BinaryTree::displayPostOrder(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }

    displayPostOrder(node->left);
    displayPostOrder(node->right);
    cout << node->data << " ";
}

void BinaryTree::add(int payload)
{
    if(payload <= this->payload)
    {
        //should go to my left
        if(!this->leftChild)
        {
            this->leftChild = new BinaryTree(payload);
        }
        else
        {
            this->leftChild->add(payload);
        }
    }
    else
    {
        //should go to my right
        if(!this->rightChild)
        {
            this->rightChild = new BinaryTree(payload);
        }
        else
        {
            this->rightChild->add(payload);
        } 
    } 
}