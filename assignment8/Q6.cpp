#include <iostream>
using namespace std;

class PriorityQueue
{
    static const int MAX = 1000;
    int arr[MAX];
    int size;

    void heapifyDown(int i)
    {
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    void heapifyUp(int i)
    {
        while (i > 0 && arr[(i - 1) / 2] < arr[i])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

public:
    PriorityQueue()
    {
        size = 0;
    }

    void insert(int val)
    {
        if (size >= MAX)
        {
            cout << "Queue is Full!" << endl;
            return;
        }
        arr[size] = val;
        heapifyUp(size);
        size++;
    }

    int extractMax()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        int maxVal = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapifyDown(0);
        return maxVal;
    }

    void display()
    {
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;

    pq.insert(2);
    pq.insert(5);
    pq.insert(4);
    pq.insert(3);
    pq.insert(6);

    pq.display();

    cout << "Max: " << pq.extractMax() << endl;
    pq.display();

    return 0;
}
