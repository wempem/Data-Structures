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
#include "/home/pwest/csu/courses/csci-315-spring-2017/lab05/test/length-test.cpp"

static MyTestSuite1 suite_MyTestSuite1;

static CxxTest::List Tests_MyTestSuite1 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite1( "test/length-test.cpp", 6, "MyTestSuite1", suite_MyTestSuite1, Tests_MyTestSuite1 );

static class TestDescription_suite_MyTestSuite1_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 8, "test1" ) {}
 void runTest() { suite_MyTestSuite1.test1(); }
} testDescription_suite_MyTestSuite1_test1;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
