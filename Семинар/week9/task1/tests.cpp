#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Queue.h"

TEST_CASE("Empty queue"){
    try {
        Queue<int> q;
        CHECK_FALSE(!q.isEmpty());
        q.enqueue(1);
        CHECK_FALSE(q.isEmpty());
    }
    catch (const std::exception &ex){
        std::cerr << "Exception occured!";
        throw;
    }
}

TEST_CASE("Enqueue element"){
    try {
        Queue<int> q;
        q.enqueue(1);
        CHECK_EQ(q.getSize(), 1);
    }
    catch (const std::exception &ex){
        std::cerr << "Exception occured!";
        throw;
    }
}

TEST_CASE("Resize queue"){
    try {
        Queue<int> q;
        q.enqueue(1);
        q.enqueue(1);
        q.enqueue(1);
        CHECK_FALSE(q.isFull());
    }
    catch (const std::exception &ex){
        std::cerr << "Exception occured!";
        throw;
    }
    
}

TEST_CASE("Dequeue element"){
    try {
        Queue<int> q;
        q.enqueue(1);
        q.dequeue();
        CHECK_EQ(q.getSize(), 0);
    }
    catch (const std::exception &ex){
        std::cerr << "Exception occured!";
        throw;
    }
}

TEST_CASE("Get peek"){
    try {
        Queue<int> q;
        q.enqueue(1);
        CHECK_EQ(q.peek(), 1);
    }
    catch (const std::exception &ex){
        std::cerr << "Exception occured!";
        throw;
    }
}

TEST_CASE("Get front"){
    try {
        Queue<int> q;
        q.enqueue(1);
        CHECK_EQ(q.front(), 1);
    }
    catch (const std::exception &ex){
        std::cerr << "Exception occured!";
        throw;
    }
}

TEST_CASE("Get back"){
    try {
        Queue<int> q;
        q.enqueue(1);
        CHECK_EQ(q.back(), 1);
    }
    catch (const std::exception &ex){
        std::cerr << "Exception occured!";
        throw;
    }
}

TEST_CASE("Copy the queue"){
    try {
        Queue<int> q1, q2;
        q1.enqueue(1);
        q2 = q1;
        CHECK_EQ(q2.front(), q1.front());
        CHECK_EQ(q2.back(), q1.back());
        CHECK_EQ(q2.getSize(), q1.getSize());
    }
    catch (const std::exception &ex){
        std::cerr << "Exception occured!";
        throw;
    }
}
