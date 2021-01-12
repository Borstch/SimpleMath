#pragma once

#include "gtest/gtest.h"
#include "SimpleMath/Vector/Vector.h"

#define EXPECT_VEC2_EQ(v1, v2)	EXPECT_FLOAT_EQ((v1).getX(), (v2).getX());\
								EXPECT_FLOAT_EQ((v1).getY(), (v2).getY());\
								EXPECT_FLOAT_EQ((v1).m_Alpha, (v2).m_Alpha);\
								EXPECT_FLOAT_EQ((v1).m_Betha, (v2).m_Betha);\
								EXPECT_FLOAT_EQ((v1).m_Magnitude, (v2).m_Magnitude)

#define EXPECT_VEC2_NE(v1, v2)	EXPECT_NE((v1).getX(), (v2).getX());\
								EXPECT_NE((v1).getY(), (v2).getY());\
								EXPECT_NE((v1).m_Alpha, (v2).m_Alpha);\
								EXPECT_NE((v1).m_Betha, (v2).m_Betha);\
								EXPECT_NE((v1).m_Magnitude, (v2).m_Magnitude) 

namespace Vec2dTests
{
	using namespace SimpleMath::Linalg::Vector;
	const float M_PI = 3.14159265358979323846f;  /* pi from math.h */

	TEST(Vec2dConstructorTest, Default)
	{
		Vector2D d;
		Vector2D v1(0.0f);
		Vector2D v2(0.0f, 0.0f);

		EXPECT_VEC2_EQ(d, v1);
		EXPECT_VEC2_EQ(d, v2);
	}

	TEST(Vec2dConstructorTest, Simple)
	{
		Vector2D v1(1010.0f);
		Vector2D v2(31.0f);
		Vector2D v3(-615.0f);
		Vector2D v4(1234567.0f);
		Vector2D v5(-1.0f);

		EXPECT_VEC2_EQ(v1, Vector2D(1010.0f, 1010.0f));
		EXPECT_VEC2_EQ(v2, Vector2D(31.0f, 31.0f));
		EXPECT_VEC2_EQ(v3, Vector2D(-615.0f, -615.0f));
		EXPECT_VEC2_EQ(v4, Vector2D(1234567.0f, 1234567.0f));
		EXPECT_VEC2_EQ(v5, Vector2D(-1.0f, -1.0f));
	}

	TEST(Vec2dConstructorTest, Copy)
	{
		Vector2D v11(3.0f, 16.0f);
		Vector2D v12 = v11;
		Vector2D v21(-3.0f, 224.0f);
		Vector2D v22 = v21;
		Vector2D v31;
		Vector2D v32 = v31;
		Vector2D v41(8.0f);
		Vector2D v42 = v41;

		EXPECT_VEC2_EQ(v11, v12);
		EXPECT_VEC2_EQ(v21, v22);
		EXPECT_VEC2_EQ(v31, v32);
		EXPECT_VEC2_EQ(v41, v42);
	}

	TEST(Vec2dOperatorsTest, FirstUnaryMinus)
	{
		Vector2D v1(15.0f);
		Vector2D v2(-15.0f);

		ASSERT_GT(v1.m_Magnitude, 0.0f);
		ASSERT_GT((-v1).m_Magnitude, 0.0f);
		ASSERT_GT(v2.m_Magnitude, 0.0f);
		ASSERT_GT((-v2).m_Magnitude, 0.0f);

		// EXPECT_VEC2_NE without magnitude
		EXPECT_NE((v1).getX(), (-v1).getX());
		EXPECT_NE((v1).getY(), (-v1).getY());
		EXPECT_NE((v1).m_Alpha, (-v1).m_Alpha);
		EXPECT_NE((v1).m_Betha, (-v1).m_Betha);

		// EXPECT_VEC2_NE without magnitude
		EXPECT_NE((v2).getX(), (-v2).getX());
		EXPECT_NE((v2).getY(), (-v2).getY());
		EXPECT_NE((v2).m_Alpha, (-v2).m_Alpha);
		EXPECT_NE((v2).m_Betha, (-v2).m_Betha);
		
		// EXPECT_VEC2_NE without magnitude
		EXPECT_NE((v1).getX(), (v2).getX());
		EXPECT_NE((v1).getY(), (v2).getY());
		EXPECT_NE((v1).m_Alpha, (v2).m_Alpha);
		EXPECT_NE((v1).m_Betha, (v2).m_Betha);

		EXPECT_VEC2_EQ(v1, -v2);
		EXPECT_VEC2_EQ(-v1, v2);
	}

