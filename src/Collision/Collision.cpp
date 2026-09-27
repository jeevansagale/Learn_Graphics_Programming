/*
* Collision of shapes 
* and Player control
* using raylib
*/


#include "raylib.h"
#include <iostream>
#include <vector>
#include "raymath.h"
using std::cout;
using std::vector;


namespace Config{
  constexpr float Width  = 800.0f;
  constexpr float Height = 600.0f;
  const char* Title = "Collision Control"; 
};


// Ball Attributes class
class Ball{
public:
  Vector2 Position;   // Position of the Ball
  Vector2 Velocity;   // Velocity of the Ball
  
  float radius;       // Radius of Ball  
  Color color;        // Color of Ball


  // Constructor
  Ball(Vector2 Pos , Vector2 Velo , float r , Color c){
    this->Position = Pos;
    this->Velocity = Velo;
    this->radius   = r;
    this->color    = c;
  }
};


void Initialize(vector<Ball> &balls , int count){
  for(int i = 0 ; i < count ; i++){
    balls.emplace_back(Ball{
      {static_cast<float>(GetRandomValue(10, Config::Width)) , static_cast<float>(GetRandomValue(10, Config::Height))},
      {static_cast<float>(GetRandomValue(200, 400))         , static_cast<float>(GetRandomValue(200, 400))},
      5.0f,
      {
        static_cast<unsigned char>(GetRandomValue(10, 255)),
        static_cast<unsigned char>(GetRandomValue(10, 255)),
        static_cast<unsigned char>(GetRandomValue(10, 255)),
        255
      }
    });
  }
}


// Add Physics
void Update(vector<Ball> &balls){

}


// Player Control
void Move(Ball &ball){
  float dt = GetFrameTime();
  if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))    ball.Position.y -= dt * ball.Velocity.y;
  if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))  ball.Position.y += dt * ball.Velocity.y;
  if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) ball.Position.x += dt * ball.Velocity.x;
  if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  ball.Position.x -= dt * ball.Velocity.x;
}


// Drawing the Ball
void Draw(const Ball &ball , const vector<Ball> &balls){
  DrawCircleV(ball.Position , ball.radius , ball.color);
  for(Ball b : balls){
    DrawCircleV(b.Position , b.radius , b.color);
  }
}


int main(){
  InitWindow(Config::Width , Config::Height , Config::Title);
  SetTargetFPS(60);
  Ball ball({20 , 20} , {200 , 200} , 30 , WHITE);
  
  vector<Ball> balls;
  balls.reserve(100);
  Initialize(balls , 100);

  while(!WindowShouldClose()){
    Move(ball);

    BeginDrawing();
    ClearBackground(BLACK);
       
      Draw(ball , balls);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
