#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Structure for a node in the linked list
struct Node {
    int data;  
    Node* next; 
};

// Define the linked list class
class LinkedList {

public:
     // Pointer to the first node in the list
    Node* head;

    // Constructor initializes head to nullptr
    LinkedList() : head(nullptr) {}

    // Function to Insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(); 
        newNode->data = value;      
        newNode->next = head;      
        head = newNode;            
    }

    // Function Insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(); 
        newNode->data = value;      
        newNode->next = nullptr;       

        // If the list is empty, update the head to the new node
        if (!head) {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        // Update the last node's next to the new node
        temp->next = newNode;
    }

    // Function to Insert a new node at a specific position in the list
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(); 
        newNode->data = value;     

        // Traverse to the node before the desired position
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        // If the position is out of range, print an error message
        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        // Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to Delete the first node of the list
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head; 
        head = head->next; 
        delete temp;      
    }

    // Function to Delete the last node of the list
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next) {
            delete head;   
            head = nullptr;   
            return;
        }

        // Traverse to the second-to-last node
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        //  Delete the last node
        delete temp->next; 
        // Set the second-to-last node's next to nullptr
        temp->next = nullptr; 
    }

    // Function to Delete a node at a specific position in the list
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        // Save the node to be deleted
        Node* nodeToDelete = temp->next; 
        // Update the next pointer
        temp->next = temp->next->next;   
         // Delete the node
        delete nodeToDelete;            
    }

    // Function to print the nodes of  the linked list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> "; 
            temp = temp->next;
        }
        cout << "nullptr" << endl; 
    }
};  

class InsertionSort {
    
    public:

    Node* sortedInsert(Node* newnode, Node* sorted) {
    
        // Special case for the head end
        if (sorted == nullptr || 
            sorted->data >= newnode->data) {
            newnode->next = sorted;
            sorted = newnode;
        }
        else {
            Node* curr = sorted;
            
            // Locate the node before the point
            // of insertion
            while (curr->next != nullptr && 
                curr->next->data < newnode->data) {
                curr = curr->next;
            }
            newnode->next = curr->next;
            curr->next = newnode;
        }
    
        return sorted;
    }

    Node* insertionSort(Node* head) {
        
        // Initialize sorted linked list
        Node* sorted = nullptr;
        Node* curr = head;
        
        // Traverse the given linked list and insert 
        // every node to sorted
        while (curr != nullptr) {
            
            // Store next for next iteration
            Node* next = curr->next;
            
            // Insert current in sorted linked list
            sorted = sortedInsert(curr, sorted);
            
            // Update current
            curr = next;
        }
        
        return sorted;
    }
};

class BubbleSort {

    public:
    // Function to get the length
    // of the linked list
    int getLength(Node *head) {
        int len = 0;
        Node *curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }
        return len;
    }

    // Function to perform bubble sort on 
    // the linked list
    Node *bubbleSort(Node *head) {
        Node *currNode = head;
        int len = getLength(head);
        int itr = 0;
        bool swapped;

        // Iterating over the whole linked list
        while (itr < len) {
            Node *traverseNode = head;
            Node *prevNode = head;
            swapped = false;

            while (traverseNode->next) {

                // Temporary pointer to store the next
                // pointer of traverseNode
                Node *ptr = traverseNode->next;
                if (traverseNode->data > ptr->data) {
                    swapped = true;
                    if (traverseNode == head) {

                        // Performing swap operations and
                        // updating the head of the linked list
                        traverseNode->next = ptr->next;
                        ptr->next = traverseNode;
                        prevNode = ptr;
                        head = prevNode;
                    }
                    else {

                        // Performing swap operation
                        traverseNode->next = ptr->next;
                        ptr->next = traverseNode;
                        prevNode->next = ptr;
                        prevNode = ptr;
                    }
                    continue;
                }
                prevNode = traverseNode;
                traverseNode = traverseNode->next;
            }

            // If no swap occurred, break the loop
            if (!swapped) {
                break;
            }

            ++itr;
        }

        // Returning the head of the linked list
        return head;
    }
};

class MergeSort {

    public:
    Node* split(Node *head) {
        Node *fast = head;
        Node *slow = head;

        // Move fast pointer two steps and slow pointer
        // one step until fast reaches the end
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            if (fast != nullptr) {
                slow = slow->next;
            }
        }

