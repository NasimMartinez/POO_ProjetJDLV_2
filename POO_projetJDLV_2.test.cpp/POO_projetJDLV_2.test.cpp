#include "pch.h"
#include "CppUnitTest.h"
#include "../grid/grid.h"



// ----------------------------------

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace POOprojetJDLV2testcpp
{
    TEST_CLASS(POOprojetJDLV2testcpp)
    {
    public:

     
        
        TEST_METHOD(Test_Grid_Creation)
        {
            Grid g(3, 4);
            Assert::IsTrue(g.getWidth() == 3);
            Assert::IsTrue(g.getHeight() == 4);

        }

        
    };
}
