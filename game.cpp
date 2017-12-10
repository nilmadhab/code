#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <windows.h>
using namespace std;
void SetColor(int fgColor, int bgColor) {
    WORD wColor = ((bgColor & 0x0F) << 4) + (fgColor & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
enum PieceType { // Types of pieces
    SINGLE,
    KING
};
enum PieceColor { // Colors of players/pieces
    BLACK,
    WHITE
};
enum GameState { // Possible states of a game
    BLACK_TO_MOVE,
    WHITE_TO_MOVE,
    BLACK_WON,
    WHITE_WON,
    DRAW
};
enum Direction { // Possible direction for player move
    UP,
    DOWN,
    BOTH // for king piece
};

class Piece {
public:
    Piece(PieceColor);                           // Create a new single piece
    void makeKing();                             // Convert a single into king
    PieceType getType() const;                   // Type accessor
    PieceColor getColor() const;                 // Color accessor
private:
    PieceType type;
    PieceColor color;
};
Piece::Piece(PieceColor color) {
    // Initially each piece type is single type
    type = SINGLE;
    this->color = color;
}
void Piece::makeKing() { type = KING; }
PieceType Piece::getType() const { return type; }
PieceColor Piece::getColor() const { return color; }
 
class Board {
public:
    Board(int boardSize = 12);                     // Create a new empty board
    ~Board();                                     // Destructor
    bool isEmpty(int x, int y) const;             // Check if cell (x,y) is empty
    Piece* getPiece(int x, int y);                // Get piece at cell (x,y)
    const Piece* getPiece(int x, int y) const;    // Const version
    void setPiece(int x, int y, Piece* piece);    // Set a piece at cell (x,y)
    void removePiece(int x, int y);               // Remove piece from cell (x,y)
    int getBoardSize() const;
    void clear();
private:
    void validateIndices(int x, int y);
    void validateIndices(int x, int y) const;
    Piece*** cells;//[BOARD_SIZE][BOARD_SIZE];
    int boardSize;
};
void Board::validateIndices(int x, int y) {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) throw runtime_error("Index out of bound");
}
void Board::validateIndices(int x, int y) const {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) throw runtime_error("Index out of bound");
}

Board::Board(int boardSize) {
    if (boardSize < 12) throw runtime_error("Board size must be at least 8");
    this->boardSize = boardSize;
    cells = new Piece**[boardSize];
    for (int x = 0; x < boardSize; ++x) {
        cells[x] = new Piece*[boardSize];
        for (int y = 0; y < boardSize; ++y) {
            cells[x][y] = NULL; // Empty cell
        }
    }
}
Board::~Board() {
    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            delete cells[x][y];
        }
        delete[] cells[x];
    }
    delete[] cells;
}
bool Board::isEmpty(int x, int y) const {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) return false;
    return cells[x][y] == NULL;
}
Piece* Board::getPiece(int x, int y) {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) return NULL;
    return cells[x][y];
}
const Piece* Board::getPiece(int x, int y) const {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) return NULL;
    return cells[x][y];
}
void Board::setPiece(int x, int y, Piece* piece) {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) return;
    removePiece(x, y);
    cells[x][y] = piece;
}
void Board::removePiece(int x, int y) {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) return;
    //validateIndices(x, y);
    //delete cells[x][y];
    cells[x][y] = NULL;
}
int Board::getBoardSize() const { return boardSize; }
void Board::clear() {
    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            delete cells[x][y];
            cells[x][y] = NULL;
        }
    }
}

