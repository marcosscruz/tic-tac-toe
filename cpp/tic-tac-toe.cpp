#include <ctime>
#include <iostream>
#include <cstdlib>   // Para utilizar o comando "clear"
#include <windows.h> // Apenas para sistemas Windows
#include <vector>
using namespace std;

// declaração das variáveis
const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE]; // o tabuleiro é uma matriz 3x3 para representar as posições do jogo
int currentPlayer;                  // o jogador atual (1 para X, 2 para O)
char playerOneSymbol;               // o símbolo do jogador 1 (X)
char playerTwoSymbol;               // o símbolo do jogador 2 (O)
int line, column;                   // coordenadas da jogada atual
int gameStatus;                     // estado do jogo (0 para em andamento, 1 para jogador 1 venceu, 2 para jogador 2 venceu, 3 para empate)

// função para inicializar o jogo
void initializeGame()
{
    // Preenche o tabuleiro com espaços vazios
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Define o jogador 1 (X) como o primeiro jogador
    currentPlayer = 1;
    playerOneSymbol = 'X';
    playerTwoSymbol = 'O';

    // Define o estado do jogo como "em andamento"
    gameStatus = 0;
}

// função para alternar o jogador atual
void switchPlayer()
{
    if (currentPlayer == 1)
    {
        currentPlayer = 2;
    }
    else
    {
        currentPlayer = 1;
    }
}

// função para verificar se um jogador venceu
bool playerWon(char player)
{
    // Verificar linhas e colunas
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }

        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }

    // Verificar diagonais
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

// função para verificar se o jogo terminou em empate
bool gameTied()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return false; // Ainda existem espaços vazios
            }
        }
    }
    return true; // Todos os espaços estão preenchidos
}

// função para inserir um símbolo no tabuleiro
void insertSymbolOnBoard(char board[3][3], int player, int line, int column)
{
    char symbol = (player == 1) ? 'X' : 'O';
    board[line][column] = symbol;
}

// função para exibir o tabuleiro formatado com cores
void displayFormattedBoard()
{
    system("cls"); // Limpa a tela do console (funciona no Windows)

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Cores dos jogadores
    int colorPlayer1 = FOREGROUND_RED | FOREGROUND_INTENSITY;
    int colorPlayer2 = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    cout << "Jogo da Velha" << endl
         << endl;
    cout << "  0   1   2" << endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 'X')
            {
                SetConsoleTextAttribute(hConsole, colorPlayer1);
            }
            else if (board[i][j] == 'O')
            {
                SetConsoleTextAttribute(hConsole, colorPlayer2);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            }
            cout << board[i][j];
            if (j < 2)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "  ---------" << endl;
        }
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << endl;
}

// função para solicitar a entrada do jogador
void requestEntryPlayer()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "Jogador ";
    if (currentPlayer == 1)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    cout << currentPlayer << ", sua vez!" << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

    while (true)
    {
        cout << "Informe a linha (0, 1 ou 2) e a coluna (0, 1 ou 2) separadas por espaco: ";
        cin >> line >> column;

        if (line < 0 || line > 2 || column < 0 || column > 2 || board[line][column] != ' ')
        {
            cout << "Jogada Invalida! Tente novamente." << endl;
        }
        else
        {
            break;
        }
    }
}

// função da máquina
void makeMoveAI()
{
    srand(static_cast<unsigned>(time(0)));

    int randomLine, randomColumn;

    do
    {
        randomLine = rand() % BOARD_SIZE;
        randomColumn = rand() % BOARD_SIZE;
    } while (board[randomLine][randomColumn] != ' ');

    // jogada da IA no tabuleiro
    insertSymbolOnBoard(board, currentPlayer, randomLine, randomColumn);
}

// função para escolher o modo de jogo (P vc COM ou P vs P)
int chooseGameMode()
{
    system("cls"); // Limpa a tela do console (funciona no Windows)
    int choice;
    cout << "Escolha o modo de jogo: \n\t1. Player vs Player \n\t2. Player vs Computador" << endl;
    cin >> choice;
    system("cls"); // Limpa a tela do console (funciona no Windows)
    return choice;
}

