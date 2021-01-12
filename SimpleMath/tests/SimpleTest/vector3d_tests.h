#pragma once

#include "gtest/gtest.h"
#include "SimpleMath/Vector/Vector.h"

#define EXPECT_VEC3_EQ(v1, v2)	EXPECT_FLOAT_EQ((v1).getX(), (v2).getX());\
								EXPECT_FLOAT_EQ((v1).getY(), (v2).getY());\
								EXPECT_FLOAT_EQ((v1).getZ(), (v2).getZ());\
								EXPECT_FLOAT_EQ((v1).m_Alpha, (v2).m_Alpha);\
								EXPECT_FLOAT_EQ((v1).m_Betha, (v2).m_Betha);\
								EXPECT_FLOAT_EQ((v1).m_Gama, (v2).m_Gama);\
								EXPECT_FLOAT_EQ((v1).m_Magnitude, (v2).m_Magnitude)

#define EXPECT_VEC3_NE(v1, v2)	EXPECT_NE((v1).getX(), (v2).getX());\
								EXPECT_NE((v1).getY(), (v2).getY());\
								EXPECT_NE((v1).getZ(), (v2).getZ());\
								EXPECT_NE((v1).m_Alpha, (v2).m_Alpha);\
								EXPECT_NE((v1).m_Betha, (v2).m_Betha);\
								EXPECT_NE((v1).m_Gama, (v2).m_Gama);\
								EXPECT_NE((v1).m_Magnitude, (v2).m_Magnitude) 

namespace Vec3dTests
{
	using namespace SimpleMath::Linalg::Vector;
	const float M_PI = 3.14159265358979323846f;  /* pi from math.h */

	TEST(Vec3dConstructorTest, Default)
	{
		Vector3D d;
		Vector3D v1(0.0f);
		Vector3D v2(0.0f, 0.0f, 0.0f);

		EXPECT_VEC3_EQ(d, v1);
		EXPECT_VEC3_EQ(d, v2);
	}

	TEST(Vec3dConstructorTest, Simple)
	{
		Vector3D v1(1010.0f);
		Vector3D v2(31.0f);
		Vector3D v3(-615.0f);
		Vector3D v4(1234567.0f);
		Vector3D v5(-1.0f);

		EXPECT_VEC3_EQ(v1, Vector3D(1010.0f, 1010.0f, 1010.0f));
		EXPECT_VEC3_EQ(v2, Vector3D(31.0f, 31.0f, 31.0f));
		EXPECT_VEC3_EQ(v3, Vector3D(-615.0f, -615.0f, -615.0f));
		EXPECT_VEC3_EQ(v4, Vector3D(1234567.0f, 1234567.0f, 1234567.0f));
		EXPECT_VEC3_EQ(v5, Vector3D(-1.0f, -1.0f, -1.0f));
	}

	TEST(Vec3dConstructorTest, Copy)
	{
		Vector3D v11(3.0f, 16.0f, -6.15f);
		Vector3D v12 = v11;
		Vector3D v21(-3.0f, 224.0f, 224.73f);
		Vector3D v22 = v21;
		Vector3D v31;
		Vector3D v32 = v31;
		Vector3D v41(8.0f);
		Vector3D v42 = v41;

		EXPECT_VEC3_EQ(v11, v12);
		EXPECT_VEC3_EQ(v21, v22);
		EXPECT_VEC3_EQ(v31, v32);
		EXPECT_VEC3_EQ(v41, v42);
	}

