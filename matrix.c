
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
    //edge case of invalid rows and cols
    if(rows<=0||cols<=0){
      return 0;
    }
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
    
    //now multiply each element in each overlap, and store in A
    for(int i=0;i<overLappingRows;i++){
      for(int j=0; j<overLappingCol;j++){
        int valueOfM = *(*(M+i) +j);
        int valueOfN = *(*(N+i) +j);
        if(i<aRows&&j<aCols){
          *(*(A+i) +j) = valueOfM*valueOfN;
        }
        
      }
    }
    //if same size return 1, if a is bigger in some form then return 2 otherwise too small return -3.
    if(mRows==nRows&& mCols==nCols){
      if(aRows==mRows&& aCols==mCols){
        return 1;
      }
      else if(aRows>=mRows&& aCols>=mCols){
        return 2;
      }
      else{
        return -3;
      }
    }
    else{
      //If a has enough space to hold res, return -1 else return -2.
      if(aRows>= overLappingRows&& aCols>=overLappingCol){
        return -1;
      }
      else{
        return -2;
      }
    }
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
    //setting overla
    int overlap=0;
    //int sum=0;
    if(mCols<nRows){
        overlap=mCols;
    }
    else{
      overlap=nRows;
    }
    //clear array A of garbage
    for (int i=0;i<aRows;i++){
      for(int j=0;j<aCols;j++){
        *(*(A+i)+j) = 0;
      }
    }
    //for each row and colum, multiply the overlaps and add to sum, and then add to A
    for(int i=0;i<mRows;i++){
      for(int j=0;j<nCols;j++){
        int sum=0;  
        for(int x=0;x<overlap;x++){
          sum+=(*(*(M+i)+x)*(*(*(N+x)+j)));
        }
        if(i<aRows &&j<aCols){
          *(*(A+i)+j)=sum;
        }
      }
    }
        //if exact match, return 1, if oversized return 2, if too small return -3, 
    if(mCols==nRows){
      if(aRows==mRows&& aCols== nCols){
        return 1;
      }
      else if (aRows>=mRows&& aCols>=nCols){
        return 2;
      }
      else{
        return -3;
      }
    }
      //if A can hold the multi result return -1, and if not enough space return -2.
    else{
      if(aRows>=mRows&& aCols>=nCols){
        return -1;
      }
      else{
        return -2;
      }

    }
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
    int neededrowSize=rows+2;
    int neededcolSize=0;
    //calculate neededcolsize
    if(cols>2){
      neededcolSize=cols;
    }
    else{
      neededcolSize=2;
    }
    //clear matrixDs of garbage
    for(int i=0;i<dsRows;i++){
      for(int j=0;j <dsCols;j++){
        *(*(DS+i)+j)=0;
      }
    }
    //Iterate through entire matrix and check which sum to go to
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
        int summedVal = *(*(A+i)+j);
        //Need Main Diagonal, then Anti-Diagonal, Then Row sum, Then Column Sum
        if(i==j&& dsRows>0&& dsCols>0){
          *(*(DS+0)+0)+= summedVal;
        }
        if((i+j==(rows-1))&&(rows==cols)){
          if(dsRows>0&&dsCols>1){
            *(*(DS+0)+1)+=summedVal;
          }
        }
        if((i+2)<dsRows &&dsCols>0){
          *(*(DS+i+2)+0)+=summedVal;
        }
        if((dsRows>1)&&(j<dsCols)){
          *(*(DS+1)+j)+=summedVal;
        }

      }
    }
    //if compatible return 1, else if DS oversized return 2, else if too small return -1.
    if(dsRows==neededrowSize&&dsCols==neededcolSize){
      return 1;
    }
    else if(dsRows>= neededrowSize&& dsCols>= neededcolSize){
      return 2;
    }
    else{
      return -1;
    }
}
