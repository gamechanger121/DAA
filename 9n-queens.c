#include<stdio.h>
#include<math.h>

int board[20],count;

void print(int n)
{
  int i, j;
  printf("\n\nSolution %d:\n\n", ++count);

  for (i = 1; i <= n; ++i)
    printf("\t%d", i);

  for (i = 1; i <= n; ++i)
  {
    printf("\n\n%d", i);
    for (j = 1; j <= n; ++j) // for nxn board
    {
      if (board[i] == j)
        printf("\tQ"); // queen at i,j position
      else
        printf("\t-"); // empty slot
    }
  }
}

int place(int row,int column)
{
    int i;
    for(i = 1;i <= row - 1;++i)
    {
        if(board[i] == column)
        {
            return 0;
        }
        else if(abs(board[i] - column) == abs(i - row))
        {
            return 0;
        }
    }
    return 1;
}

void queens(int row,int n)
{
    int column;
    for(column = 1;column <= n;++column)
    {
        if(place(row,column))
        {
            board[row]  = column;
            if (row == n)
            {
                print(n);
            }
            else
            {
                queens(row+1,n);
            }  
        }
    }
}

int main()
{
  int n, i, j;
  void queens(int row, int n);

  printf(" - N Queens Problem Using Backtracking -");
  printf("\n\nEnter number of Queens:");
  scanf("%d", &n);
  queens(1, n);
  return 0;
}
