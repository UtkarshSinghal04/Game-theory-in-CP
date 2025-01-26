Implement Zobrist Hashing for a two-player board game to generate a unique hash value for any given board configuration. This function will help efficiently store and retrieve evaluated board states in future game scenarios.

Problem Requirements:
The board is represented as a 2D matrix, where each cell can either be empty or contain a game piece.
Each type of piece (e.g., in chess: pawn, knight, rook) and cell position is mapped to a unique random number.
Use the XOR operation to calculate the hash value for the given board configuration.
If a piece is moved or removed, the hash value should be updated efficiently without recalculating it from scratch.

Input:
A 2D board matrix representing the current game state.
A pre-generated Zobrist hashing table containing random numbers for each board cell and piece type.

Output:
A unique hash value representing the current board configuration.

Example:
For a simple chess-like board:

Board: 
[
    ["Rook", "", "Knight"],
    ["", "Pawn", ""],
    ["", "", ""]
]
Random Numbers Table: 
[
    [rand1, rand2, rand3],  # Cell 1
    [rand4, rand5, rand6],  # Cell 2
    ...
]
The hash function should compute a unique hash value for the above board. If a move is made (e.g., "Knight" moves), update the hash using efficient XOR operations.

Constraints:
Use 64-bit random numbers for Zobrist hashing to minimize collisions.
Ensure the function can handle updates to the board state dynamically.

Bonus:
Implement a way to initialize the random numbers table dynamically.
Add functionality to verify that hash values for identical board states are consistent.
