//
//  PlayerShip.hpp
//  Astral Pathfinder
//
//  Created by Logan Harvell on 4/29/18.
//  Copyright © 2018 Logan Harvell. All rights reserved.
//

#ifndef PlayerShip_hpp
#define PlayerShip_hpp

#include "Ship.hpp"

class PlayerShip : public Ship {
  
public:
  // MARK: - Initiallization Methods
  void init(SDL_Point startPostion);

  // MARK: - PlayerShip Methods
  ShipParameters::ShipType getTag() { return tag; };
  int getFuel() { return fuel; };
  int getCrewPopulation() { return crewPopulation; };
  
  void updateFuel(int minerals);
  
private:
  // MARK: - PlayerShip Fields
  ShipParameters::ShipType tag;
  int crewPopulation;
  int fuel;
  
  // MARK: - Helper Methods
  PointVector shipVertexVectors();
  
  void updateVelocity();  
};



#endif /* PlayerShip_hpp */