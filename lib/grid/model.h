#define X_SIZE 7
#define Y_SIZE 6

/**
 * @brief Model component in grid MVC pattern
 * data structure and helper functions to :
 * - create a grid data modal
 * - interact with the grid
 * - manage memory of grid
 * @note For internal use of model, use it only in controller
 */
#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

enum Case{
  case_empty, case_red, case_yellow
};

typedef enum Case Matrix[X_SIZE][Y_SIZE];

/**
 * @brief Grid map system
 * first is row, second nested array is column
 * - matrix[x][y]
 */
typedef struct GridMap {
  Matrix matrix;
} GridMap;

#endif
