// By: Gonçalo Leão

#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    //TODO...

    int maxSum = -100;
    int tempSum;

    for(int x=0; x<n-1; x++){
        tempSum = A[x];
        for(int y=x+1; y<n; y++){
            tempSum += A[y];
            if(tempSum > maxSum){
                i = x;
                j = y;
                maxSum = tempSum;
            }
        }
    }

    return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}