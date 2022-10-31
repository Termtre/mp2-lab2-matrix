#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    TDynamicMatrix<int> m1(1);
    m1[0][0] = 1;
    ASSERT_NO_THROW(TDynamicMatrix<int> m2(m1));
    TDynamicMatrix<int> m2(m1);
    EXPECT_EQ(m1, m2);

    ASSERT_NO_THROW(TDynamicMatrix<int> m3(m2));
    TDynamicMatrix<int> m3(m2);
    EXPECT_EQ(m2, m3);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    ASSERT_NO_THROW(TDynamicMatrix<int> m2(m1));
    TDynamicMatrix<int> m2(m1);
    EXPECT_EQ(m2, m1);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> m1(5);
    EXPECT_EQ(5, m1.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> m1(2);
    for (int i = 0; i < m1.size(); i++)
        for (int j = 0; j < m1.size(); j++)
        {
            ASSERT_NO_THROW(m1[i][j] = i + j);
            EXPECT_EQ(m1[i][j], i + j);
        }
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m1(2);
    ASSERT_ANY_THROW(m1.at(-1, -1) = 2);
    ASSERT_ANY_THROW(m1.at(-1, 0) = 2);
    ASSERT_ANY_THROW(m1.at(0, -1) = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m1(1);
    ASSERT_ANY_THROW(m1.at(1, 2) = 1);
    ASSERT_ANY_THROW(m1.at(0, 2) = 1);
    ASSERT_ANY_THROW(m1.at(1, 0) = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m1(2);
    ASSERT_NO_THROW(m1 = m1);
    m1[0][0] = 1;
    m1[0][1] = 1;
    m1[1][0] = 2;
    m1[1][1] = 2;
    ASSERT_NO_THROW(m1 = m1);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(2);
    ASSERT_NO_THROW(m1 = m2);
    m1[0][0] = 1;
    m1[0][1] = 1;
    m1[1][0] = 2;
    m1[1][1] = 2;
    ASSERT_NO_THROW(m2 = m1);
    EXPECT_EQ(m2, m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(3);
    ASSERT_NO_THROW(m2 = m1);
    m2 = m1;
    EXPECT_EQ(2, m2.size());
    TDynamicMatrix<int> m3(3);
    ASSERT_NO_THROW(m1 = m3);
    m1 = m3;
    EXPECT_EQ(3, m1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(3);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;
    
    m2[0][0] = 1; m2[0][1] = 2; m2[0][2] = 3;
    m2[1][0] = 4; m2[1][1] = 5; m2[1][2] = 6;
    m2[2][0] = 7; m2[2][1] = 8; m2[2][2] = 9;
    ASSERT_NO_THROW(m1 = m2);
    m1 = m2;
    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(2);
    EXPECT_EQ(true, m1 == m2);

    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 1; m2[0][1] = 2;
    m2[1][0] = 3; m2[1][1] = 4;

    EXPECT_EQ(true, m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m1(2);
    EXPECT_EQ(true, m1 == m1);

    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    EXPECT_EQ(true, m1 == m1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(3);
    EXPECT_EQ(false, m1 == m2);

    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 1; m2[0][1] = 2;
    m2[1][0] = 3; m2[1][1] = 4;

    EXPECT_EQ(false, m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(2);
    TDynamicMatrix<int> m3(2);
    EXPECT_EQ(m3, m2 + m1);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 1; m2[0][1] = 2;
    m2[1][0] = 3; m2[1][1] = 4;

    m3[0][0] = 2; m3[0][1] = 4;
    m3[1][0] = 6; m3[1][1] = 8;
    EXPECT_EQ(m3, m2 + m1);

    TDynamicMatrix<double> m4(2);
    TDynamicMatrix<double> m5(2);
    TDynamicMatrix<double> m6(2);
    EXPECT_EQ(m6, m5 + m4);
    m4[0][0] = 1.0; m4[0][1] = 2.0;
    m4[1][0] = 3.0; m4[1][1] = 4.0;

    m5[0][0] = 1.0; m5[0][1] = 2.0;
    m5[1][0] = 3.0; m5[1][1] = 4.0;

    m6[0][0] = 2.0; m6[0][1] = 4.0;
    m6[1][0] = 6.0; m6[1][1] = 8.0;
    EXPECT_EQ(m6, m5 + m4);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(3);
    ASSERT_ANY_THROW(m2 + m1);

    TDynamicMatrix<double> m3(2);
    TDynamicMatrix<double> m4(3);
    ASSERT_ANY_THROW(m3 + m4);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(2);
    TDynamicMatrix<int> m3(2);
    EXPECT_EQ(m3, m2 - m1);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 1; m2[0][1] = 2;
    m2[1][0] = 3; m2[1][1] = 4;

    EXPECT_EQ(m3, m2 - m1);

    TDynamicMatrix<double> m4(2);
    TDynamicMatrix<double> m5(2);
    TDynamicMatrix<double> m6(2);
    EXPECT_EQ(m6, m5 - m4);
    m4[0][0] = 1.0; m4[0][1] = 2.0;
    m4[1][0] = 3.0; m4[1][1] = 4.0;

    m5[0][0] = 1.0; m5[0][1] = 2.0;
    m5[1][0] = 3.0; m5[1][1] = 4.0;

    EXPECT_EQ(m6, m5 - m4);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(3);
    ASSERT_ANY_THROW(m2 - m1);

    TDynamicMatrix<double> m3(2);
    TDynamicMatrix<double> m4(3);
    ASSERT_ANY_THROW(m3 - m4);
}

TEST(TDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(2);
    TDynamicMatrix<int> m3(2);
    EXPECT_EQ(m3, m2 * m1);

    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 1; m2[0][1] = 2;
    m2[1][0] = 3; m2[1][1] = 4;

    m3[0][0] = 7; m3[0][1] = 10;
    m3[1][0] = 15; m3[1][1] = 22;

    EXPECT_EQ(m3, m2 * m1);

    TDynamicMatrix<double> m4(2);
    TDynamicMatrix<double> m5(2);
    TDynamicMatrix<double> m6(2);
    EXPECT_EQ(m6, m5 * m4);
    m4[0][0] = 1.0; m4[0][1] = 2.0;
    m4[1][0] = 3.0; m4[1][1] = 4.0;

    m5[0][0] = 1.0; m5[0][1] = 2.0;
    m5[1][0] = 3.0; m5[1][1] = 4.0;

    m6[0][0] = 7.0; m6[0][1] = 10.0;
    m6[1][0] = 15.0; m6[1][1] = 22.0;
    EXPECT_EQ(m6, m5 * m4);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(3);
    ASSERT_ANY_THROW(m2 * m1);

    TDynamicMatrix<double> m3(2);
    TDynamicMatrix<double> m4(3);
    ASSERT_ANY_THROW(m3 * m4);
}

TEST(TDynamicMatrix, can_multiply_scalar_by_matrix)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(2);
    int scalar1 = 0;
    EXPECT_EQ(m2, m1 * scalar1);

    scalar1 = 2;
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 2; m2[0][1] = 4;
    m2[1][0] = 6; m2[1][1] = 8;

    EXPECT_EQ(m2, m1 * scalar1);

    TDynamicMatrix<double> m4(2);
    TDynamicMatrix<double> m5(2);
    double scalar2 = 0.0;
    EXPECT_EQ(m5, m4 * scalar2);
    scalar2 = 2.0;
    m4[0][0] = 1.0; m4[0][1] = 2.0;
    m4[1][0] = 3.0; m4[1][1] = 4.0;

    m5[0][0] = 2.0; m5[0][1] = 4.0;
    m5[1][0] = 6.0; m5[1][1] = 8.0;

    EXPECT_EQ(m5, m4 * scalar2);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector_with_equal_sizes)
{
    TDynamicMatrix<int> m1(2);
    TDynamicVector<int> v1(2);
    TDynamicVector<int> v2(2);
    EXPECT_EQ(v2, m1 * v1);

    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    v1[0] = 1;
    v1[1] = 2;

    v2[0] = 5;
    v2[1] = 11;

    EXPECT_EQ(v2, m1 * v1);

    TDynamicMatrix<double> m2(2);
    TDynamicMatrix<double> v3(2);
    TDynamicMatrix<double> v4(2);
    EXPECT_EQ(v4, m2 * v3);

    m1[0][0] = 1.0; m1[0][1] = 2.0;
    m1[1][0] = 3.0; m1[1][1] = 4.0;

    v1[0] = 1.0;
    v1[1] = 2.0;

    v2[0] = 5.0;
    v2[1] = 11.0;

    EXPECT_EQ(v2, m1 * v1);
}

TEST(TDynamicMatrix, cant_multiply_matrix_by_vector_with_different_sizes)
{
    TDynamicMatrix<int> m1(2);
    TDynamicVector<int> v1(5);
    ASSERT_ANY_THROW(m1 * v1);
    TDynamicMatrix<int> m2(5);
    TDynamicVector<int> v2(2);
    ASSERT_ANY_THROW(m2 * v2);
}