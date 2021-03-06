//
//  PlayerShip.hpp
//  Astral Pathfinder
//
//  Created by Logan Harvell on 4/29/18.
//  Copyright © 2018 Logan Harvell. All rights reserved.
//
//  Description:
//  Class extension of Ship base class for modeling the player. Handles input
//  based movement to calculate velocity vectors, calculating vertex vectors.
//  Also handles initializing and updating.

#ifndef PlayerShip_hpp
#define PlayerShip_hpp

// MARK: Parent Class
#include "Ship.hpp"


class PlayerShip : public Ship {
  
public:
  // MARK: - Initiallization Methods
  void init(SDL_Point startPostion);

  void update(Game::State *gs);
  
  // MARK: - PlayerShip Methods
  int getFuel() { return fuel; };
  int getCrewPopulation() { return crewPopulation; };
  
  void updateFuel(int minerals);
  
private:
  // MARK: - PlayerShip Fields
  int crewPopulation;
  int fuel;
  
  // MARK: - Helper Methods
  PointVector shipVertexVectors();
  
  void updateVelocity();  
};



#endif /* PlayerShip_hpp */