	TEST(Vec3dOperatorsTest, FirstUnaryMinus)
	{
		Vector3D v1(15.0f);
		Vector3D v2(-15.0f);

		ASSERT_GT(v1.m_Magnitude, 0.0f);
		ASSERT_GT((-v1).m_Magnitude, 0.0f);
		ASSERT_GT(v2.m_Magnitude, 0.0f);
		ASSERT_GT((-v2).m_Magnitude, 0.0f);

		// EXPECT_VEC3_NE without magnitude
		EXPECT_NE((v1).getX(), (-v1).getX());
		EXPECT_NE((v1).getY(), (-v1).getY());
		EXPECT_NE((v1).getZ(), (v2).getZ());
		EXPECT_NE((v1).m_Alpha, (-v1).m_Alpha);
		EXPECT_NE((v1).m_Betha, (-v1).m_Betha);
		EXPECT_NE((v1).m_Gama, (-v1).m_Gama);

		// EXPECT_VEC3_NE without magnitude
		EXPECT_NE((v2).getX(), (-v2).getX());
		EXPECT_NE((v2).getY(), (-v2).getY());
		EXPECT_NE((v2).getZ(), (-v2).getZ());
		EXPECT_NE((v2).m_Alpha, (-v2).m_Alpha);
		EXPECT_NE((v2).m_Betha, (-v2).m_Betha);
		EXPECT_NE((v2).m_Gama, (-v2).m_Gama);

		// EXPECT_VEC3_NE without magnitude
		EXPECT_NE((v1).getX(), (v2).getX());
		EXPECT_NE((v1).getY(), (v2).getY());
		EXPECT_NE((v1).getZ(), (v2).getZ());
		EXPECT_NE((v1).m_Alpha, (v2).m_Alpha);
		EXPECT_NE((v1).m_Betha, (v2).m_Betha);
		EXPECT_NE((v1).m_Gama, (v2).m_Gama);

		EXPECT_VEC3_EQ(v1, -v2);
		EXPECT_VEC3_EQ(-v1, v2);
	}

	TEST(Vec3dOperatorsTest, SecondUnaryMinus)
	{
		Vector3D v;
		EXPECT_VEC3_EQ(v, -v);
	}

	TEST(Vec3dOperatorsTest, FirstEquality)
	{
		Vector3D v1(35.0f, 16.0f, -486.0931f);
		Vector3D v2 = v1;
		EXPECT_TRUE(v1 == v1);
		EXPECT_TRUE(v2 == v2);
		EXPECT_TRUE(v1 == v2);
	}

	TEST(Vec3dOperatorsTest, SecondEquality)
	{
		Vector3D v1(40.0f, 22.0f, 16.16f);
		Vector3D v2(38.0f, 66.0f, 16.16f);
		EXPECT_FALSE(v1 == v2);
	}

	TEST(Vec3dOperatorsTest, ThirdEquality)
	{
		Vector3D v1(35.0f, -16.0f, 215.978f);
		Vector3D v2(-35.0f, 16.0f, -215.978f);
		EXPECT_TRUE(-v1 == v2);
		EXPECT_TRUE(v1 == -v2);
		EXPECT_FALSE(v1 == v2);
		EXPECT_FALSE(-v1 == -v2);
	}

	TEST(Vec3dOperatorsTest, PositiveScaling)
	{
		Vector3D v1(75.0f, 1.0f, -10.0f);
		Vector3D answer(150.0f, 2.0f, -20.0f);
		EXPECT_VEC3_EQ(answer, 2.0f * v1);
	}

	TEST(Vec3dOperatorsTest, PositiveFloatScaling)
	{
		Vector3D v1(120.0f, 36.0f, 5.2f);
		Vector3D answer(60.0f, 18.0f, 2.6f);
		EXPECT_VEC3_EQ(answer, 0.5f * v1);
	}

	TEST(Vec3dOperatorsTest, NegativeScaling)
	{
		Vector3D v1(8.0f, -5.0f, -1.5);
		Vector3D answer(-48.0f, 30.0f, 9.0f);
		EXPECT_VEC3_EQ(answer, -6.0f * v1);
	}

	TEST(Vec3dOperatorsTest, NegativeFloatScaling)
	{
		Vector3D v1(-64.0f, -32.0f, -12.0f);
		Vector3D answer(96.0f, 48.0f, 18.0f);
		EXPECT_VEC3_EQ(answer, -1.5f * v1);
	}

