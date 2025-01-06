# Misère Game

### Game Description:
The **Misère Game** is a variation of the Nim game with a twist:  
The player who removes the **last stick loses the game**.

---

### Game States:
- Similar to the standard Nim game, the state is represented as `[x1, x2, ..., xn]`, where `xk` denotes the number of sticks in heap `k`.
- The game is played the same way as the standard Nim game until the endgame scenario, where the strategy changes.

---

### Winning and Losing States:
1. **Standard Play (Before the Endgame):**
   - Play the Misère game like the standard Nim game.
   - Compute the **nim sum**: `s = x1 ⊕ x2 ⊕ ... ⊕ xn`.
   - If `s = 0`, it is a **losing state**.
   - If `s ≠ 0`, it is a **winning state**.

2. **Endgame (Special Case):**
   - The **endgame** begins when every heap will contain at most **one stick** after the next move.
   - In this scenario:
     - In the **standard Nim game**, the strategy is to ensure an **even number of heaps** with one stick.
     - In the **Misère Nim game**, the strategy is to ensure an **odd number of heaps** with one stick.

---

### Strategy:
1. **Standard Play:**
   - Follow the same strategy as the standard Nim game:
     - If `s = 0`, you are in a losing state.
     - If `s ≠ 0`, choose a move that transitions to a losing state.

2. **Endgame Strategy:**
   - If each heap will have at most one stick after the next move:
     - Choose a move to leave an **odd number of heaps** with one stick.

---

### Example:
#### Initial State:
`A = [3, 4, 5]`

1. **Compute the Nim Sum:**
   - `s = 3 ⊕ 4 ⊕ 5 = 6`
   - Since `s ≠ 0`, this is a **winning state**.

2. **Make a Move:**
   - Identify a heap to move to a losing state.
   - For example, from heap 3 (5 sticks):
     - `5 ⊕ 6 = 3`
   - Remove 2 sticks from heap 3 to leave `[3, 4, 3]`.

3. **Endgame Transition:**
   - When the state transitions to a point where all heaps will have at most one stick:
     - Ensure there is an **odd number of heaps** with one stick.
