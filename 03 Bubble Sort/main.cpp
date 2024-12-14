#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(NULL), next(NULL) {}
};

void swapData(Node* node1, Node* node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

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

        void deleteNode(int _data)
        {
            Node * node=getNode(_data);

            if(node == NULL)
            {
                cout << "\nNo node with data ( " << _data << " ) is found !!!\n";
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
                node->prev->next=node->next;
                node->next->prev=node->prev;
            }

            delete node;
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
                            swapData(current, current->next);
                            swapped = true;
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
