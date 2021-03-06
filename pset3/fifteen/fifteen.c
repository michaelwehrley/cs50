/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void) {
  // TODO
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      int value = d*(d-i) - (j) - 1;
      if (d % 2 == 0) {
        if (value == 2) {
          value = 1;
        } else if (value == 1) {
          value = 2;
        }
      }
      board[i][j] = value;
    }
  }
}

/**
 * Prints the board in its current state.
 */
void draw(void) {
  // TODO
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      int tile = board[i][j];
      if (tile == 0) {
        printf("%c", '_');
      } else {
       printf("%i", tile); 
      }
      if (j < d - 1) {
        if (tile < 10) {
          printf(" |");
        } else {
          printf("|");
        }
      }
    }
    printf("\n");
  }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool horizotonal_swap(int coordinates[], int _e, int* p_current, int temp);
bool vertical_swap(int coordinates[], int _e, int* p_current, int temp);

bool move(int tile) {
  // TODO
  int coordinates[2];

  for (int x = 0; x < d; x++) {
    for (int y = 0; y < d; y++) {
      if (board[x][y] == tile) {
        coordinates[0] = x;
        coordinates[1] = y;
      }
    }
  }

  int* p_current = &board[coordinates[0]][coordinates[1]];
  int temp = *p_current;

  // top tile
  if (vertical_swap(coordinates, coordinates[0] - 1, p_current, temp)) {
    return true;
  }

  // bottom tile
  if (vertical_swap(coordinates, coordinates[0] + 1, p_current, temp)) {
    return true;
  }

  // left tile
  if (horizotonal_swap(coordinates, coordinates[1] - 1, p_current, temp)) {
    return true;
  }

  // right tile
  if (horizotonal_swap(coordinates, coordinates[1] + 1, p_current, temp)) {
    return true;
  }

  return false;
}

bool horizotonal_swap(int coordinates[], int _e, int* p_current, int temp) {
  if (_e >= 0 && _e < d) {
    if (board[coordinates[0]][_e] == 0) {
      int* p_zero = &board[coordinates[0]][_e];

      *p_zero = temp;
      *p_current = 0;
      return true;
    }
  }
  return false;
}

bool vertical_swap(int coordinates[], int _e, int* p_current, int temp) {
  if (_e >= 0 && _e < d) {
    if (board[_e][coordinates[1]] == 0) {
      int* p_zero = &board[_e][coordinates[1]];

      *p_zero = temp;
      *p_current = 0;
      return true;
    }
  }
  return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void) {
  // TODO
  int previous = 0;
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      int current = board[i][j];
      if (d - 1 == j && d - 1 == i) {
        return true;
      } else if (current > previous) {
        previous = current;
      } else {
        return false;
      }
    }
  }
  return true;
}