	TEST(Vec3dAdditionTest, FirstPositiveValues)
	{
		Vector3D v1(4.0f, 6.0f, 8.0f);
		Vector3D v2(13.0f, 7.0f, 2.013f);
		Vector3D answer(17.0f, 13.0f, 10.013f);
			  
		Vector3D res1 = add(v1, v2);
		Vector3D res2 = v1 + v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dAdditionTest, SecondPositiveValues)
	{
		Vector3D v1(122.0f, 13.0f, 0.0f);
		Vector3D v2(65.0f, 0.0f, 256.15f);
		Vector3D answer(187.0f, 13.0f, 256.15f);
			  
		Vector3D res1 = add(v1, v2);
		Vector3D res2 = v1 + v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dAdditionTest, ThirdPositiveValues)
	{
		Vector3D v1(15.0f, 2.0f, 94.5);
		Vector3D v2(985.0f, 998.0f, 0.5f);
		Vector3D answer(1000.0f, 1000.0f, 95.0f);
			  
		Vector3D res1 = add(v1, v2);
		Vector3D res2 = v1 + v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dAdditionTest, FirstNegativeValues)
	{
		Vector3D v1(-34.0f, -15.0f, 38.21f);
		Vector3D v2(-5.0f, 1.0f, -0.2f);
		Vector3D answer(-39.0f, -14.0f, 38.01f);
			  
		Vector3D res1 = add(v1, v2);
		Vector3D res2 = v1 + v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dAdditionTest, SecondNegativeValues)
	{
		Vector3D v1(-34.0f, 15.0f, -1.0f);
		Vector3D v2(35.0f, -30.0f, 2.5f);
		Vector3D answer(1.0f, -15.0f, 1.5f);
			  
		Vector3D res1 = add(v1, v2);
		Vector3D res2 = v1 + v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dAdditionTest, ThirdNegativeValues)
	{
		Vector3D v1(34.0f, -15.0f, 15.0f);
		Vector3D v2(-35.0f, 30.0f, -15.0f);
		Vector3D answer(-1.0f, 15.0f, 0.0f);
			  
		Vector3D res1 = add(v1, v2);
		Vector3D res2 = v1 + v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dAdditionTest, FourthNegativeValues)
	{
		Vector3D v1(-1111.0f, 151515.0f, 908.87f);
		Vector3D v2(1111.0f, -151515.0f, -908.87f);
		Vector3D answer;
			  
		Vector3D res1 = add(v1, v2);
		Vector3D res2 = v1 + v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dAdditionTest, ZeroesAddition)
	{
		Vector3D answer;

		Vector3D res1 = add(answer, answer);
		Vector3D res2 = answer + answer;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dAdditionTest, FirstModifiyng)
	{
		Vector3D v1(24.0f, 3.0f, 644.0f);
		Vector3D v2 = v1;

		v1.add(v2);
		// EXPECT_VEC3_NE without angles
		EXPECT_NE((v1).getX(), (v2).getX());
		EXPECT_NE((v1).getY(), (v2).getY());
		EXPECT_NE((v1).getZ(), (v2).getZ());
		EXPECT_NE((v1).m_Magnitude, (v2).m_Magnitude);
	}

