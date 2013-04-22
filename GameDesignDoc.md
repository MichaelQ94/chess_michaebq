# Michael Qian PA5 - Chess

## Player
+ 2 players per game: 1 black, 1 white
+ Each player owns a set of 8 pawns, 2 knights, 2 bishops, 2 rooks, 1 queen, and 1 king

## Gameplay
+ 2 Players: Either human vs. human or human vs. computer (AI)
  + AI will be partially implemented in PA5 and completed in PA6
+ Players take turns making moves (white player moves first)
+ Game-ending conditions:
  + Checkmate: a player's king is in check and cannot get out of check in one turn. In this case, the other player wins.
  + Stalemate: a player's king is not in check but there are no legal moves available. This results in a draw.
+ A player clicks on a piece to select it, and then clicks the destination square to move the piece
  + The move will only be executed if it is legal
  + Moving to a square which contains a piece will result in that piece being captured
+ Players will be given the option to use a clock during the game, allowing for timed gameplay
  + This will result in each player having a set amount of time which counts down during that player's turn
+ The board will be embedded in a QMainWindow
  + Toolbar at the top will contain a "start new game" button as well as a "quit" button
  + Radio buttons will be provided to allow players to select either human vs. human or human vs. computer
  + A text field allows players to enter a time setting if they wish to use a clock. Entering 0 or any text which is not a number will result in no clock.
  + Each player will have a text field indicating the total score of the pieces captured
  + A text on the side will keep track of the moves played using algebraic chess notation

![alt text](http://www.reviewboardgames.com/media/setting-up-a-chess-board.gif "Initial chess board setup")

## Board
+ 8x8 board containing alternating black and white squares
+ Each board square will be an object which can contain a chess piece
+ Pieces are not allowed to move off of the board

## Pieces

### Pawn
+ Worth 1 point
+ Can only move forward 1 square at a time
  + If the pawn has not yet moved, moving ahead 2 squares is allowed for just the first move
+ Can only capture diagonally forward

![alt text](http://0.tqn.com/d/chess/1/0/8/-/-/-/PawnMoves.gif "Legal pawn moves. Dots denote legal movements while crosses denote legal captures.")

+ En passant:
  + If a pawn moves up 2 squares on its first move, and is left either to the immediate left or immediate right of an enemy pawn,
  that pawn is allowed to capture this pawn by moving diagonally behind it
  
  ![alt text](http://0.tqn.com/d/chess/1/0/L/-/-/-/Enpassant.gif "En passant")
  
### Knight
+ Worth 3 points
+ Moves and captures in an "L" shape
  + Must move 2 squares either vertically and horizontally, and then 1 square horizontally (if the first move was vertical) or vertically (if the first move was horizontal)
  + Passes through all other pieces to its destination
  + Cannot land on a friendly piece, but can land on an enemy piece (in which case the enemy piece is captured)

![alt text](http://0.tqn.com/d/chess/1/0/6/-/-/-/KnightMoves.gif "Legal knight moves")

### Bishop
+ Worth 3 points
+ Moves and captures diagonally
+ Cannot pass through other pieces
  + Can move through as many unoccupied squares in succession as possible, but must stop if it reaches an occupied square
  + Can only move in one direction per turn

![alt text](http://0.tqn.com/d/chess/1/0/3/-/-/-/BishopMoves.gif "Legal bishop moves")

### Rook
+ Worth 5 points
+ Moves and captures both vertically and horizontally
+ Cannot pass through other pieces
  + Can move through as many unoccupied squares in succession as possible, but must stop if it reaches an occupied square
  + Can only move in one direction per turn

![alt text](http://0.tqn.com/d/chess/1/0/1/-/-/-/RookMoves.gif "Legal rook moves")

### Queen
+ Worth 9 points
+ Moves and captures vertically, horizontally, and diagonally
+ Cannot pass through other pieces
  + Can move through as many unoccupied squares in succession as possible, but must stop if it reaches an occupied square
  + Can only move in one direction per turn

![alt text](http://0.tqn.com/d/chess/1/0/4/-/-/-/QueenMoves.gif "Legal queen moves")

### King
+ Does not have a point value becuase having the king is never actually captured
+ Moves and captures vertically, horizontally, and diagonally
  + Can only move in one direction per turn
  + Can only move one square per turn
  
  ![alt text](http://0.tqn.com/d/chess/1/0/5/-/-/-/KingMoves.gif "Legal king moves")

+ Castling
  + If the king has not moved and one of the rooks has also not moved, and there are no pieces in between them, 
  the king is allowed to move 2 squares in the direction of the rook, with the rook moving so that it is one square on the other side of the king
  
  ![alt text](http://www.pressmantoy.com/instructions/chess_spec1.jpg "Castling")

+ A king is in check if there is an enemy piece which currently has the ability to capture it
  + Kings cannot move into check
  + Kings cannot castle if it would involve moving through squares on which they would be in check
  + Kings cannot castle if it would result in moving to a square on which they would be in check

