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
    inline Color Background = WHITE;
}


// Physics Const
namespace Angular{
    float displacement = 0.0f;
    float velocity     = 0.0f;
}

// Properties of ball
struct Ball{
    public:
    float mass;
    
    Vector3 velocity;
    Vector3 position;
    
    Color color;
};

int main(){
    InitWindow(Config::Width , Config::Height,  Config::Title);
    SetTargetFPS(60);

    Camera3D cam;
    cam.fovy = 60.0f;
    cam.position = {0 , 10 , 10};
    cam.projection = CAMERA_PERSPECTIVE;
    cam.target = {0 , 0 , 0};
    cam.up = {0 , 1 , 0};

    Image image = GenImageColor(100, 100, BLUE);
    Texture2D def = LoadTextureFromImage(image);

    while(!WindowShouldClose()){
        UpdateCamera(&cam , CAMERA_FREE);

        if(IsKeyPressed(KEY_P)){
            if(IsCursorHidden()){
                EnableCursor();
            }
            else DisableCursor();
        }

        BeginDrawing();
        ClearBackground(Config::Background);

            BeginMode3D(cam);

                DrawCube({1 , 1 , 1}, 1, 1, 1, BLACK);
                DrawGrid(100, 1);
                DrawBillboard(cam, def, {20 , 20 , 20}, 5, WHITE);

            EndMode3D();

        EndDrawing();
    }
    CloseWindow();
    UnloadImage(image);
    UnloadTexture(def);
    return 0;
}