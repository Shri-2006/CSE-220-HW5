/* wasn't sure if was needed in all files so i just copy pasted it
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name:Shriyans Singh
 * SBU ID:114807762
 */
#include <criterion/criterion.h>
#include "matrix.h"

Test(SparseMatrix, simple_sparse)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,0,0},
        {0,2,0},
        {0,0,3}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,3);
}

Test(HadamardProduct, compatible)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {2,2},
        {2,2}
    };

    int A[2][2];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(Multiplication, simple_case)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {5,6},
        {7,8}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, square_matrix)
{
    int D[4] = {3,3,5,5};

    int A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int DS[5][5];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,2);
}



//Shri's Tests
Test(SparseMatrix, test_1)
{
    int D[2] = {2,2};

    int M[2][2] = {
        {0,0},
        {0,0},
        
    };

    int S[2][200];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,0);
}


Test(SparseMatrix, test_2)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,3);
}

Test(SparseMatrix, test_3)
{
    int D[2] = {2,4};

    int M[2][4] = {
        {1,1,0,0},
        {0,0,1,1}
    };

    int S[4][4];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,4);

}
Test(SparseMatrix, test_4)
{
    int D[2] = {2,2};

    int M[2][2] = {
        {1,1},
        {0,1}
    };

    int S[2][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,-1);

}
Test(SparseMatrix, test_5)
{
    int D[2] = {1,1};

    int M[1][1] = {
        {1}
    };

    int S[1][1];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,1);

}

Test(SparseMatrix, test_6)
{
    int D[2] = {2,2};

    int M[2][2] = {
        {0,0},
        {0,1}
    };

    int S[2][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,1);

}


Test(SparseMatrix, test_7)
{
    int D[2] = {4,4};

    int M[4][4] = {
        {0,0,0,1},
        {0,0,1,0},
        {0,1,0,0},
        {1,0,0,0}
    };

    int S[4][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,4);

}

Test(SparseMatrix, test_8)
{
    int D[2] = {2,2};

    int M[2][2] = {
        {1  ,0},
        {0,-1}
    };

    int S[2][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,2);

}