	TEST(Vec3dAdditionTest, SecondModifiyng)
	{
		Vector3D v1(24.0f, 3.0f, 15.08f);
		Vector3D v2(12.0f, 10.0f, 4.02f);
		Vector3D answer(36.0f, 13.0f, 19.1f);

		v1.add(v2);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dAdditionTest, ThirdModifiyng)
	{
		Vector3D v1(-13.0f, 3.0f, -200.0f);
		Vector3D v2(22.0f, -68.0f, 63.0f);
		Vector3D answer(9.0f, -65.0f, -137.0f);

		v1.add(v2);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dAdditionTest, FourthModifiyng)
	{
		Vector3D v1(77.0f, -48.0f, 13.0f);
		Vector3D v2(-150.0f, 42.0f, -10.0f);
		Vector3D answer(-73.0f, -6.0f, 3.0f);

		v1.add(v2);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dAdditionTest, FifthModifiyng)
	{
		Vector3D v1(15.0f, -33.0f, -256.235f);
		Vector3D v2(-15.0f, 33.0f, 256.235f);
		Vector3D answer;

		v1.add(v2);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dAdditionTest, SixthModifiyng)
	{
		Vector3D v1;
		Vector3D answer;

		v1.add(v1);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dAdditionTest, SeventhModifiyng)
	{
		Vector3D v1(15.0f, -33.0f, 1.1f);
		Vector3D answer(30.0f, -66.0f, 2.2f);

		v1.add(v1);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dSubtractionTest, FirstPositiveValues)
	{
		Vector3D v1(2.0f, 200.0f, 678.659f);
		Vector3D v2(1.0f, 56.0f, 600.059f);
		Vector3D answer(1.0f, 144.0f, 78.6f);
			  
		Vector3D res1 = sub(v1, v2);
		Vector3D res2 = v1 - v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dSubtractionTest, SecondPositiveValues)
	{
		Vector3D v1(6.0f, 103.0f, 76.0f);
		Vector3D v2(55.0f, 104.0f, 17.0f);
		Vector3D answer(-49.0f, -1.0f, 59.0f);
			  
		Vector3D res1 = sub(v1, v2);
		Vector3D res2 = v1 - v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dSubtractionTest, ThirdPositiveValues)
	{
		Vector3D v1(6.0f, 1298.0f, 546.465f);
		Vector3D v2(6.0f, 98.0f, 0.465f);
		Vector3D answer(0.0f, 1200.0f, 546.0f);
			  
		Vector3D res1 = sub(v1, v2);
		Vector3D res2 = v1 - v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dSubtractionTest, FirstNegativeValues)
	{
		Vector3D v1(-34.0f, -15.0f, 28.0f);
		Vector3D v2(-5.0f, 1.0f, -2.5f);
		Vector3D answer(-29.0f, -16.0f, 30.5f);
			  
		Vector3D res1 = sub(v1, v2);
		Vector3D res2 = v1 - v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dSubtractionTest, SecondNegativeValues)
	{
		Vector3D v1(-34.0f, 264.0f, 13.0f);
		Vector3D v2(60.0f, -38.0f, -167.0f);
		Vector3D answer(-94.0f, 302.0f, 180.0f);
			  
		Vector3D res1 = sub(v1, v2);
		Vector3D res2 = v1 - v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dSubtractionTest, ThirdNegativeValues)
	{
		Vector3D v1(215.0f, -5.0f, -31.68f);
		Vector3D v2(-13.0f, 88.0f, 15.56f);
		Vector3D answer(228.0f, -93.0f, -47.24f);
			  
		Vector3D res1 = sub(v1, v2);
		Vector3D res2 = v1 - v2;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dSubtractionTest, FourthNegativeValues)
	{
		Vector3D v1(-215.0f, 30215.0f, 5.05f);
		Vector3D answer;
			  
		Vector3D res1 = sub(v1, v1);
		Vector3D res2 = v1 - v1;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dSubtractionTest, ZeroesSubtraction)
	{
		Vector3D answer;

		Vector3D res1 = sub(answer, answer);
		Vector3D res2 = answer - answer;

		EXPECT_VEC3_EQ(answer, res1);
		EXPECT_VEC3_EQ(answer, res2);
	}

	TEST(Vec3dSubtractionTest, FirstModifiyng)
	{
		Vector3D v1(24.0f, 3.0f, -24.3f);
		Vector3D v2 = v1;

		v1.sub(v2);
		EXPECT_VEC3_NE(v1, v2);
	}

	TEST(Vec3dSubtractionTest, SecondModifiyng)
	{
		Vector3D v1(77.0f, 48.0f, -5.0f);
		Vector3D v2(17.0f, 42.0f, -5.0f);
		Vector3D answer(60.0f, 6.0f, 0.0f);

		v1.sub(v2);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dSubtractionTest, ThirdModifiyng)
	{
		Vector3D v1(-77.0f, 48.0f, 13.0f);
		Vector3D v2(17.0f, -42.0f, 15.0f);
		Vector3D answer(-94.0f, 90.0f, -2.0f);

		v1.sub(v2);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dSubtractionTest, FourthModifiyng)
	{
		Vector3D v1(77.0f, -48.0f, 86.0f);
		Vector3D v2(-17.0f, 42.0f, 64.0f);
		Vector3D answer(94.0f, -90.0f, 22.0f);

		v1.sub(v2);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dSubtractionTest, FifthModifiyng)
	{
		Vector3D v1(15.0f, -33.0f, 423.0f);
		Vector3D answer;

		v1.sub(v1);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dSubtractionTest, SixthModifiyng)
	{
		Vector3D v1;
		Vector3D answer;

		v1.sub(v1);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dDotProductTest, DotProductWithDot)
	{
		Vector3D v0;
		Vector3D v1(3.0f, 15.0f, 5.0f);
		Vector3D v2(-8.0f, 264.0f, -16.0f);

		EXPECT_FLOAT_EQ(0.0f, v0.dot(v1));
		EXPECT_FLOAT_EQ(0.0f, dot(v0, v1));
		EXPECT_FLOAT_EQ(0.0f, v0 * v1);

		EXPECT_FLOAT_EQ(0.0f, v2.dot(v0));
		EXPECT_FLOAT_EQ(0.0f, dot(v2, v0));
		EXPECT_FLOAT_EQ(0.0f, v2 * v0);
	}