        // Split the list into two halves
        Node *temp = slow->next;
        slow->next = nullptr;
        return temp;
    }

    // Function to merge two sorted singly linked lists
    Node* merge(Node *first, Node *second) {
    
        // If either list is empty, return the other list
        if (first == nullptr) return second;
        if (second == nullptr) return first;

        // Pick the smaller value between first and second nodes
        if (first->data < second->data) {

            // Recursively merge the rest of the lists and
            // link the result to the current node
            first->next = merge(first->next, second);
            return first;
        }
        else {
            // Recursively merge the rest of the lists
            // and link the result to the current node
            second->next = merge(first, second->next);
            return second;
        }
    }

    // Function to perform merge sort on a singly linked list
    Node *mergeSort(Node *head) {
    
        // Base case: if the list is empty or has only one node, 
        // it's already sorted
        if (head == nullptr || head->next == nullptr)
            return head;

        // Split the list into two halves
        Node *second = split(head);

        // Recursively sort each half
        head = mergeSort(head);
        second = mergeSort(second);

        // Merge the two sorted halves
        return merge(head, second);
    }

    /* void printList(Node *head) {
        Node *curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    } */

};

class QuickSort {

    public:

    // Returns the last node of the list
    Node* getTail(Node* cur) {
        while (cur != nullptr && cur->next != nullptr)
            cur = cur->next;
        return cur;
    }

    // Partitions the list taking the first element as the pivot
    Node* partition(Node* head, Node* tail) {
    
        // Select the first node as the pivot node
        Node* pivot = head;
    
        // 'pre' and 'curr' are used to shift all 
        // smaller nodes' data to the left side of the pivot node
        Node* pre = head;
        Node* curr = head;

        // Traverse the list until you reach the node after the tail
        while (curr != tail->next) {
            
            if (curr->data < pivot->data) {
                swap(curr->data, pre->next->data);
            
                // Move 'pre' to the next node
                pre = pre->next;
            }
            
            // Move 'curr' to the next node
            curr = curr->next;
        }
        
        swap(pivot->data, pre->data);
        
        // Return 'pre' as the new pivot
        return pre;
    }

    // Helper function for quick sort
    void quickSortHelper(Node* head, Node* tail) {
    
        // Base case: if the list is empty or consists of a single node
        if (head == nullptr || head == tail) {
            return;
        }
        
        // Call partition to find the pivot node
        Node* pivot = partition(head, tail);
        
        // Recursive call for the left part of the list (before the pivot)
        quickSortHelper(head, pivot);
        
        // Recursive call for the right part of the list (after the pivot)
        quickSortHelper(pivot->next, tail);
    }

    // The main function for quick sort. This is a wrapper over quickSortHelper
    Node* quickSort(Node* head) {
        
        Node* tail = getTail(head);
        
        // Call the helper function to sort the list
        quickSortHelper(head, tail);
        return head;
    }

};

class HeapSort {

    public:
    //nested class
    class SortByValueComparator {

        public:

        int compare(Node* node1,Node* node2) {
        
            // If we interchange return value
            // -1 and 1 then LinkedList will be
            // sorted in reverse/descending order.
            if (node1->data < node2->data) {
                return -1;
            } else if (node1->data > node2->data) {
                return 1;
            }
            return 0;
        }
    };
 
    SortByValueComparator sortByValueComparator;

    int getLength(Node *head) {
        int len = 0;
        Node *curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }
        return len;
    }

    void heapify(Node **arr, int n, int i) {
        int largest = i;
        int right = 2 * i + 2;
        int left = 2 * i + 1;
    
    
    // Check if left child is larger
    // than root
        if (left < n && sortByValueComparator.compare(arr[left], arr[largest]) > 0) {
            largest = left;
        }
        
    // Check if right child is larger
    // than the largest till now
        if (right < n && sortByValueComparator.compare(arr[right], arr[largest]) > 0) {
            largest = right;
        }
        
        // swap if largest is not root
        if (largest != i) {
            int swap = arr[i]->data;
            arr[i]->data = arr[largest]->data;
            arr[largest]->data = swap;
            
            // Recursively heapify the subTree
            heapify(arr, n, largest);
        }
    }

    void sortArray(Node **arr, int n) {
   
        // Build heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    
        // Moving current root to end
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0]->data;
            arr[0]->data = arr[i]->data;
            arr[i]->data = temp;
    
            heapify(arr, i, 0);
        }
    }

    void heapSort(Node* node) {
        Node* head = node;
        int len = getLength(head);
        int i = 0;
    
        // Array to copy the linked list data
        Node **arr = new Node *[len];
        while (head != nullptr) {
            arr[i] = head;
            i++;
            head = head->next;
        }
        sortArray(arr, len);
        cout << "\nLinkedList after sorting: ";
        for (int i = 0; i < len; i++) {
            cout << arr[i]->data << " ";
        }
        delete[] arr;
    }
};

