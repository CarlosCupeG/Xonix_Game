//
// Created by zero on 30/11/18.
//

#ifndef XONIX_GAME_H
#define XONIX_GAME_H


#include "Scene.h"
#include "Player.h"
#include "settings.h"



class Game : public Scene{
private:
    int vidas, ts;
    bool game;
    int puntaje = -126;
    int progreso = 0;
    int nivel = 1;
    bool freeze = false;
    int mapa[25][40] = { 0 };

    Player *currentPlayer;
    Font font;
    vector<sf::Text> textArray;
    int textPosX[8] = {150, 5, 475, 325, 90, 250, 625, 420};
    int textPosY[8] = {465, 465, 465, 465 , 465, 465, 465, 465};

    Clock clock;
public:
    Game();
    void init() override;

    void onEvent(sf::Event &event) override;
    void onUpdate();
    void onRender(sf::RenderWindow &window) override;

    int nextView() override;


    void rellenarTiles(int y, int x) {
        if (mapa[y][x] == 0) mapa[y][x] = -1;
        if (mapa[y - 1][x] == 0) rellenarTiles(y - 1, x);
        if (mapa[y + 1][x] == 0) rellenarTiles(y + 1, x);
        if (mapa[y][x - 1] == 0) rellenarTiles(y, x - 1);
        if (mapa[y][x + 1] == 0) rellenarTiles(y, x + 1);
    }

    void crearMapa() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 || j == 0 || i == M - 1 || j == N - 1) {
                    mapa[i][j] = 1;
                }
            }
        }
    }
};


#endif //XONIX_GAME_H
