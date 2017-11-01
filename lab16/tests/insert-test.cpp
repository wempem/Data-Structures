#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "heap.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            Heap<int> *heap = new Heap<int>(100);
            heap->insert(18);
            heap->insert(4);
            TS_ASSERT_EQUALS(18, (*heap)[0]);
            TS_ASSERT_EQUALS(4, (*heap)[1]);
            delete heap;
        }
        void test2(void) {
            Heap<int> *heap = new Heap<int>(100);
            heap->insert(4);
            heap->insert(18);
            TS_ASSERT_EQUALS(18, (*heap)[0]);
            TS_ASSERT_EQUALS(4, (*heap)[1]);
            delete heap;
        }
        void test3(void) {
            Heap<int> *heap = new Heap<int>(100);
            heap->insert(4);
            heap->insert(18);
            heap->insert(22);
            TS_ASSERT_EQUALS(22, (*heap)[0]);
            TS_ASSERT_EQUALS(4, (*heap)[1]);
            TS_ASSERT_EQUALS(18, (*heap)[2]);
            delete heap;
        }
        void test4(void) {
            Heap<int> *heap = new Heap<int>(100);
            heap->insert(4);
            heap->insert(18);
            heap->insert(22);
            heap->insert(74);
            heap->insert(9001);
            heap->insert(2);
            heap->insert(-5);
            heap->insert(6);
            TS_ASSERT_EQUALS(9001, (*heap)[0]);
            TS_ASSERT_EQUALS(74, (*heap)[1]);
            TS_ASSERT_EQUALS(18, (*heap)[2]);
            TS_ASSERT_EQUALS(6, (*heap)[3]);
            TS_ASSERT_EQUALS(22, (*heap)[4]);
            TS_ASSERT_EQUALS(2, (*heap)[5]);
            TS_ASSERT_EQUALS(-5, (*heap)[6]);
            TS_ASSERT_EQUALS(4, (*heap)[7]);
            delete heap;
        }
};