class Move {
public:
    Move(int xFrom, int yFrom, int xTo, int yTo); // Create a new move
    ~Move();                                      // Destroy move
    void append(Move* move);                       // Append next move in a sequence of jumps
    int getXFrom() const;                         // X coordinate of start accessor
    int getYFrom() const;                         // Y coordinate of start accessor
    int getXTo() const;                           // X coordinate of finish accessor
    int getYTo() const;                           // Y coordinate of finish accessor
    const Move* getNext() const;                  // Next move accessor
private:
    int xFrom, yFrom, xTo, yTo;
    Move* next;
};
Move::Move(int xFrom, int yFrom, int xTo, int yTo) {
    this->xFrom = xFrom;
    this->yFrom = yFrom;
    this->xTo = xTo;
    this->yTo = yTo;
    next = NULL;
}
Move::~Move() {
    while (next != NULL) {
        Move* cur = next;
        next = next->next;
        delete cur;
    }
    next = NULL;
}
void Move::append(Move* move) {
    if (next == NULL) {
        next = move;
    }
    else {
        Move* cur = next;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = move;
    }
}
int Move::getXFrom() const { return xFrom; }
int Move::getYFrom() const { return yFrom; }
int Move::getXTo() const { return xTo; }
int Move::getYTo() const { return yTo; }
const Move* Move::getNext() const { return next; }

