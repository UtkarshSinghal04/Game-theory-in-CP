# Nim Game

### Game Description:
The **Nim Game** is a two-player game played with multiple heaps of sticks.  
Each player takes turns, and during their turn, they:
1. Select one heap that contains sticks.
2. Remove any number of sticks from that heap (at least one stick).

The player who removes the last stick wins the game.

---

### Game States:
- The state of the game is represented as `[x1, x2, ..., xn]`, where `xk` denotes the number of sticks in heap `k`.
- For example, the state `[10, 12, 5]` represents three heaps with 10, 12, and 5 sticks respectively.

---

### Winning and Losing States:
1. **Losing States:**
   - The state `[0, 0, ..., 0]` is a losing state because there are no moves left for the player.
   - Any move from a losing state leads to a winning state.

2. **Winning States:**
   - A state is a winning state if it is possible to move to a losing state in one move.
   - This is determined by the **nim sum**:
     - `nim sum (s) = x1 ⊕ x2 ⊕ ... ⊕ xn` (where `⊕` is the XOR operation).
   - If `s = 0`, the state is a **losing state**.  
   - If `s ≠ 0`, the state is a **winning state**.

---

### Strategy:
1. **Determine the Nim Sum:**
   - Compute `s = x1 ⊕ x2 ⊕ ... ⊕ xn`.
2. **If `s = 0`:**
   - The current player will lose if the opponent plays optimally.
3. **If `s ≠ 0`:**
   - Identify a heap `k` such that `xk ⊕ s < xk`.
   - Remove sticks from heap `k` so that it contains `xk ⊕ s` sticks.  
   - This will lead to a losing state for the opponent.

---

### Example:
#### Initial State:
`A = [10, 12, 5]`

1. **Compute the Nim Sum:**
   - `s = 10 ⊕ 12 ⊕ 5 = 3`
   - Since `s ≠ 0`, this is a winning state.

2. **Move to a Losing State:**
   - Choose a heap `k` where `xk ⊕ s < xk`.
   - For example, in heap 1:
     - `10 ⊕ 3 = 9` and `9 < 10`
   - Remove sticks so that heap 1 contains `9` sticks.
   - New state: `[9, 12, 5]`

