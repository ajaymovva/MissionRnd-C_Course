/*

problemCode : ChessMoves
score : 15

Praveen is teaching chess to his students, he started teaching the basics
i.e piece movements of King,Rook,Bishop on Day1


After teaching he wants to test them by giving simple puzzles,
To make it intresting , the chess board is infinitely expanding towards right and bottom.

He asks his students 3 type of questions,
If there is a piece [Rook or Bishop or King] at position (x1,y1)
what is the minimum number of moves required for that piece to move to position (x2,y2)

    1 2 3 4 5 . . . INF                 1 2 3 4 5 . . . INF
1   . . . . . . . . INF             1   . . . . . . . . INF
2   . . . . . . . . INF             2   . . . . . . . . INF
3   . . . . x . . . INF             3   . x . . . . . . INF
4   . . . . . . . . INF             4   . . . . . . . . INF
5   . . . . R . . . INF             5   . . . . R . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
.   . . . . . . . . INF             .   . . . . . . . .	INF
INF . . . . . . . . INF             INF . . . . . . . . INF

piece = Rook							piece = Rook
source = (5,5)							source = (5,5)
dest = (2,5)							dest  = (3,2)
MinMovesRequired = 1  					MinMovesRequired = 2

    1 2 3 4 5 . . . INF                 1 2 3 4 5 . . . INF
1   x . . . . . . . INF             1   . . . . . . . . INF
2   . . . . . . . . INF             2   . . . . . . . . INF
3   . . . . . . . . INF             3   . . . . . . . . INF
4   . . . . . . . . INF             4   . . . . . . . . INF
5   . . . . B . . . INF             5   . . x . B . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
INF . . . . . . . . INF             INF . . . . . . . . INF

piece = Bishop						piece = Bisiop
source = (5,5)						source = (5,5)
dest = (8,8)						dest  = (3,5)
MinMovesRequired = 1  				MinMovesRequired = 2

    1 2 3 4 5 . . . INF                 1 2 3 4 5 . . . INF
1   . . . . . . . . INF             1   . . . . . . . . INF
2   . . . . . . . . INF             2   . . . . . . . . INF
3   x . . . . . . . INF             3   . . . . x . . . INF
4   . . . . . . . . INF             4   . . . . . . . . INF
5   . . . . K . . . INF             5   . . . . K . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
INF . . . . . . . . INF             INF . . . . . . . . INF

piece = King						piece = King
source = (5,5)						source = (5,5)
dest = (3,1)						dest  = (3,5)
MinMovesRequired = 4  				 MinMovesRequired = 2

Note :
[1] If the destination cannot be reached by the piece, return -1
[2] All the inputs, outputs fits in a 64 bit integer
*/

/**
@sourceX,sourceY contains initial position 1 <= sourceX,sourceY <= 1e18
@destX,destY contains destination positions 1 <= destX,destY <= 1e18
@piece contains type of the piece			piece ∈ {'K','R','B'} 
*/

long long minimumPieceMoves(long long sourceX, long long sourceY, 
							long long destX, long long destY, char piece){
	if (sourceX <= 0 || sourceY <= 0)
	{
		return -1;
	}
	else
	{
		long long n1=0, n2=0,k1=0,k2=0;
		if (piece == 'R')
		{
			n1 = sourceX - destX;
			if (n1 != 0){ n1 = 1; }
			n2 = sourceY - destY;
			if (n2 != 0){ n2 = 1; }
			return (n1 + n2);
		}
		else if (piece == 'K')
		{
			if (sourceX == destX)
			{
				n1 = sourceY - destY;
				if (n1 < 0){ n1 = -n1; }
			}
			if (sourceY == destY)
			{
				n2 = sourceX - destX;
				if (n2 < 0){ n2 = -n2; }
			}
			else if (sourceX != destX&&sourceY != destY)
			{
				
				k1 = sourceX - destX;
				if (k1 < 0)
				{
					k1 = -k1;
				}
				k2 = sourceY - destY;
				if (k2 < 0){ k2 = -k2; }
				k2 = k2 - k1;
				if (k2 < 0){ k2 = -k2; }
				return k2 + k1;
			}
			return n1 + n2;
		}
		else if (piece == 'B')
		{
			if (sourceX == destX)
			{
				k1 = sourceY - destY;
				if (k1 < 0){ k1 = -k1; }
				if (k1 == 1)
				{
					return -1;
				}
				return -1;
			}
			else if (sourceY == destY)
			{
				k1 = sourceX - destX;
				if (k1 < 0){ k1 = -k1; }
				if (k1 == 1)
				{
					return -1;
				}
				return -1;
			}
			else
			{
				k1 = sourceX - sourceY;
				k2 = destX - destY;
				if (k1 < 0){ k1 = -k1; }
				if (k2 < 0){ k2 = -k2; }
				if (k1 == k2){ return 1; }
				else
				{
					return -1;
				}

			}
		}
	}
}

