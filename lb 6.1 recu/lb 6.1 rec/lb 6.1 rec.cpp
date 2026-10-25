#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST                              
#include "../lb 6.1 recu/lb 6.1 recu.cpp"       

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61Rec
{
    TEST_CLASS(UnitTest61Rec)
    {
    public:
        
        TEST_METHOD(TestCount)
        {
            int p[10] = { 5, -3, 7, -2, 9, 4, -1, 8, 0, -6 };
            Assert::AreEqual(7, Count(p, 10, 0));
        }

        
        TEST_METHOD(TestSum)
        {
            int p[10] = { 5, -3, 7, -2, 9, 4, -1, 8, 0, -6 };
            Assert::AreEqual(32, Sum(p, 10, 0));
        }

        TEST_METHOD(TestZeroOut)
        {
            int p[10] = { 5, -3, 7, -2, 9, 4, -1, 8, 0, -6 };
            int expected[10] = { 0, -3, 0, -2, 0, 0, 0, 0, 0, -6 };
            ZeroOut(p, 10, 0);
            for (int i = 0; i < 10; i++)
                Assert::AreEqual(expected[i], p[i]);
        }

        
        TEST_METHOD(TestAllNegative)
        {
            int p[4] = { -1, -2, -3, -4 };
            Assert::AreEqual(2, Count(p, 4, 0));
            Assert::AreEqual(-4, Sum(p, 4, 0));
        }

        TEST_METHOD(TestCreateInRange)
        {
            const int n = 100;
            int p[n];
            Create(p, n, -10, 14, 0);
            for (int i = 0; i < n; i++)
            {
                Assert::IsTrue(p[i] >= -10);
                Assert::IsTrue(p[i] <= 14);
            }
        }
    };
}