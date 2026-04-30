/// NAME: Esmail Emad El-Din Mohamed ///

#include <iostream>
using namespace std;

// Node class for the ordered linked list
class Node
{
public:
    int info;    // stores the data value
    Node* next;  // pointer to the next node
    int ctr;     // tracks how many times this value appears

    Node(int i, Node* n = nullptr) // constructor
    {
        info = i;
        next = n;
        ctr  = 1;
    }
};

// Ordered (sorted ascending) linked list with duplicate counting
class OrderedLL
{
private:
    Node* head, *tail;  // head and tail pointers

public:
    OrderedLL() { head = tail = nullptr; }  // constructor

    // Insert item in sorted order; increment counter if duplicate
    void addinorder(int item)
    {
        if (head == nullptr)
        {
            head = new Node(item);
            return;
        }

        Node* n = head;
        Node* p = nullptr;

        while (n != nullptr)
        {
            if (n->info == item)   // duplicate found — just increment counter
            {
                n->ctr++;
                return;
            }
            else if (n->info > item) { break; }  // correct sorted position found
            p = n;
            n = n->next;
        }

        Node* temp = new Node(item);

        if (p == nullptr)   // insert at the beginning
        {
            temp->next = head;
            head = temp;
        }
        else                // insert in the middle or at the end
        {
            temp->next = n;
            p->next = temp;
        }
    }

    // Display all elements in ascending order
    void display()
    {
        Node* n = head;
        while (n != nullptr)
        {
            for (int i = 0; i < n->ctr; i++)
            {
                cout << n->info << " ";
            }
            n = n->next;
        }
        cout << endl;
    }

    // Delete one occurrence of item (remove node if ctr reaches 0)
    void deletevalue(int item)
    {
        Node* n = head;
        Node* p = nullptr;

        while (n != nullptr)
        {
            if (n->info == item)
            {
                if (n->ctr > 1)
                {
                    n->ctr--;  // just decrement counter
                }
                else           // remove the node entirely
                {
                    if (p == nullptr) { head = n->next; }
                    else              { p->next = n->next; }
                    delete n;
                }
                return;
            }
            p = n;
            n = n->next;
        }
    }

    // Display all elements in descending order
    void displayDescending()
    {
        Node* n = head;
        int length = 0;

        while (n != nullptr)
        {
            length += n->ctr;
            n = n->next;
        }

        int* arr = new int[length];
        n = head;
        int index = 0;

        while (n != nullptr)
        {
            for (int i = 0; i < n->ctr; i++)
            {
                arr[index++] = n->info;
            }
            n = n->next;
        }

        for (int i = length - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete[] arr;
    }

    // Remove all occurrences of the maximum element
    void removemax()
    {
        if (head == nullptr) { return; }

        Node* n = head;
        int maxVal, maxCtr;

        while (n != nullptr)  // the last node holds the max in a sorted list
        {
            maxVal = n->info;
            maxCtr = n->ctr;
            n = n->next;
        }

        for (int i = 0; i < maxCtr; i++)
        {
            deletevalue(maxVal);
        }
    }

    // Bulk-insert elements from an array
    void generateFromArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            addinorder(arr[i]);
        }
    }

    // Remove all nodes and free memory
    void clearr()
    {
        while (head != nullptr)
        {
            Node* n = head;
            head = head->next;
            delete n;
        }
    }
};


int main()
{
    OrderedLL olist;

    cout << " CASE ONE ( INSERTION ELEMENTS IN LIST ) :" << endl;
    olist.addinorder(5);
    olist.addinorder(3);
    olist.addinorder(3);
    olist.addinorder(9);
    olist.addinorder(1);
    cout << " ELEMENTS: ";
    olist.display();

    cout << endl;

    cout << " CASE TWO ( INSERTION DUPLICATES ELEMENTS IN LIST ) :" << endl;
    olist.addinorder(5);
    olist.addinorder(1);
    cout << " ELEMENTS: ";
    olist.display();

    cout << endl;

    cout << " CASE THREE ( DELETE AN ELEMENT FROM THE LIST ) :" << endl;
    olist.deletevalue(5);
    olist.deletevalue(9);
    cout << " ELEMENTS: ";
    olist.display();

    cout << endl;

    cout << " CASE FOUR ( DISPLAY THE ELEMENTS IN DESCENDING ORDER ) :" << endl;
    cout << " ELEMENTS: ";
    olist.displayDescending();

    cout << endl;

    cout << " CASE FIVE ( REMOVE THE MAXIMUM ELEMENT IN THE LIST ) :" << endl;
    olist.removemax();
    cout << " ELEMENTS: ";
    olist.display();

    cout << endl;

    cout << " CASE SIX ( GENERATING FROM THE ARRAY ) :" << endl;
    int arr[] = {5, 5, 8, 10, 10, 10};
    olist.generateFromArray(arr, 6);
    cout << " ELEMENTS: ";
    olist.display();

    cout << endl;

    cout << " CASE SEVEN ( CLEAR THE ELEMENTS IN THE LIST ) :" << endl;
    olist.clearr();
    cout << " ELEMENTS: EMPTY LIST" << endl;
    olist.display();

    return 0;
}