	TEST(Vec2dOperatorsTest, SecondUnaryMinus)
	{
		Vector2D v;
		EXPECT_VEC2_EQ(v, -v);
	}

	TEST(Vec2dOperatorsTest, FirstEquality)
	{
		Vector2D v1(35.0f, 16.0f);
		Vector2D v2 = v1;
		EXPECT_TRUE(v1 == v1);
		EXPECT_TRUE(v2 == v2);
		EXPECT_TRUE(v1 == v2);
	}

	TEST(Vec2dOperatorsTest, SecondEquality)
	{
		Vector2D v1(40.0f, 22.0f);
		Vector2D v2(38.0f, 66.0f);
		EXPECT_FALSE(v1 == v2);
	}

	TEST(Vec2dOperatorsTest, ThirdEquality)
	{
		Vector2D v1(35.0f, -16.0f);
		Vector2D v2(-35.0f, 16.0f);
		EXPECT_TRUE(-v1 == v2);
		EXPECT_TRUE(v1 == -v2);
		EXPECT_FALSE(v1 == v2);
		EXPECT_FALSE(-v1 == -v2);
	}

	TEST(Vec2dOperatorsTest, PositiveScaling)
	{
		Vector2D v1(75.0f, 1.0f);
		Vector2D answer(150.0f, 2.0f);
		EXPECT_VEC2_EQ(answer, 2.0f * v1);
	}

	TEST(Vec2dOperatorsTest, PositiveFloatScaling)
	{
		Vector2D v1(120.0f, 36.0f);
		Vector2D answer(60.0f, 18.0f);
		EXPECT_VEC2_EQ(answer, 0.5f * v1);
	}

	TEST(Vec2dOperatorsTest, NegativeScaling)
	{
		Vector2D v1(8.0f, -5.0f);
		Vector2D answer(-48.0f, 30.0f);
		EXPECT_VEC2_EQ(answer, -6.0f * v1);
	}

	TEST(Vec2dOperatorsTest, NegativeFloatScaling)
	{
		Vector2D v1(-64.0f, -32.0f);
		Vector2D answer(96.0f, 48.0f);
		EXPECT_VEC2_EQ(answer, -1.5f * v1);
	}

	TEST(Vec2dAdditionTest, FirstPositiveValues)
	{
		Vector2D v1(4.0f, 6.0f);
		Vector2D v2(13.0f, 7.0f);
		Vector2D answer(17.0f, 13.0f);

		Vector2D res1 = add(v1, v2);
		Vector2D res2 = v1 + v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dAdditionTest, SecondPositiveValues)
	{
		Vector2D v1(122.0f, 13.0f);
		Vector2D v2(65.0f, 0.0f);
		Vector2D answer(187.0f, 13.0f);

		Vector2D res1 = add(v1, v2);
		Vector2D res2 = v1 + v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dAdditionTest, ThirdPositiveValues)
	{
		Vector2D v1(15.0f, 2.0f);
		Vector2D v2(985.0f, 998.0f);
		Vector2D answer(1000.0f, 1000.0f);

		Vector2D res1 = add(v1, v2);
		Vector2D res2 = v1 + v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dAdditionTest, FirstNegativeValues)
	{
		Vector2D v1(-34.0f, -15.0f);
		Vector2D v2(-5.0f, 1.0f);
		Vector2D answer(-39.0f, -14.0f);

		Vector2D res1 = add(v1, v2);
		Vector2D res2 = v1 + v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dAdditionTest, SecondNegativeValues)
	{
		Vector2D v1(-34.0f, 15.0f);
		Vector2D v2(35.0f, -30.0f);
		Vector2D answer(1.0f, -15.0f);

		Vector2D res1 = add(v1, v2);
		Vector2D res2 = v1 + v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dAdditionTest, ThirdNegativeValues)
	{
		Vector2D v1(34.0f, -15.0f);
		Vector2D v2(-35.0f, 30.0f);
		Vector2D answer(-1.0f, 15.0f);

		Vector2D res1 = add(v1, v2);
		Vector2D res2 = v1 + v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dAdditionTest, FourthNegativeValues)
	{
		Vector2D v1(-1111.0f, 151515.0f);
		Vector2D v2(1111.0f, -151515.0f);
		Vector2D answer;

		Vector2D res1 = add(v1, v2);
		Vector2D res2 = v1 + v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dAdditionTest, ZeroesAddition)
	{
		Vector2D answer;

		Vector2D res1 = add(answer, answer);
		Vector2D res2 = answer + answer;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dAdditionTest, FirstModifiyng)
	{
		Vector2D v1(24.0f, 3.0f);
		Vector2D v2 = v1;

		v1.add(v2);
		// EXPECT_VEC2_NE without angles
		EXPECT_NE((v1).getX(), (v2).getX());
		EXPECT_NE((v1).getY(), (v2).getY());
		EXPECT_NE((v1).m_Magnitude, (v2).m_Magnitude);
	}

