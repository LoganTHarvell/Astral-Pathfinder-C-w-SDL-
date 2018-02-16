//
//  GameObject.cpp
//  Astral Pathfinder
//
//  Created by Logan Harvell, Ian Holdeman on 1/15/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

// MARK: Header File
#include "GameObject.hpp"


// MARK: - GameObject Methods

SDL_Point GameObject::getPosition() {
  return { rect.x, rect.y };
}

void GameObject::setPosition(SDL_Point p) {
  rect.x = p.x;
  rect.y = p.y;
}

SDL_Rect GameObject::getRect() {
  return rect;
}

void GameObject::scale(float x) {
  rect.w *= x;
  rect.h *= x;
};

