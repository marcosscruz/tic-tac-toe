import tkinter as tk
from tkinter import messagebox

class TicTacToe:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("Jogo da Velha")

        self.turn = "X"
        self.board = [[" " for _ in range(3)] for _ in range(3)]

        for i in range(3):
            for j in range(3):
                btn = tk.Button(self.window, text=" ", font=("Open Sans", 30), width=5, height=2, command=lambda line=i, pillar=j: self.make_move(line, pillar))
                btn.grid(row=i, column=j)

        self.window.mainloop()

    def make_move(self, line, pillar):
        if self.board[line][pillar] == " ":
            self.board[line][pillar] = self.turn
            self.update_button(line, pillar)
            
            if self.check_victory():
                messagebox.showinfo("Fim do Jogo", f"Jogador {self.turn} venceu!")
                self.restar_game()
            elif self.check_draw():
                messagebox.showinfo("Fim do Jogo", "O jogo terminou em empate!")
                self.restar_game()
            else:
                self.turn = "O" if self.turn == "X" else "X"

    def update_button(self, line, pillar):
        btn = self.window.grid_slaves(row=line, column=pillar)[0]
        btn.config(text=self.turn, state="disabled")

    def check_victory(self):
        # Verifica lines e pillars
        for i in range(3):
            if all(self.board[i][j] == self.turn for j in range(3)) or all(self.board[j][i] == self.turn for j in range(3)):
                return True

        # Verifica diagonais
        if all(self.board[i][i] == self.turn for i in range(3)) or all(self.board[i][2 - i] == self.turn for i in range(3)):
            return True

        return False

    def check_draw(self):
        return all(self.board[i][j] != " " for i in range(3) for j in range(3))

    def restar_game(self):
        self.turn = "X"
        self.board = [[" " for _ in range(3)] for _ in range(3)]

        for i in range(3):
            for j in range(3):
                btn = self.window.grid_slaves(row=i, column=j)[0]
                btn.config(text=" ", state="active")

if __name__ == "__main__":
    game_mode = input('Escolha o modo de Jogo: \n\t1. PvP \n\t2. PvIA')