class Player {
public:
    Player(string, PieceColor);                   // Create a new player
    virtual Move* makeMove(Board const&);         // Request player for a move
    string getName() const;                       // Name accessor
    Direction getDirection() const;
private:
    Move* constructMove(int xFrom, int yFrom, int xTo, int yTo, Board const& board);
    string name;
    PieceColor color;
    Direction dir;
};
Player::Player(string name, PieceColor color) {
    this->name = name;
    this->color = color;
    dir = (color == BLACK ? UP : DOWN);
}
Direction Player::getDirection() const { return dir; }
Move* Player::constructMove(int xFrom, int yFrom, int xTo, int yTo, Board const& board) {
    if (xFrom < 0 || xFrom >= board.getBoardSize() || xTo < 0 || xTo >= board.getBoardSize()
        || yFrom < 0 || yFrom >= board.getBoardSize() || yTo < 0 || yTo >= board.getBoardSize())
        return NULL;
    const Piece* piece = board.getPiece(xTo, yTo);
    if (piece == NULL) { // Empty cell is always valid move
        return new Move(xFrom, yFrom, xTo, yTo);
    }
    if (piece->getColor() != this->color) { // Enemy piece
        int dy = yTo - yFrom; // Positive -> right diagonal, negative -> left
        switch (dir) {
        case UP:
        {
            if (!(xTo - 1 >= 0 && yTo + dy >= 0 && yTo + dy < board.getBoardSize()))
                return NULL;
            const Piece* afterEnemy = board.getPiece(xTo - 1, yTo + dy);
            // We can kill current enemy piece only if we can obtain empty cell after current move
            if (afterEnemy != NULL) return NULL;
            Move* move = new Move(xFrom, yFrom, xTo - 1, yTo + dy);
            Move* next = constructMove(xTo - 1, yTo + dy, xTo - 2, yTo + dy * 2, board);
            if (next != NULL)
                move->append(next);
            return move;
        }
            break;
        case DOWN:
        {
            if (!(xTo + 1 < board.getBoardSize() && yTo + dy >= 0 && yTo + dy < board.getBoardSize()))
                return NULL;
            const Piece* afterEnemy = board.getPiece(xTo + 1, yTo + dy);
            // We can kill current enemy piece only if we can obtain empty cell after current move
            if (afterEnemy != NULL) return NULL;
            Move* move = new Move(xFrom, yFrom, xTo + 1, yTo + dy);
            Move* next = constructMove(xTo + 1, yTo + dy, xTo + 2, yTo + dy * 2, board);
            if (next != NULL)
                move->append(next);
            return move;
        }
            break;
        case BOTH: // King
            if (xTo - 1 >= 0 && yTo + dy >= 0 && yTo + dy < board.getBoardSize()) {
                const Piece* afterEnemy = board.getPiece(xTo - 1, yTo + dy);
                // We can kill current enemy piece only if we can obtain empty cell after current move
                if (afterEnemy != NULL) return NULL;
                Move* move = new Move(xFrom, yFrom, xTo - 1, yTo + dy);
                Move* next = constructMove(xTo - 1, yTo + dy, xTo - 2, yTo + dy * 2, board);
                if (next != NULL)
                    move->append(next);
                return move;
            }
            if (xTo + 1 < board.getBoardSize() && yTo + dy >= 0 && yTo + dy < board.getBoardSize()) {
                const Piece* afterEnemy = board.getPiece(xTo + 1, yTo + dy);
                // We can kill current enemy piece only if we can obtain empty cell after current move
                if (afterEnemy != NULL) return NULL;
                Move* move = new Move(xFrom, yFrom, xTo + 1, yTo + dy);
                Move* next = constructMove(xTo + 1, yTo + dy, xTo + 2, yTo + dy * 2, board);
                if (next != NULL)
                    move->append(next);
                return move;
            }
            return NULL;
            break;
        }
    }
    return NULL;
}
Move* Player::makeMove(Board const& board) {
    // Gather all pieces that available for current player
    vector<Move*> moves;
    map<const Piece*, pair<int, int> > pieces;
    for (int x = 0; x < board.getBoardSize(); ++x) {
        for (int y = 0; y < board.getBoardSize(); ++y) {
            // Skip empty cells and cells with different piece color
            if (board.isEmpty(x, y)) continue;
            const Piece* piece = board.getPiece(x, y);
            if (piece->getColor() != this->color) continue;
            // Piece color same as player color
            switch (dir) {
            case UP:
                {
                    // Trying to construct move for top right cell
                    if (x - 1 >= 0 && y + 1 < board.getBoardSize()) {
                        Move* move = constructMove(x, y, x - 1, y + 1, board);
                        if (move != NULL) { moves.push_back(move); }
                    }
                    // Trying to construct move for top left cell
                    if (x - 1 >= 0 && y - 1 >= 0) {
                        Move* move = constructMove(x, y, x - 1, y - 1, board);
                        if (move != NULL) { moves.push_back(move); }
                    }
                }
                break;
            case DOWN:
                // Trying to construct move for bottom right cell
                if (x + 1 < board.getBoardSize() && y + 1 < board.getBoardSize()) {
                    Move* move = constructMove(x, y, x + 1, y + 1, board);
                    if (move != NULL) { moves.push_back(move); }
                }
                // Trying to construct move for bottom left cell
                if (x + 1 < board.getBoardSize() && y - 1 >= 0) {
                    Move* move = constructMove(x, y, x + 1, y - 1, board);
                    if (move != NULL) { moves.push_back(move); }
                }
                break;
            case BOTH: // King
            {
                // From current pos to all posible position to the top right
                for (int xx = x, yy = y; xx >= 0 && yy < board.getBoardSize(); --xx, ++yy) {
                    Move* move = constructMove(x, y, xx, yy, board);
                    if (move != NULL) { moves.push_back(move); }
                }
                // From current pos to all posible position to the top left
                for (int xx = x, yy = y; xx >= 0 && yy >= 0; --xx, --yy) {
                    Move* move = constructMove(x, y, xx, yy, board);
                    if (move != NULL) { moves.push_back(move); }
                }
                // From current pos to all posible position to the bottom right
                for (int xx = x, yy = y; xx < board.getBoardSize() && yy < board.getBoardSize(); ++xx, ++yy) {
                    Move* move = constructMove(x, y, xx, yy, board);
                    if (move != NULL) { moves.push_back(move); }
                }
                // From current pos to all posible position to the bottom left
                for (int xx = x, yy = y; xx < board.getBoardSize() && yy >= 0; ++xx, --yy) {
                    Move* move = constructMove(x, y, xx, yy, board);
                    if (move != NULL) { moves.push_back(move); }
                }
            }
                break;
            }
        }
    }
    if (moves.empty()) return NULL;
    cout << "Choose piece to move: " << endl;
    for (size_t i = 0; i < moves.size(); ++i) {
        cout << i << ". " << moves[i]->getXFrom() << " " << moves[i]->getYFrom() << " -> "
            << moves[i]->getXTo() << " " << moves[i]->getYTo() << endl;
    }
    int pos;
    do {
        cin >> pos;
    } while (pos < 0 || pos >= moves.size());
    Move* selected = moves[pos];
    for (size_t i = 0; i < moves.size(); ++i) {
        if (i == pos) continue;
        delete moves[i];
    }
    return selected;
}
string Player::getName() const { return name; }
class Game {
public:
    Game(Player*, Player*);                       // Create a new game and set players
    void init();                                  // Places pieces on board at initial positions
    GameState getState();                         // Checks the current state of a game
    Player* getCurrentPlayer();                   // Retrieves current player
    Board const& getBoard() const;                // Retrieves a board
    bool makeMove(Move* move);                    // Validates and performs a move
    int evaluateScore(PieceColor color) const;
private:
    PieceColor currentPlayerColor;
    GameState state;
    Player* black;
    Player* white;
    Board board;
};
int Game::evaluateScore(PieceColor color) const {
    int n = 0;
    for (int x = 0; x < board.getBoardSize(); ++x) {
        for (int y = 0; y < board.getBoardSize(); ++y) {
            if (board.isEmpty(x, y)) continue;
            const Piece* piece = board.getPiece(x, y);
            if (piece->getColor() == color) {
                if (piece->getType() == KING) // +5 for kings, +1 for single piece
                    n += 5;
                else
                    n++;
            }
        }
    }
    return n;
}
Game::Game(Player* black, Player* white) {
    currentPlayerColor = BLACK;
    state = BLACK_TO_MOVE;
    this->black = black;
    this->white = white;
}
void Game::init() {
    currentPlayerColor = BLACK;
    state = BLACK_TO_MOVE;
    board.clear();
    // Place black pieces
    for (int x = 0; x < board.getBoardSize(); x += 2) {
        board.setPiece(0, x, new Piece(WHITE));
        board.setPiece(1, x + 1, new Piece(WHITE));
        board.setPiece(2, x, new Piece(WHITE));
    }
    // Place white pieces
    for (int x = 0; x < board.getBoardSize(); x += 2) {
        board.setPiece(board.getBoardSize() - 1, x + 1, new Piece(BLACK));
        board.setPiece(board.getBoardSize() - 2, x, new Piece(BLACK));
        board.setPiece(board.getBoardSize() - 3, x + 1, new Piece(BLACK));
    }
}

