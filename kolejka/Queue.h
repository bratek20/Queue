#ifndef QUEUE_H
#define QUEUE_H

#include <initializer_list>
#include "QueueIterator.h"

class Queue {
public:
    friend class QueueIterator;
    
    using Iterator = QueueIterator;
    using Type = Iterator::Type;
    using sizeT = int;

    static const sizeT DEFAULT_SIZE = 4;

    Queue();
    Queue(sizeT size);
    Queue(const std::initializer_list<Type>& list);
    Queue(const std::initializer_list<Type>& list, sizeT size);
    ~Queue();

    Queue(const Queue& q);
    Queue& operator=(const Queue& q);

    Queue(Queue&& q);
    Queue& operator=(Queue&& q);

    void push(Type elem);
    const Type& front();
    Type pop();

    const Iterator& begin() {
        return begIt;
    }
    
    const Iterator& end() {
        return endIt;
    }

    sizeT size() {
        return currentSize;
    }

private:
    void rValueAssign(Queue& q);

    sizeT currentSize = 0;
    sizeT maxSize;

    Type* data;
    
    Iterator begIt;
    Iterator endIt;
};

#endif
