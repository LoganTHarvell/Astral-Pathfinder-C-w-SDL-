//
//  TextBox.cpp
//  Astral Pathfinder
//
//  Created by Ian Holdeman on 2/24/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//

// MARK: Header File
#include "TextBox.hpp"

// MARK: Source Files
#include "Game.hpp"
#include "TextureManager.hpp"


// MARK: - TextBox Initialization

void TextBox::init(SDL_Rect rectangle) {
  font = TTF_OpenFont(TextParameters::fontFile.c_str(), 36);
  
  rect = rectangle;
}


// MARK: - Game Loop Methods

void TextBox::update(Game::State *gs) {
  
}

void TextBox::render(Game::State *gs) {
  SDL_RenderCopy(Game::renderer, texture, NULL, &rect);
}

void TextBox::clean() {
  if (texture == nullptr) return;
  
  SDL_DestroyTexture(texture);
  texture = nullptr;
}


// MARK: - TextBox Methods

void TextBox::setMessage(const std::string words) {
  using TextParameters::color;
  
  if(texture != nullptr) clean();
  
  SDL_Surface *surface = TTF_RenderText_Solid(font, words.c_str(), color);
  texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
  SDL_FreeSurface(surface);
}

void TextBox::setFinalScore(TTF_Font *newFont, const std::string words) {
  using TextParameters::color;
  
  if(texture != nullptr) clean();
  
  SDL_Surface *surface = TTF_RenderText_Blended(font, words.c_str(), color);
  texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
  SDL_FreeSurface(surface);
}

bool TextBox::checkNull() {
  if(texture == nullptr) return true;
  else return false;
}

void TextBox::setRect(int x, int w) {
  rect.x = x;
  rect.w = w;
}

void TextBox::setNewColor(SDL_Color color) {
  SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}
