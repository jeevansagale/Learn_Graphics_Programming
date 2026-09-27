/*
* Rotation of an 
* Object using
* Trignometry
*/

#include <iostream>
#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


// General Configuration
namespace Config{
    constexpr int Width  = 800;
    constexpr int Height = 600;
    const char *Title = "Rotation of an Object";
    inline Color Background = BLACK;
}


// Properties of ball
struct Ball{
    public:
    float mass;
    float radius;
    Vector3 velocity;
    Vector3 position;
    
    Color color;

    Ball(float mass , float radius , Vector3 pos , Vector3 velo , Color color){
        this->mass     = mass;
        this->radius     = radius;
        this->position = pos;
        this->velocity = velo;
        this->color    = color;
    }
};


void Update(Ball &b1 , Ball &b2){
    double dt = GetTime();
    
    float OrbitRadius = 30.0f;
    float YearTime = 5.0f;

    float speed = 2 * PI / YearTime;
    b1.position.x = b2.position.x + OrbitRadius * cosf(speed * (float)dt);
    b1.position.y = b2.position.y;
    b1.position.z = b2.position.z + OrbitRadius * sinf(speed * (float)dt);
}


// Toggle Mouse Cursor
void ToggleMouseCursor(){
    if(IsKeyPressed(KEY_P)){
        if(IsCursorHidden()){
             EnableCursor();
        }
        else DisableCursor();
    }
}


int main(){
    InitWindow(Config::Width , Config::Height,  Config::Title);
    SetTargetFPS(60);
    
    Ball Earth(100 , 5 , {0 , 0 , 0} , {10 , 10 , 10} , BLUE);
    Ball Sun(1000  , 10 , {0 , 0 , 0} , {0 , 0 , 0 }   , GOLD);

    Camera3D cam;
    cam.fovy = 60.0f;
    cam.position = {0 , 40 ,60};
    cam.projection = CAMERA_PERSPECTIVE;
    cam.target = Sun.position;
    cam.up = {0 , 1 , 0};


    while(!WindowShouldClose()){
        UpdateCamera(&cam , CAMERA_FREE);
        Update(Earth , Sun);

        ToggleMouseCursor();

        BeginDrawing();
        ClearBackground(Config::Background);

            BeginMode3D(cam);

                DrawGrid(100, 10);
                DrawSphereEx(Earth.position, Earth.radius, 100 , 100 , Earth.color);
                DrawSphereEx(Sun.position, Sun.radius, 100, 100, Sun.color);
            
            EndMode3D();

            DrawText(TextFormat("%.0f %.0f %.0f" , Earth.position.x , Earth.position.y , Earth.position.z) , 10 , 10 , 30 , BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}