	TEST(Vec3dDotProductTest, FirstDotProduct)
	{
		Vector3D v1(3.5f, 64.75f, 1.1f);
		Vector3D v2(-8.25f, 313.8f, -5.0f);

		EXPECT_FLOAT_EQ(20284.175f, v1.dot(v2));
		EXPECT_FLOAT_EQ(20284.175f, dot(v1, v2));
		EXPECT_FLOAT_EQ(20284.175f, v1 * v2);
	}

	TEST(Vec3dDotProductTest, SecondDotProduct)
	{
		Vector3D v1(64.0f, 0.0f, 0.0f);
		Vector3D v2(0.0f, 15.0f, 25613.13f);

		EXPECT_FLOAT_EQ(0.0f, v1.dot(v2));
		EXPECT_FLOAT_EQ(0.0f, dot(v1, v2));
		EXPECT_FLOAT_EQ(0.0f, v1 * v2);
	}

	TEST(Vec3dDotProductTest, ThirdDotProduct)
	{
		Vector3D v1(-1010.1f, 67.13f, 0.0f);
		Vector3D v2(0.65f, 8.08f, 145.0f);

		EXPECT_FLOAT_EQ(-114.15454f, v1.dot(v2));
		EXPECT_FLOAT_EQ(-114.15454f, dot(v1, v2));
		EXPECT_FLOAT_EQ(-114.15454f, v1 * v2);
	}

	TEST(Vec3dCrossProductTest, PositiveValues)
	{
		Vector3D v1(64.1f, 285.33f, -100.0f);
		Vector3D v2(-10.0f, 45.45f, 15.0f);
		Vector3D answer(8824.95f, 38.5f, 5766.645f);

		EXPECT_VEC3_EQ(answer, cross(v1, v2));
	}

	TEST(Vec3dCrossProductTest, VectorWithPoint)
	{
		Vector3D v0;
		Vector3D v1(15.5f, -3.0f, 6.0f);
		Vector3D answer;

		EXPECT_VEC3_EQ(answer, cross(v0, v1));
		EXPECT_VEC3_EQ(answer, cross(v1, v0));
	}

	TEST(Vec3dCrossProductTest, VectorWithItself)
	{
		Vector3D v1(1.5f, -3.0f, -45.0f);
		Vector3D answer;

		EXPECT_VEC3_EQ(answer, cross(v1, v1));
	}

	TEST(Vec3dCrossProductTest, DifferentOrder)
	{
		Vector3D v1(64.5f, -875.0f, 9.9f);
		Vector3D v2(3.0f, 58.0f, 6785.33f);

		Vector3D res1 = cross(v1, v2);
		Vector3D res2 = cross(v2, v1);

		// EXPECT_VEC3_NE without magnitude
		EXPECT_NE((res1).getX(), (res2).getX());
		EXPECT_NE((res1).getY(), (res2).getY());
		EXPECT_NE((res1).getZ(), (res2).getZ());
		EXPECT_NE((res1).m_Alpha, (res2).m_Alpha);
		EXPECT_NE((res1).m_Betha, (res2).m_Betha);
		EXPECT_NE((res1).m_Gama, (res2).m_Gama);

		EXPECT_VEC3_EQ(res1, -res2);
	}

	TEST(Vec3dCrossProductTest, CollinearVectors)
	{
		Vector3D v1(1.0f, -2.0f, -18.0f);
		Vector3D v2(-6.0f, 12.0f, 108.0f);
		Vector3D answer;

		EXPECT_VEC3_EQ(answer, cross(v1, v2));
		EXPECT_VEC3_EQ(answer, cross(v2, v1));
	}

