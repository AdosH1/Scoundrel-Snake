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
#pragma region TestDistanceBetweenTwoPoints
		TEST_METHOD(TestDistanceBetweenTwoPointsPosPos)
		{
			Point p1 = Point(1, 1);
			Point p2 = Point(3, 3);

			double dist = Geometry::DistanceBetweenTwoPoints(p1, p2);
			double distCheck = sqrt(pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2));

			Assert::AreEqual(distCheck, dist, 0.01);
		}

		TEST_METHOD(TestDistanceBetweenTwoPointsPosNeg)
		{
			Point p1 = Point(1, 1);
			Point p2 = Point(-3, -3);

			double dist = Geometry::DistanceBetweenTwoPoints(p1, p2);
			double distCheck = sqrt(pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2));

			Assert::AreEqual(distCheck, dist, 0.01);
		}

		TEST_METHOD(TestDistanceBetweenTwoPointsNegPos)
		{
			Point p1 = Point(-1, -1);
			Point p2 = Point(3, 3);

			double dist = Geometry::DistanceBetweenTwoPoints(p1, p2);
			double distCheck = sqrt(pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2));

			Assert::AreEqual(distCheck, dist, 0.01);
		}

		TEST_METHOD(TestDistanceBetweenTwoPointsNegNeg)
		{
			Point p1 = Point(-1, -1);
			Point p2 = Point(-3, -3);

			double dist = Geometry::DistanceBetweenTwoPoints(p1, p2);
			double distCheck = sqrt(pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2));

			Assert::AreEqual(distCheck, dist, 0.01);
		}
#pragma endregion 

#pragma region TestRandomPointWithinRectangle
		TEST_METHOD(TestRandomPointWithinRectanglePosPos)
		{
			Point p1 = Point(0, 0);
			Point p2 = Point(600, 600);
			Rectangle r = Rectangle(p1, p2);

			Point t1 = Geometry::RandomPointWithinRectangle(r);
			Point t2 = Geometry::RandomPointWithinRectangle(r);
			Point t3 = Geometry::RandomPointWithinRectangle(r);
			Point t4 = Geometry::RandomPointWithinRectangle(r);
			Point t5 = Geometry::RandomPointWithinRectangle(r);
			Point t6 = Geometry::RandomPointWithinRectangle(r);

			Assert::IsTrue(t1.X < r.Max.X && 
				t1.Y < r.Max.Y && 
				t1.X >= r.Min.X && 
				t1.Y >= r.Min.Y);

			Assert::IsTrue(t2.X < r.Max.X &&
				t2.Y < r.Max.Y &&
				t2.X >= r.Min.X &&
				t2.Y >= r.Min.Y);

			Assert::IsTrue(t3.X < r.Max.X &&
				t3.Y < r.Max.Y &&
				t3.X >= r.Min.X &&
				t3.Y >= r.Min.Y);

			Assert::IsTrue(t4.X < r.Max.X &&
				t4.Y < r.Max.Y &&
				t4.X >= r.Min.X &&
				t4.Y >= r.Min.Y);

			Assert::IsTrue(t5.X < r.Max.X &&
				t5.Y < r.Max.Y &&
				t5.X >= r.Min.X &&
				t5.Y >= r.Min.Y);

			Assert::IsTrue(t6.X < r.Max.X &&
				t6.Y < r.Max.Y &&
				t6.X >= r.Min.X &&
				t6.Y >= r.Min.Y);
		}

		TEST_METHOD(TestRandomPointWithinRectanglePosNeg)
		{
			Point p1 = Point(300, 300);
			Point p2 = Point(-300, -300);
			Rectangle r = Rectangle(p1, p2);

			Point t1 = Geometry::RandomPointWithinRectangle(r);
			Point t2 = Geometry::RandomPointWithinRectangle(r);
			Point t3 = Geometry::RandomPointWithinRectangle(r);
			Point t4 = Geometry::RandomPointWithinRectangle(r);
			Point t5 = Geometry::RandomPointWithinRectangle(r);
			Point t6 = Geometry::RandomPointWithinRectangle(r);

			Assert::IsTrue(t1.X < r.Max.X &&
				t1.Y < r.Max.Y &&
				t1.X >= r.Min.X &&
				t1.Y >= r.Min.Y);

			Assert::IsTrue(t2.X < r.Max.X &&
				t2.Y < r.Max.Y &&
				t2.X >= r.Min.X &&
				t2.Y >= r.Min.Y);

			Assert::IsTrue(t3.X < r.Max.X &&
				t3.Y < r.Max.Y &&
				t3.X >= r.Min.X &&
				t3.Y >= r.Min.Y);

			Assert::IsTrue(t4.X < r.Max.X &&
				t4.Y < r.Max.Y &&
				t4.X >= r.Min.X &&
				t4.Y >= r.Min.Y);

			Assert::IsTrue(t5.X < r.Max.X &&
				t5.Y < r.Max.Y &&
				t5.X >= r.Min.X &&
				t5.Y >= r.Min.Y);

			Assert::IsTrue(t6.X < r.Max.X &&
				t6.Y < r.Max.Y &&
				t6.X >= r.Min.X &&
				t6.Y >= r.Min.Y);
		}

		TEST_METHOD(TestRandomPointWithinRectangleNegNeg)
		{
			Point p1 = Point(-900, -900);
			Point p2 = Point(-300, -300);
			Rectangle r = Rectangle(p1, p2);

			Point t1 = Geometry::RandomPointWithinRectangle(r);
			Point t2 = Geometry::RandomPointWithinRectangle(r);
			Point t3 = Geometry::RandomPointWithinRectangle(r);
			Point t4 = Geometry::RandomPointWithinRectangle(r);
			Point t5 = Geometry::RandomPointWithinRectangle(r);
			Point t6 = Geometry::RandomPointWithinRectangle(r);

			Assert::IsTrue(t1.X < r.Max.X &&
				t1.Y < r.Max.Y &&
				t1.X >= r.Min.X &&
				t1.Y >= r.Min.Y);

			Assert::IsTrue(t2.X < r.Max.X &&
				t2.Y < r.Max.Y &&
				t2.X >= r.Min.X &&
				t2.Y >= r.Min.Y);

			Assert::IsTrue(t3.X < r.Max.X &&
				t3.Y < r.Max.Y &&
				t3.X >= r.Min.X &&
				t3.Y >= r.Min.Y);

			Assert::IsTrue(t4.X < r.Max.X &&
				t4.Y < r.Max.Y &&
				t4.X >= r.Min.X &&
				t4.Y >= r.Min.Y);

			Assert::IsTrue(t5.X < r.Max.X &&
				t5.Y < r.Max.Y &&
				t5.X >= r.Min.X &&
				t5.Y >= r.Min.Y);

			Assert::IsTrue(t6.X < r.Max.X &&
				t6.Y < r.Max.Y &&
				t6.X >= r.Min.X &&
				t6.Y >= r.Min.Y);
		}
