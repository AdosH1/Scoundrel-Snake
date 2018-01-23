#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Utility/Point.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestUtility
{		
	TEST_CLASS(TestPoint)
	{
	public:
		TEST_METHOD(TestAddPoints)
		{
			Point p1 = Point(1, 2);
			Point p2 = Point(3, 4);
			Point p3 = p1 + p2;

			Assert::AreEqual(p3.X, (double)4);
			Assert::AreEqual(p3.Y, (double)6);
		}

		TEST_METHOD(TestSubtractPoints)
		{
			Point p1 = Point(1, 2);
			Point p2 = Point(3, 4);
			Point p3 = p1 - p2;

			Assert::AreEqual(p3.X, (double)-2);
			Assert::AreEqual(p3.Y, (double)-2);
		}

		TEST_METHOD(TestMultiplyPoints)
		{
			Point p1 = Point(1, 2);
			Point p2 = Point(3, 4);
			Point p3 = p1 * p2;

			Assert::AreEqual(p3.X, (double)3);
			Assert::AreEqual(p3.Y, (double)8);
		}

		TEST_METHOD(TestDividePoints)
		{
			Point p1 = Point(3, 4);
			Point p2 = Point(2, 2);
			Point p3 = p1 / p2;

			Assert::AreEqual(p3.X, (double)1.5);
			Assert::AreEqual(p3.Y, (double)2);
		}

		TEST_METHOD(TestMultiplyPoint)
		{
			Point p1 = Point(1,2);
			p1 = p1 * (int)3;

			Assert::AreEqual(p1.X, (double)3);
			Assert::AreEqual(p1.Y, (double)6);

			Point p2 = Point(3, 4);
			p2 = p2 * (float)4;

			Assert::AreEqual(p2.X, (double)12);
			Assert::AreEqual(p2.Y, (double)16);

			Point p3 = Point(5, 6);
			p3 = p3 * (double)5;

			Assert::AreEqual(p3.X, (double)25);
			Assert::AreEqual(p3.Y, (double)30);
		}

	};
}