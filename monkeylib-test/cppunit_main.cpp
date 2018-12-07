#include <stdio.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main(int, char ** )
{
    CppUnit::TextUi::TestRunner   runner;
    runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );
    return((runner.run( "", false )) ? 0 : 1);
}