GameState Game::getState() { return state; }
Player* Game::getCurrentPlayer() {
    if (currentPlayerColor == BLACK) return black;
    if (currentPlayerColor == WHITE) return white;
    return NULL;
}
Board const& Game::getBoard() const { return board; }
bool Game::makeMove(Move* move) {
    // No more moves for one of the players
    if (move == NULL) {
        int BlackScorer = evaluateScore(BLACK);
        int WhiteScorer = evaluateScore(WHITE);
        if (BlackScorer > WhiteScorer) {
            state = BLACK_WON;
        }
        else if (BlackScorer < WhiteScorer) {
            state = WHITE_WON;
        }
        else {
            state = DRAW;
        }
        return true;
    }
    // Apply move
    const Move* cur = move;
    while (cur != NULL) {
        Player* player = getCurrentPlayer();
        const Piece* piece = board.getPiece(move->getXFrom(), move->getYFrom());
        board.removePiece(move->getXFrom(), move->getYFrom());
        int delta = abs(move->getXFrom() - move->getXTo()) + abs(move->getYFrom() - move->getYTo());
        cout << move->getXFrom() - move->getXTo() << " " << move->getYFrom() - move->getYTo() << endl;
        board.setPiece(move->getXTo(), move->getYTo(), const_cast<Piece*>(piece));
        if ((currentPlayerColor == BLACK && move->getXTo() == 0) // BLACK piece become king
            || (currentPlayerColor == WHITE && move->getXTo() == board.getBoardSize() - 1) // WHITE piece become king
            ) {
            //cout << "KING" << endl;
            Piece* king = board.getPiece(move->getXTo(), move->getYTo());
            king->makeKing();
        }
        //cout << "DELTA: " << delta << endl;
        if (delta >= 4) { // Remove killed piece
            switch (player->getDirection()) {
            case UP:
            {
                int dy = move->getYTo() - move->getYFrom();
                if (dy < 0) {
                    const Piece*p = board.getPiece(move->getXFrom() - 1, move->getYFrom() - 1);
                    board.removePiece(move->getXFrom() - 1, move->getYFrom() - 1);
                    delete p;
                }
                else {
                    const Piece*p = board.getPiece(move->getXFrom() - 1, move->getYFrom() + 1);
                    board.removePiece(move->getXFrom() - 1, move->getYFrom() + 1);
                    delete p;
                }
            }
                break;
            case DOWN:
            {
                int dy = move->getYTo() - move->getYFrom();
                if (dy > 0) {
                    const Piece*p = board.getPiece(move->getXFrom() + 1, move->getYFrom() + 1);
                    board.removePiece(move->getXFrom() + 1, move->getYFrom() + 1);
                    delete p;
                }
                else {
                    const Piece*p = board.getPiece(move->getXFrom() + 1, move->getYFrom() - 1);
                    board.removePiece(move->getXFrom() + 1, move->getYFrom() - 1);
                    delete p;
                }
            }
                break;
            case BOTH: // King NOT IMPLEMENTED YET
                break;
            } // end remove dead piece
        }
        cur = cur->getNext();
        if (cur != NULL) {
            cout << "LINKED" << endl;
        }
    }
    move->~Move();
    // Next turn
    currentPlayerColor = (currentPlayerColor == BLACK ? WHITE : BLACK);
    state = (currentPlayerColor == BLACK ? WHITE_TO_MOVE : BLACK_TO_MOVE);
    return true;
}

