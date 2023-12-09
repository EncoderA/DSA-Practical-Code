#include<iostream>
using namespace std;

class Queue{
    int front,rear;
    int size;
    int *queue;

    public:
    Queue(int s){
        size = s;
        front = rear = -1;
        queue = new int[s];
    }

    void enQueue(int key){
        if(front == -1 && rear == -1){
            front = rear = 0;
            queue[rear] = key;
        }else if((rear + 1)%size == front){
            cout << "Over Flow" << "\n";
        }else {
            rear = (rear + 1) % size;
            queue[rear] = key;
        }
    }

    void deQueue(){
        if(front == -1 && rear == -1){
            cout << "Under flow" << "\n";
        } else if(front==rear)  
        {  
            printf("\nThe dequeued element is %d", queue[front]);  
            front=-1;  
            rear=-1;  
        } else{
            cout << "deleted Element : " << queue[front] << "\n";
            front =( front + 1 ) % size;
        }
    }

    void display(){
        int i = front;
        if(front == -1 && rear == -1) return;
        while(i <= rear){
            cout << queue[i] << "  ";
            i = (i+1) % size;
        }
    }


};

int main(){
    Queue q(5);

    q.enQueue(5);
    q.enQueue(4);
    q.enQueue(3);
    q.enQueue(2);
    q.deQueue();
    q.display();

}