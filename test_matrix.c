/* wasn't sure if was needed in all files so i just copy pasted it
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name:Shriyans Singh
 * SBU ID:114807762
 */
#include <criterion/criterion.h>
#include "matrix.h"




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

Test(SparseMatrix, test_9)
{
    int D[2] = {1,5};

    int M[1][5] = {
       { 1, 0, 0, 0, 1}
    };


    int S[5][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,2);

}

Test(SparseMatrix, test_10)
{
    int D[2] = {5,1};

    int M[5][1] = {
    {1},{1},{1},{0},{0}
    };


    int S[5][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,3);

}


Test(SparseMatrix, test_11)
{
    int D[2] = {2,2};

    int M[2][2] = {{999999,0},{999999,0}};
    


    int S[2][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,2);

}
Test(SparseMatrix, test_12)
{
    int D[2] = {2,2};

    int M[2][2] = {
    {1,0},{0,0}
    };


    int S[2][2];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,1);

}



//Now Hadamard Tests


Test(HadamardProduct, test_1)
{
    int D[6] = {1,1,1,1,1,1};

    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[2][2];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(HadamardProduct, test_2)
{
    int D[6] = {2,2,2,2,3,3};

    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[3][3];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,2);
}
Test(HadamardProduct, test_3)
{
    int D[6] = {2,2,2,2,1,1};

    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-3);
}
Test(HadamardProduct, test_4)
{
    int D[6] = {2,3,3,2,2,2};

    int M[2][3] = {
        {1,1,1},
        {1,1,1}
    };

    int N[3][2] = {
        {1,1},
        {1,1},
        {1,1}
    };

    int A[2][2];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-1);
}


Test(HadamardProduct, test_5)
{
    int D[6] = {2,2,2,2,2,1};

    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[2][2];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-3);
}
Test(HadamardProduct, test_6)
{
    int D[6] = {2,3,3,2,2,2};

    int M[2][3] = {
        {1,1,1},
        {1,1,1}
    };

    int N[3][2] = {
        {0,0},
        {0,0},
        {0,0}
    };

    int A[2][2];

    int r = HadamardProduct(D,M,N,A);
    //need to check if everything is 0 using criterion, not the print
    cr_assert_eq(A[0][0],0);
    cr_assert_eq(r,-1);
}

Test(HadamardProduct, test_7)
{
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {1}
        
    };

    int N[1][1] = {
        {0}
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);
   

    cr_assert_eq(r,1);
}


Test(HadamardProduct, test_8)
{
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {-1}
        
    };

    int N[1][1] = {
        {-1}
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);
   
    cr_assert_eq(A[0][0],1);
    cr_assert_eq(r,1);
}

Test(HadamardProduct, test_9)
{
    int D[6] = {1,1,1,1,2,1};

    int M[1][1] = {
        {1}
        
    };

    int N[1][1] = {
        {0}
    };

    int A[2][1];

    int r = HadamardProduct(D,M,N,A);
   

    cr_assert_eq(r,2);
}

Test(HadamardProduct, test_10)
{
    int D[6] = {1,2,2,1,1,1};

    int M[1][2] = {
        {1,1}
        
    };

    int N[2][1] = {
        {3422312312},
        {0}
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);
   
    //incorrect thinking:cr_assert_eq(A[0][0],1232);
    cr_assert_eq(r,-1);
}
Test(HadamardProduct, test_11)
{
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {1}
        
    };

    int N[1][1] = {
        {999999},
        
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);
    cr_assert_eq(A[0][0],999999);
    cr_assert_eq(r,1);
}

Test(HadamardProduct, test_12)
{
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {999999}
        
    };

    int N[1][1] = {
        {1},
        
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);
    cr_assert_eq(A[0][0],999999);
    cr_assert_eq(r,1);
}
Test(HadamardProduct, test_13)
{
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {-1}
        
    };

    int N[1][1] = {
        {1},
        
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);
    cr_assert_eq(A[0][0],-1);
    cr_assert_eq(r,1);
}
Test(HadamardProduct, test_14)
{
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {1}
        
    };

    int N[1][1] = {
        {-1},
        
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);
    cr_assert_eq(A[0][0],-1);
    cr_assert_eq(r,1);
}

//Now multiplicationmatrixes tests
