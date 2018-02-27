//
//  PlanetInfo.hpp
//  Astral Pathfinder
//
//  Created by Ian Holdeman on 2/25/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

#ifndef PlanetInfo_hpp
#define PlanetInfo_hpp

// MARK: Source Files
#include "TextBox.hpp"
#include "PlanetManager.hpp"
#include "Planet.hpp"

// MARK: - PlanetInfo Parameters

namespace InfoParameters {
  const SDL_Rect depositsRect = {1275, 600, 225, 50};
  const SDL_Rect fertilityRect = {1275, 650, 225, 50};
}

class PlanetInfo {
public:
  // MARK: - PlanetInfo Initialization
  void init();
  
  // MARK: - Game Loop Methods
  void render();
  void clean();

  
  // MARK: - PlanetInfo Methods
  void setText(Planet p);

  
private:
  // MARK: - PlanetInfo Fields
  TextBox depositsText, fertilityText;
  
  // MARK: - Helper Methods
  void setBoxes(Planet p);

};

#endif /* PlanetInfo_hpp */
