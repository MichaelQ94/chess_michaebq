#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <vector>
#include "chessboard.h"
#include "chessboardsquare.h"
using namespace std;

class ChessBoard;
class ChessBoardSquare;

class ChessPiece
{
	protected:

		char piece_type; //P = pawn, N = knight, B = bishop, R = rook, Q = queen, K = king
		char piece_color; //W = white, B = black
		int value_; //pawn-1, knight-3, bishop-3, rook-5, queen-9, king-(-1)
		bool captured_; //false if on board (default)
		ChessBoardSquare *square_;
		ChessBoard* board_;
		
	public:
		ChessPiece(ChessBoard *board, char type, char color, int value);
		char type();
		char color();
		int value();
		bool captured();
		void isCaptured();
		virtual bool hasMoved();
		virtual bool enPassant();
		virtual void reset(); //used to reset the hasMoved conditions on pieces after their initial placement on the board
		void copyData(ChessPiece *piece);
		
		virtual void move(ChessBoardSquare *dest);
		virtual void refresh();
		virtual vector<int> legalMoves() = 0;
		virtual void promote(char type);
		
		virtual bool inCheck();
		virtual bool checkForCheck();
};

class ChessPiece_Pawn : public ChessPiece
{
	public:
		ChessPiece_Pawn(ChessBoard *board, char color);
		~ChessPiece_Pawn();
		vector<int> legalMoves();
		void move(ChessBoardSquare*);
		void refresh();
		void promote(char type);
		bool hasMoved();
		bool enPassant();
		void reset();
	private:
		ChessPiece *promoted_piece;
		bool hasMoved_;
		bool enPassant_;
};

class ChessPiece_Knight : public ChessPiece
{
	public:
		ChessPiece_Knight(ChessBoard *board, char color);
		vector<int> legalMoves();
};

class ChessPiece_Bishop : public ChessPiece
{
	public:
		ChessPiece_Bishop(ChessBoard *board, char color);
		vector<int> legalMoves();
};

class ChessPiece_Rook : public ChessPiece
{
	public:
		ChessPiece_Rook(ChessBoard *board, char color);
		vector<int> legalMoves();
		void move(ChessBoardSquare *dest);
		bool hasMoved();
		void reset();
	private:
		bool hasMoved_;
};

class ChessPiece_Queen : public ChessPiece
{
	public:
		ChessPiece_Queen(ChessBoard *board, char color);
		vector<int> legalMoves();
};

class ChessPiece_King : public ChessPiece
{
	public:
		ChessPiece_King(ChessBoard *board, char color);
		vector<int> legalMoves();
		void move(ChessBoardSquare *dest);
		bool inCheck();
		bool checkForCheck();
		bool hasMoved();
		void reset();
	private:
		bool inCheck_;
		bool hasMoved_;
};
#endif
