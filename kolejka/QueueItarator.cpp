#include "QueueIterator.h"
#include "Queue.h"

QueueIterator::QueueIterator(Queue& q, Type* elem) : elem(elem) {
    dataBegin = q.data;
    dataEnd = q.data + q.maxSize;
}

QueueIterator& QueueIterator::operator++() {
    elem++;
    if (elem == dataEnd) {
        elem = dataBegin;
        loop++;
    }

    return *this;
}

void QueueIterator::align(const QueueIterator& otherIt) {
    loop = otherIt.loop;
    elem = dataBegin + (&(*otherIt) - otherIt.dataBegin);
}

QueueIterator::Type& QueueIterator::operator*() {
    return *elem;
}

const QueueIterator::Type& QueueIterator::operator*() const {
    return *elem;
}

QueueIterator& QueueIterator::operator=(Type* newElem) {
    elem = newElem;
    return *this;
}

bool QueueIterator::operator==(const QueueIterator& other) {
    return loop == other.loop && elem == other.elem;
}

bool QueueIterator::operator!=(const QueueIterator& other) {
    return !(*this == other);
}