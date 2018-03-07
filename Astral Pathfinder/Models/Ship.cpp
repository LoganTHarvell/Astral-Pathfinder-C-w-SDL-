//
//  Ship.cpp
//  Astral Pathfinder
//
//  Created by Logan Harvell, Ian Holdeman on 2/10/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

// MARK: Header File
#include "Ship.hpp"

// MARK: Libraries and Frameworks
#include <iostream>

// MARK: Source Files
#include "Game.hpp"
#include "Map.hpp"
#include "TextureManager.hpp"

using PointVector = std::vector<SDL_Point>;

// MARK: - Initialization Methods

void Ship::init(SDL_Point p) {
  using namespace ShipParameters;
  
  population = 1000;
  fuel = 0;

  velocity.x = 0;
  velocity.y = 0;
  
  rotation = 270;
  
  rect.x = p.x;
  rect.y = p.y;
  rect.w = shipSize.w;
  rect.h = shipSize.h;
  
  collider = new ColliderComponent(getCenter(), computeShipVertices());
  texture = TextureManager::loadTexture(shipTexture);
}


// MARK: - Game Loop Methods

void Ship::update() {
  updateVelocity();
  updateRotation();
  
  collider->update(getCenter(), computeShipVertices());
}

void Ship::render() {
  SDL_RenderCopyEx(Game::renderer, texture, NULL, &rect,
                   rotation, NULL, SDL_FLIP_NONE);
}


// MARK: - Ship Methods

void Ship::updateVelocity() {
  using namespace ShipParameters;
  
  auto *keyState = SDL_GetKeyboardState(NULL);
  
  if (keyState[SDL_SCANCODE_UP]) velocity.y = (-speed);
  else if (keyState[SDL_SCANCODE_DOWN]) velocity.y = speed;
  else velocity.y = 0;
  
  if (keyState[SDL_SCANCODE_RIGHT]) velocity.x = speed;
  else if (keyState[SDL_SCANCODE_LEFT]) velocity.x = (-speed);
  else velocity.x = 0;
  
}

void Ship::move(Uint32 ticks) {
  rect.x += (velocity.x * (ticks/10));
  rect.y += (velocity.y * (ticks/10));
  
  if (boundaryCollision()) {
    rect.x -= (velocity.x * (ticks/10));
    rect.y -= (velocity.y * (ticks/10));
  }
}

// MARK: - Helper Methods

SDL_Point Ship::getMapPosition(SDL_Point uiPosition) {
  return Map::mapPosition(uiPosition);
}

bool Ship::boundaryCollision() {
  PointVector vertices = getCollider().getVertices();
  
  PointVector axes;
  axes.push_back({ 1, 0 });   // X axis normal vector
  axes.push_back({ 0, 1 });   // Y axis normal vector
  
  SDL_Point mins = { collider->minAlongAxis(vertices, axes[0]),
                     collider->minAlongAxis(vertices, axes[1]) };
  SDL_Point maxs = { collider->maxAlongAxis(vertices, axes[0]),
                     collider->maxAlongAxis(vertices, axes[1]) };
  
  return Map::checkBounds(mins, maxs);
}

PointVector Ship::shipVertexVectors() {
  PointVector cornerVectors;
  
  cornerVectors.push_back({ rect.x, rect.y + rect.h/2 });
  cornerVectors.push_back({ rect.x + rect.w/2, rect.y });
  cornerVectors.push_back({ rect.x + rect.w, rect.y + rect.h/2 });
  cornerVectors.push_back({ rect.x + rect.w/2, rect.y + rect.h });
  
  SDL_Point center = getCenter();
  for (auto& cv : cornerVectors) {
    cv.x -= center.x;
    cv.y -= center.y;
  }
  
  return cornerVectors;
}

PointVector Ship::computeShipVertices() {
  SDL_Point c = getCenter();
  PointVector svv = shipVertexVectors();
  int r = rotation;
  PointVector shipVertices = ColliderComponent::computeVertices(c, svv, r);
  return shipVertices;
}


void Ship::updateRotation() {
  using ShipParameters:: turnSpeed;
  
  int desiredRotation = 0;
  
  enum Direction {
    right = 0, downRight = 45,
    down = 90, downLeft = 135,
    left = 180, upLeft = 225,
    up = 270, upRight = 315
  };
  
  if (velocity.x == 0 && velocity.y == 0) return;
  if (velocity.x > 0 && velocity.y == 0) desiredRotation = Direction::right;
  if (velocity.x > 0 && velocity.y > 0) desiredRotation = Direction::downRight;
  if (velocity.x == 0 && velocity.y > 0) desiredRotation = Direction::down;
  if (velocity.x < 0 && velocity.y > 0) desiredRotation = Direction::downLeft;
  if (velocity.x < 0 && velocity.y == 0) desiredRotation = Direction::left;
  if (velocity.x < 0 && velocity.y < 0) desiredRotation = Direction::upLeft;
  if (velocity.x == 0 && velocity.y < 0) desiredRotation = Direction::up;
  if (velocity.x > 0 && velocity.y < 0) desiredRotation = Direction::upRight;


  if (desiredRotation == rotation) return;

  int ts;
  if (desiredRotation >= 180) {
    if (desiredRotation > rotation && rotation >= (desiredRotation+180)%360)
      ts = turnSpeed;
    else
      ts = -turnSpeed;
  }
  else {
    if (desiredRotation < rotation && rotation <= (desiredRotation+180)%360)
      ts = -turnSpeed;
    else 
      ts = turnSpeed;
  }
  
  int tmp = rotation;
  rotation = (rotation+ts)%360;
  if (rotation < 0) rotation = rotation + 360;
  
  if (boundaryCollision()) {
    rotation = tmp;
  }
  
}
