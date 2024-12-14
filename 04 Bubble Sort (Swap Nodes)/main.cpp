#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(NULL), next(NULL) {}

    Node(Node &node)
    {
        this->data = node.data;
        this->prev = node.prev;
        this->next = node.next;
    }
};


class doublyLinkedList
{
private:
    Node * head;
    Node * tail;

    Node* getNode(int _data)
    {
        Node *current=head;
        while(current != NULL )
        {
            if(current->data == _data)
            {
                return current;
            }
            current=current->next;
        }
        return NULL;
    }

    public:
        doublyLinkedList()
        {
            head = tail = NULL;
        }

        void addNode(int _data)
        {
            Node *newNode = new Node(_data);

            if(head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void addNodeAfter(Node *newNode, Node *currentNode)
        {
            if(currentNode == NULL)
            {
                cout << "\nThere is NO node to add data after !!!\n";
            }
            else if(tail == currentNode)
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else
            {
                newNode->next = currentNode->next;
                newNode->prev = currentNode;
                currentNode->next->prev = newNode;
                currentNode->next = newNode;
            }
        }



        Node* deleteNodeConnections(Node *node)
        {
            if(node == NULL)
            {
                cout << "\nNo node is found !!!\n";
            }
            else if(head == node)
            {
                if(head == tail)
                {
                    head = tail = NULL;
                }
                else
                {
                    head = head->next;
                    head->prev = NULL;
                }
            }
            else if(tail == node)
            {
                tail=tail->prev;
                tail->next = NULL;
            }
            else
            {
                Node * A= node->prev;
                Node * B= node->next;
                A->next=B;
                B->prev=A;
            }

            return node;
        }

        void print()
        {
            Node *current=head;

            if(current == NULL){
                cout << "\nThe doubly linked list is already Empty !!!";
            }
            else
            {
                cout << "[\t";
                while(current != NULL )
                {
                    cout << current->data << "\t";
                    current = current->next;
                }
                cout << "]\n";
            }
        }

        void bubbleSort()
        {
            if (head == NULL)
            {
                cout << "\nNo data to be sorted !!!\n";
            }
            else
            {
                bool swapped;
                Node* current;
                do
                {
                    swapped = false;
                    current = head;

                    while (current->next != NULL)
                    {
                        if (current->data > current->next->data)
                        {
                            Node* nextNode = current->next;
                            this->deleteNodeConnections(current);
                            this->addNodeAfter(current, nextNode);
                            swapped = true;
                            current = nextNode;
                        }
                        current = current->next;
                    }
                } while (swapped);
            }
        }
};


int main()
{
    doublyLinkedList l;
    l.bubbleSort();

    cout << "\n----------------------------------------------------------------------------------------\n\n";

    l.addNode(6);
    l.addNode(7);
    l.addNode(8);
    l.addNode(2);
    l.addNode(4);
    l.addNode(3);
    l.addNode(5);
    l.addNode(1);


    cout << "Linked List before sorting: \n";
    l.print();

    l.bubbleSort();

    cout << "\n\nLinked List after sorting: \n";
    l.print();

    return 0;
}