	TEST(Vec2dAdditionTest, SecondModifiyng)
	{
		Vector2D v1(24.0f, 3.0f);
		Vector2D v2(12.0f, 10.0f);
		Vector2D answer(36.0f, 13.0f);

		v1.add(v2);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dAdditionTest, ThirdModifiyng)
	{
		Vector2D v1(-13.0f, 3.0f);
		Vector2D v2(22.0f, -68.0f);
		Vector2D answer(9.0f, -65.0f);

		v1.add(v2);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dAdditionTest, FourthModifiyng)
	{
		Vector2D v1(77.0f, -48.0f);
		Vector2D v2(-150.0f, 42.0f);
		Vector2D answer(-73.0f, -6.0f);

		v1.add(v2);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dAdditionTest, FifthModifiyng)
	{
		Vector2D v1(15.0f, -33.0f);
		Vector2D v2(-15.0f, 33.0f);
		Vector2D answer;

		v1.add(v2);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dAdditionTest, SixthModifiyng)
	{
		Vector2D v1;
		Vector2D answer;

		v1.add(v1);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dAdditionTest, SeventhModifiyng)
	{
		Vector2D v1(15.0f, -33.0f);
		Vector2D answer(30.0f, -66.0f);

		v1.add(v1);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dSubtractionTest, FirstPositiveValues)
	{
		Vector2D v1(2.0f, 200.0f);
		Vector2D v2(1.0f, 56.0f);
		Vector2D answer(1.0f, 144.0f);

		Vector2D res1 = sub(v1, v2);
		Vector2D res2 = v1 - v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dSubtractionTest, SecondPositiveValues)
	{
		Vector2D v1(6.0f, 103.0f);
		Vector2D v2(55.0f, 104.0f);
		Vector2D answer(-49.0f, -1.0f);

		Vector2D res1 = sub(v1, v2);
		Vector2D res2 = v1 - v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dSubtractionTest, ThirdPositiveValues)
	{
		Vector2D v1(6.0f, 1298.0f);
		Vector2D v2(6.0f, 98.0f);
		Vector2D answer(0.0f, 1200.0f);

		Vector2D res1 = sub(v1, v2);
		Vector2D res2 = v1 - v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dSubtractionTest, FirstNegativeValues)
	{
		Vector2D v1(-34.0f, -15.0f);
		Vector2D v2(-5.0f, 1.0f);
		Vector2D answer(-29.0f, -16.0f);

		Vector2D res1 = sub(v1, v2);
		Vector2D res2 = v1 - v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dSubtractionTest, SecondNegativeValues)
	{
		Vector2D v1(-34.0f, 264.0f);
		Vector2D v2(60.0f, -38.0f);
		Vector2D answer(-94.0f, 302.0f);

		Vector2D res1 = sub(v1, v2);
		Vector2D res2 = v1 - v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dSubtractionTest, ThirdNegativeValues)
	{
		Vector2D v1(215.0f, -5.0f);
		Vector2D v2(-13.0f, 88.0f);
		Vector2D answer(228.0f, -93.0f);

		Vector2D res1 = sub(v1, v2);
		Vector2D res2 = v1 - v2;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dSubtractionTest, FourthNegativeValues)
	{
		Vector2D v1(-215.0f, 30215.0f);
		Vector2D answer;

		Vector2D res1 = sub(v1, v1);
		Vector2D res2 = v1 - v1;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dSubtractionTest, ZeroesSubtraction)
	{
		Vector2D answer;

		Vector2D res1 = sub(answer, answer);
		Vector2D res2 = answer - answer;

		EXPECT_VEC2_EQ(answer, res1);
		EXPECT_VEC2_EQ(answer, res2);
	}

	TEST(Vec2dSubtractionTest, FirstModifiyng)
	{
		Vector2D v1(24.0f, 3.0f);
		Vector2D v2 = v1;

		v1.sub(v2);
		EXPECT_VEC2_NE(v1, v2);
	}

