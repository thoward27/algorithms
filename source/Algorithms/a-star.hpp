/** A* Search
 * A guided breadth-first-search algorithm.
 * For this problem we will operate on a restricted grid, which must be 4x4.
 * Start from the top-left, finish at bottom-right, you may only go "up-hill",
 * or to level ground.
 *
 * That means you may go 0 -> 1 -> 2
 * or, 0 -> 0 -> 0;
 * both are completely valid paths.
 *
 * As a result, you should send back a string containing the path to take from
 * start to finish.
 */

#include "../String/String.hpp"

String a_search(int maze[4][4]);
