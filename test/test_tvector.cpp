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
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

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
  ADD_FAILURE();
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
  ADD_FAILURE();
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
  ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    TDynamicVector<int> v1(1);
    TDynamicVector<int> v2(2);
    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(1);
    TDynamicVector<int> v2(2);
    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  ADD_FAILURE();
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
    TDynamicVector<int> v3(2);
    EXPECT_EQ(v3, v1 * v2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(1);
    TDynamicVector<int> v2(2);
    ASSERT_ANY_THROW(v1 * v2);
}

