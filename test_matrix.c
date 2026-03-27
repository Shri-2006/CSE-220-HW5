/* wasn't sure if was needed in all files so i just copy pasted it
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name:Shriyans Singh
 * SBU ID:114807762
 */
#define three 3
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
Test(Multiplication, test_1)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(Multiplication, test_2)
{   //practicing macros so used three
    int D[6] = {2,three,3,2,2,2};

    int M[2][3] = {
        {1,1,1},
        {1,1,1}
    };

    int N[3][2] = {
        {1,1},
        {1,1},
        {2,23213}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}
Test(Multiplication, test_3){
    int D[6] = {2,three,2,2,2,2};

    int M[2][3] = {
        {1,1,1},
        {1,1,1}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-1);
}
Test(Multiplication, test_4){
    int D[6] = {2,three,2,2,1,1};

    int M[2][3] = {
        {1,1,1},
        {1,1,1}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[1][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-2);
}
Test(Multiplication, test_5_typo){
    int D[6] = {2,three,2,2,10,10};

    int M[2][3] = {
        {1,1,1},
        {1,1,1}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[10][10];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-1);
}
Test(Multiplication, test_5){
    int D[6] = {2,2,2,2,10,10};

    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[10][10];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,2);
}
Test(Multiplication, test_6){
    int D[6] = {1,2,2,1,1,1};

    int M[1][2] = {
        {10,1}
    };

    int N[2][1] = {
        {1},
        {1}
    };

    int A[1][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
    cr_assert_eq(A[0][0], 11);
}

Test(Multiplication, test_7){
    int D[6] = {2,1,1,2,2,2};

    int M[2][1] = {
        {2},
        {2}
    };

    int N[1][2] = {
        {2,2}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
    cr_assert_eq(A[0][0], 4);
}




Test(Multiplication, test_8){
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {2}
    };

    int N[1][1] = {
        {20231232}
    };

    int A[1][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
    cr_assert_eq(A[0][0], (20231232*2));
}





Test(Multiplication, test_9){
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {0,0},{0,0}
    };

    int N[2][2] = {
        {0,0},{0,0}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
    cr_assert_eq(A[0][0], (0));
}
Test(Multiplication, test_10){
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {-1,-2},{-1,-2}
    };

    int N[2][2] = {
        {-1,-1},{-1,-1}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
    cr_assert_eq(A[0][0], (3));
}

Test(Multiplication, test_11){
    int D[6] = {2,2,2,2,2,100};

    int M[2][2] = {
        {-1,-2},{-1,-2}
    };

    int N[2][2] = {
        {-1,-1},{-1,-1}
    };

    int A[2][100];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,2);
   
}
Test(Multiplication, test_12){
    int D[6] = {2,2,2,2,200,2};

    int M[2][2] = {
        {-1,-2},{-1,-2}
    };

    int N[2][2] = {
        {-1,-1},{-1,-1}
    };

    int A[200][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,2);
   
}

Test(Multiplication, test_13){
    int D[6] = {2,2,2,2,200,100};

    int M[2][2] = {
        {-1,-2},{-1,-2}
    };

    int N[2][2] = {
        {-1,-1},{-1,-1}
    };

    int A[200][100];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,2);
   
}

Test(Multiplication, test_14){
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {-2}
    };

    int N[1][1] = {
        {-1}
    };

    int A[1][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
    cr_assert_eq(A[0][0],2);
   
}
Test(Multiplication, test_15){
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {2}
    };

    int N[1][1] = {
        {-1}
    };

    int A[1][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
    cr_assert_eq(A[0][0],-2);
   
}
Test(Multiplication, test_16){
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {2}
    };

    int N[1][1] = {
        {1}
    };

    int A[1][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
    cr_assert_eq(A[0][0],2);
   
}

//Now Diagonalsum Tests
Test(DiagonalSum, test_1)
{
    int D[4] = {2,2,4,2};

    int A[2][2] = {
        {1,1},
        {1,1}
    };

    int DS[4][2];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}


Test(DiagonalSum, test_2)
{
    int D[4] = {2,2,400,2000};

    int A[2][2] = {
        {1,1},
        {1,1}
    };

    int DS[400][2000];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,2);
}
Test(DiagonalSum, test_3)
{
    int D[4] = {2,2,3,2};

    int A[2][2] = {
        {1,1},
        {1,1}
    };

    int DS[3][2];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,-1);
}


Test(DiagonalSum, test_4)
{
    int D[4] = {2,2,3,1};

    int A[2][2] = {
        {1,1},
        {1,1}
    };

    int DS[3][1];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,-1);
}
Test(DiagonalSum, test_5)
{
    int D[4] = {2,3,3,3};

    int A[2][3] = {
        {1,1,1},
        {1,1,1}
        
    };

    int DS[3][3];

    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(DS[1][1],2);
    cr_assert_eq(r,-1);
}
Test(DiagonalSum, test_6)
{
    int D[4] = {2,2,4,2};

    int A[2][2] = {
        {1,1},{1,1}
    };

    int DS[4][2];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, test_7)
{
    int D[4] = {2,2,4,2};

    int A[2][2] = {
        {-1,-1},{1,-1}
    };

    int DS[4][2];

    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(DS[1][0],0);
    cr_assert_eq(r,1);
}

Test(DiagonalSum, test_8_typo_from_intended)
{
    int D[4] = {1,10,2,10};

    int A[1][10] = {
        {-1,-1,2,-2,3,-3,4,-4,5,-6}
    };

    int DS[2][10];

    int r = DiagonalSum(D,A,DS);
   // cr_assert_eq(DS[1][0],-1);
    cr_assert_eq(r,-1);
}
Test(DiagonalSum, test_8)
{
    int D[4] = {1,10,3,10};

    int A[1][10] = {
        {-1,-1,2,-2,3,-3,4,-4,5,-6}
    };

    int DS[3][10];

    int r = DiagonalSum(D,A,DS);
    cr_assert_eq(DS[1][0],-1);
    cr_assert_eq(r,1);
}

Test(DiagonalSum, test_9)
{
    int D[4] = {2,2,1,1};

    int A[2][2] = {
        {-1,-1},
        {2,-2}
    };

    int DS[1][1];

    int r = DiagonalSum(D,A,DS);
    
    cr_assert_eq(r,-1);
}

Test(DiagonalSum, test_10)
{
    int D[4] = {2,4,4,4};

    int A[2][4] = {
        {-1,-1,3,-3},
        {2,-2,50,-50}
    };

    int DS[4][4];

    int r = DiagonalSum(D,A,DS);
    
    cr_assert_eq(r,1);
    cr_assert_eq(DS[0][1],0);
}

