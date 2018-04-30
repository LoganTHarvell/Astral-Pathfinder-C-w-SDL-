//
//  ShipManager.cpp
//  Astral Pathfinder
//
//  Created by Logan Harvell on 2/14/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

// MARK: Header File
#include "ShipManager.hpp"


// MARK: - ShipManager Initialization

void ShipManager::init(SDL_Point homeworldPos) {
  using namespace ShipParameters;
  
  // Centers ship on homeworld
  SDL_Point p = { homeworldPos.x - (shipSize.w/2),
                  homeworldPos.y - (shipSize.h/2) };
  
  playerShip.init(p);
}

// MARK: - Game Loop Methods

void ShipManager::update(Game::State *gameState, PlanetManager *pm) {
  playerShip.update(gameState);
  if (pm->playerIsDocked()) playerShip.updateFuel(pm->fuelDockedShip());
  
  // Endgame check for if player ran out of fuel
  if (playerShip.getFuel() <= 0 && !pm->playerIsDocked()) {
    gameState->endgame = Game::State::noFuel;
  }
}

void ShipManager::render(Game::State *gameState) {
  playerShip.render(gameState);
  
  if (gameState->debugMode) {
    DebugTools::renderVertices(playerShip.getCollider().getVertices());
  }
}
