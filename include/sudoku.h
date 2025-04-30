/**
 * @file sudoku.h
 * @brief Core Sudoku solving and board generation functions.
 *
 * This header file declares functions essential for solving Sudoku puzzles
 * and validating board states. It includes:
 * - A backtracking Sudoku solver.
 * - A cell validation function to ensure valid number placement.
 * - A board generation stub for creating Sudoku puzzles.
 *
 * All functions operate on dynamically allocated 9x9 Sudoku boards
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H

#include <iostream>

/**
 * @brief Checks if a number is valid to be placed in a given cell of a Sudoku board.
 *
 * This function checks whether placing a number `k` at the position `r, c` (row, column)
 * of the given 9x9 Sudoku board is valid. A number is considered valid if:
 * 1. It does not already exist in the same row.
 * 2. It does not already exist in the same column.
 * 3. It does not already exist in the corresponding 3x3 subgrid.
 *
 * @param BOARD A 9x9 Sudoku board represented as a pointer-to-pointer (`int**`).
 * @param r The row index (0 to 8) where the number is to be placed.
 * @param c The column index (0 to 8) where the number is to be placed.
 * @param k The number to be placed at the specified position.
 *
 * @return bool Returns `true` if placing `k` at position `(r, c)` is valid, and `false` if not.
 *
 * @note This function checks the validity by examining the row, column, and the 3x3 subgrid
 * in which the given position lies. It ensures that no number is repeated in these regions.
 *
 * Example:
 * @code
 * int** board = getEmptyBoard();
 * bool valid = isValid(board, 0, 0, 5);  // Check if placing '5' at position (0, 0) is valid.
 * if (valid) {
 *     std::cout << "Valid placement" << std::endl;
 * } else {
 *     std::cout << "Invalid placement" << std::endl;
 * }
 * @endcode
 */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);

/**
 * @brief Solves a 9x9 Sudoku board using a backtracking algorithm.
 *
 * This function attempts to solve a Sudoku puzzle using a recursive backtracking approach. It starts from the top-left
 * cell of the board and tries to fill the board by placing numbers 1 to 9 in empty cells, ensuring that the placement
 * follows the rules of Sudoku:
 * 1. No number repeats in the same row.
 * 2. No number repeats in the same column.
 * 3. No number repeats in the corresponding 3x3 subgrid.
 *
 * The function recursively explores all possible valid placements and backtracks if a placement doesn't lead to a solution.
 *
 * @param BOARD A 9x9 Sudoku board represented as a pointer-to-pointer (`int**`), which will be modified to represent the solved puzzle.
 * @param r The current row index (0 to 8) being processed.
 * @param c The current column index (0 to 8) being processed.
 *
 * @return bool Returns `true` if the board is solved, and `false` if no solution is found.
 *
 * @note This function solves the board in a depth-first manner using backtracking. The function makes recursive calls
 * to check if placing numbers 1 to 9 at a given position will lead to a valid solution. If a solution is found, it
 * returns `true`. If a placement leads to no valid solution, it backtracks and tries the next possible number.
 *
 **/
bool solveBoard(int** BOARD, const int& r=0, const int& c=0);


// ========================= Efficient Solutions ==========================


/**
 * @brief Finds the next empty cell using the Minimum Remaining Value (MRV) heuristic.
 *
 * This function scans the 9x9 Sudoku board to find the most constrained empty cell — that is, the one with the
 * fewest number of valid choices available (Minimum Remaining Value). This improves the efficiency of the solver
 * by reducing the branching factor in the recursive search.
 *
 * The function iterates through all empty cells (cells with value 0) and, for each one, counts how many numbers
 * from 1 to 9 can be legally placed according to Sudoku rules using `isValid()`. The cell with the lowest number
 * of valid options is selected.
 *
 * Early Exit: If any cell has exactly one valid option, it is returned immediately to save computation time.
 * If a cell has 0 valid options, it is considered a dead-end and also returned to trigger backtracking.
 *
 * @param BOARD A 9x9 dynamically allocated Sudoku board (`int**`), where 0 represents an empty cell.
 *
 * @return std::tuple<int, int, int> A tuple containing:
 *         - The row index of the selected cell.
 *         - The column index of the selected cell.
 *         - The number of valid options for that cell.
 *
 *         If no empty cell is found (i.e., board is full), the returned indices will be (-1, -1).
 *         If a cell with zero options is found, it returns that cell's location and 0 (to signal an unsolvable state).
 *
 * @note This function is typically used by the efficient solver (e.g., `solveBoardEfficient`) to guide its recursive
 * decision-making.
 */
std::tuple<int, int, int> findNextCell(int** BOARD);


/**
 * @brief Solves Sudoku using backtracking with MRV heuristic for optimization.
 *
 * Uses Minimum Remaining Value (MRV) to select cells with fewest options first,
 * reducing the search space compared to basic backtracking.
 *
 * @param BOARD 9x9 Sudoku board (modified in-place)
 * @return true if solved, false if unsolvable
 *
 * @note Relies on findNextCell() for MRV selection and isValid() for constraints.
 *       Backtracks automatically when dead-ends are encountered.
 */
bool solveBoardEfficient(int** BOARD);


/**
 * @brief Solves a Sudoku board using either basic or optimized backtracking.
 *
 * @param board 9x9 Sudoku board (0 = empty)
 * @param efficient true for optimized solver, false for basic
 * @return true if solved, false if unsolvable
 */
bool solve(int** board, const bool& efficient = false);

#endif //SUDOKUPROJECT_SUDOKU_H