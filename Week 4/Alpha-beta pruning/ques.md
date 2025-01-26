Objective: Enhance the Minimax algorithm to determine the optimal move for the maximizing player while skipping unnecessary nodes using Alpha-Beta Pruning.

Alpha-Beta Pruning Requirements:

Add two additional parameters alpha and beta to the minimax function:

alpha: The best value that the maximizer can guarantee so far.
beta: The best value that the minimizer can guarantee so far.
Prune branches where:

A branch leads to a score worse than alpha for the maximizer.
A branch leads to a score worse than beta for the minimizer.
Modify the algorithm:

For the maximizing player, initialize bestVal = -infinity. Update alpha during the recursion.
For the minimizing player, initialize bestVal = +infinity. Update beta during the recursion.
Stop exploring further when beta <= alpha (pruning condition).

