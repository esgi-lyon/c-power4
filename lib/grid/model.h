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

typedef enum Case{
  case_empty, case_red, case_yellow
} Case;

/**
 * @brief Grid map system
 * first is row, second nested array is column
 * - matrix[x][y]
 */
typedef struct GridMap {
  Case* matrix[6][7];
} GridMap;

/**
 * @brief Create a grid empty struct
 *
 * @return GridMap*
 */
GridMap* create_grid();

/**
 * @brief Given coordinates, give the case to interact with
 *
 * @param grid
 * @param x
 * @param y
 * @return enum Case
 */
Case* get_case(GridMap* grid, unsigned int x, unsigned int y);

/**
 * @brief add case in grid, error if already exist in coords
 *
 * @param grid
 * @param grid_case
 * @param x
 * @param y
 * @return struct Grid*
 */
GridMap* append_case(
  GridMap* grid,
  Case* grid_case,
  unsigned int x,
  unsigned int y
);

#endif
