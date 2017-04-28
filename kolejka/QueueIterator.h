#ifndef QUEUE_ITERATOR_H
#define QUEUE_ITERATOR_H

#include <string>
class Queue;

class QueueIterator {
public:
    using Type = std::string;
    using Counter = int;
    
    QueueIterator() {}
    QueueIterator(Queue& q, Type* elem);
    
    void align(const QueueIterator& otherIt);

    QueueIterator& operator++();
    Type& operator*();
    const Type& operator*() const;
    QueueIterator& operator=(Type* newElem);
    bool operator==(const QueueIterator& other);
    bool operator!=(const QueueIterator& other);

private:
    Type* dataBegin;
    Type* dataEnd;
    Type* elem;

    Counter loop = 0;
};

#endif 
