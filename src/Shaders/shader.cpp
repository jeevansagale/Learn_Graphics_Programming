/**
* Learning Shaders
* Through raylib
*/

#include <iostream>
#include "raylib.h"
#include "raymath.h"


// Main Program
int main(){
  InitWindow(800, 600, "Learn Shaders");
  SetTargetFPS(60);

  Shader shader = LoadShader("Assets/basic.vert", "Assets/basic.frag");
  
  Camera3D cam;
  cam.fovy = 45.0f;
  cam.position = {2.0 , 1.0 , 2.0};
  cam.up = {0 , 1.0, 0};
  cam.target = {0 , 1 , 0};
  cam.projection = CAMERA_PERSPECTIVE;

  int InDt = GetShaderLocation(shader, "dt");
  float dt = 0;

  
  while(!WindowShouldClose()){
    UpdateCamera(&cam, CAMERA_ORBITAL);
    dt += GetTime();
    SetShaderValue(shader, InDt, &dt, SHADER_UNIFORM_FLOAT);
    
    
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(cam);
        BeginShaderMode(shader);
            DrawRectangle(200, 300, 400, 100, WHITE);
            DrawCube({0 , 0 , 0} , 2 , 1 , 2 , WHITE);
        EndShaderMode();
    EndMode3D();
    EndDrawing();
  }
  
  UnloadShader(shader);
  CloseWindow();
  return 0;
}