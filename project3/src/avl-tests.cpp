#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "binarytree.hpp"
#include "scapetree.hpp"
class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            /* Fill in some test cases here for cxx test gen */
        BinaryTree<int> bt;
        ScapeTree<int> st;
	bt.put(100);
        bt.put(5);
        bt.put(200);
        bt.put(17);
        bt.put(199);
        bt.put(12);
        TS_ASSERT(bt.contains(12));
        TS_ASSERT(!bt.contains(-100));
	st.put(100);
	st.put(5);
	st.put(200);
	st.put(17);
	st.put(199);
	st.put(12);
	TS_ASSERT(st.contains(12));
	TS_ASSERT(!st.contains(-100));
        }
};
