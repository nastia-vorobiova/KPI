#include <iostream>
#include <string>

using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void setSize(int newSize) {
        if (newSize < 0) {
            std::cout << "Invalid size!" << std::endl;
        }
        if (newSize < size) {
            int removeCount = size - newSize;
            for (int i = 0; i < removeCount; i++) {
                removeAt(size - 1); // Remove elements from the end
            }
        }
        else if (newSize > size) {
            int addCount = newSize - size;
            for (int i = 0; i < addCount; i++) {
                insert(T()); // Add elements with default value 0 at the end
            }
        }
        size = newSize;
    }

    int getSize() {
        return size;
    }
    
    void setList() {
        Node* current = head;
        T element;
        cout << "Enter " << size << " elements with ENTER:" << endl;
        while (current != nullptr) {
            cin >> element;
            current->data = element;
            current = current->next;
        }
        cout << endl;
    }

    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << ", ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getPosition(const T& value) const {
        Node* current = head;
        int position = 0;
        while (current) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1; // Return -1 if the value is not found
    }

    void removeAt(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position!" << std::endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head) {
                tail = nullptr;
            }
        }
        else {
            Node* prev = head;
            for (int i = 0; i < position - 1; i++) {
                prev = prev->next;
            }
            Node* current = prev->next;
            prev->next = current->next;
            delete current;
            if (!prev->next) {
                tail = prev;
            }
        }

        size--;
    }

    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        void begin() {
            current = head;
        }

        bool end() const {
            return current == nullptr;
        }

        T& value() const {
            return current->data;
        }

        void next() {
            if (current) {
                current = current->next;
            }
        }
    };

    Iterator getIterator() {
        return Iterator(head);
    }

    void insert(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    bool chooseFunction(int n)
    {
        switch (n) {
            case 1:
            {
                setList();
                cout << "Created list:" << endl;
                displayList();
                break;
            }
            case 2:
            {
                cout << "List is" << (isEmpty() ? " " : " not ") << "empty." << endl;
                break; 
            }
            case 3:
            {
                clear();
                cout << "List is empty now." << endl;
                break;
            }
            case 4:
            {
                T searchValue;
                cout << "Enter the value you want to find: ";
                cin >> searchValue;
                int position = getPosition(searchValue);
                if (position != -1) {
                    cout << "Value " << searchValue << " was found at position " << position + 1 << "." << endl;
                }
                else {
                    cout << "Value " << searchValue << " was not found in the list." << endl;
                }
                break;
            }
            case 5:
            {
                int pos;
                cout << "Enter the position for removing an element: ";
                cin >> pos;
                removeAt(pos - 1);
                cout << "List after removing element at position " << pos << ":" << endl;
                displayList();
                break;
            }
            case 6:
            {
                if (isEmpty())
                    cout << "List is empty." << endl;
                else
                    displayList();
                break;
            }
            case 0:
            {
                return false;
            }
            default:
            {
                cout << "The entered number is invadil!" << endl;
            }
            }
        return true;

    }
};

void ShowInstructions()
{
    cout << "Possible functins:" << endl;
    cout << "1. Set the list;" << endl;
    cout << "2. Check if list is empty; " << endl;
    cout << "3. Clear the list;" << endl;
    cout << "4. Find a specific element in the list;" << endl;
    cout << "5. Remove an element at the specific position;" << endl;
    cout << "6. Display the list;" << endl;
    //cout << "7. Set iterator to the specific position;" << endl;
    cout << "0. Stop the program." << endl;
}

int main() {
    LinkedList<string> list;
    int n;
    cout << "Set the size of the starting list: ";
    cin >> n;
    list.setSize(n);

    int num;
    bool function;
    ShowInstructions();
    do {
        cout << "\nChoose a function: ";
        cin >> num;
        function = list.chooseFunction(num);

    } while (function);

    cout << "\n\nProgram has been stopped." << endl;

}
