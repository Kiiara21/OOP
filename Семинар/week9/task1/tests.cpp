#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Queue.h"


TEST_CASE("Empty queue"){
    Queue<int> q;
    CHECK_FALSE(!q.isEmpty());
    q.enqueue(1);
    CHECK_FALSE(q.isEmpty());
}

TEST_CASE("Enqueue element"){
    Queue<int> q;
    q.enqueue(1);
    CHECK_EQ(q.getSize(), 1);
}

TEST_CASE("Resize queue"){
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    CHECK_FALSE(q.isFull());
}

TEST_CASE("Dequeue element"){
    Queue<int> q;
    q.enqueue(1);
    q.dequeue();
    CHECK_EQ(q.getSize(), 0);
}

TEST_CASE("Get peek"){
    Queue<int> q;
    q.enqueue(1);
    CHECK_EQ(q.peek(), 1);
    q.dequeue();
    CHECK_EQ(q.peek(), -100);   
}

TEST_CASE("Get front"){
    Queue<int> q;
    q.enqueue(1);
    CHECK_EQ(q.front(), 1);
    q.dequeue();
    CHECK_EQ(q.front(), -100);   
}

TEST_CASE("Get back"){
    Queue<int> q;
    q.enqueue(1);
    CHECK_EQ(q.back(), 1);
    q.dequeue();
    CHECK_EQ(q.back(), -100);   
}

TEST_CASE("Copy the queue"){
    Queue<int> q1, q2;
    q1.enqueue(1);
    q2 = q1;
    CHECK_EQ(q2.front(), q1.front());
    CHECK_EQ(q2.back(), q1.back());
    CHECK_EQ(q2.getSize(), q1.getSize());
}
