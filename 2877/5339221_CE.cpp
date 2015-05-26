#include <stdio.h>
#define LIMIT 6
#define TOTAL ((LIMIT*LIMIT)/4)

#define LINE 1
#define SQUARE 2
#define LEFTLEAN 3
#define RIGHTLEAN 4
#define LEFTL 5
#define RIGHTL 6
#define MIDDLE 7

int pieces[TOTAL];
int placed[TOTAL];
int board[LIMIT][LIMIT];

int top;
int left;
int infillboard;
int solved;

int checkit(int t1, int l1, int t2, int l2, int t3, int l3, int t4, int l4, int num)
{
    if ((t1> (LIMIT-1)) || (t2>(LIMIT-1)) || (t3 > (LIMIT-1)) || (t4 > (LIMIT-1)) || (l1>(LIMIT-1)) || (l2 > (LIMIT-1)) || (l3 > (LIMIT-1)) || (l4 > (LIMIT-1))) return 0;
    if ((t1<0 ) || (t2<0) || (t3 <0) || (t4 <0) || (l1<0) || (l2 <0) || (l3 <0) || (l4 <0)) return 0;

    if ((board[t1][l1] == ' ') && (board[t2][l2] == ' ') &&
	(board[t3][l3] == ' ') && (board[t4][l4] == ' '))
	{
	    placed[num] = 1;
	    board[t1][l1] = num + 'A';
	    board[t2][l2] = num + 'A';
	    board[t3][l3] = num + 'A';
	    board[t4][l4] = num + 'A';
	    return 1;
	}
    return 0;
}

void locateTL()
{
    int i;
    int j;
    for (i = 0; i < LIMIT; i++)
    {
        for (j = 0; j < LIMIT; j++)
        {
            if(board[i][j] == ' ')
            {
                top = i;
                left = j;
                return;
            }
        }
    }
    top = LIMIT;
    left = LIMIT;
}

void removePiece(int num)
{
    int i;
    int j;
    int found;
    
    char target;
    
    target = 'A' + num;
    found = 0;
    placed[num] = 0;
    
    for (i = 0; i < LIMIT; i++)
    {
        for (j = 0; j < LIMIT; j++)
        {
            if(board[i][j] == target)
            {
                board[i][j] = ' ';
                found++;
                if (found == 4)
                {
                    return;
                }
            }
        }
    }
}


int placePiece(int num, int rotate)
{
    int type;

    locateTL();

    type = pieces[num];

    switch(type)
    {
        case LINE:
        {
            if (rotate == 0) return checkit(top, left, top, left+1, top, left+2, top, left + 3, num);
            else if (rotate == 1) return checkit(top, left, top+1, left, top+2, left, top+3, left, num);  
            break;
        }
        case SQUARE:
        {
            if (rotate == 0) return checkit(top, left, top+1, left, top, left+1, top+1, left+1, num);
            break;
        }
        case LEFTLEAN:
        {
            if (rotate == 0) return checkit(top, left, top, left+1,top+1, left+1, top+1, left+2,num);
            else if (rotate == 1) return checkit(top, left, top+1, left-1, top+1, left, top+2, left-1, num);
            break;
        }
        case RIGHTLEAN:
        {
            if (rotate == 0) return checkit(top, left, top, left+1, top+1, left, top+1, left-1,num);
            else if (rotate == 1) return checkit(top, left, top+1, left, top+1, left+1, top+2, left+1, num);
            break;
        }
        case LEFTL:
        {
            if (rotate == 0) return checkit(top, left, top+1, left, top+1, left+1, top+1, left+2, num);
            else if (rotate == 1) return checkit(top, left, top, left+1, top+1, left, top+2, left, num);
            else if (rotate == 2) return checkit(top, left, top, left+1, top, left+2, top+1, left+2, num);
            else if (rotate == 3) return checkit(top, left, top+1, left, top+2, left, top+2, left-1, num);
            break;
        }
        case RIGHTL:
        {
            if (rotate == 0) return checkit(top, left, top, left+1, top, left+2, top+1, left, num);
            else if (rotate == 1) return checkit(top, left, top, left+1, top+1, left+1, top+2, left+1, num);
            else if (rotate == 2) return checkit(top, left, top+1, left, top+1, left-1, top+1, left-2, num);
            else if (rotate == 3) return checkit(top, left, top+1, left, top+2, left, top+2, left+1, num);
            break;
        }
        case MIDDLE:
        {
            if (rotate == 0) return checkit(top, left, top+1, left-1, top+1, left, top+1, left+1, num);
            else if (rotate == 1) return checkit(top, left, top+1, left, top+1, left+1, top+2, left, num);
            else if (rotate == 2) return checkit(top, left, top, left+1, top, left+2, top+1, left+1, num);
            else if (rotate == 3) return checkit(top, left, top+1, left-1, top+1, left, top+2, left, num);
            break;
        }
    }

    return 0;    
}

void fillBoard(int already)
{
    int putPiece;
    int status;
    int rotate;
    int wontPlace[7];
    int i;
    int type; 
#if 0
int row; int col;

for (row = 0; row < LIMIT; row++)
    {
for (col = 0; col < LIMIT; col++)
printf("%c", board[row][col]);
printf("\n");
}
#endif


    for (i = 0; i < 7; i++)
    {
    	wontPlace[i] = -1;
    }

    if (already == TOTAL)
    {
	    solved = 1;
        return;
    }

    for (putPiece = 0; putPiece < TOTAL; putPiece++)
    {
        if (placed[putPiece] == 0) 
        {

            type = pieces[putPiece];
	        if (wontPlace[type] == -1)
	        {
		        for (rotate = 0; rotate < 4; rotate++)
		        {
		            status = placePiece(putPiece, rotate);
		            if (status != 0)
		            {
			        fillBoard(already+1);
			        if (solved) return;
			        removePiece(putPiece);
		            }
		        }
	    	    wontPlace[type] = putPiece;
    	    }
        }
    }
}

void main(void)
{
    int numRuns;
    
    int currentRun;
    int row;
    int col;
    int piece;
    

    scanf("%d", &numRuns);
    
    for (currentRun = 0; currentRun < numRuns; currentRun++)
    {
    	infillboard = 0;
        for (row = 0; row < LIMIT; row++)
        {
            for (col = 0; col < LIMIT; col++)
            {
                board[row][col] = ' ';
            }
        }
        
        for (piece = 0; piece < TOTAL; piece++)
        {
            scanf("%d", &(pieces[piece]));
            placed[piece] = 0;
        }
        
        solved = 0;
        fillBoard(0);

        printf("Data Set %d\n", currentRun+1);
        if (solved == 0)
        {
            printf("The floor may not be tiled.\n");
        }
        else
        {
            printf("The floor may be tiled.\n");
    	    for (row = 0; row < LIMIT; row++)
	        {
		        for (col = 0; col < LIMIT; col++)
        		{
		            printf("%c", board[row][col]);
        		}
		        printf("\n");
    	    }
        }
        printf("\n");
    }
    printf("End of Output\n");

}

