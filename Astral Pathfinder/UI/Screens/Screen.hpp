//
//  Screen.hpp
//  Astral Pathfinder
//
//  Created by Ian Holdeman on 7/14/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

// MARK: Libraries and Frameworks
#include "SDL2/SDL.h"
#include <vector>

// MARK: Source Files
#include "TextBox.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Button.hpp"

// MARK: - Screen Parameters

namespace ScreenParameters {
  const SDL_Rect screenRect = {0, 0, GameParameters::windowRect.w, GameParameters::windowRect.h};
}


// MARK: - Scren Class

class Screen {
  
public:
  // MARK: - Screen Initialization
  virtual void init() = 0;
  
  // MARK: - Game Loop Methods
  virtual void update(Game::State *gs) = 0;
  virtual void render(Game::State *gs) = 0;
  
  // MARK: - Screen Methods
  void checkForHovering(Game::State *gs, int screen);
  int checkClick(Game::State *gs, int screen);
  void addButton(int currentScreen, SDL_Rect bounds, SDL_Rect border, int nextScreen);
  void renderButtons(int screen);
  
protected:
  SDL_Texture *texture = nullptr;
  SDL_Texture *hoveringBorder = TextureManager::loadTexture("../Resources/border.png");
  SDL_Rect borderRect;
  
  enum activeScreen {
    none=-1, menu, scores, game, over, quit
  };
  
private:
  std::vector<Button> mainMenuButtons;
  std::vector<Button> scoreboardButtons;
  std::vector<Button> endScreenButtons;
  
  std::vector<Button> *getActiveScreenButtons(int screen);
};

#endif /* Screen_hpp */