	TEST(Vec2dSubtractionTest, SecondModifiyng)
	{
		Vector2D v1(77.0f, 48.0f);
		Vector2D v2(17.0f, 42.0f);
		Vector2D answer(60.0f, 6.0f);

		v1.sub(v2);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dSubtractionTest, ThirdModifiyng)
	{
		Vector2D v1(-77.0f, 48.0f);
		Vector2D v2(17.0f, -42.0f);
		Vector2D answer(-94.0f, 90.0f);

		v1.sub(v2);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dSubtractionTest, FourthModifiyng)
	{
		Vector2D v1(77.0f, -48.0f);
		Vector2D v2(-17.0f, 42.0f);
		Vector2D answer(94.0f, -90.0f);

		v1.sub(v2);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dSubtractionTest, FifthModifiyng)
	{
		Vector2D v1(15.0f, -33.0f);
		Vector2D answer;

		v1.sub(v1);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dSubtractionTest, SixthModifiyng)
	{
		Vector2D v1;
		Vector2D answer;

		v1.sub(v1);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2dDotProductTest, DotProductWithDot)
	{
		Vector2D v0;
		Vector2D v1(3.0f, 15.0f);
		Vector2D v2(-8.0f, 264.0f);

		EXPECT_FLOAT_EQ(0.0f, v0.dot(v1));
		EXPECT_FLOAT_EQ(0.0f, dot(v0, v1));
		EXPECT_FLOAT_EQ(0.0f, v0 * v1);

		EXPECT_FLOAT_EQ(0.0f, v2.dot(v0));
		EXPECT_FLOAT_EQ(0.0f, dot(v2, v0));
		EXPECT_FLOAT_EQ(0.0f, v2 * v0);
	}

	TEST(Vec2dDotProductTest, FirstDotProduct)
	{
		Vector2D v1(3.5f, 64.75f);
		Vector2D v2(-8.25f, 313.8f);

		EXPECT_FLOAT_EQ(20289.675f, v1.dot(v2));
		EXPECT_FLOAT_EQ(20289.675f, dot(v1, v2));
		EXPECT_FLOAT_EQ(20289.675f, v1 * v2);
	}

	TEST(Vec2dDotProductTest, SecondDotProduct)
	{
		Vector2D v1(64.0f, 0.0f);
		Vector2D v2(0.0f, 15.0f);

		EXPECT_FLOAT_EQ(0.0f, v1.dot(v2));
		EXPECT_FLOAT_EQ(0.0f, dot(v1, v2));
		EXPECT_FLOAT_EQ(0.0f, v1 * v2);
	}

	TEST(Vec2dDotProductTest, ThirdDotProduct)
	{
		Vector2D v1(-1010.1f, 67.13f);
		Vector2D v2(0.65f, 8.08f);

		EXPECT_FLOAT_EQ(-114.15454f, v1.dot(v2));
		EXPECT_FLOAT_EQ(-114.15454f, dot(v1, v2));
		EXPECT_FLOAT_EQ(-114.15454f, v1 * v2);
	}

	TEST(Vec2dPointTest, OnePoint)
	{
		Vector2D v0;
		Vector2D v1(-3.0f);
		Vector2D v2(0.0f, 16.0f);
		Vector2D v3(-5.0f, 0.0f);

		EXPECT_TRUE(v0.is_point());
		EXPECT_FALSE(v1.is_point());
		EXPECT_FALSE(v2.is_point());
		EXPECT_FALSE(v3.is_point());
	}

	TEST(Vec2dCollinearTest, OneVector)
	{
		Vector2D v1(1.0f, 6.0f);
		EXPECT_TRUE(v1.is_collinear_with(v1));
		EXPECT_TRUE(is_collinear(v1, v1));
	}

	TEST(Vec2dCollinearTest, DotWithVector)
	{
		Vector2D v0;
		Vector2D v1(1.0f, 6.0f);
		Vector2D v2(13.0f, 8.0f);
		EXPECT_TRUE(v1.is_collinear_with(v0));
		EXPECT_TRUE(is_collinear(v1, v0));
		EXPECT_TRUE(v2.is_collinear_with(v0));
		EXPECT_TRUE(is_collinear(v2, v0));
		EXPECT_TRUE(v0.is_collinear_with(v1));
		EXPECT_TRUE(is_collinear(v0, v1));
		EXPECT_TRUE(v0.is_collinear_with(v2));
		EXPECT_TRUE(is_collinear(v0, v2));
	}

	TEST(Vec2dCollinearTest, ReversedVector)
	{
		Vector2D v1(101010.0f);
		EXPECT_TRUE(v1.is_collinear_with(-v1));
		EXPECT_TRUE(is_collinear(v1, -v1));
	}

