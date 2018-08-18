//
//  Slider.hpp
//  Astral Pathfinder
//
//  Created by Ian Holdeman on 3/3/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

#ifndef Slider_hpp
#define Slider_hpp

// MARK: Libraries and Frameworks
#include "SDL2/SDL.h"
#include <string>

// MARK: Source Files
#include "Game.hpp"
#include "Planet.hpp"


// MARK: - Slider Parameters
// TODO: - Move parameters to parameters file

namespace SliderParameters {
  
  const std::string barFilename = "../Resources/base.png";
  const std::string circFilename = "../Resources/slider.png";
  const SDL_Color baseColor = { 150, 150, 150 };
  const SDL_Color sliderColor = { 0, 128, 0 };
  
}


// MARK: - Slider Class

class Slider {
public:
  // MARK: - Initialization Methods
  void init(SDL_Rect base, SDL_Rect circ);
  
  // MARK: - Game Loop Methods
  void update();
  void render();
  void clean();
  
  // MARK: - Slider Methods
  bool isInitialized();
  void setTextures(int percent);
  void colorMod(SDL_Color base, SDL_Color slider);
  SDL_Rect getBaseRect() { return base; }
  SDL_Rect getSliderRect() { return slider; }
  SDL_Point getSliderPosition() { return { slider.x, slider.y }; };
  void setSliderPosition(int pos);
  int getPercent();
  void updateSliderPosition(int percent);
  
private:
  // MARK: - Slider Fields
  SDL_Rect base, slider;
  SDL_Texture *baseTexture, *sliderTexture;
  bool setPos = false;
};


#endif /* Slider_hpp */