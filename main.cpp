#include "include/generator.h"
#include "include/sudoku.h"
#include "include/sudoku_io.h"
#include "include/utils.h"
#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

// Define DEBUG_MODE to enable debug main, comment following to run the actual program
#define DEBUG_MODE

string PATH_TO_PUZZLES = "data/puzzles/";
string PATH_TO_SOLUTIONS = "data/solutions/";

string PUZZLE_PREFIX = "PUZZLE";
string SOLUTION_PREFIX = "SOLUTION";

int NUM_PUZZLE_TO_GENERATE = 10;

int COMPLEXITY_EMPTY_BOXES = 45;

#ifdef DEBUG_MODE
/**
 * @brief Debug main function for testing and experimenting.
 *
 * This function is designed to help developers quickly test and experiment
 * with different functions across the program without running the full production flow.
 *
 * Use this space to:
 * - Test specific functions (e.g., board generation, solving, printing).
 * - Experiment with new features or changes.
 * - Verify function integration from different headers.
 * - Run isolated tests to debug specific issues.
 */
int main() {
    // You can modify this main function to access all other function implemented
    //
    srand(0);
    for(int count = 1;count<=NUM_PUZZLE_TO_GENERATE;count++) {
        cout << "Running in DEBUG MODE...\n";

        // Example: Generate a single puzzle and print it
        int** board = generateBoard(COMPLEXITY_EMPTY_BOXES);  // Generate with 40 empty cells
        cout << "Generated Sudoku Puzzle:\n";
        printBoard(board);  // Assuming printBoard is defined in sudoku_io.h

        // Test solving the puzzle
        if (solve(board)) {
            cout << "Solved Puzzle:\n";
            printBoard(board);
        } else {
            cout << "Failed to solve the puzzle.\n";
        }
        if(board != nullptr) {
            cout<<"Needs to be deallocated"<<endl;
        }
        // Clean up memory
        deallocateBoard(board,9);
        cout<<"BOARD "<<count<<endl;
        cout<<"Board value: "<<board<<endl;
        if(board == nullptr) cout<<"No memory leak"<<endl;
        cout<<"------------------------------------------------------------"<<endl;

    }
    return 0;
}
#else
/**
 * @brief Main function for production use.
 *
 * Generates, solves, and compares Sudoku puzzles.
 */
int main() {

    cout<<"......................WELCOME TO OUR SUDOKU SOLVER..........................."<<endl;
    char status;

    while(true) {
        cout<<"...........Ready to run the program?..............Y/N:"<<endl;
        cout<<endl;
        cin>>status;
        srand(static_cast<unsigned int>(time(0)));
        if(std::toupper(status)=='Y') {
            //Defined in utils.h
            initDataFolder();
            //Defined in sudoku_io.h
            createAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, COMPLEXITY_EMPTY_BOXES, PATH_TO_PUZZLES, PUZZLE_PREFIX);
            solveAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, PATH_TO_PUZZLES, PATH_TO_SOLUTIONS, SOLUTION_PREFIX);

            // Run experiments to compare solvers
            //Defined in sudoku_io.h
            compareSudokuSolvers(10, 64);
            compareSudokuSolvers(100, 45);
            compareSudokuSolvers(1000, 32);
            compareSudokuSolvers(10000, 16);
            return 0;
        }
        else if(std::toupper(status)=='N') {
            cout<<"See you next time"<<endl;
            return 0;
        }
        else
            cout<<"Invalid Input"<<endl;
    }
}
#endif