// Função principal
int main()
{
    // escolhendo o modo de jogo
    int gameMode = chooseGameMode();

    char playAgain;

    switch (gameMode)
    {
    case 1: // player vs player
        do
        {
            // inicializa o jogo
            initializeGame();

            // loop principal do jogo
            while (gameStatus == 0)
            {
                // exibe o tabuleiro
                displayFormattedBoard();

                // solicita a entrada do jogador
                requestEntryPlayer();

                // marca a jogada no tabuleiro
                insertSymbolOnBoard(board, currentPlayer, line, column);

                // verifica se o jogador venceu
                if (playerWon((currentPlayer == 1) ? playerOneSymbol : playerTwoSymbol))
                {
                    displayFormattedBoard();
                    cout << "Jogador " << currentPlayer << " venceu!" << endl;
                    gameStatus = currentPlayer;
                }
                else if (gameTied())
                {
                    displayFormattedBoard();
                    cout << "O jogo terminou em empate!" << endl;
                    gameStatus = 3; // 3 representa empate
                }
                else
                {
                    // alterna para o próximo jogador
                    switchPlayer();
                }
            }

            // exibe o resultado
            if (gameStatus == 1 || gameStatus == 2)
            {
                cout << "Jogador " << gameStatus << " venceu!" << endl;
            }
            else if (gameStatus == 3)
            {
                cout << "O jogo terminou em empate!" << endl;
            }

            // pergunta se os jogadores desejam jogar novamente
            cout << "Deseja jogar novamente? (S/N): ";
            cin >> playAgain;

            if (playAgain == 'S' || playAgain == 's')
            {
                // reinicia o jogo
                initializeGame();
            }
            else
            {
                cout << "Obrigado por jogar!" << endl;
            }

        } while (playAgain == 'S' || playAgain == 's');
        break;

    case 2: // player vs computador
        do
        {
            // inicializa o jogo
            initializeGame();

            // loop principal do jogo
            while (gameStatus == 0)
            {
                // exibe o tabuleiro
                displayFormattedBoard();

                // solicita a entrada do jogador
                requestEntryPlayer();

                // marca a jogada do jogador 1 no tabuleiro
                insertSymbolOnBoard(board, currentPlayer, line, column);

                displayFormattedBoard();

                // verifica se o player 1 ganhou
                if (playerWon((currentPlayer == 1) ? playerOneSymbol : playerTwoSymbol))
                {
                    displayFormattedBoard();
                    cout << "Jogador " << currentPlayer << " venceu!" << endl;
                    gameStatus = currentPlayer;
                    break;
                }
                else if (gameTied())
                {
                    displayFormattedBoard();
                    cout << "O jogo terminou em empate!" << endl;
                    gameStatus = 3;
                    break;
                }

                switchPlayer();

                if (gameStatus != 0)
                {
                    break;
                }

                // vez da máquina (jogador 2)
                makeMoveAI();

                displayFormattedBoard();

                // verifica se a máquina venceu
                if (playerWon(playerTwoSymbol))
                {
                    cout << "A IA venceu!" << endl;
                    gameStatus = 2;
                    break;
                }
                else if (gameTied())
                {
                    cout << "O jogo terminou em empate!" << endl;
                    gameStatus = 3;
                    break;
                }

                switchPlayer();

                // exibindo resultado
                if (gameStatus == 1 || gameStatus == 2)
                {
                    cout << "Jogador " << gameStatus << " venceu!" << endl;
                }
                else if (gameStatus == 3)
                {
                    cout << "O jogo terminou em empate!" << endl;
                }
            }

            // pergunta de jogar novamente
            cout << "Deseja jogar novamente? (S/N): ";
            cin >> playAgain;

            if (playAgain == 'S' || playAgain == 's')
            {
                initializeGame();
            }
            else
            {
                cout << "Obrigado por jogar!" << endl;
            }

        } while (playAgain == 'S' || playAgain == 's');
        break;

    default:
        cout << "Opcao Invalida! Tente novamente." << endl;
    }

    return 0;
}