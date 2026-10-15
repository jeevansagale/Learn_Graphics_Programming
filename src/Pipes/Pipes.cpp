/*
* Randome pipes 
* generation 
* BS
*/ 

#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"
#include "raymath.h"

using std::cout, std::string, std::vector;


namespace CONFIG{
  constexpr float SCREEN_HEIGHT = 800.0f;
  constexpr float SCREEN_WIDTH  = 800.0f;
  const char* TITLE             = "Randome Pipes";
  constexpr Color BACKGROUND    = BLACK;
  constexpr float FPS           = 60.0f;
};


int main(){
  InitWindow(CONFIG::SCREEN_WIDTH, CONFIG::SCREEN_HEIGHT , CONFIG::TITLE);
  SetTargetFPS(CONFIG::FPS);
  float offset = 300;
  while(!WindowShouldClose()){
    static float dt = GetFrameTime();
    offset += 10;
    BeginDrawing();
    ClearBackground(CONFIG::BACKGROUND);
      DrawCircle(40 , 50 , 50, WHITE);
      DrawRectangle(400 , 400 , 10 + offset*dt  , 10 + offset*dt + 100 , BLUE);
    EndDrawing();
  }
  CloseWindow();
}