	TEST(Vec3dCrossProductTest, FirstModifiyng)
	{
		Vector3D v0;
		Vector3D v1(15.5f, -3.0f, 6.0f);
		Vector3D answer;

		v1.cross(v0);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dCrossProductTest, SecondModifiyng)
	{
		Vector3D v1(64.1f, 285.33f, -100.0f);
		Vector3D v2(-10.0f, 45.45f, 15.0f);
		Vector3D answer(8824.95f, 38.5f, 5766.645f);

		v1.cross(v2);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dCrossProductTest, ThirdModifiyng)
	{
		Vector3D v1(1.5f, -3.0f, -45.0f);
		Vector3D answer;

		v1.cross(v1);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dCrossProductTest, FourthModifiyng)
	{
		Vector3D v1(64.5f, -875.0f, 9.9f);
		Vector3D v2(3.0f, 58.0f, 6785.33f);

		Vector3D res1 = v1;
		Vector3D res2 = v2;
		res1.cross(v2);
		res2.cross(v1);

		// EXPECT_VEC3_NE without magnitude
		EXPECT_NE((res1).getX(), (res2).getX());
		EXPECT_NE((res1).getY(), (res2).getY());
		EXPECT_NE((res1).getZ(), (res2).getZ());
		EXPECT_NE((res1).m_Alpha, (res2).m_Alpha);
		EXPECT_NE((res1).m_Betha, (res2).m_Betha);
		EXPECT_NE((res1).m_Gama, (res2).m_Gama);

		EXPECT_VEC3_EQ(res1, -res2);
	}

	TEST(Vec3dCrossProductTest, FifthModifiyng)
	{
		Vector3D v1(1.0f, -2.0f, -18.0f);
		Vector3D v2(-6.0f, 12.0f, 108.0f);
		Vector3D answer;

		v1.cross(v2);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3dPointTest, OnePoint)
	{
		Vector3D v0;
		Vector3D v1(-3.0f);
		Vector3D v2(0.0f, 16.0f, 0.0f);
		Vector3D v3(-5.0f, 0.0f, 0.0f);
		Vector3D v4(0.0f, 0.0f, 56.215f);

		EXPECT_TRUE(v0.is_point());
		EXPECT_FALSE(v1.is_point());
		EXPECT_FALSE(v2.is_point());
		EXPECT_FALSE(v3.is_point());
		EXPECT_FALSE(v4.is_point());
	}

	TEST(Vec3dCollinearTest, OneVector)
	{
		Vector3D v1(1.0f, 6.0f, 3.0f);
		EXPECT_TRUE(v1.is_collinear_with(v1));
		EXPECT_TRUE(is_collinear(v1, v1));
	}

	TEST(Vec3dCollinearTest, DotWithVector)
	{
		Vector3D v0;
		Vector3D v1(1.0f, 6.0f, 2.5f);
		Vector3D v2(13.0f, 8.0f, 1.25f);
		EXPECT_TRUE(v1.is_collinear_with(v0));
		EXPECT_TRUE(is_collinear(v1, v0));
		EXPECT_TRUE(v2.is_collinear_with(v0));
		EXPECT_TRUE(is_collinear(v2, v0));
		EXPECT_TRUE(v0.is_collinear_with(v1));
		EXPECT_TRUE(is_collinear(v0, v1));
		EXPECT_TRUE(v0.is_collinear_with(v2));
		EXPECT_TRUE(is_collinear(v0, v2));
	}

	TEST(Vec3dCollinearTest, ReversedVector)
	{
		Vector3D v1(101010.0f);
		EXPECT_TRUE(v1.is_collinear_with(-v1));
		EXPECT_TRUE(is_collinear(v1, -v1));
	}