#pragma endregion 

#pragma region TestRandomPointWithinRectangleAwayFromPoint
		TEST_METHOD(TestRandomPointWithinRectangleAwayFromPoint)
		{
			Point p1 = Point(0, 0);
			Point p2 = Point(600, 600);
			Rectangle r = Rectangle(p1, p2);

			Point away = Point(100, 100);
			double distance = 100;

			for (int i = 0; i < 100; i++)
			{
				Point t = Geometry::RandomPointWithinRectangleAwayFromPoint(r, away, distance);

				Assert::IsTrue(t.X < r.Max.X &&
					t.Y < r.Max.Y &&
					t.X >= r.Min.X &&
					t.Y >= r.Min.Y);
				Assert::IsTrue(abs(t.X - away.X) >= 100 &&
					abs(t.Y - away.Y) >= 100);
			}
		}

		TEST_METHOD(TestRandomPointWithinRectangleAwayFromPointMixBox)
		{
			Point p1 = Point(-300, -300);
			Point p2 = Point(300, 300);
			Rectangle r = Rectangle(p1, p2);

			Point away = Point(0, 0);
			double distance = 100;

			for (int i = 0; i < 100; i++)
			{
				Point t = Geometry::RandomPointWithinRectangleAwayFromPoint(r, away, distance);

				Assert::IsTrue(t.X < r.Max.X &&
					t.Y < r.Max.Y &&
					t.X >= r.Min.X &&
					t.Y >= r.Min.Y);
				Assert::IsTrue(abs(t.X - away.X) >= 100 &&
					abs(t.Y - away.Y) >= 100);
			}
		}

		TEST_METHOD(TestRandomPointWithinRectangleAwayFromPointSmallBox)
		{
			Point p1 = Point(-100, -100);
			Point p2 = Point(100, 100);
			Rectangle r = Rectangle(p1, p2);

			Point away = Point(-100, -100);
			double distance = 100;

			for (int i = 0; i < 100; i++)
			{
				Point t = Geometry::RandomPointWithinRectangleAwayFromPoint(r, away, distance);

				Assert::IsTrue(t.X < r.Max.X &&
					t.Y < r.Max.Y &&
					t.X >= r.Min.X &&
					t.Y >= r.Min.Y);
				Assert::IsTrue(abs(t.X - away.X) >= 100 &&
					abs(t.Y - away.Y) >= 100);
			}
		}

		TEST_METHOD(TestRandomPointWithinRectangleAwayFromPointAllNeg)
		{
			Point p1 = Point(-100, -100);
			Point p2 = Point(-1000, -1000);
			Rectangle r = Rectangle(p1, p2);

			Point away = Point(-200, -200);
			double distance = -200;

			for (int i = 0; i < 100; i++)
			{
				Point t = Geometry::RandomPointWithinRectangleAwayFromPoint(r, away, distance);

				Assert::IsTrue(t.X < r.Max.X &&
					t.Y < r.Max.Y &&
					t.X >= r.Min.X &&
					t.Y >= r.Min.Y);
				Assert::IsTrue(abs(t.X - away.X) >= 100 &&
					abs(t.Y - away.Y) >= 100);
			}
		}
#pragma endregion 

#pragma region TestContactCircleAndCircle
		TEST_METHOD(TestContactCircleAndCircleNoContact)
		{
			Circle c1 = Circle(Point(1, 1), 1);
			Circle c2 = Circle(Point(3, 3), 1);

			bool contact = Geometry::ContactCircleAndCircle(c1, c2);

			Assert::IsFalse(contact);
		}

		TEST_METHOD(TestContactCircleAndCircleCrossOver)
		{
			Circle c1 = Circle(Point(1, 1), 1);
			Circle c2 = Circle(Point(2, 2), 2);

			bool contact = Geometry::ContactCircleAndCircle(c1, c2);

			Assert::IsTrue(contact);
		}

		TEST_METHOD(TestContactCircleAndCircleEngulfed)
		{
			Circle c1 = Circle(Point(3, 3), 1);
			Circle c2 = Circle(Point(3, 3), 2);

			bool contact = Geometry::ContactCircleAndCircle(c1, c2);

			Assert::IsTrue(contact);
		}

		TEST_METHOD(TestContactCircleAndCircleInRectNotCircle)
		{
			Circle c1 = Circle(Point(1, 1), 1);
			Circle c2 = Circle(Point(3, 3), 0.99);

			bool contact = Geometry::ContactCircleAndCircle(c1, c2);

			Assert::IsFalse(contact);
		}
		#pragma endregion
		
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