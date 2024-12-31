# Sprague-Grundy Theorem:

The **Sprague-Grundy Theorem** states that in a composite game (made up of multiple sub-games), if the XOR of the Grundy Numbers of the initial positions in all sub-games is:
- **Non-zero**: The player starting first will **win** if they play optimally.
- **Zero**: The player starting first will **lose**, no matter what.

This theorem allows us to determine the winner of any impartial game where players play optimally.

---

### Steps to Apply the Sprague-Grundy Theorem:
1. **Break the Composite Game into Sub-Games**:
   - Each sub-game is treated independently.
   
2. **Calculate the Grundy Number for Each Sub-Game**:
   - Use the rules of each sub-game to compute its Grundy Number.

3. **Compute the XOR of All Grundy Numbers**:
   - Combine the Grundy Numbers of all sub-games using the XOR operation.

4. **Determine the Winner**:
   - If the XOR value is **non-zero**, the first player wins.
   - If the XOR value is **zero**, the second player wins.

---

### Example Game:
#### Description:
The game starts with **3 piles** containing `3`, `4`, and `5` stones.  
The player to move may take any positive number of stones (up to `3`) from any pile.  
The last player to move wins.

---

### Solution:

#### Step 1: Treat Each Pile as a Sub-Game
- Sub-game 1: Pile with `3` stones.
- Sub-game 2: Pile with `4` stones.
- Sub-game 3: Pile with `5` stones.

#### Step 2: Calculate Grundy Numbers for Each Sub-Game

##### Summary Table of Grundy Numbers:
| **N**  | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 |
|--------|----|----|----|----|----|----|----|----|----|----|----|
| **Grundy (n)** | 0  | 1  | 2  | 3  | 0  | 1  | 2  | 3  | 0  | 1  | 2  |

Using the rules of the game:
- **Grundy(3) = 3**
- **Grundy(4) = 0**
- **Grundy(5) = 1**

#### Step 3: Compute the XOR of Grundy Numbers
- XOR: `Grundy(3) ⊕ Grundy(4) ⊕ Grundy(5) = 3 ⊕ 0 ⊕ 1 = 2`

#### Step 4: Determine the Winner
- Since the XOR value is **non-zero** (`2`), the **first player wins** if they play optimally.

