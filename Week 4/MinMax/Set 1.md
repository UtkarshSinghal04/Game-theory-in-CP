Implement the Minimax Algorithm to determine the optimal move for the maximizing player in a two-player turn-based game, given a binary tree structure of game states. Assume that the opponent (minimizing player) always plays optimally.

Problem Description:

The game is represented as a perfect binary tree with each node containing a score.
The maximizing player tries to maximize the score, while the minimizing player tries to minimize it.
Write a function to compute the optimal move for the maximizing player starting from the root.
Requirements:

Implement a recursive Minimax Algorithm that traverses the game tree.
Simulate the decision-making process for both the maximizing and minimizing players.
Return the best score the maximizing player can achieve and the optimal move direction (Left or Right).

Example Input:

# Game Tree:
#          Max
#        /     \
#      Min      Min
#     /  \     /   \
#    3    5   2     9

tree = {
    "root": {"left": {"left": 3, "right": 5}, "right": {"left": 2, "right": 9}}
}

Expected Output:

Optimal Score: 3
Optimal Move: Left
