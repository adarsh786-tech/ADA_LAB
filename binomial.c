//// A Dynamic Programming based solution that uses table C[][] to
//// calculate the Binomial Coefficient
//#include<stdio.h>
//
//// Prototype of a utility function that returns minimum of two integers
//int min(int a, int b);
//
//// Returns value of Binomial Coefficient C(n, k)
//int binomialCoeff(int n, int k)
//{
//	int C[n+1][k+1];
//	int i, j;
//
//	// Caculate value of Binomial Coefficient in bottom up manner
//	for (i = 0; i <= n; i++)
//	{
//		for (j = 0; j <=n; j++)
//		{
//			// Base Cases
//			if (j == 0 || j == i)
//				C[i][j] = 1;
//
//			// Calculate value using previously stored values
//			else
//				C[i][j] = C[i-1][j-1] + C[i-1][j];
//		}
//	}
//    for (i = 0; i <= n; i++)
//	{
//		for (j = 0; j <=n; j++)
//            printf("%d\t",C[i][j]);
//        printf("\n");
//	}
//
//	return C[n][k];
//}
//
//// A utility function to return minimum of two integers
//int min(int a, int b)
//{
//	return (a<b)? a: b;
//}
//
///* Drier program to test above function*/
//int main()
//{
//	int n = 6, k =2 ;
//	int i,j;
//	printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k) );
//
//	return 0;
//}

// A Dynamic Programming based solution that uses table C[][] to
// calculate the Binomial Coefficient
#include<stdio.h>

// Prototype of a utility function that returns minimum of two integers
int min(int a, int b);

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
	int C[n+1][k+1];
	int i, j;

	// Caculate value of Binomial Coefficient in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= min(i, k); j++)
		{
			// Base Cases
			if (j == 0 || j == i)
				C[i][j] = 1;

			// Calculate value using previously stored values
			else
				C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}

    for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= min(i, k); j++)
		{
            printf("%d\t",C[i][j]);
		}
		printf("\n");
	}
	return C[n][k];
}

// A utility function to return minimum of two integers
int min(int a, int b)
{
	return (a<b)? a: b;
}

/* Drier program to test above function*/
int main()
{
	int n = 6, k = 5;
	printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k) );
	return 0;
}

