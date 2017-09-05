/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite1_init = false;
#include "/home/pwest/csu/courses/csci-315-spring-2017/lab04/test/search-test.cpp"

static MyTestSuite1 suite_MyTestSuite1;

static CxxTest::List Tests_MyTestSuite1 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite1( "test/search-test.cpp", 6, "MyTestSuite1", suite_MyTestSuite1, Tests_MyTestSuite1 );

static class TestDescription_suite_MyTestSuite1_testFirst : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testFirst() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 8, "testFirst" ) {}
 void runTest() { suite_MyTestSuite1.testFirst(); }
} testDescription_suite_MyTestSuite1_testFirst;

static class TestDescription_suite_MyTestSuite1_testSecond : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testSecond() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 13, "testSecond" ) {}
 void runTest() { suite_MyTestSuite1.testSecond(); }
} testDescription_suite_MyTestSuite1_testSecond;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