	TEST(Vec2dCollinearTest, ThreeCollinearVectors)
	{
		Vector2D v1(1.0f, 3.0f);
		Vector2D v2(3.0f, 9.0f);
		Vector2D v3(-8.0f, -24.0f);
		EXPECT_TRUE(v1.is_collinear_with(v2));
		EXPECT_TRUE(is_collinear(v1, v2));
		EXPECT_TRUE(v2.is_collinear_with(v1));
		EXPECT_TRUE(is_collinear(v2, v1));

		EXPECT_TRUE(v1.is_collinear_with(v3));
		EXPECT_TRUE(is_collinear(v1, v3));
		EXPECT_TRUE(v3.is_collinear_with(v1));
		EXPECT_TRUE(is_collinear(v3, v1));

		EXPECT_TRUE(v2.is_collinear_with(v3));
		EXPECT_TRUE(is_collinear(v2, v3));
		EXPECT_TRUE(v3.is_collinear_with(v2));
		EXPECT_TRUE(is_collinear(v3, v2));
	}

	TEST(Vec2dCollinearTest, NotCollinearVectors)
	{
		Vector2D v1(0.0f, 13.0f);
		Vector2D v2(13.0f, 0.0f);

		EXPECT_FALSE(v1.is_collinear_with(v2));
		EXPECT_FALSE(is_collinear(v1, v2));
	}

	TEST(Vec2dSetCoordsTest, SetDotCoords)
	{
		Vector2D v;
		Vector2D answer(101010.314f, -3214125.1f);
		
		v.setCoords(101010.314f, -3214125.1f);
		EXPECT_VEC2_EQ(v, answer);
	}

	TEST(Vec2dSetCoordsTest, SetPositiveValues)
	{
		Vector2D v(13.0f, 207.0f);
		Vector2D answer(13.01f, 256.17f);

		v.setCoords(13.01f, 256.17f);
		EXPECT_VEC2_EQ(v, answer);
	}

	TEST(Vec2dSetCoordsTest, SetNegativeValues)
	{
		Vector2D v(13.0f, 207.0f);
		Vector2D answer(-64.15f, -165.81f);

		v.setCoords(-64.15f, -165.81f);
		EXPECT_VEC2_EQ(v, answer);
	}

	TEST(Vec2dSetCoordsTest, SetZeroes)
	{
		Vector2D v(5262.23f, 31251.561f);
		Vector2D answer;

		v.setCoords(0.0f, -0.0f);
		EXPECT_VEC2_EQ(v, answer);
	}

	TEST(Vec2dSetCoordsTest, MultipleSet)
	{
		Vector2D v(5262.23f, 31251.561f);
		Vector2D answer(1.0f, 2.0f);

		v.setCoords(870.513f, 311515.767f);
		v.setCoords(656.0f, 13.0f);
		v.setCoords(1.0f, 2.0f);
		EXPECT_VEC2_EQ(v, answer);
	}

	TEST(Vec2DNormalizationTest, ParamsCheck)
	{
		Vector2D v_normalized(13.0f, 26.0f);
		Vector2D v = v_normalized;
		v_normalized.normalize();

		EXPECT_FLOAT_EQ(v.m_Alpha, v_normalized.m_Alpha);
		EXPECT_FLOAT_EQ(v.m_Betha, v_normalized.m_Betha);
		EXPECT_FLOAT_EQ(1.0f, v_normalized.m_Magnitude);
	}

	TEST(Vec2DNormalizationTest, NoChanges)
	{
		Vector2D v1(0.0f, 1.0f);
		Vector2D v2 = v1;

		v1.normalize();
		EXPECT_VEC2_EQ(v1, v2);
	}

	TEST(Vec2DNormalizationTest, JustScaling)
	{
		Vector2D v1(64.0f, 0.0f);
		Vector2D answer(1.0f, 0.0f);

		v1.normalize();
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2DNormalizationTest, SimilarityCheck)
	{
		Vector2D v1(123.0f, 546.0f);
		Vector2D answer(0.21976729f, 0.97555238f);

		v1.normalize();
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2DScalingTest, ScaleByZero)
	{
		Vector2D v1(123.0f, 546.0f);
		Vector2D answer;

		v1.scale(0.0f);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2DScalingTest, ScaleByPositiveValue)
	{
		Vector2D v1(-256.0f, 16.0f);
		Vector2D answer(-128.0f, 8.0f);

		v1.scale(0.5f);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2DScalingTest, ScaleByNegativeValue)
	{
		Vector2D v1(15.0f, -3.0f);
		Vector2D answer(-150.0f, 30.0f);

		v1.scale(-10.0f);
		EXPECT_VEC2_EQ(answer, v1);
	}

	TEST(Vec2DScalingTest, MultipleScaling)
	{
		Vector2D v1(64.15f, -301.005f);
		Vector2D answer = v1;

		v1.scale(-10.0f);
		v1.scale(-0.1f);
		EXPECT_VEC2_EQ(answer, v1);
	}
}