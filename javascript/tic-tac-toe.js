document.addEventListener("DOMContentLoaded", function () {
    const screen1 = document.getElementById("screen1");
    const screen2 = document.getElementById("screen2");
    const screen3 = document.getElementById("screen3");
    const modePvP = document.getElementById("modePvP");
    const modePvIA = document.getElementById("modePvIA");
    const returnHomeScreen1_2 = document.getElementById("returnHomeScreen1_2");
    const returnHomeScreen1_3 = document.getElementById("returnHomeScreen1_3");

    modePvP.addEventListener("click", function () {
        screen1.style.display = "none";
        screen2.style.display = "block";
        initializaGamePvP(); // iniciando pvp
    });

    modePvIA.addEventListener("click", function () {
        screen1.style.display = "none";
        screen3.style.display = "block";
    });

    returnHomeScreen1_2.addEventListener("click", function () {
        screen1.style.display = "block";
        screen2.style.display = "none";
        screen3.style.display = "none";
    });

    returnHomeScreen1_3.addEventListener("click", function () {
        screen1.style.display = "block";
        screen2.style.display = "none";
        screen3.style.display = "none";
    });

});

const board = document.querySelectorAll('#board button');
const buttons = document.getElementById('button');
const winningPlayer = document.getElementById('winningPlayer');
const restartButton = document.getElementById('restartButton');

let currentPlayer = 'X';
let gameBoard = ['', '', '', '', '', '', '', '', ''];
let gameActive = true;

// verifca se há vencedor
function checkWinner() {
    const winningCombinations = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8], // linhas
        [0, 3, 6], [1, 4, 7], [2, 5, 8], // colunas
        [0, 4, 8], [2, 4, 6] // diagonais
    ];

    for (const combination of winningCombinations) {
        const [a, b, c] = combination;
        if (gameBoard[a] && gameBoard[a] === gameBoard[b] && gameBoard[a] === gameBoard[c]) {
            return gameBoard[a];
        }
    }

    if (!gameBoard.includes('')) {
        return 'Draw'; // empate
    }

    return null;
}

// alternando jogador
function changePLayer() {
    currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
}

// cliques nos botões do tabuleiro
function buttonClick(button, index) {
    if (gameBoard[index] === '' && gameActive) {
        button.textContent = currentPlayer;
        gameBoard[index] = currentPlayer;
        const winner = checkWinner();
        if (winner) {
            gameActive = false;
            if (winner === 'Draw') {
                winningPlayer.textContent = 'Empate!';
            } else {
                winningPlayer.textContent = `${winner} venceu!`;
            }
        } else {
            changePLayer();
        }
    }
}

// reiniciando o jogo
function restartGame() {
    gameBoard = ['', '', '', '', '', '', '', '', ''];
    gameActive = true;
    currentPlayer = 'X';
    winningPlayer.textContent = '';
    buttons.forEach((buttons) => (button.textContent = ''));
}

// adicionando manipuladores de eventos aos botões
buttons.forEach((button, index) => {
    button.addEventListener('click', () => buttonClick(button, index));
});

// adicionando o evento ao botão reiniciar
restartButton.addEventListener('click', restartGame);

// função para iniciar o pvp
function initializaGamePvP() {
    gameBoard = ['', '', '', '', '', '', '', '', ''];
    gameActive = true;
    currentPlayer = 'X';
    winningPlayer.textContent = '';

    // adicionanod o evento de clique aos botões novamente
    buttons.forEach((button, index) => {
        button.addEventListener('click', () => buttonClick(button, index));
    });
}