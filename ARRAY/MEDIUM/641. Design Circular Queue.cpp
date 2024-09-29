/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
class MyCircularDeque {
public:
    vector<int>circularDeq;
    int size;
    int currentCount;
    int front;
    int rear;
    MyCircularDeque(int k) {
        size = k;
        circularDeq = vector<int>(size, 0);
        front = 0;
        rear = k - 1;
        currentCount = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front = (front - 1 + size) % size;
        circularDeq[front] = value;
        currentCount++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear + 1) % size;
        circularDeq[rear] = value;
        currentCount++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front = (front + 1) % size;
        currentCount--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear = (rear - 1 + size) % size;
        currentCount--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return circularDeq[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return circularDeq[rear];
    }
    
    bool isEmpty() {
        return currentCount == 0;
    }
    
    bool isFull() {
        return currentCount == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

