
/*
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name:Shriyans Singh
 * SBU ID:114807762
 */

#include "matrix.h"
#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
 
/*----------------------------------------------------
  1. Sparse Matrix
----------------------------------------------------*/
int SparseMatrix(int D[2], int M[D[0]][D[1]],
                 int S[3][(D[1] > D[0] ? D[1] : D[0])])
{

    int rows = D[0];
    int cols = D[1];
    int m = max(rows, cols);

    int nonZeroCount = 0;
  //make entire array 0s. MUST USE POINTER DEREFERENCING v2 A[row][i] is equivalent to (*(*(A + row) + i))
    for(int i=0;i<3;i++){
      for(int j=0; j<m;j++){
        *(*(S+i) +j) = 0;
      }
    }

    //using pointers go throuh the matrix and check if there have been more than m nonzero values and if there was, return -1.
    for(int i=0;i<rows;i++){
      for(int j=0; j<cols;j++){
        int val=0;
        val=*(*(M+i) +j);
        if(val!=0){
          if(nonZeroCount>=m){
            return -1;
          }
          //store row index , column index and value index in s[0],s[1],s[2] respectively with nonzerocount in the second array position
          *(*(S+0) +nonZeroCount) =i;
          *(*(S+1)+nonZeroCount)=j;
          *(*(S+2)+nonZeroCount) =val;
          //increment nonzero after adding a nonzero to the positions
          nonZeroCount++;
        }

      }
    }



    //if nonzerocount<=m, state the nonzero amount.
    return nonZeroCount;
}


/*----------------------------------------------------
  2. Hadamard Product
----------------------------------------------------*/
int HadamardProduct(const int D[6],
                    const int M[D[0]][D[1]],
                    const int N[D[2]][D[3]],
                    int A[D[4]][D[5]])
{
  //matrixM
    int mRows = D[0];
    int mCols = D[1];
  //Matrix N
    int nRows = D[2];
    int nCols = D[3];
  //Matrix A ( result)
    int aRows = D[4];
    int aCols = D[5];


    //if m<n, then mrows. else nrows. same with cols. Basically, we do it on the min of the 2 matrices.
    int overLappingRows = mRows < nRows ? mRows : nRows;
    int overLappingCol = mCols < nCols ? mCols : nCols;
    //clear A of garbage
    for(int i=0;i<aRows;i++){
     for(int j=0; j<aCols;j++){
       *(*(A+i) +j) = 0;
      }
    }
    /*//check A >= than overlapping rows and cols else return -1.
    if(aRows <overLappingRows ||aCols<overLappingCol){
      return -3;
    }*/


    //now multiply each element in each overlap, and store in A
    for(int i=0;i<overLappingRows;i++){
      for(int j=0; j<overLappingCol;j++){
        int valueOfM = *(*(M+i) +j);
        int valueOfN = *(*(N+i) +j);
        *(*(A+i) +j) = valueOfM*valueOfN;
      }
    }
    //if same size return 1, if a is bigger in some form then return 2 otherwise too small return -3.
    if(mRows==nRows&& mCols==nCols){
      return 1;
    }
    else if(aRows>=mRows&& aCols>=mCols){
      return 2;
    }
    else{
      return -3;
    }
    }






    return 0;
}


/*----------------------------------------------------
  3. Matrix Multiplication
----------------------------------------------------*/
int Multiplication(const int D[6],
                   const int M[D[0]][D[1]],
                   const int N[D[2]][D[3]],
                   int A[D[4]][D[5]])
{

    int mRows = D[0];
    int mCols = D[1];

    int nRows = D[2];
    int nCols = D[3];

    int aRows = D[4];
    int aCols = D[5];


    return 0;
}


/*----------------------------------------------------
  4. Diagonal Sum
----------------------------------------------------*/
int DiagonalSum(const int D[4],
                const int A[D[0]][D[1]],
                int DS[D[2]][D[3]])
{

    int rows = D[0];
    int cols = D[1];

    int dsRows = D[2];
    int dsCols = D[3];


    return 0;
}
