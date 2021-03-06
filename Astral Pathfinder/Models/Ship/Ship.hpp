//
//  Ship.hpp
//  Astral Pathfinder
//
//  Created by Logan Harvell on 2/10/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//
//  Description:
//  Abstract class extension of GameObject used as a base class to model Ship
//  game elements. Handles ship bounding box position and orientation, as well
//  as boundary collisions using the collider component. Also handles rendering.

#ifndef Ship_hpp
#define Ship_hpp

// MARK: Libraries and Frameworks
#include "SDL2/SDL.h"
#include "GameObject.hpp"

// MARK: Source Files
#include "Game.hpp"


// MARK: - Ship Class

class Ship: public GameObject {
  
public:
  // Ship Tags
  enum ShipType {
    playerShip,
    alienWarship
  };
  
  // MARK: - Initialization Methods
  
  virtual void init(SDL_Point startPosition) = 0;
  
  // MARK: - Game Loop Methods
  
  virtual void update(Game::State *gs) = 0;
  void render(Game::State *gs);
  
  // MARK: - Ship Methods
  
  ShipType getTag() { return tag; };
  SDL_Point getVelocity() { return velocity; }
  SDL_Point getUIPosition() { return getCenter(); };
  SDL_Point mapPosition();
    
protected:
  using PointVector = std::vector<SDL_Point>;

  // MARK: - Ship Fields
  
  ShipType tag;
  SDL_Point velocity;
  
  // MARK: - Helper Methods
  bool boundaryCollision();
  
  virtual PointVector shipVertexVectors() = 0;
  PointVector computeShipVertices();
  
  virtual void updateVelocity() = 0;
  
  void updateRotation();
  void updatePosition(Uint32 ticks);

};

#endif /* Ship_hpp */
