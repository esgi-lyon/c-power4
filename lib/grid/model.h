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

struct Case {
    struct Model* top;
    struct Model* bottom;
    struct Model* left;
    struct Model* right;

    int x;
    int y; // TODO check if need unsigned int
};

struct Grid
{
    struct Case* zero_zero_case; // x = 0 and y = 0 case

    int dimension_x;
    int dimension_y;
};

struct Grid* build();

/**
 * @brief Given coordinates, give the case to interact with
 * 
 * @param grid 
 * @param x 
 * @param y 
 * @return struct Case* 
 */
struct Case* get_case(struct Grid* grid, int x, int y);

/**
 * @brief add case in grid, error if already exist in coords
 * 
 * @param x 
 * @param y 
 * @return struct Grid* 
 */
struct Grid* append_case(struct Case* grid_case, int x, int y);

#endif
