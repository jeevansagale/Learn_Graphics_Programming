/*
* Bouncing ball program
* Using Physics , motion equations 
* to replicate bounciness of a ball
*/


#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>
using std::cout;


float g  = 980.665f; // Accelaration due to gravity
float e  = 0.7f;     // Coefficient of Restitution
float cd = 0.5f;     // Drag Coefficient


// Artributes of the ball
struct Ball{
  float mass;
  float size;
  Vector2 position;
  Vector2 velocity;
  Color color;
  Ball(): mass(10.0f), size(30.0f), position({50, 100}), velocity({150.0f, 150.0f}), color(BLACK) {} 
};


// Give motion to ball
void Bounce(Ball &ball){

  Vector2 Mousepos = GetMousePosition();
  if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ball.position = Mousepos;}

  // Initiliazed Delta time and Force
  float dt = GetFrameTime();
  Vector2 Force = {0.0f , 0.0f};

  // Calculate Force by F = mg;
  Force.y = ball.mass * g;

  // Apply Air Drag
  Force.x -= ball.velocity.x * cd;
  Force.y -= ball.velocity.y * cd;

  // Newtons second law [a = F / m]
  Vector2 Accelaration;
  Accelaration.x = Force.x / ball.mass;
  Accelaration.y = Force.y / ball.mass;

  // Update Values
  ball.velocity = Vector2Add( ball.velocity, Vector2Scale(Accelaration, dt));
  ball.position = Vector2Add(ball.position , Vector2Scale(ball.velocity, dt));

  // Checking Boundries
  // Floor
  if(ball.position.y >= 570){
    ball.velocity.y *= -e;
    ball.position.y = 570;
  }

  // Celiling
  if(ball.position.y <= 0){
    ball.velocity.y *= -e;
    ball.position.y = 0;
  }

  // Right wall
  if(ball.position.x >= 770){
    ball.velocity.x *= -e;
    ball.position.x = 770;  
  }

  // Left wall
  if(ball.position.x <= 0){
    ball.velocity.x *= -e;
    ball.position.x = 0;
  }

  if(IsKeyPressed(KEY_R)){
    ball.position = {50 , 100};
    ball.size = 30.0f;
    ball.velocity = {150.0f, 150.0f};
    ball.color = BLACK;
  }
}


// Draw the ball
void DrawBall(Ball &ball){
  DrawCircleV(ball.position, ball.size, ball.color);
}


// Show Debug screen
void ShowDebug(Ball &ball){
  static bool show = false;
  if(!show){
    DrawText("Press [P] \nfor debug screen", 550, 50, 20, BLACK);
  }

  if(IsKeyPressed(KEY_P)) show = !show;
  if(show){
    DrawText(TextFormat("Postion = [%.0f , %.0f]" , ball.position.x , ball.position.y) , 550 , 50 , 20 , BLACK);
    DrawText(TextFormat("Velocity: [%.0f , %.0f]", ball.velocity.x , ball.velocity.y) , 550 , 80 , 20 , BLACK);
    DrawText(TextFormat("Mass: %.1f" , ball.mass) , 550 , 110 , 20 , BLACK); 
    DrawText(TextFormat("COR: %.1f" , e) , 550 , 140 , 20 , BLACK); 
    DrawText(TextFormat("Air Drag: %.1f" , cd) , 550 , 170 , 20 , BLACK); 
  }

  DrawText("[esc]" , 30 , 30 , 20 , Fade(BLACK , 0.6f));
  DrawText("[R] to Reset" , 30 , 50 , 20 , Fade(BLACK , 0.6f));
}


// Change Values
void Change(Ball &ball){
  GuiSlider({300, 50 , 200 , 10}, "Mass", "", &ball.mass, 1.0f, 1000.0f);
  GuiSlider({300, 60 , 200 , 10}, "COR", "", &e, 0.0f, 1.0f);
  GuiSlider({300, 70 , 200 , 10}, "Air Drag", "", &cd, 0.0f, 1000.0f);
}


// Main Program
int main(){
  InitWindow(800, 600, "Learn Raylib");
  SetTargetFPS(60);
  Ball ball;
  cout << "Window Initiliazed\n";

  while(!WindowShouldClose()){
    Bounce(ball);
    Change(ball);

    BeginDrawing();
    ClearBackground(WHITE);

      DrawBall(ball);
      ShowDebug(ball);

    EndDrawing();
  }
  
  CloseWindow();
  return 0;
}