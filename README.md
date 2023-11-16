# Sudoku-Solver

Background

Sudoku puzzles are constructed using a N2 x N2 grid made up of N2 sub grids of size N x N, known as blocks. For each puzzle, some of the N4 cells, called givens, are assigned one of the numbers 1, 2, … , N2, and the other cells are blank. The puzzle is solved by assigning a number to each blank cell so that every row, every column, and every one of the N2 , N x N blocks contains each of the  N2 possible numbers. 

Examples
	4 x 4 sudoku puzzle 	9 x 9 sudoku puzzle
Grid dimensions 	4 x 4 	9 x 9
Number of sub grids / blocks 	4 	9
Sub grid / Block dimensions 	2 x 2 	3 x 3
Total number of cells 	16 	81
Possible numbers for each cell 	1, 2, 3, 4 	1, 2, 3, 4, 5, 6, 7, 8, 9
Example 	4x4 sudoku example 	sudoku 9x9 example
Step-by-step process of solving this assignment
Problem solving flow

Problem Statement

Given a set of 9x9 sudoku puzzles, write the SMT-LIB code for solving at least two of them by following the terminology described below and your code should generate the output similar to the sample output of 4x4.
Puzzle Set:
Puzzle 1 	Puzzle 2 	Puzzle 3 	Puzzle 4
Sudoku Puzzle 1 	Sudoku Puzzle 2 	Sudoku Puzzle 3 	Sudoku Puzzle 4
Know the terminology (Propositional variable naming convention)

To encode a 9x9 sudoku puzzle into SMT-LIB, Assume P(i, j, k) denotes the proposition that is true when the number k is in the cell in the ith row and jth column. There are 9x9x9=729 such propositions, as i, j, and n all range from 1 to 9. Name this propositional variable as P_i_j_k (P is a uppercase character) by substituting the appropriate value for i, j, & k. 

Example, if the number 6 is present in the fifth row and first column of 9x9 sudoku. Then, we can write P(5, 1, 6) to be true, and P(5, j, 6) to be false for j = 2, 3, … , 9 because of the fact that 6 should not be placed in any of the remaining 8 cells of fifth row. We can write the below compound preposition which is always true from these inferences.
