#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "chessboard.h"
#include "chessboardsquare.h"

class ChessBoard;
class ChessBoardSquare;

class ChessPiece
{
	private:

		char piece_type; //P = pawn, N = knight, B = bishop, R = rook, Q = queen, K = king
		char piece_color; //W = white, B = black
		int value_; //pawn-1, knight-3, bishop-3, rook-5, queen-9, king-(-1)
		bool captured_; //false if on board (default)
		ChessBoardSquare *square_;
		
	public:
		ChessPiece(char type, char color, int value);
		char type();
		char color();
		int value();
		bool captured();
		void isCaptured();
		
		void move(ChessBoardSquare *dest);
		
};

class ChessPiece_Pawn : public ChessPiece
{
	public:
		ChessPiece_Pawn(char color);
		~ChessPiece_Pawn();
	private:
		ChessPiece *promoted_piece;
};

class ChessPiece_Knight : public ChessPiece
{
	public:
		ChessPiece_Knight(char color);
};

class ChessPiece_Bishop : public ChessPiece
{
	public:
		ChessPiece_Bishop(char color);
};

class ChessPiece_Rook : public ChessPiece
{
	public:
		ChessPiece_Rook(char color);
};

class ChessPiece_Queen : public ChessPiece
{
	public:
		ChessPiece_Queen(char color);
};

class ChessPiece_King : public ChessPiece
{
	public:
		ChessPiece_King(char color);
		bool inCheck();
		void check();
		void outOfCheck();
	private:
		bool inCheck_;
};
#endif
