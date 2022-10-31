#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(3);
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
  TDynamicVector<int> v1(v);
  for (int i = 0; i < v.size(); i++)
      EXPECT_EQ(v[i], v1[i]);

}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
    TDynamicVector<int> v1(1);
    v1[0] = 1;
    ASSERT_NO_THROW(TDynamicVector<int> v2(v1));
    TDynamicVector<int> v2(v1);
    EXPECT_EQ(true, v1 == v2);

    ASSERT_NO_THROW(TDynamicVector<int> v3(v2));
    TDynamicVector<int> v3(v2);
    EXPECT_EQ(true, v2 == v3);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
    double array[5] = {1, 2, 3, 4, 5};
    ASSERT_NO_THROW(TDynamicVector<double> v(array, 5););
    TDynamicVector<double> v(array, 5);
    ASSERT_NO_THROW(TDynamicVector<double> v1(v););
    TDynamicVector<double> v1(v);
    EXPECT_EQ(true, v1 == v);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  ASSERT_NO_THROW(v[0] = 4);
  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
    TDynamicVector<int> v(1);
    ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
    TDynamicVector<int> v(1);
    ASSERT_ANY_THROW(v.at(1));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v(4);
    v[0] = 0; v[1] = 1;
    v[2] = 2; v[3] = 3;
    ASSERT_NO_THROW(v = v);
    for (int i = 0; i < v.size(); i++)
        EXPECT_EQ(i, v[i]);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
    TDynamicVector<int> v(2);
    TDynamicVector<int> v1(2);
    v[0] = 1;
    v[1] = 2;
    v1[0] = 50;
    v1[1] = 84;
    ASSERT_NO_THROW(v = v1);
    EXPECT_EQ(true ,v1 == v);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    TDynamicVector<int> v(1);
    TDynamicVector<int> v1(2);
    v[0] = 1;
    v1[0] = 50;
    v1[1] = 84;
    v = v1;
    EXPECT_EQ(2, v.size());

    TDynamicVector<int> v3(20);
    v3 = v;
    EXPECT_EQ(2, v3.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    TDynamicVector<int> v(1);
    TDynamicVector<int> v1(2);
    ASSERT_NO_THROW(v = v1);
    EXPECT_EQ(true, v == v1);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    TDynamicVector<int> a(2);
    TDynamicVector<int> b(2);
    EXPECT_EQ(true, a == b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    TDynamicVector<int> a(2);
    EXPECT_EQ(true, a == a);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    TDynamicVector<int> a(2);
    TDynamicVector<int> b(1);
    EXPECT_EQ(false, a == b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    TDynamicVector<int> v1(2);
    TDynamicVector<int> v2(2);
    int scalar = 0;

    ASSERT_NO_THROW(v1 + scalar);

    EXPECT_EQ(v2, v1 + scalar);
    scalar = 2;
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 3;
    v2[1] = 4;
    EXPECT_EQ(v2, v1 + scalar);

    TDynamicVector<double> v4(4);
    v4[0] = 1.5;
    v4[1] = 2.5;
    v4[2] = 3.5;
    v4[3] = 4.5;
    TDynamicVector<double> v5(4);
    v5[0] = 3.5;
    v5[1] = 4.5;
    v5[2] = 5.5;
    v5[3] = 6.5;

    double scalar1 = 2.0;

    EXPECT_EQ(v5, v4 + scalar1);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    TDynamicVector<int> v1(2);
    TDynamicVector<int> v2(2);
    int scalar = 0;

    ASSERT_NO_THROW(v1 - scalar);

    EXPECT_EQ(v2, v1 - scalar);
    scalar = 2;
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = -1;
    v2[1] = 0;
    EXPECT_EQ(v2, v1 - scalar);

    TDynamicVector<double> v4(4);
    v4[0] = 1.5;
    v4[1] = 2.5;
    v4[2] = 3.5;
    v4[3] = 4.5;
    TDynamicVector<double> v5(4);
    v5[0] = -0.5;
    v5[1] = 0.5;
    v5[2] = 1.5;
    v5[3] = 2.5;

    double scalar1 = 2.0;

    EXPECT_EQ(v5, v4 - scalar1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    TDynamicVector<int> v1(2);
    TDynamicVector<int> v2(2);
    int scalar = 0;

    ASSERT_NO_THROW(v1 * scalar);

    EXPECT_EQ(v2, v1 * scalar);
    scalar = 2;
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 4;
    EXPECT_EQ(v2, v1 * scalar);

    TDynamicVector<double> v4(4);
    v4[0] = 1.5;
    v4[1] = 2.5;
    v4[2] = 3.5;
    v4[3] = 4.5;
    TDynamicVector<double> v5(4);
    v5[0] = 3;
    v5[1] = 5;
    v5[2] = 7;
    v5[3] = 9;

    double scalar1 = 2.0;

    EXPECT_EQ(v5, v4 * scalar1);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    TDynamicVector<int> v1(2);
    TDynamicVector<int> v2(2);
    TDynamicVector<int> v3(2);

    ASSERT_NO_THROW(v1 + v2);

    EXPECT_EQ(v3, v1 + v2);

    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 1;
    v2[1] = 2;
    v3[0] = 2;
    v3[1] = 4;
    EXPECT_EQ(v3, v1 + v2);

    TDynamicVector<double> v4(4);
    v4[0] = 1.5;
    v4[1] = 2.5;
    v4[2] = 3.5;
    v4[3] = 4.5;
    TDynamicVector<double> v6(4);
    v6[0] = 3;
    v6[1] = 5;
    v6[2] = 7;
    v6[3] = 9;
    TDynamicVector<double> v5(v4);
    EXPECT_EQ(v6, v4 + v5);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(1);
    TDynamicVector<int> v2(2);
    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
    TDynamicVector<int> v1(2);
    TDynamicVector<int> v2(2);
    TDynamicVector<int> v3(2);

    ASSERT_NO_THROW(v1 - v2);

    EXPECT_EQ(v3, v1 - v2);

    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 1;
    v2[1] = 2;
    EXPECT_EQ(v3, v1 - v2);

    TDynamicVector<double> v4(4);
    v4[0] = 1.5;
    v4[1] = 2.5;
    v4[2] = 3.5;
    v4[3] = 4.5;
    TDynamicVector<double> v6(4);
    TDynamicVector<double> v5(v4);
    EXPECT_EQ(v6, v4 - v5);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(1);
    TDynamicVector<int> v2(2);
    ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
    TDynamicVector<int> v1(2);
    TDynamicVector<int> v2(2);

    ASSERT_NO_THROW(v1 * v2);

    EXPECT_EQ(0, v1 * v2);

    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 1;
    v2[1] = 2;
    int res = 1 * 1 + 2 * 2;
    EXPECT_EQ(res, v1 * v2);

    TDynamicVector<double> v4(4);
    v4[0] = 1.5;
    v4[1] = 2.5;
    v4[2] = 3.5;
    v4[3] = 4.5;
    double res1 = 1.5 * 1.5 + 2.5 * 2.5 + 3.5 * 3.5 + 4.5 * 4.5;
    TDynamicVector<double> v5(v4);
    EXPECT_EQ(res1, v4 * v5);

}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(1);
    TDynamicVector<int> v2(2);
    ASSERT_ANY_THROW(v1 * v2);
}

