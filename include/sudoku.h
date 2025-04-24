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
 * @brief Finds the next empty cell on the Sudoku board using the Minimum Remaining Value (MRV) heuristic.
 *
 * The MRV heuristic chooses the empty cell with the fewest legal number options (1–9) remaining.
 * This optimizes the backtracking process by reducing the branching factor and prioritizing
 * more constrained decisions.
 *
 * If a cell is found with only one valid option, it is returned immediately (early exit).
 *
 * @param BOARD A pointer to a 9x9 integer array representing the Sudoku board.
 * @return std::tuple<int, int, int> A tuple containing:
 *         - Row index of the selected empty cell.
 *         - Column index of the selected empty cell.
 *         - Number of valid options (1–9) for that cell.
 *
 * @note Returns (-1, -1, INT_MAX) if no empty cells are found (i.e., the board is complete).
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