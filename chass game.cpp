
#include <iostream>
#include <string>

class ChessBoard {
public:
    char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    void printBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

class ChessPiece {
public:
    char symbol;
    int color;
    int x, y;

    ChessPiece(char symbol, int color, int x, int y) {
        this->symbol = symbol;
        this->color = color;
        this->x = x;
        this->y = y;
    }
};

class King : public ChessPiece {
public:
    King(int color, int x, int y) : ChessPiece('K', color, x, y) {}
};

class Queen : public ChessPiece {
public:
    Queen(int color, int x, int y) : ChessPiece('Q', color, x, y) {}
};

class Pawn : public ChessPiece {
public:
    Pawn(int color, int x, int y) : ChessPiece('P', color, x, y) {}
};

class ChessGame {
public:
    ChessBoard board;
    ChessPiece* pieces[32];
    int turn;

    ChessGame() {
        turn = 0;
        for (int i = 0; i < 16; i++) {
            pieces[i] = new Pawn(0, i, 1);
        }
        for (int i = 16; i < 32; i++) {
            pieces[i] = new Pawn(1, i, 6);
        }
    }

    void makeMove(int from_x, int from_y, int to_x, int to_y) {
        ChessPiece* piece = getPiece(from_x, from_y);
        if (piece == nullptr || piece->color != turn) {
            return;
        }
        board.board[to_y][to_x] = piece->symbol;
        board.board[from_y][from_x] = ' ';
        piece->x = to_x;
        piece->y = to_y;
        turn = 1 - turn;
    }

    bool isValidMove(int from_x, int from_y, int to_x, int to_y) {
        ChessPiece* piece = getPiece(from_x, from_y);
        if (piece == nullptr || piece->color != turn) {
            return false;
        }
        return true;
    }

    ChessPiece* getPiece(int x, int y) {
        for (int i = 0; i < 32; i++) {
            if (pieces[i]->x == x && pieces[i]->y == y) {
                return pieces[i];
            }
        }
        return nullptr;
    }
};

int main() {
    ChessGame game;
    while (true) {
        game.board.printBoard();
        int from_x, from_y, to_x, to_y;
        std::cout << "Enter move (from_x from_y to_x to_y): ";
        std::cin >> from_x >> from_y >> to_x >> to_y;
        game.makeMove(from_x, from_y, to_x, to_y);
    }
    return 0;
}



