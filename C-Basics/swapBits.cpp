/*Problem - Swapping bits in a given number.

Aim: A positive number is given as input along with two positions p1, p2 and length n. Your job is to write a program that swaps 'n' bits of the number starting from positions p1,p2. p1, p2 are 0-indexed values that start from least significant bit of the number.
	 Use unsigned int data type.

Explanation:
Sample 1: number = 47. Its binary representation is 00101111
          p1 = 1 (Start from 2nd bit from right side)
          p2 = 5 (Start from 6th bit from right side)
          n = 3 (No of bits to be swapped)
          The 3 bits starting from p1 are 00101'111' and the 3 bits staring from p2 are '001'01111. After swapping these two, the resultant binary string will be 1110011
          which is equal to decimal value 227.
          Hence the output must be 227.
          
Sample 2: number = 28. Its binary representation is 11100
          p1 = 0 (Start from 1st bit from right side)
          p2 = 3 (Start from 4th bit from right side)
          n = 2 (No of bits to be swapped)
          The 2 bits starting from p1 are 111'00' and the 2 bits staring from p2 are '11'100. After swapping these two, the resultant binary string will be 00111.
          which is equal to decimal value 7.
          Hence the output must be 7.

Sample 3: number=178. Its binary representation is 10110010.
		  p1=0  (Start from 1st bit from right side)
		  p2=30 (Start from 31st bit from right side)
	      n=5   (No of bits to be swapped)
		  In this case, since range exceeds at position2, use 0's in that case. So, the bits starting from p1 are '10010' and the bits staring from p2 are '00000'.
		  After swapping the two, the resultant binary string will be '10010000000000000000000000010100000'.But considering only 32 bits, dicsard extra bits 
		  on left side and hence resultant string will be '10000000000000000000000010100000' which is equal to decimal value 2147483808
	      Hence the output must be 2147483808.


Constraints:
1) The positions and the length 'n' must always be positive.
2) 0<=p1<p2<=32.
3) If the range overflows 32, discard the extra bits.(See Sample 3)
2) It is guaranteed that positions and ranges will not overlap.
3) It is guaranteed that the number will not exceed 32 bit range. 

Note: If constraints are violated, then return 0.
      Please Use 32 bit data(unsigned int) type to get accurate results.

	  DONT CHANGE THE FUNCTION HEADERS.

*/

#include<stdio.h>
#include<stdlib.h>

unsigned int swapBits(unsigned int num, int p1, int p2, int n)
{
	int i, k, j, p;
	int a[100] = { 0 };
	unsigned int sum = 0;

	if (n <= 0||p1<0||p2<0||p1>32||p2>32||num <=0)
	{
		return 0;
	}
	else
	{
		i = 99;
		while (num>0)
		{
			k = num % 2;
			num = num / 2;
			a[i] = k;
			i--;
		}
		/*for(i=0;i<100;i++)
		printf("%d",a[i]);*/
		i = 100 - 1 - p1;
		j = 100 - 1 - p2;
		k = 0;
		while (k<n)
		{
			p = a[i];
			a[i] = a[j];
			a[j] = p;
			k++;
			i--;
			j--;
		}
		for (i = 0; i<100; i++)
			printf("%d", a[i]);
		k = 0;
		for (i = 99; i >= 67; i--)
		{
			if (a[i] == 1)
			{
				j = 1, p = 1;
				while (j <= k)
				{
					p = 2 * p;
					j++;
				}
				sum = sum + p;
			}
			k++;
		}
		//printf("\nsum is %u", sum);
		return sum;

	}
}