class CheckBoard {
public:
    CheckBoard(Game* game);
    void drawBoard();
private:
    Game* game;
};
CheckBoard::CheckBoard(Game* game) { this->game = game; }
 
void CheckBoard::drawBoard() {
    SetColor(0x0f, 0);
    cout << " ";
    for (int x = 0; x < game->getBoard().getBoardSize(); ++x) {
        cout << " " << x;
    }
    cout << endl;
    for (int x = 0; x < game->getBoard().getBoardSize(); ++x) {
        cout << x ;
        for (int y = 0; y < game->getBoard().getBoardSize(); ++y) {
            if (y == 0) {
                SetColor(0x0f, 0);
                cout << "|";
            }
            const Piece* piece = game->getBoard().getPiece(x, y);
            if (piece == NULL) {
                SetColor(3, (x + y) % 2 == 0 ? 0 : 0x0F);
                cout << " ";
                SetColor(0x0f, 0);
                cout << "|";
            }
            else {
                SetColor(3, (x + y) % 2 == 0 ? 0 : 0x0F);
                string symb = (piece->getColor() == BLACK ? "b" : "w");
                if (piece->getType() == KING) transform(symb.begin(), symb.end(), symb.begin(), ::toupper);
                cout << symb;
                SetColor(0x0f, 0);
                cout << "|";
            }

        }
        cout << endl;
    }
    SetColor(0x0f, 0);
    Player* player = game->getCurrentPlayer();
    cout << endl << "Current turn: " << player->getName() << endl;
}
// Main program outline:
int main() {
    string name1 = "Player1", name2 = "Player2";
    /*cout << "Player1 name: ";
    getline(cin, name1);
    cout << "Player2 name: ";
    getline(cin, name2);
    system("cls");*/
    // Create players (humans or AI) and init a new game:
    Player* black = new Player(name1, BLACK); //= ... (obtain a black player)
    Player* white = new Player(name2, WHITE); // = ... (obtain a white player)
    Game game(black, white);
    game.init();
    CheckBoard checkboard(&game);
    // In a cycle allow players to make their moves until a win/draw condition
    bool gameOver = false;
    while (!gameOver) {
        checkboard.drawBoard();
        switch (game.getState()) { // Depending on current state of game...
        case BLACK_TO_MOVE: // Request black to make move
        case WHITE_TO_MOVE: // Request white to make move
        {
            Player* currentPlayer = game.getCurrentPlayer();
            Move* move;
            do { // Request for a move in a cycle until valid move is obtained
                move = currentPlayer->makeMove(game.getBoard());
            } while (!game.makeMove(move));
        }
        break;
        case BLACK_WON: // Tell black won
            cout << "Black player win" << endl;
            gameOver = true;
            break;
        case WHITE_WON: // Tell white won
                        //... (pronoun a player as winner)
            cout << "White player win" << endl;
            gameOver = true;
            break;
        case DRAW: // Tell no one won
                   //... (tell that no one won)
            cout << "Draft game" << endl;
            gameOver = true;
        }
    }
    delete black;
    delete white;
    return 0;
}