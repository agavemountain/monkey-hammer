#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include <iostream>
#include <monkeylib/core/Version.h>

using namespace std;   // so sue me, I'm lazy tonight.
using namespace Monkey::Version;

class version_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( version_test );
    CPPUNIT_TEST( TestMajorMinorPatch );
    CPPUNIT_TEST( TestCompilerVersionString );
    CPPUNIT_TEST_SUITE_END();
public:

    void TestMajorMinorPatch()
    {
    	char buff[10];
        auto major = GetVersionMajor();
        auto minor = GetVersionMinor();
        auto patch = GetVersionPatch();
        std::string version;
        sprintf(buff, "%d.%d.%d", major, minor, patch);
        version = buff;
        std::string versionString = GetVersionString();
        CPPUNIT_ASSERT(versionString == version);
    }

    void TestCompilerVersionString()
    {
        std::string compiler = GetCompilerVersionString();
    #if defined(_MSC_VER)
        const auto expected = "MSVC";
    #elif defined(__GNUC__)
        const auto expected = "GCC";
    #elif defined(__clang__)
        const auto expected = "Clang";
    #else
        const auto expected = "Unknown";
    #endif

        CPPUNIT_ASSERT( compiler.find(expected) != std::string::npos ) ;
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( version_test );


