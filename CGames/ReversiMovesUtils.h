
/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) {
	ReversiMove *res = (ReversiMove *)malloc(sizeof(ReversiMove));
	res->x = x;
	res->y = y;
	return res;
}

/*
	Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
	Hint : Use While Loop and isValidInput function
	Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/

ReversiMove *inputMove(ReversiGame *game) {
	int x, y,k=0;
	ReversiMove *res;
	while (1)
	{
		if (k == 1)break;
	}
	res = createMove(1, 1);
	return res;
}


/*
	To check the validity of coordinate on the board 
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {
	char c;
	x--; y--;
	if (x < game->cols && y < game->rows&&x>=0&&y>=0)
	{
		c = game->board[y][x];
		if (c == ' ')
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		return 0;
	}
}

/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

int isValidMove(ReversiGame *game, ReversiMove *move) {
	int x, y,x1,y1,l; int i,j,k; char c,c1;
	x = move->x; y = move->y;
	int *a = (int *)malloc(16 * sizeof(int));
	i=isvalidCoordinate(game,x, y);
	if (i == 1)
	{
		j = game->turn;
		if (j == 1)
		{                               
			c = 'b';
			c1 = 'w';
		}
		else if (j == -1)
		{
			c = 'w';
			c1 = 'b';
		}
		k = 0; x--; y--;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (i != x||j != y)
				{
					a[k++] = i; a[k++] = j;
				}
			}
		}
		k = 1;
		for (i = 0, j = 1; i < 16 && j < 16;)
		{
			x1 = a[i], y1 = a[j]; l = 0;
			if (x1>=0 && x1 < game->cols&&y1 >=0 && y1 < game->rows)
			{
				if (game->board[y1][x1] == c)
				{
						while (x1 >=0 && x1 < game->cols&&y1 >=0 && y1 < game->rows)
						{
							if (game->board[y1][x1] == c1)
							{
								l = 1; break;
							}
							else if (game->board[y1][x1] == ' ')break;	
							if (k == 1){ x1--; y1--; }
							if (k == 2){ x1--; }
							if (k == 3){ x1--; y1++; }
							if (k == 4){y1--;}
							if (k == 5){y1++;}
							if (k == 6){ x1++; y1--; }
							if (k == 7){ x1++;}
							if (k == 8){ x1++; y1++;}
						}
						if (l == 1)break;
				}
			}
			k++; j = j + 2; i = i + 2;
		}
		if (l == 1)return 1;
		else return 0;
	}
	else
		return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game){
	int i,j,x,y,k,l=0;
	ReversiMove *move;
	for (i = 0; i < game->rows; i++)
	{
		for (j = 0; j < game->cols; j++)
		{
			if (game->board[i][j] == ' ')
			{
				y = i+1; x = j+1;
				move = createMove(x, y);
				k = isValidMove(game,move);
				if (k == 1)
				{ 
					l = 1; 
					break; 
				}
			}
		}
		if (l == 1)break;
	}
	if (l == 1)return 1;
	else return 0;
	/*if (l != 1)
	{
		if (game->turn == -1)game->turn = 1;
		else if (game->turn == 1)game->turn = -1;
		for (i = 0; i < game->rows; i++)
		{
			for (j = 0; j < game->cols; j++)
			{
				if (game->board[i][j] == ' ')
				{
					y = i++; x = j++;
					move = createMove(x, y);
					k = isValidMove(game, move);
					if (k == 1){ l = 1; break; }
				}
			}
			if (l == 1)break;
		}
		if (l == 1)return 1;
		else return 0;
	}
	else
	{
		return 1;
	}*/
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) {
	game->NumberofMoves = game->NumberofMoves + 1;
	return;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game) {
	if (game->turn == -1)game->turn = 1;
	else if (game->turn == 1)game->turn = -1;
	return;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {
	if (game->blackCount > game->whiteCount)game->winner = -1;
	else if (game->blackCount < game->whiteCount)game->winner = 1;
	else game->winner = 0;
	game->state = 1;
	return;
}

/*
	Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}


/*
	This function performs move action on the board
	Note : call validity check performs using above functions before making a move
	returns :
	true on move sucess
	false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move) {
	int p, i, j, k,x,y,x1,y1,l,x2,y2; char c, c1;
	int *a = (int *)malloc(sizeof(int) * 16);
	p = isValidMove(game, move);
	if (p == 0)
	{
		//modifyTurn(game);
		return false;
	}
	else
	{
		j = game->turn; x = move->x; y = move->y;
		game->NumberofMoves++;
		if (j == 1)
		{
			c = 'b';
			c1 = 'w';
		}
		else if (j == -1)
		{
			c = 'w';
			c1 = 'b';
		}
		k = 0; x--; y--;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (i != x || j != y)
				{
					a[k++] = i; a[k++] = j;
				}
			}
		}
		k = 1; l = 0;
		for (i = 0, j = 1; i < 16 && j < 16;)
		{
			x1 = a[i], y1 = a[j];
			if (x1 >= 0 && x1 < game->cols&&y1 >= 0 && y1 < game->rows)
			{
				if (game->board[y1][x1] == c)
				{
					while (x1 >= 0 && x1 < game->cols&&y1 >= 0 && y1 < game->rows)
					{
						if (game->board[y1][x1] == c1)
						{
							x2 = x; y2 = y;
							while (x2 != x1||y2 != y1)
							{
								if (k == 1){ x2--; y2--; }
								if (k == 2){ x2--; }
								if (k == 3){ x2--; y2++; }
								if (k == 4){ y2--; }
								if (k == 5){ y2++; }
								if (k == 6){ x2++; y2--; }
								if (k == 7){ x2++; }
								if (k == 8){ x2++; y2++; }
								if (x2 != x1||y2 != y1)
								{
									game->board[y2][x2] = c1;
									/*if (c1 == 'w')
									{
										game->blackCount--;
										game->whiteCount++;
									}
									else if (c1 == 'b')
									{
										game->blackCount++;
										game->whiteCount--;
									}*/
								}
							}
							l = 1;
						}
						else if (game->board[y1][x1] == ' ')break;
						if (k == 1){ x1--; y1--; }
						if (k == 2){ x1--; }
						if (k == 3){ x1--; y1++; }
						if (k == 4){ y1--; }
						if (k == 5){ y1++; }
						if (k == 6){ x1++; y1--; }
						if (k == 7){ x1++; }
						if (k == 8){ x1++; y1++; }
					}
				}
			}
			k++; j = j + 2; i = i + 2;
		}
		if (l == 1)
		{
			game->board[y][x] = c1;
			//if (c1 == 'w')game->whiteCount++;
			//else if (c1 == 'b')game->blackCount++;
		}
		int w = 0, b = 0;
		for (i = 0; i < game->rows; i++)
		{
			for (j = 0; j < game->cols; j++)
			{
				if (game->board[i][j] == 'w')w++;
				else if (game->board[i][j] == 'b')b++;
				k++;
			}
		}
		game->whiteCount = w; game->blackCount = b;
		modifyTurn(game);
		k=hasMove(game);
		if (k == 0)
		{
			modifyTurn(game);
		}
		return true;
	}
}


void printWinner(ReversiGame *game) {
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/
	
}