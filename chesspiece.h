#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <vector>
#include "chessboard.h"
#include "chessboardsquare.h"
#include "chessmove.h"
using namespace std;

/**Class to handle the collection of all squares and pieces*/
class ChessBoard;
/**Class used to represent a single square on the board*/
class ChessBoardSquare;
/**Class used to represent a single move on the board*/
class ChessMove;

/**Class used to handle generic chess piece functionality.
 */
class ChessPiece
{
	protected:
		/**P = pawn, N = knight, B = bishop, R = rook, Q = queen, K = king*/
		char piece_type;
		/**W = white, B = black*/
		char piece_color;
		/**pawn-1, knight-3, bishop-3, rook-5, queen-9, king-(-1)*/
		int value_;
		/**false if on board (default), true if the piece has been captured*/
		bool captured_;
		/**Reference to the square occupied by this piece*/
		ChessBoardSquare *square_;
		/**Reference to the board containing this piece*/
		ChessBoard* board_;
		
	public:
		ChessPiece(ChessBoard *board, char type, char color, int value);
		ChessPiece(ChessBoard *board, ChessPiece *piece);
		char type();
		char color();
		int value();
		bool captured();
		void isCaptured();
		ChessBoardSquare* square();
		virtual bool hasMoved();
		virtual bool enPassant();
		virtual void reset(); //used to reset the hasMoved conditions on pieces after their initial placement on the board
		void copyData(ChessPiece *piece);
		
		virtual void move(ChessBoardSquare *dest);
		virtual void cmove(ChessBoardSquare *dest);
		virtual void refresh();
		/**Returns a list of all legal moves which can be made by this piece*/
		virtual vector<int> legalMoves() = 0;
		virtual void promote(char type);
		
		virtual bool inCheck();
		virtual bool checkForCheck();
};

/**Class used to handle pawn-specific functionality*/
class ChessPiece_Pawn : public ChessPiece
{
	public:
		ChessPiece_Pawn(ChessBoard *board, char color);
		ChessPiece_Pawn(ChessBoard *board, ChessPiece_Pawn *piece);
		~ChessPiece_Pawn();
		vector<int> legalMoves();
		void move(ChessBoardSquare*);
		void cmove(ChessBoardSquare*);
		void refresh();
		void promote(char type);
		bool hasMoved();
		bool enPassant();
		void reset();
	private:
		/**Used to handle pawn promotions. Set to NULL for a normal pawn (default) and can be dynamically
		 * instantiated as a queen, rook, bishop, or knight at the time of promotion.
		 */
		ChessPiece *promoted_piece;
		/**True if the pawn has moved, false if not (default)*/
		bool hasMoved_;
		/**True if the pawn has just moved up two squares and is capable of being captured via en passant*/
		bool enPassant_;
};

/**Class used to handle knight-specific functionality*/
class ChessPiece_Knight : public ChessPiece
{
	public:
		ChessPiece_Knight(ChessBoard *board, char color);
		ChessPiece_Knight(ChessBoard *board, ChessPiece_Knight *piece);
		vector<int> legalMoves();
};

/**Class used to handle bishop-specific functionality*/
class ChessPiece_Bishop : public ChessPiece
{
	public:
		ChessPiece_Bishop(ChessBoard *board, char color);
		ChessPiece_Bishop(ChessBoard *board, ChessPiece_Bishop *piece);
		vector<int> legalMoves();
};

/**Class used to handle rook-specific functionality*/
class ChessPiece_Rook : public ChessPiece
{
	public:
		ChessPiece_Rook(ChessBoard *board, char color);
		ChessPiece_Rook(ChessBoard *board, ChessPiece_Rook *piece);
		vector<int> legalMoves();
		void move(ChessBoardSquare *dest);
		void cmove(ChessBoardSquare*);
		bool hasMoved();
		void reset();
	private:
		/**True if the rook has moved, false if not (default)*/
		bool hasMoved_;
};

/**Class used to handle queen-specific functionality*/
class ChessPiece_Queen : public ChessPiece
{
	public:
		ChessPiece_Queen(ChessBoard *board, char color);
		ChessPiece_Queen(ChessBoard *board, ChessPiece_Queen *piece);
		vector<int> legalMoves();
};

/**Class used to handle king-specific functionality*/
class ChessPiece_King : public ChessPiece
{
	public:
		ChessPiece_King(ChessBoard *board, char color);
		ChessPiece_King(ChessBoard *board, ChessPiece_King *piece);
		vector<int> legalMoves();
		void move(ChessBoardSquare *dest);
		void cmove(ChessBoardSquare*);
		bool inCheck();
		bool checkForCheck();
		bool hasMoved();
		void reset();
	private:
		/**True if there is an enemy piece which is able to capture the king*/
		bool inCheck_;
		/**True if the king has moved, false if not (default)*/
		bool hasMoved_;
};
#endif
