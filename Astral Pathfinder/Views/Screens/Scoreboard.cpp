//
//  Scoreboard.cpp
//  Astral Pathfinder
//
//  Created by Ian Holdeman on 7/14/18.
//  Copyright © 2018 Logan Harvell, Ian Holdeman. All rights reserved.
//
//  Description:
//  Extension of the Screen class for the Scoreboard screen. Initializes
//  appropriate UI elements and updates them accordingly.

// MARK: Header File
#include "Scoreboard.hpp"

// MARK: Parameter File
#include "Parameters.hpp"

// MARK: Libraries and Frameworks
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


// MARK: - Scoreboard Initialization

void Scoreboard::init() {
  using namespace Parameters::UI::Scoreboard;
  
  TextureManager::loadTexture(textureFile, &texture, Game::renderer);
  
  addButton(ButtonID::menu, mainMenuButton, mainMenuBorder);
  
  TextBox box;
  SDL_Rect temp;
  for (int i = 0; i < scoreboardMax; i++) {
    scoreList[i*2] = box;
    scoreList[i*2+1] = box;
    temp = {startingNameBox.x, startingNameBox.y+(53*i),
      startingNameBox.w, startingNameBox.h};
    scoreList[i*2].init(temp);
    temp = {startingScoreBox.x, startingScoreBox.y+(53*i),
      startingScoreBox.w, startingScoreBox.h};
    scoreList[(i*2)+1].init(temp);
  }
  readScores();
}


// MARK: - Game Loop Methods

void Scoreboard::update(Game::State *gs) {
}

void Scoreboard::render(Game::State *gs) {
  using namespace Parameters::UI::Scoreboard;
  
  SDL_RenderCopy(Game::renderer, texture, NULL,
                 &Parameters::UIManager::screenRect);
  
  renderButtons();
  
  for (int i = 0; i < scoreboardMax; i++) {
    if (boardScores[i] > -1) {
      scoreList[i*2].render(gs);
      scoreList[(i*2)+1].render(gs);
    }
  }
}


// MARK: - Scoreboard Methods

void Scoreboard::writeScore(Game::State *gs, int score) {
  using namespace std;
  ofstream file;
  file.open(Parameters::UI::Scoreboard::scoresFile.c_str(), ios::app);
  while (gs->playerName.length() < 3)
    gs->playerName += '-';
  string message = gs->playerName + ";" + to_string(score) + ";";
  file << message << endl;
  file.close();
}

// Evaluates buttonID and checks for transitions
Screen::ID Scoreboard::getNextScreen(int buttonID) {
  switch (buttonID) {
    case menu:
      return ID::menu;
      
    default:
      return none;
  }
}


// MARK: - Scoreboard Helper Methods

void Scoreboard::readScores() {
  using namespace std;
  
  const char lineBreak = ';';
  string line;
  ifstream file;
  file.open(Parameters::UI::Scoreboard::scoresFile.c_str());
  while (static_cast<void>(file >> ws), getline(file, line, lineBreak)) {
    // Player Name
    string name = line;
    // Player Score
    getline(file, line, lineBreak);
    stringstream s(line);
    int score;
    s >> score;
    
    compareScores(name, score);
  }
  
  file.close();
}

void Scoreboard::compareScores(std::string name, int score) {
  int tempScore;
  std::string tempName;
  TextBox tempBox;
  
  for (int i = 0; i < Parameters::UI::Scoreboard::scoreboardMax; i++) {
    if (score > boardScores[i]) {
      tempScore = boardScores[i];
      boardScores[i] = score;
      score = tempScore;
      
      tempName = names[i];
      names[i] = name;
      name = tempName;
      
      scoreList[i*2].setScoreboardMessage(names[i] + ": ");
      scoreList[(i*2)+1].setScoreboardMessage(std::to_string(boardScores[i]).c_str());
    }
  }
}
