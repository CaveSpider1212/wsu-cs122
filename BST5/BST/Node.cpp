#include "Node.hpp"

string Node::getData() const
{
    return this->data;
}

Node* Node::getLeftPtr() const
{
    return this->mpLeft;
}

Node* Node::getRightPtr() const
{
    return this->mpRight;
}

void Node::setLeftPtr(Node* newLeftPtr)
{
    this->mpLeft = newLeftPtr;
}

void Node::setRightPtr(Node* newRightPtr)
{
    this->mpRight = newRightPtr;
}
