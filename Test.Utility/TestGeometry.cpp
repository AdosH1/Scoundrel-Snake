#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Utility/Point.hpp"
#include "../Utility/Geometry.hpp"
#include "../Utility/Rectangle.hpp"
#include "../Utility/Circle.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestUtility
{		
	TEST_CLASS(TestGeometry)
	{
	public:
		#pragma region TestContactCircleAndRectangle
		TEST_METHOD(TestContactCircleAndRectangleNoContact)
		{
			Circle c = Circle(Point(1, 1), 1);
			Rectangle r = Rectangle(Point(2, 2), Point(4, 4));

			bool contact = Geometry::ContactCircleAndRectangle(c, r);

			Assert::IsFalse(contact);
		}
		#pragma endregion

		#pragma region TestContactRectangleAndRectangle
		TEST_METHOD(TestContactRectangleAndRectangleNoContact)
		{
			Rectangle r1 = Rectangle(Point(1, 1), Point(2, 2));
			Rectangle r2 = Rectangle(Point(3, 3), Point(4, 4));

			bool contact = Geometry::ContactRectangleAndRectangle(r1, r2);

			Assert::IsFalse(contact);
		}

		TEST_METHOD(TestContactRectangleAndRectangleSameRectangle)
		{
			Rectangle r1 = Rectangle(Point(1, 1), Point(2, 2));
			Rectangle r2 = Rectangle(Point(1, 1), Point(2, 2));

			bool contact = Geometry::ContactRectangleAndRectangle(r1, r2);

			Assert::IsTrue(contact);
		}

		// This is a debatable interaction - for now we'll keep it as it is.
		TEST_METHOD(TestContactRectangleAndRectangleOneSideSame)
		{
			Rectangle r1 = Rectangle(Point(1, 1), Point(2, 2));
			Rectangle r2 = Rectangle(Point(2, 2), Point(3, 3));

			bool contact = Geometry::ContactRectangleAndRectangle(r1, r2);

			Assert::IsFalse(contact);
		}

		TEST_METHOD(TestContactRectangleAndRectangleRectangleInside)
		{
			Rectangle r1 = Rectangle(Point(1, 1), Point(4, 4));
			Rectangle r2 = Rectangle(Point(2, 2), Point(3, 3));

			bool contact = Geometry::ContactRectangleAndRectangle(r1, r2);

			Assert::IsTrue(contact);
		}

		TEST_METHOD(TestContactRectangleAndRectanglePlusShape)
		{
			Rectangle r1 = Rectangle(Point(1, 1), Point(10, 2));
			Rectangle r2 = Rectangle(Point(3, -1), Point(3, 4));

			bool contact = Geometry::ContactRectangleAndRectangle(r1, r2);

			Assert::IsTrue(contact);
		}

		TEST_METHOD(TestContactRectangleAndRectangleOneCorner)
		{
			Rectangle r1 = Rectangle(Point(1, 1), Point(4, 4));
			Rectangle r2 = Rectangle(Point(0,0), Point(2,2));

			bool contact = Geometry::ContactRectangleAndRectangle(r1, r2);

			Assert::IsTrue(contact);
		}

		TEST_METHOD(TestContactRectangleAndRectangleTwoCorner)
		{
			Rectangle r1 = Rectangle(Point(1, 1), Point(4, 4));
			Rectangle r2 = Rectangle(Point((float)0, 1.5f), Point(2.0f, 3.5f));

			bool contact = Geometry::ContactRectangleAndRectangle(r1, r2);

			Assert::IsTrue(contact);
		}
		#pragma endregion 
	};
}