//
//  TextBox.hpp
//  Astral Pathfinder
//
//  Created by Ian Holdeman on 2/24/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

#ifndef Text_hpp
#define Text_hpp

// MARK: Libraries and Frameworks
#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"

// MARK: Source Files
#include "Game.hpp"
#include "GameObject.hpp"


// MARK: - TextBox Parameters

namespace TextParameters {
  const SDL_Color color = {255, 255, 255};
  const auto fontFile = "Resources/Assets/Arial.ttf";
}


// MARK: - TextBox Class

class TextBox : public GameObject {
public:
  // MARK: - Initialization Methods
  void init(SDL_Rect rect);
  
  // MARK: - Game Loop Methods
  void update();
  void render();
  void clean();
  
  // MARK: - TextBox Methods
  void setMessage(const char *words);
  
  
private:
  // MARK: - Textbox Fields
  TTF_Font *font;
};

#endif /* Text_hpp */