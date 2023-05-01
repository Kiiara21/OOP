#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "PriorityQueue.h"

TEST_CASE("Create priority queue"){
    PriorityQueue<int> pq(4);
    item<int> item1;
    item1.m_data = 1;
    item1.m_priority = 3;
    pq.enqueue(item1);
    CHECK_EQ(pq.getSize(), 1);
}

TEST_CASE("Priority by index"){
    PriorityQueue<int> pq(4);
    item<int> item1;
    item1.m_data = 1;
    item1.m_priority = 3;
    pq.enqueue(item1);
    CHECK_EQ(pq.getPriorityByIndex(0), 3);
    CHECK_EQ(pq.getPriorityByIndex(1), -1);
}

TEST_CASE("Enqueue element in the queue"){
    PriorityQueue<int> pq(4);
    item<int> item1;
    item1.m_data = 1;
    item1.m_priority = 3;
    pq.enqueue(item1);
    CHECK_EQ(pq.getDataByIndex(0), 1);
}

TEST_CASE("Dequeue element from the queue"){
    PriorityQueue<int> pq(4);
    item<int> item1, item2;
    item1.m_data = 1;
    item1.m_priority = 3;
    item2.m_data = 10;
    item2.m_priority = 4;
    pq.enqueue(item2);
    pq.enqueue(item1);

    item dequeuedElement = pq.dequeue();
    CHECK_EQ(dequeuedElement.m_data, 10);
}


TEST_CASE("Peek element from the queue"){
    PriorityQueue<int> pq(4);
    item<int> item1, item2;
    item1.m_data = 1;
    item1.m_priority = 3;
    item2.m_data = 10;
    item2.m_priority = 4;
    pq.enqueue(item2);
    pq.enqueue(item1);

    item dequeuedElement = pq.peek();
    CHECK_EQ(dequeuedElement.m_data, 10);
}

TEST_CASE("Front element from the queue"){
    PriorityQueue<int> pq(4);
    item<int> item1, item2;
    item1.m_data = 1;
    item1.m_priority = 3;
    item2.m_data = 10;
    item2.m_priority = 4;
    pq.enqueue(item2);
    pq.enqueue(item1);

    item dequeuedElement = pq.front();
    CHECK_EQ(dequeuedElement.m_data, 10);
}

TEST_CASE("Back element from the queue"){
    PriorityQueue<int> pq(4);
    item<int> item1, item2;
    item1.m_data = 1;
    item1.m_priority = 3;
    item2.m_data = 10;
    item2.m_priority = 4;
    pq.enqueue(item2);
    pq.enqueue(item1);

    item dequeuedElement = pq.back();
    CHECK_EQ(dequeuedElement.m_data, 1);
}

