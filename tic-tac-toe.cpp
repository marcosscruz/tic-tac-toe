#include <iostream>
#include <cstdlib>   // Para utilizar o comando "clear"
#include <windows.h> // Apenas para sistemas Windows
using namespace std;

// Declaração das variáveis
char board[3][3];     // O tabuleiro é uma matriz 3x3 para representar as posições do jogo
int currentPlayer;    // O jogador atual (1 para X, 2 para O)
char playerOneSymbol; // O símbolo do jogador 1 (X)
char playerTwoSymbol; // O símbolo do jogador 2 (O)
int line, column;     // Coordenadas da jogada atual
int gameStatus;       // Estado do jogo (0 para em andamento, 1 para jogador 1 venceu, 2 para jogador 2 venceu, 3 para empate)

// Função para inicializar o jogo
void initializeGame()
{
    // Preenche o tabuleiro com espaços vazios
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
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

// Função para alternar o jogador atual
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

// Função para verificar se um jogador venceu
bool playerWon(char player)
{
    // Verificar linhas
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    // Verificar colunas
    for (int i = 0; i < 3; i++)
    {
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

// Função para verificar se o jogo terminou em empate
bool gameTied()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false; // Ainda existem espaços vazios
            }
        }
    }
    return true; // Todos os espaços estão preenchidos
}

// Função para inserir um símbolo no tabuleiro
void insertSymbolOnBoard(char board[3][3], int player, int line, int column)
{
    char symbol = (player == 1) ? 'X' : 'O';
    board[line][column] = symbol;
}

// Função para exibir o tabuleiro formatado com cores
void displayFormattedBoard()
{
    system("cls"); // Limpa a tela do console (funciona no Windows)

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Cores dos jogadores
    int colorPlayer1 = FOREGROUND_RED | FOREGROUND_INTENSITY;
    int colorPlayer2 = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    cout << "Jogo da Velha" << endl
         << endl;
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 3; j++)
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

// Função para solicitar a entrada do jogador
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

    int line, column;
    do
    {
        cout << "Informe a linha (0, 1 ou 2) e a coluna (0, 1 ou 2) separadas por espaco: ";
        cin >> line >> column;
    } while (line < 0 || line > 2 || column < 0 || column > 2 || board[line][column] != ' ');
    insertSymbolOnBoard(board, currentPlayer, line, column);
}

// Função principal
int main()
{
    // Inicializa o jogo
    initializeGame();

    // Loop principal do jogo
    while (gameStatus == 0)
    { // Enquanto o jogo estiver em andamento
        // Exibe o tabuleiro
        displayFormattedBoard();

        // Solicita a entrada do jogador
        requestEntryPlayer();

        // Verifica se a jogada é válida
        if (line < 0 || line > 2 || column < 0 || column > 2 || board[line][column] != ' ')
        {
            cout << "Jogada invalida! Tente novamente." << endl;
        }
        else
        {
            // Marca a jogada no tabuleiro
            insertSymbolOnBoard(board, currentPlayer, line, column);

            // Verifica se o jogador venceu
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
                // Alterna para o próximo jogador
                switchPlayer();
            }
        }
    }

    // Exibe o resultado
    if (gameStatus == 1 || gameStatus == 2)
    {
        cout << "Jogador " << gameStatus << " venceu!" << endl;
    }
    else if (gameStatus == 3)
    {
        cout << "O jogo terminou em empate!" << endl;
    }

    // Pergunta se os jogadores desejam jogar novamente
    char playAgain;
    cout << "Deseja jogar novamente? (S/N): ";
    cin >> playAgain;

    if (playAgain == 'S' || playAgain == 's')
    {
        // Reinicia o jogo
        initializeGame();
    }
    else
    {
        cout << "Obrigado por jogar! Ate a proxima." << endl;
    }

    return 0;
}
