/*
* Collision of shapes 
* and Player control
* using raylib
*/


#include "raylib.h"
#include <cmath>
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
      15.0f,
      {
        static_cast<unsigned char>(GetRandomValue(10, 255)),
        static_cast<unsigned char>(GetRandomValue(10, 255)),
        static_cast<unsigned char>(GetRandomValue(10, 255)),
        255
      }
    });
  }
}


// Collisions 
void GetCollision(vector<Ball> &balls , Ball &player){
  for(auto &ball : balls){
    float dx = ball.Position.x - player.Position.x;
    float dy = ball.Position.y - player.Position.y;
    float dist = std::sqrtf(dx*dx + dy*dy);
    float rsum = (ball.radius + player.radius);

    if(dist <= rsum){
      float nx = dx / dist;
      float ny = dy / dist;

      float dot = ball.Velocity.x * nx + ball.Velocity.y * ny;
      ball.Velocity.x -= dot * 2.0f * nx;
      ball.Velocity.y -= dot * 2.0f * ny;

      float overlap = rsum - dist;
      ball.Position.x += nx * overlap;
      ball.Position.y += ny * overlap;

      break;
    }
  }
}


// Add Physics
void Update(vector<Ball> &balls , Ball &player){
  double dt = GetFrameTime();
  const float offset = 30;
  Vector2 dir = {1 , 1};

  for(auto &ball : balls){
    ball.Position.x += ball.Velocity.x * dt * dir.x;
    ball.Position.y += ball.Velocity.y * dt * dir.y;
    if(ball.Position.y >= Config::Height){
      dir.y = -1;
      ball.Position.y = Config::Height;
    }
    if(ball.Position.y <= 0){
      dir.y = 1;
      ball.Position.y = 0;
    }
    if(ball.Position.x >= Config::Width){
      dir.x = -1;
      ball.Position.x = Config::Width;
    }
    if(ball.Position.x <= 0){
      dir.x = 1;
      ball.Position.x = 0;
    }
  }
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
    Update(balls , ball);
    GetCollision(balls , ball);

    BeginDrawing();
    ClearBackground(BLACK);
         
      Draw(ball , balls);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
