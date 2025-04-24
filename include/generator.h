/**
* @file generator.h
 * @brief Function prototypes for generating random solvable Sudoku boards.
 *
 * This header defines functions to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve and generate a complete Sudoku board.
 * - Randomly delete cells to create a solvable puzzle.
 * - Generate a complete Sudoku puzzle with a specific number of empty cells.
 *
 * Detailed function descriptions and parameters are provided below.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef GENERATOR_H
#define GENERATOR_H
#include <vector>


/**
* @brief Creates and initializes a 9x9 Sudoku board with all cells set to 0.
*
* -This function dynamically allocates memory for a 9x9 integer board using a
* pointer-to-pointer structure (`int**`).
* -It initializes all the cells of the
* board to 0, which represents an empty Sudoku grid.
*-@return int** A pointer to a 9x9 Sudoku board with all cells initialized to 0.
* -The returned board is a **dynamically allocated 2D array**
*/
int** getEmptyBoard();

/**
/**
 * @brief Creates a vector containing numbers from 1 to 9, shuffles it using a random engine, and returns the shuffled vector.
 *
 * The vector `fill_box` is created and initialized with the numbers 1 to 9. A random number generator is then
 * initialized using `std::random_device` and `std::mt19937`. The `std::shuffle` algorithm is applied to randomly
 * shuffle the vector's elements. Finally, the shuffled vector is returned.
 *
 * @return std::vector<int> A shuffled vector containing numbers from 1 to 9, in random order.
 *
 * @note `std::random_device` is used to generate a seed for the random number generator, and `std::mt19937` is
 * a Mersenne Twister engine that provides high-quality random numbers.
 */
std::vector<int> getShuffledVector();

/**
 * @brief Fills the diagonal 3x3 boxes of a Sudoku board with unique numbers from 1 to 9.
 *
 * This function fills the three **diagonal 3x3 boxes** of a 9x9 Sudoku board (top-left, center, and bottom-right)
 * with unique numbers from 1 to 9, using **shuffling** to randomize the values in each 3x3 box.
 * The values in each diagonal 3x3 box are filled with unique values from the shuffled vector, and the
 * remaining cells are left empty (set to 0).
 *
 * The board is passed as a 2D array (`int** BOARD`), and the function modifies the cells directly by filling
 * them with the shuffled values.
 *
 * @param BOARD A 9x9 Sudoku board, represented as a pointer-to-pointer (`int**`).
 *
 * @note This function does not check for the validity of the Sudoku board. It only modifies the diagonal
 * 3x3 boxes.
 *
 * Example:
 * @code
 * int** board = getEmptyBoard();
 * fillBoardWithIndependentBox(board);
 * // The board will have the diagonal 3x3 boxes filled with unique values from 1 to 9.
 * @endcode
 */
void fillBoardWithIndependentBox(int** BOARD);

/**
 * @brief Deletes 'n' random cells from a 9x9 Sudoku board.
 *
 * This function randomly selects 'n' cells from a given Sudoku board and sets
 * the values of those cells to 0. The function ensures that each selected cell
 * is unique (i.e., no cell is deleted more than once). The number of cells to delete
 * is specified by the parameter `n`, which should be between 1 and 81. The function
 * will modify the board in place by replacing the randomly selected cells with 0.
 *
 * @param BOARD A 9x9 Sudoku board, represented as a pointer-to-pointer (`int**`),
 *              where the board's values are modified.
 * @param n The number of cells to delete (should be between 1 and 81). The function
 *          will randomly select `n` filled cells and set them to 0.
 *
 * @note The function does not perform checks for whether the board is solvable after deletion.
 *       It simply modifies the `BOARD` by deleting `n` random cells.
 *
 * @example
 * int** board = getEmptyBoard();
 * deleteRandomItems(board, 5); // Deletes 5 random cells from the board
 * // The board will have 5 random cells set to 0.
 */
void deleteRandomItems(int** BOARD, const int& n);

/**
 * @brief Generates a solvable Sudoku board with a specified number of empty cells.
 *
 * This function creates a 9x9 Sudoku board, fills its diagonal 3x3 boxes with random numbers,
 * solves the board to fill in the remaining cells, and then deletes a specified number of cells
 * to create a playable puzzle. The number of cells to be emptied is provided by the `empty_boxes` parameter.
 *
 * The process involves:
 * 1. Initializing an empty board.
 * 2. Filling the diagonal 3x3 boxes.
 * 3. Solving the board to complete it.
 * 4. Randomly deleting the specified number of cells to generate the puzzle.
 *
 * The function ensures that the board remains solvable after deleting cells.
 *
 * @param empty_boxes The number of cells to be emptied in the generated puzzle (must be between 1 and 81).
 *
 * @return int** A dynamically allocated 9x9 Sudoku board with 'empty_boxes' empty cells.
 *
 * @note The function uses helper functions like `getEmptyBoard()`, `fillBoardWithIndependentBox()`,
 * `solveBoard()`, and `deleteRandomItems()` to perform its operations. It ensures that the puzzle
 * generated has a unique solution.
 *
 * Example:
 * @code
 * int** board = generateBoard(5);  // Generates a board with 5 empty cells
 * // The generated board will have 5 random cells set to 0.
 * @endcode
 */
int** generateBoard(const int& empty_boxes);

#endif // GENERATOR_H
