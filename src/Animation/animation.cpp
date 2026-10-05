/*
* Animation using
* Raylib
* To make animatons
*/

#include "raylib.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout, std::runtime_error, std::cin, std::string, std::invalid_argument, std::vector;

namespace Config{
    constexpr float Width  = 800.0f;
    constexpr float Height = 800.0f;
    const char * Title     = "Aniamtion";
};

int main(){
    InitWindow(Config::Width , Config::Height , Config::Title);
    SetTargetFPS(60);
    vector<Texture2D> Elenore(9);
    int CurrentFrame   = 0;
    float FrameTimer   = 0.0f;
    float FramePerTime = 0.2f;

    for(int i = 0 ; i < 9 ; i++){
        string path = ("Assets/Sprites/Eleonore/Idle/Idle" + std::to_string(i+1) + ".png");
        cout << path << "\n";
        Elenore[i] = LoadTexture(path.c_str());
    }

    while(!WindowShouldClose()){

        FrameTimer += GetFrameTime();

        if(FrameTimer >= FramePerTime){
            FrameTimer = 0.0f;
            CurrentFrame = (CurrentFrame + 1) % 9;
        }

        BeginDrawing();
        ClearBackground(BLACK);

            DrawTexturePro(Elenore[CurrentFrame] , {0 , 0 , static_cast<float>(Elenore[0].width) , static_cast<float>(Elenore[0].height)} , {300 , 300 , 500 , 500} , {0 , 0} , 0 , WHITE);
            // DrawTexture(Elenore[CurrentFrame] , 100 , 100 , WHITE);
        EndDrawing();
    }
    CloseWindow();

    for(int i = 0 ; i < 9 ; i++){
        UnloadTexture(Elenore[i]);
    }
}