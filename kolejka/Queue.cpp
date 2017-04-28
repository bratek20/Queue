#include "Queue.h"
#include <string>

Queue::Queue() : Queue(DEFAULT_SIZE) {}

Queue::Queue(sizeT size) : maxSize(size){
    data = new Type[maxSize];
    begIt = QueueIterator(*this, data);
    endIt = QueueIterator(*this, data);
}

Queue::Queue(const std::initializer_list<Type>& list) : Queue(list, list.size()) {}

Queue::Queue(const std::initializer_list<Type>& list, sizeT size) : Queue(size) {
    for(auto& e : list){
        push(e);
    }
}

Queue::~Queue() {
    delete[] data;
}


Queue::Queue(const Queue& q) : Queue(q.maxSize) {
    for (int i = 0; i < maxSize; i++) {
        data[i] = q.data[i];
    }

    begIt.align(q.begIt);
    endIt.align(q.endIt);
}


Queue& Queue::operator=(const Queue& q) {
    if (this == &q) {
        return *this;
    }

    Queue tmp(q);
    *this = std::move(tmp);
    
    return *this;
}


void Queue::rValueAssign(Queue& q) {
    maxSize = q.maxSize;
    currentSize = q.currentSize;

    data = q.data;
    q.data = nullptr;

    begIt = q.begIt;
    endIt = q.endIt;
}

Queue::Queue(Queue&& q) {
    rValueAssign(q);
}


Queue& Queue::operator=(Queue&& q) {
    this->~Queue();
    
    rValueAssign(q);

    return *this;
}


void Queue::push(Type elem) {
    if (currentSize >= maxSize)
        throw std::string("No space for new element!");

    currentSize++;
    *endIt = elem;
    ++endIt;
}


const Queue::Type& Queue::front() {
    if (currentSize == 0)
        throw std::string("No elements in queue!");
    return *begIt;
}


Queue::Type Queue::pop() {
    if (currentSize == 0)
        throw std::string("No element to pop!");

    currentSize--;
    Type elem = *begIt;
    ++begIt;
    return elem;
}