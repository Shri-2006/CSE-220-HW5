So, the tests are similar because i copied and pasted examples, then adjusted them
Used a multiplication matric calc from online to do most of the calculations, it was taking too long to figure out the results.

SparseMatrix handles 0 rows or 0 cols as return 0.



SparseMatrix:
test1=all zero 
test2= check identity 
test_3= checks non square to equal M
test4=nonsparse
test_5= test for 1x1 nonzero working or non
test_6= check nearly empty matrix with 1 nonzero
test_7=anti diagonal with all nonzeros check
test_8= negative value in 2 x2 check
test9:flat matrix check
test10:skyscraper matrix check
test_11: large int within C support test
test_12: single non zero check

Hadamard test:
test1: smallest possible valid case test
test2: too large A test 
test 3: Too small A test 
test 4: if dimensions can't work return -1
test 5: if A too small when inputs are good return -3
test 6 checks fir incompaitble matrices and ensures first element of A=0
test 7: single matrices that should result in 0, checks to ensure no bug in multiplying
test 8: checking negative multiplications.
test_9: check compaitble multi with oversized a
Test 10 incompatible multi with single matrice A overlap, with large int in first elelemt. should return -1
tets11 checks whether elements are actually being right
test 12 checks for correct element results
test 13 checks negative elements
test 14 confirm sign transfer again

MatriceMulti tests
test1: just regular test
test2: also pretty normal, just not square. I also used a macro because I had forgotten about them and wanted to make sure I knew how to use them correctly.
test3: incompatible mult, return -1
test 4: same, but with smaller A, return -2
test_5_typo: i mistyped thee criterion type, so i decided to just include it. reuslts in -1 because A oversized
test 5: actual test, a oversized with compatible multi is 2.
test 6: checks actual value and verifies the math works.
test 7; makes sure the test runs right and checks the value in first spot
test8: checks witha large number, works right
test 9: checks 0 matrice values and size to ensure it owkrs
test 10 checks if it works with negative matrices multi right
test 11: compatible but very oversized, result in 2.
test 12: same as 11, but with colums and rows swappped. result in 2
test 13 both col and rol are oversized now
test 14 checks negative multi cancles each other out.
test 15 checks negative multi no cancleing
test 16checks identity matriix if it works or no.

DiagonalSum tests
test1 checks basic workign strucutre,just a normal question
test 2 checks oversized which should return 2
test 3 should be undersized and return -1
test 4 should be like 3, undersized and return -1
test 5 checks if non square but also too small will work, should be -1 according to instructions
test 6 checks for incorrect row/cols and should be -1
test 7 checks negatives to ensure its working right in cancleing
test 8_typo mistyped the test i had made in programiz online compiler, but its nice test
            its testing for not large enough res matrix, return -1
test 8: checks long matrix with a good res matrix size and should return 1
test9 Should return -1 because undersize res 
test10 checks that anti diagonal gets skipped non square according to piazza & hw instruction doc.

























Examples given stored:
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
