## What is Mex?

**Minimum Excludant (Mex):**  
The `Mex` of a set of numbers is the smallest non-negative integer that is not present in the set.

### Example:
For the set `{0, 1, 3}`, the `Mex` is `2` (as it is the smallest non-negative integer not in the set).

---

## How to Calculate Grundy Numbers?

The **Grundy Number** for a game is defined as follows:

1. The Grundy Number is `0` for a game that is lost immediately by the first player.
2. For any other game, the Grundy Number is equal to the `Mex` of the Grundy Numbers of all possible next positions.

---

## Example 1: Calculating Grundy Numbers for a Stone Game

### Game Description:
The game starts with a pile of `n` stones.  
The player to move can take any positive number of stones.  
The last player to move wins.

### Grundy Number Calculation:

1. **Base Case:**
   - If the first player has `0` stones, they lose immediately.
     - `Grundy(0) = 0`

2. **For `1` Stone:**
   - The player can take all stones and win.
   - The next possible position is `0` stones.
     - `Grundy(1) = Mex({0}) = 1`

3. **For `2` Stones:**
   - The player can take `1` stone or all `2` stones and win.
   - The next possible positions are `1` and `0` stones.
     - `Grundy(2) = Mex({0, 1}) = 2`

4. **For `n` Stones:**
   - The player can take `1`, `2`, ..., or all `n` stones.
   - The next possible positions are `(n-1, n-2, ..., 0)` stones.
     - `Grundy(n) = Mex({0, 1, 2, ..., n-1}) = n`

### Summary Table of Grundy Numbers:
| **N**  | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 |
|--------|----|----|----|----|----|----|----|----|----|----|----|
| **Grundy (n)** | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 |

### Winning Strategy:
- If the initial Grundy Number of the pile is `0`, the first player loses if both players play optimally.
- If the initial Grundy Number is non-zero, the first player has a winning strategy.

---

## Example 2: Stone Game with a Constraint (Take Up to 3 Stones)

### Game Description:
The game starts with a pile of `n` stones.  
The player to move can take **any positive number of stones up to 3**.  
The last player to move wins.

### Grundy Number Calculation:

1. **Base Case:**
   - If the first player has `0` stones, they lose immediately.
     - `Grundy(0) = 0`

2. **For `1` Stone:**
   - The player can take all stones and win.
   - The next possible position is `0` stones.
     - `Grundy(1) = Mex({0}) = 1`

3. **For `2` Stones:**
   - The player can take `1` stone or `2` stones and win.
   - The next possible positions are `{1, 0}` stones.
     - `Grundy(2) = Mex({0, 1}) = 2`

4. **For `3` Stones:**
   - The player can take `1`, `2`, or all `3` stones and win.
   - The next possible positions are `{2, 1, 0}` stones.
     - `Grundy(3) = Mex({0, 1, 2}) = 3`

5. **For `n >= 4` Stones:**
   - The player can take `1`, `2`, or `3` stones.
   - The next possible positions are `{n-1, n-2, n-3}` stones.
     - `Grundy(n) = Mex({Grundy(n-1), Grundy(n-2), Grundy(n-3)})`

### Summary Table of Grundy Numbers:
| **N**  | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 |
|--------|----|----|----|----|----|----|----|----|----|----|----|
| **Grundy (n)** | 0  | 1  | 2  | 3  | 0  | 1  | 2  | 3  | 0  | 1  | 2  |

### Winning Strategy:
- If the initial Grundy Number of the pile is `0`, the first player loses if both players play optimally.
- If the initial Grundy Number is non-zero, the first player has a winning strategy.

---

## Example 3: Division Game

### Game Description:
The game starts with a number `n`.  
The player to move can divide the number `n` by **2**, **3**, or **6**, taking the floor of the result.  
If the resulting integer becomes `0`, it is removed.  
The last player to move wins.

### Grundy Number Calculation:

1. **Base Case:**
   - If the number is `0`, the player loses immediately.
     - `Grundy(0) = 0`

2. **For any number `n`:**
   - The player can divide `n` by `2`, `3`, or `6`, taking the floor.
   - The next possible positions are:
     - `floor(n/2)`, `floor(n/3)`, `floor(n/6)`
   - The Grundy Number for `n` is:
     - `Grundy(n) = Mex({Grundy(floor(n/2)), Grundy(floor(n/3)), Grundy(floor(n/6))})`

### Summary Table of Grundy Numbers:
| **N**  | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 |
|--------|----|----|----|----|----|----|----|----|----|----|----|
| **Grundy (n)** | 0  | 1  | 1  | 1  | 2  | 2  | 2  | 3  | 3  | 3  | 4  |

### Winning Strategy:
- If the initial Grundy Number of the number `n` is `0`, the first player loses if both players play optimally.
- If the initial Grundy Number is non-zero, the first player has a winning strategy.
           