	TEST(Vec3dCollinearTest, ThreeCollinearVectors)
	{
		Vector3D v1(1.0f, 3.0f, -1.25f);
		Vector3D v2(3.0f, 9.0f, -3.75f);
		Vector3D v3(-8.0f, -24.0f, 10.0f);
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

	TEST(Vec3dCollinearTest, NotCollinearVectors)
	{
		Vector3D v1(0.0f, 13.0f, 0.0f);
		Vector3D v2(13.0f, 0.0f, 0.0f);

		EXPECT_FALSE(v1.is_collinear_with(v2));
		EXPECT_FALSE(is_collinear(v1, v2));
	}

	TEST(Vec3dSetCoordsTest, SetDotCoords)
	{
		Vector3D v;
		Vector3D answer(101010.314f, -3214125.1f, 6474.0f);

		v.setCoords(101010.314f, -3214125.1f, 6474.0f);
		EXPECT_VEC3_EQ(v, answer);
	}

	TEST(Vec3dSetCoordsTest, SetPositiveValues)
	{
		Vector3D v(13.0f, 207.0f, -615.14f);
		Vector3D answer(13.01f, 256.17f, 614.5f);

		v.setCoords(13.01f, 256.17f, 614.5f);
		EXPECT_VEC3_EQ(v, answer);
	}

	TEST(Vec3dSetCoordsTest, SetNegativeValues)
	{
		Vector3D v(13.0f, 207.0f, 0.0f);
		Vector3D answer(-64.15f, -165.81f, 15.61f);

		v.setCoords(-64.15f, -165.81f, 15.61f);
		EXPECT_VEC3_EQ(v, answer);
	}

	TEST(Vec3dSetCoordsTest, SetZeroes)
	{
		Vector3D v(5262.23f, 31251.561f, 7855.0f);
		Vector3D answer;

		v.setCoords(0.0f, -0.0f, 0.0f);
		EXPECT_VEC3_EQ(v, answer);
	}

	TEST(Vec3dSetCoordsTest, MultipleSet)
	{
		Vector3D v(5262.23f, 31251.561f, 52.0f);
		Vector3D answer(1.0f, 2.0f, 3.0f);

		v.setCoords(870.513f, 311515.767f, 68476.6f);
		v.setCoords(656.0f, 13.0f, 794.0f);
		v.setCoords(1.0f, 2.0f, 3.0f);
		EXPECT_VEC3_EQ(v, answer);
	}

	TEST(Vec3DNormalizationTest, ParamsCheck)
	{
		Vector3D v_normalized(13.0f, 26.0f, 39.0f);
		Vector3D v = v_normalized;
		v_normalized.normalize();

		EXPECT_FLOAT_EQ(v.m_Alpha, v_normalized.m_Alpha);
		EXPECT_FLOAT_EQ(v.m_Betha, v_normalized.m_Betha);
		EXPECT_FLOAT_EQ(v.m_Gama, v_normalized.m_Gama);
		EXPECT_FLOAT_EQ(1.0f, v_normalized.m_Magnitude);
	}

	TEST(Vec3DNormalizationTest, NoChanges)
	{
		Vector3D v1(0.0f, 1.0f, 0.0f);
		Vector3D v2 = v1;

		v1.normalize();
		EXPECT_VEC3_EQ(v1, v2);
	}

	TEST(Vec3DNormalizationTest, JustScaling)
	{
		Vector3D v1(64.0f, 0.0f, 0.0f);
		Vector3D answer(1.0f, 0.0f, 0.0f);

		v1.normalize();
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3DNormalizationTest, SimilarityCheck)
	{
		Vector3D v1(123.0f, 0.0f, 546.0f);
		Vector3D answer(0.21976729f, 0.0f, 0.97555238f);

		v1.normalize();
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3DScalingTest, ScaleByZero)
	{
		Vector3D v1(123.0f, 546.0f, 51.7f);
		Vector3D answer;

		v1.scale(0.0f);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3DScalingTest, ScaleByPositiveValue)
	{
		Vector3D v1(-256.0f, 16.0f, 77.0f);
		Vector3D answer(-128.0f, 8.0f, 38.5f);

		v1.scale(0.5f);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3DScalingTest, ScaleByNegativeValue)
	{
		Vector3D v1(15.0f, -3.0f, -6.65f);
		Vector3D answer(-150.0f, 30.0f, 66.5f);

		v1.scale(-10.0f);
		EXPECT_VEC3_EQ(answer, v1);
	}

	TEST(Vec3DScalingTest, MultipleScaling)
	{
		Vector3D v1(64.15f, -301.005f, 3.0f);
		Vector3D answer = v1;

		v1.scale(-10.0f);
		v1.scale(-0.1f);
		EXPECT_VEC3_EQ(answer, v1);
	}
}