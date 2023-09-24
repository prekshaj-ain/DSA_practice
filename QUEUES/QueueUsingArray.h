
template <typename T>
class QueueUsingArray
{
private:
    int capacity;
    int size;
    int frontIndex;
    int nextIndex;
    T *data;

public:
    QueueUsingArray(int n)
    {
        data = new T[n];
        capacity = n;
        size = 0;
        nextIndex = 0;
        frontIndex = -1;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(T x)
    {
        nextIndex = nextIndex % capacity;
        if (size == capacity)
        {
            cout << "\n Overflow";
            return;
        }

        else
        {
            data[nextIndex] = x;
            nextIndex++;
            size++;
            if (frontIndex == -1)
                frontIndex = 0;
        }
    }
    T dequeue()
    {
        if (size == 0)
        {
            cout << "\nUnderflow";
            return -1;
        }
        else if (size == 1)
        {
            int val = data[frontIndex];
            frontIndex = -1;
            nextIndex = 0;
            size--;
            return val;
        }
        else
        {
            int val = data[frontIndex];
            frontIndex = (frontIndex + 1) % capacity;
            size--;
            return val;
        }
    }
    bool isEmpty()
    {
        return size == 0;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        return data[frontIndex];
    }
};