//
//  Map.hpp
//  Astral Pathfinder
//
//  Created by Logan Harvell, Ian Holdeman on 1/28/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

// MARK: Libraries and Frameworks
#include "SDL2/SDL.h"

// MARK: Source Files
#include "parameters.h"

// MARK: Parameter Constants
#define MAP_WIDTH 800
#define MAP_HEIGHT 800
#define MAP_X_ORIGIN 400
#define MAP_Y_ORIGIN 50
#define GRID_OFFSET 50
#define GRID_X_ORIGIN MAP_X_ORIGIN + (GRID_OFFSET/2)
#define GRID_Y_ORIGIN MAP_Y_ORIGIN + (GRID_OFFSET/2)
#define GRID_WIDTH (MAP_WIDTH - GRID_OFFSET)/NUMBER_OF_PLANETS
#define GRID_HEIGHT (MAP_HEIGHT - GRID_OFFSET)/NUMBER_OF_PLANETS
#define PLANET_TEXTURE_SIZE 8
#define PLANET_TEXTURE_OFFSET_X (GRID_WIDTH - PLANET_TEXTURE_SIZE)/2
#define PLANET_TEXTURE_OFFSET_Y (GRID_HEIGHT - PLANET_TEXTURE_SIZE)/2

class Map {
  
public:
  static SDL_Point uiPosition(SDL_Point position);
  
private:
  
};

#endif /* Map_hpp */
