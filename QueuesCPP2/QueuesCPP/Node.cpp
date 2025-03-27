#include "Node.hpp"

Node::Node(const string newData)
{
    this->mJob = newData;
    this->mpNext = nullptr; // always set the new Node's next pointer to nullptr initially
}

Node::~Node()
{
    cout << "deleting print job: " << this->mJob << endl;
}

string Node::getData() const
{
    return this->mJob;
}

Node* Node::getNextPtr() const
{
    return mpNext;
}

void Node::setNextPtr(Node* const newNextPtr)
{
    this->mpNext = newNextPtr;
}
