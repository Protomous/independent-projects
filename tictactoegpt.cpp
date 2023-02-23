#include <iostream>
#include <ctime>
#include <cstring>
#include <SDL2/SDL.h>

using namespace std;

const int BOARD_SIZE = 3;
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
SDL_Texture *gBoardTexture = NULL;
SDL_Texture *gXTexture = NULL;
SDL_Texture *gOTexture = NULL;
SDL_Rect gBoardRect = {50, 50, 300, 300};
SDL_Rect gCellRects[BOARD_SIZE][BOARD_SIZE];

// Function to load textures from file
SDL_Texture *loadTexture(const char *filename)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = SDL_LoadBMP(filename);

    if (surface == NULL)
    {
        cerr << "Failed to load image: " << SDL_GetError() << endl;
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(gRenderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

// Function to initialize SDL
bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "Failed to initialize SDL: " << SDL_GetError() << endl;
        return false;
    }

    gWindow = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        cerr << "Failed to create window: " << SDL_GetError() << endl;
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL)
    {
        cerr << "Failed to create renderer: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

// Function to load textures
bool loadMedia()
{
    gBoardTexture = loadTexture("board.bmp");
    if (gBoardTexture == NULL)
    {
        cerr << "Failed to load board texture" << endl;
        return false;
    }

    gXTexture = loadTexture("x.bmp");
    if (gXTexture == NULL)
    {
        cerr << "Failed to load X texture" << endl;
        return false;
    }

    gOTexture = loadTexture("o.bmp");
    if (gOTexture == NULL)
    {
        cerr << "Failed to load O texture" << endl;
        return false;
    }

    return true;
}

// Function to free resources
void close()
{
    SDL_DestroyTexture(gBoardTexture);
    SDL_DestroyTexture(gXTexture);
    SDL_DestroyTexture(gOTexture);

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    SDL_Quit();
}

// Function to render the board
void renderBoard(char board[][BOARD_SIZE])
{
    SDL_RenderCopy(gRenderer, gBoardTexture, NULL, &gBoardRect);

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            SDL_Rect cellRect = {gBoardRect.x + j * 100, gBoardRect.y + i * 100, 100, 100};
            gCellRects[i][j] = cellRect;

            if (board[i][j] == 'X')
            {
                SDL_RenderCopy(gRenderer, gXTexture, NULL, &cellRect);
            }
            else if (board[i][j] == 'O')
            {
                SDL_RenderCopy(gRenderer, gOTexture, NULL, &cellRect);
            }
        }
    }

    SDL_RenderPresent(gRenderer);
}

// Function to get player move from input
void getPlayerMove(char board[][BOARD_SIZE], char currentPlayer)
{
    int row, col;
    cout << "Player " << currentPlayer << "'s turn." << endl;
    cout << "Enter row (1-3) and column (1-3) separated by a space: ";
    cin >> row >> col;

    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
    {
        cout << "Invalid move. Please try again." << endl;
        cout << "Enter row (1-3) and column (1-3) separated by a space: ";
        cin >> row >> col;
    }

    board[row - 1][col - 1] = currentPlayer;
}

// Function to get computer move
void getComputerMove(char board[][BOARD_SIZE], char currentPlayer)
{
    int row, col;
    srand(time(NULL));
    do
    {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != ' ');

    board[row][col] = currentPlayer;
}

// Function to check if the game is over
bool checkGameOver(char board[][BOARD_SIZE], char currentPlayer)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
        {
            return true;
        }
    } // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer)
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    {
        return true;
    }

    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    {
        return true;
    }

    // Check for tie
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }

    cout << "It's a tie!" << endl;
    return true;
}

// Function to play the game
void playGame()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char currentPlayer = 'X';
    bool gameOver = false;
    if (!loadMedia())
    {
        cerr << "Failed to load media" << endl;
        return;
    }

    while (!gameOver)
    {
        renderBoard(board);

        if (currentPlayer == 'X')
        {
            getPlayerMove(board, currentPlayer);
        }
        else
        {
            getComputerMove(board, currentPlayer);
        }

        gameOver = checkGameOver(board, currentPlayer);

        if (!gameOver)
        {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    renderBoard(board);
}

// Main function
int main()
{
    if (!init())
    {
        cerr << "Failed to initialize" << endl;
        return 1;
    }
    playGame();

    close();

    return 0;
}