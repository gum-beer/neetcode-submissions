class DynamicArray {
private:
    int* arr;        // pointer to underlying array
    int size;        // number of elements currently stored
    int capacity;    // total allocated capacity

public:
    // Constructor
    DynamicArray(int capacity) {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    // Get element at index i
    int get(int i) {
        if (i < 0 || i >= size) {
            throw out_of_range("Index out of bounds");
        }
        return arr[i];
    }

    // Set element at index i to n
    void set(int i, int n) {
        if (i < 0 || i >= size) {
            throw out_of_range("Index out of bounds");
        }
        arr[i] = n;
    }

    // Add element at the end
    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    // Remove and return last element
    int popback() {
        if (size == 0) {
            throw out_of_range("Array is empty");
        }
        int val = arr[size - 1];
        size--;
        return val;
    }

    // Resize array when full
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
