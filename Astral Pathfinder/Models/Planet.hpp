//
//  Planet.hpp
//  Astral Pathfinder
//
//  Created by Logan Harvell, Ian Holdeman on 2/10/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

#ifndef Planet_hpp
#define Planet_hpp

// MARK: Libraries and Frameworks
#include "SDL2/SDL.h"

// MARK: Source Files
#include "GameObject.hpp"


// MARK: - Planet Parameters

namespace PlanetParameters {
  
  const int planetTexSize = 8;
  const int minFertility = 0;
  const int fertilityRange = (200-minFertility);
  const int minDeposits = 100;
  const int depositsRange = (600-minDeposits);
  
  // Defines resource information
  const int startPopulation = 5000;
  const int foodRqmt = 50;
  const int farminCost = 25;
  const int miningCost = 30;
  const int shipCost = 100;
  const float infrastructureCost = 0.05;
}


// MARK: - Planet Class

class Planet: public GameObject {

public:
  // MARK: - Initialization Methods
  void initHomeworld();
  void initPlanet();
  
  // MARK: - Game Loop Methods
  void update();
  void render();
  
  // MARK: - Planet Methods
  SDL_Point getCoordinates() { return coordinates; };
  int getDeposits() { return deposits; };
  int getFertility() { return fertility; };
  void clicked();
  
private:
  // MARK: - Planet Fields
  SDL_Point coordinates;
  
  enum {
    undiscovered,
    discovered,
    colonized
  } status;

  // resources
  int deposits, fertility;
  
  // MARK: - Helper Methods
  SDL_Point uiPosition(SDL_Point p);
};

#endif /* Planet_hpp */
