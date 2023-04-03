# Clear-the-Mines

- The first line in the input will contain two integer row and col, indicate the size of the given matrix.
- The rest of the input will contain the matrix that need to be solved.
- Each element will be separated by a space.
- There will be no redundant spaces or empty lines.
- There will be no empty input.

3. Operations
- There are four operation that need to be considered when solving the matrix:
- Shift up: shift all the elements in the matrix upward (corresponding to 1)
- Shift right: shift all the elements in the matrix to the right (corresponding to 2)
- Shift down: shift all the elements in the matrix downward (corresponding to 3)
- Shift left: shift all the elements in the matrix to the left (corresponding to 4)
- Elements in the matrix will either be ‘O’, ‘X’, or ‘B’.

- ‘O’ will represent an open path in the matrix.
- ‘X’ will act as a barrier when shifting the matrix.
- ‘B’ will represent a bomb that need to be detonate.
- In order to solve the matrix, all the bomb (B) in the matrix will need to be detonated.
- To detonate a bomb, they need to collide into another bomb by shifting the matrix up, right, down, or
left. Which two bomb collided first will be detonated.
- The matrix will always have even number of bomb (B).
- When two bomb detonated, a barrier (X) will be created at the index of detonation
When shifting up, the bomb (B) marked in red collided and detonated, created two barriers (X).

- When shifting the matrix, all the barrier (X) will be stationary and will not shift.
- A bomb (B) will stop shifting when it meets a barrier (X).

Output files
- Output the sequence of moves that detonate all the bomb and solve the matrix.
- If there are multiple sequence that solve the matrix (ex: 124, 211, 3214), output the smallest one.
- If the matrix is already solved without any moves, output “0” for the sequence.
