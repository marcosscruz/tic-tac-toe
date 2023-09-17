// variáveis globais
const board = document.getElementById("board");
const cells = [];
let currentPlayer = "X";
let winner = null;

// criando o tabuleiro
function createBoard() {
    for (let i = 0; i < 9; i++) {
        const cell = document.createElement("div");
        cell.classList.add("cell");
        cell.dataset.index = i;
        cell.addEventListener("click", () => handleCellClick(i));
        board.appendChild(cell);
        cells.push(cell);
    }
}

// clique na célula
function handleCellClick(index) {
    if (!winner && !cells[index].textContent) {
        cells[index].textContent = currentPlayer;
        checkWinner();
        currentPlayer = currentPlayer === "X" ? "O" : "X";
    }
}

// verificando se alguém venceu
function checkWinner() {
    const winPatterns = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8], // linhas
        [0, 3, 6], [1, 4, 7], [2, 5, 8], // colunas
        [0, 4, 8], [2, 4, 6]             // diagonais
    ];

    for (const pattern of winPatterns) {
        const [a, b, c] = pattern;
        if (cells[a].textContent && cells[a].textContent === cells[b].textContent && cells[a].textContent === cells[c].textContent) {
            winner = currentPlayer;
            setTimeout(() => alert(`Jogador ${winner} venceu!`), 10);
            return;
        }
    }

    if (!cells.some(cell => !cell.textContent)) {
        setTimeout(() => alert("O jogo empatou!"), 10);
    }
}

// iniciando o jogo com base no modo escolhido
function startGame() {
    const gameMode = document.getElementById("game-mode").value;
    resetBoard();

    if (gameMode === "player-vs-ai") {
        currentPlayer = "X"; // O jogador humano sempre começa quando jogando contra a máquina
        playAgainstAI();
    } else {
        currentPlayer = "X"; // O primeiro jogador sempre começa no modo jogador contra jogador
    }
}

// resetando o tabuleiro
function resetBoard() {
    cells.forEach(cell => {
        cell.textContent = "";
    });
    winner = null;
}

// jogada da máquina (IA simples)
function playAgainstAI() {
    if (!winner) {
        setTimeout(() => {
            const availableCells = cells.filter(cell => !cell.textContent);
            if (availableCells.length > 0) {
                const randomIndex = Math.floor(Math.random() * availableCells.length);
                handleCellClick(parseInt(availableCells[randomIndex].dataset.index));
            }
        }, 500);
    }
}

document.getElementById("start-button").addEventListener("click", startGame);

// inicializando o jogo
createBoard();