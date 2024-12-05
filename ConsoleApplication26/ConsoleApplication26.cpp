#include <iostream>
using namespace std;

class CircularQueue {
public:
    CircularQueue(int capacity = 10) 
    {
        _capacity = capacity;
        _array = new int[_capacity];
        _front = -1;
        _back = -1;
        _size = 0;
    }

    ~CircularQueue() 
    {
        delete[] _array;
    }

    void enqueue(int value) 
    {
        if (_size == _capacity) 
        {
            resize();
        }

        if (_size == 0) 
        {
            _front = 0;
            _back = 0;
        }
        else {
            _back = (_back + 1) % _capacity;
        }

        _array[_back] = value;
        _size++;
    }

    int dequeue() 
    {
        if (empty()) 
        {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return -1;  
        }

        int dequeuedValue = _array[_front];
        if (_front == _back) 
        { 
            _front = -1;
            _back = -1;
        }
        else 
        {
            _front = (_front + 1) % _capacity;
        }

        _size--;
        return dequeuedValue;
    }

    int size() const 
    {
        return _size;
    }

    bool empty() const 
    {
        return _size == 0;
    }

    void print() const 
    {
        if (empty()) 
        {
            cout << "Queue is empty. Nothing to print.\n";
            return;
        }

        std::cout << "Queue elements: ";
        int index = _front;
        for (int i = 0; i < _size; ++i) 
        {
            std::cout << _array[index] << " ";
            index = (index + 1) % _capacity; 
        }
        std::cout << std::endl;
    }

private:
    int _front;
    int _back;
    int* _array;
    int _capacity;
    int _size;

    void resize() 
    {
        int newCapacity = _capacity * 2;
        int* newArray = new int[newCapacity];

        
        int index = _front;
        for (int i = 0; i < _size; ++i) 
        {
            newArray[i] = _array[index];
            index = (index + 1) % _capacity; 
        }

        delete[] _array;
        _array = newArray;
        _capacity = newCapacity;
        _front = 0;
        _back = _size - 1;
    }
};

int main() 
{
    CircularQueue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();

    q.enqueue(40);  
    q.print();

    q.dequeue(); 
    q.enqueue(50);
    q.print();

    return 0;
}