class ExchangeSort {

    public:

    int getLength(Node *head) {
        int len = 0;
        Node *curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }
        return len;
    }

    Node* returnNodeAtPosition(Node* head, int pos) {
        Node* temp{head};
        int count{};
        while(temp -> next, count < pos) {
            temp = temp -> next;
            count++;
        }
        return temp;
    }

    void swap(Node*& head, int pos1,int pos2) {
        Node* temp01{returnNodeAtPosition(head, pos1)};
        Node* temp02{returnNodeAtPosition(head, pos2)};
        
        if(pos2 - pos1 == 1) {

            temp01 -> next = temp02 -> next;
            temp02 -> next = temp01;
            if(pos1 > 0) {
                returnNodeAtPosition(head, pos1 - 1) -> next = temp02;
            } else {
                head = temp02;
            }

        } else if (pos2 - pos1 == 2) {

            Node* newNode01{returnNodeAtPosition(head, pos2 - 1)};
            temp01 -> next = temp02 -> next;
            temp02 -> next = newNode01;
            newNode01 -> next = temp01;
            if(pos1 > 0) {
                returnNodeAtPosition(head, pos1 - 1) -> next = temp02;
            } else {
                head = temp02;
            }

        } else if ((pos2 - pos1) > 2) {

            Node* newNode01{returnNodeAtPosition(head, pos1 + 1)};
            Node* newNode02{returnNodeAtPosition(head, pos2 - 1)};
            temp01 -> next = temp02 -> next;
            temp02 -> next = newNode01;
            newNode02 -> next = temp01;
            if(pos1 > 0) {
                returnNodeAtPosition(head, pos1 - 1) -> next = temp02;
            } else {
                head = temp02;
            }

        }


    }

    Node* exchangeSort(Node*& head) {
        int len{getLength(head)};
        for(int i{}; i < len - 1; i++) {
            for(int j{i}; j < len - 1; j++) {
                if(returnNodeAtPosition(head, i) -> data > returnNodeAtPosition(head, j + 1) -> data) {
                    swap(head,i ,j + 1);
                }
            }
        }

        return head;
    }
};

void insertionS(LinkedList linked) {
    Node* head{linked.head};
    InsertionSort insertion_Sort;
    head = insertion_Sort.insertionSort(head);
    //reset head's position for LinkedList
    linked.head = head;
    linked.display();
}

void bubbleS(LinkedList linked) {
    Node* head{linked.head};
    BubbleSort bubble_Sort;
    head = bubble_Sort.bubbleSort(head);
    //reset head's position for LinkedList
    linked.head = head;
    linked.display();
}

void mergeS (LinkedList linked) {
    Node* head{linked.head};
    MergeSort merge_Sort;
    head = merge_Sort.mergeSort(head);
    //reset head's position for LinkedList
    linked.head = head;
    linked.display();
}

void quickS (LinkedList linked) {
    Node* head{linked.head};
    QuickSort quick_Sort;
    head = quick_Sort.quickSort(head);
    //reset head's position for LinkedList
    linked.head = head;
    linked.display();
}

void heapS (LinkedList linked) {
    Node* head{linked.head};
    HeapSort heap_Sort;
    heap_Sort.heapSort(head);
    //reset head's position for LinkedList
    linked.head = head;
}

void exchangeS (LinkedList linked) {
    Node* head{linked.head};
    ExchangeSort exchange_Sort;
    exchange_Sort.exchangeSort(head);
    linked.head = head;
    linked.display();
}

int main() {
    LinkedList linked;
    
    //Generate a linked list manually with proper order by inserting at the end
    linked.insertAtEnd(10);
    linked.insertAtEnd(9);
    linked.insertAtEnd(8);
    linked.insertAtEnd(7);
    linked.insertAtEnd(6);
    linked.insertAtEnd(5);
    linked.insertAtEnd(4);
    linked.insertAtEnd(3);
    linked.insertAtEnd(2);
    linked.insertAtEnd(1);

    //mergeS(linked);
    //insertionS(linked);
    //bubbleS(linked);
    //quickS(linked);
    //heapS(linked);
    exchangeS(linked);
    
    

    //linked.display();
    
} 
