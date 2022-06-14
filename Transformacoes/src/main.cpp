/*
    Nome: Juliano Leonardo Soares
    Matricula: 201713854

    Descrição:
    O projeto é uma animação/jogo de um personagem andando de bicileta;

    Manual de Uso:
    Basta abrir a plicação executar o main junto com as bibliotecas necessaria
    para rodar o canvas2d. Use as setas esquerda e direita para acelerar e desacelerar
    o ciclista e assim também acelerar e desacelerar a animação, a tecla "D" exibe o
    mode debug que pode ser visualizado os pontos para gerar curvas e outras coisas.

    Implementações:
    Básico:
        [x] Desenho da bicicleta e personagem (utilizando-se de estruturas de classes).
        [X] Animação de pedalar com posicionamento correto das pernas e pedais, e correta rotação
        das rodas
        [x] Uso de matrizes de rotação e translação para posicionar os elementos de desenho na tela
        [X] Controle de FPS
    Extras:
        [X] Ligação matematicamente correta entre o pedal e a perna.
        [X] Utilizar curvas Bezier ou B-Spline para o desenho do personagem e montanhas.
        [X] Utilizar técnicas de parallax para desenhar um background com sensação de perspectiva
        conforme a bicicleta anda..
        [X] Utilizar concatenação de matrizes de transformação..
        [X] Acelerometro.
        [X] Relógio que não segue o tempo correto mas utiliza as técnicas de rotação e translação.

    Melhorias a fazer:
    [ ] Melhorar o relógio.
    [ ] Fazer um chão e bicicleta acompanhar os desniveis.
    [ ] Dar uma estudada de como suavizar as conexões de curvas de Bezier e B-Spline.

    Obs: As montanhas foram feitas para ficar a forma mais caricata possivel então elas devem ser todas tortas
    e não suavizadas.
*/
#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include "sys/time.h"

#include "Modules/gl_canvas2d.h"
#include "Utils/Utils.h"
#include "Utils/Vector2.h"
#include "./Components/ClockHUD/ClockHUD.h"
#include "./Components/Cyclist/Cyclist.hpp"
#include "./Components/Parallax/Parallax.hpp"
#include "./Components/Speedometer/Speedometer.hpp"

/*
Sets of global variables for handling time, screen size,
speed, debug mode and references to some objects;

It was preferable for me to leave them because there is
no need to complicate the work more just to make it as
clean as possible
*/
ClockHUD *clockHud = NULL;
Cyclist *cyclist = NULL;
Parallax *parallax = NULL;
Speedometer *speedometer = NULL;
int start, endTime;
int opcao  = 50;
int screenWidth = 1024;
int screenHeight = 720;
int seconds = 0;
int speed = 3;
int startTime = 0;
bool debug;

/*
    Method for controlling fps
*/
void fps()
{
    int frameDelay = 1000/30;
    int frameTime = endTime - start;

    if (frameDelay > frameTime)
        Sleep(frameDelay - frameTime);
}

/*
    Method to draw the squares of the buttons,
    Only designer improvements to make the project
    more beautiful
*/
void RectButton(int x, int y, string label)
{
    CV::color(1, 1, 1);
    CV::rectFill(x, y, x + 60, y + 50);
    CV::color(0, 0, 0);
    float posX = (60 - (label.length() * 10)) / 2;
    float posY = (40 + 8)/2;
    CV::text(x + posX, y + posY, label.c_str());
}

/*
    Method called to draw information from buttons on
    the screen. Just something to make the project more beautiful
*/
void Info()
{
    CV::color(1, 1, 1);
    CV::text(40, 135, "Segure a tecla [>] para acelerar");
    CV::text(40, 115, "e a telcla [<] para desacelerar!");
    CV::text(40, 95, "Tecla [D] para modo debug.");
    RectButton(120,30, "->");
    RectButton(40,30, "<-");
}

/*
    Render the project screen
*/
void render()
{
    // takes the time to later be used in fps control
    start = time(NULL);
    int secNow = time(NULL);
    seconds = secNow - startTime;

    // faint blue color of the sky in the background
    vector<float> rgb = Utils::RGBtoFloat(144, 191, 173);
    CV::clear(rgb[0], rgb[1], rgb[2]);

    // create parallax
    parallax->Render(start, speed, debug);

    // draw a square floor below the cyclist
    rgb = Utils::RGBtoFloat(7, 46, 45);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::rectFill(0 , 0, screenWidth, 150);
    // draw cyclist
    cyclist->Render(speed, debug);
    // draw clock
    clockHud->Render(seconds);
    // draw speedometer
    speedometer->Render(screenWidth, screenHeight, speed, seconds);
    // draw infos
    Info();
    endTime = time(NULL);
    // fps control
    fps();
}

/*
    keyboard input control method
*/
void keyboard(int key)
{
    if( key < 200 )
    {
      opcao = key;
    }

    switch(key)
    {
        case 27:
            exit(0);
            break;
        case 200: //seta para a esquerda Desacelera
            speed --;
            if(speed<3)
                speed=3;
            break;
        case 202: //seta para a direita Acelera
            speed ++;
            if(speed>25)
                speed=25;
            break;
        case 100:
            debug ? debug = false : debug = true;
            break;
    }
}

/*
    keyboard input control method
    not used
*/
void keyboardUp(int key)
{}

/*
    mouse input control method
    not used
*/
void mouse(int button, int state, int wheel, int direction, int x, int y)
{}

/*
    main method that instantiates and destroys objects and starts rendering
*/
int main(void)
{
    startTime = time(NULL);
    clockHud = new ClockHUD(screenWidth, screenHeight, 100, 100);
    cyclist = new Cyclist(screenWidth, screenHeight);
    parallax = new Parallax(screenWidth, screenHeight, startTime);
    speedometer = new Speedometer();

    CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
    CV::run();

    delete clockHud;
    delete cyclist;
    delete parallax;
    delete speedometer;
}

