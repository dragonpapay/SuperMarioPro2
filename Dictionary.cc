#include "Dictionary.hh"
using namespace std;
//colors
const int _ = -1; 
const int w = 0xdce4e6;
//Matriu de digits {0..9}
const vector<vector<vector<int>>> numsprites{

    {{_, w, w, w, w, _},
     {w, w, _, _ , w, w},
     {w, w, _, _ , w, w},
     {w, w, _, _ , w, w},
     {w, w, _, _ , w, w},
     {w, w, _, _ , w, w},
     {w, w, _, _ , w, w},
     {_, w, w, w, w, _}}, // 0

    {{_, _, _, w, w, _},
     {_, _, w, w, w, _},
     { _, _, _, w, w, _},
     { _, _, _, w, w, _},
     { _, _, _, w, w, _},
     { _, _, _, w, w, _},
     { _, _, _, w, w, _},
     { _, _, w, w, w, w}}, // 1

    {{_, w, w, w, w, _},
     {w, w, _, _, w, w},
     {_, _, _, _, w, w},
     {_, _, _, _, w, w},
     {_, _, w, w, w, _},
     {_, w, w, _, _, _},
     {w, w, _, _, _, _},
     {w, w, w, w, w, w}}, // 2
    
    {{_, w, w, w, w, _},
    {w, w, _, _, w, w},
    {_, _, _, _, w, w},
    {_, _, _, _, w, w},
    {_, _, w, w, w, _},
    {_, _, _, _, w, w},
    {w, w, _, _, w, w},
    {_, w, w, w, w, _}}, // 3

    {{w, w, _, _, w, w},
    {w, w, _, _, w, w},
    {w, w, _, _, w, w},
    {w, w, _, _, w, w},
    {_, w, w, w, w, w},
    {_, _, _, _, w, w},
    {_, _, _, _, w, w},
    {_, _, _, _, w, w}}, // 4

    {{w, w, w, w, w, w},
     {w, w, _, _, _, _},
     {w, w, w, w, w, _},
     {_, _, _, _, w, w},
     {_, _, _, _, w, w},
     {_, _, _, _, w, w},
     {w, w, _, _, w, w},
     {_, w, w, w, w, _}}, // 5

    {{_, w, w, w, w, _},
    {w, w, _, _, w, w},
    {w, w, _, _, _, _},
    {w, w, w, w, w, _},
    {w, w, _, _, w, w},
    {w, w, _, _, w, w},
    {w, w, _, _, w, w},
    {_, w, w, w, w, _}}, // 6

    {{w, w, w, w, w, w},
     {_, _, _, _, w, w},
     {_, _, _, w, w, _},
     {_, _, w, w, _, _},
     {_, _, w, w, _, _},
     {_, _, w, w, _, _},
     {_, _, w, w, _, _},
     {_, _, w, w, _, _}}, //7

    {{_, w, w, w, w, _},
    {w, w, _, _, w, w},
    {w, w, _, _, w, w},
    {_, w, w, w, w, _},
    {w, w, _, _, w, w},
    {w, w, _, _, w, w},
    {w, w, _, _, w, w},
    {_, w, w, w, w, _}}, // 8

    {{_, w, w, w, w, _},
    {w, w, _, _, w, w},
    {w, w, _, _, w, w},
    {_, w, w, w, w, w},
    {_, _, _, _, w, w},
    {_, _, _, _, w, w},
    {w, w, _ ,_, w, w},
    {_, w, w, w, w, _}}, // 9
};

//Matriu de caracters{A..Z}
const vector<vector<vector<int>>> lettersprites{

    {{_, _, w, w, w, _, _},  // A
     {_, w, w, _, w, w, _},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, w, w, w, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w}},

    {{w, w, w, w, w, w, _},  // B
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, w, w, w, w, _},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, w, w, w, w, _}},

    {{_, _, w, w, w, w, _},  // C
     {_, w, w, _, _, w, w},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {_, w, w, _, _, w, w},
     {_, w, w, w, w, w, _}},

    {{w, w, w, w, w, _, _},  // D
     {w, w, _, _, w, w, _},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, w, w, _},
     {w, w, w, w, w, _, _}},

    {{w, w, w, w, w, w, w},  // E
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, w, w, w, w, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, w, w, w, w, w}},

    {{w, w, w, w, w, w, w},  // F
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, w, w, w, w, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _}},

    {{_, _, w, w, w, w, w},  // G
     {_, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, w, w, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {_, w, _, _, _, w, w},
     {_, _, w, w, w, w, _}},

    {{w, w, _, _, _, w, w},  // H
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, w, w, w, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w}},

    {{w, w, w, w, w, w, _},  // I
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {w, w, w, w, w, w, _}},

    {{_, _, _, w, w, w, w},  // J
     {_, _, _, _, _, w, w},
     {_, _, _, _, _, w, w},
     {_, _, _, _, _, w, w},
     {_, _, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {_, w, w, w, w, w, _}},

    {{w, w, _, _, _, w, w},  // K
     {w, w, _, _, w, w, _},
     {w, w, _, w, w, _, _},
     {w, w, w, w, _, _, _},
     {w, w, w, w, w, _, _},
     {w, w, _, w, w, _, _},
     {w, w, _, _, w, w, _},
     {w, w, _, _, w, w, w}},

    {{w, w, _, _, _, _, _},  // L
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, w, w, w, w, w}},

    {{w, w, _, _, _, w, w},  // M
     {w, w, w, _, w, w, w},
     {w, w, w, w, w, w, w},
     {w, w, _, w, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w}},

    {{w, w, _, _, _, w, w},  // N
     {w, w, w, _, _, w, w},
     {w, w, w, w, _, w, w},
     {w, w, w, w, w, w, w},
     {w, w, w, w, w, w, w},
     {w, w, _, w, w, w, w},
     {w, w, _, _, w, w, w},
     {w, w, _, _, _, w, w}},

    {{_, w, w, w, w, w, _},  // O
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {_, w, w, w, w, w, _}},

    {{w, w, w, w, w, w, _},  // P
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, w, w, w, w, w},
     {w, w, _, _, _, _, _},
     {w, w, _, _, _, _, _}},

    {{_, w, w, w, w, w, _},  // Q
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, w, _, w, w},
     {w, w, _, _, w, w, _},
     {_, w, w, w, w, _, w}},

     {{w, w, w, w, w, w, _},  // R
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, w, w, w},
     {w, w, w, w, w, _, _},
     {w, w, _, w, w, w, _},
     {w, w, _, _, w, w, w}},

    {{_, w, w, w, w, w, _},  // S
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, _, _},
     {_, w, w, w, w, w, _},
     {_, _, _, _, _, w, w},
     {_, _, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {_, w, w, w, w, w, _}},

    {{w, w, w, w, w, w, _},  // T
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _},
     {_, _, w, w, _, _, _}},

    {{w, w, _, _, _, w, w},  // U
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {_, w, w, w, w, w, _}},

    {{w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},  // V
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {_, w, w, _, w, w, _},
     {_, _, w, w, w, _, _},
     {_, _, _, w, _, _, _}},

    {{w, w, _, _, _, w, w},  // W
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, _, _, w, w},
     {w, w, _, w, _, w, w},
     {w, w, w, w, w, w, w},
     {w, w, w, _, w, w, w},
     {w, w, _, _, _, w, w}},

    {{w, w, _, _, _, w, w},  // X
     {_, w, w, _, w, w, _},
     {_, _, w, w, w, _, _},
     {_, _, _, w, _, _, _},
     {_, _, _, w, _, _, _},
     {_, _, w, w, w, _, _},
     {_, w, w, _, w, w, _},
     {w, w, _, _, _, w, w}},

    {{w, w, _, _, _, w, w},  // Y
     {_, w, w, _, w, w, _},
     {_, _, w, w, w, _, _},
     {_, _, _, w, _, _, _},
     {_, _, _, w, _, _, _},
     {_, _, _, w, _, _, _},
     {_, _, _, w, _, _, _},
     {_, _, _, w, _, _, _}},

    {{w, w, w, w, w, w, w},  // Z
     {_, _, _, _, _, w, w},
     {_, _, _, _, w, w, _},
     {_, _, _, w, w, _, _},
     {_, _, w, w, _, _, _},
     {_, w, w, _, _, _, _},
     {w, w, _, _, _, _, _},
     {w, w, w, w, w, w, w}},
    
};


void paint_digits(pro2::Window& window, pro2::Pt pos, int num){
    if(num < 10){
        paint_sprite(window, pos, numsprites[num], false);
    }
    //Si num >10 pintem a la seva esquerra els digits que queden
    else{
        int i = 0;
        while(num > 0){
            int  digit  = num % 10;
            paint_sprite(window, {pos.x - i, pos.y}, numsprites[digit], false);
            i += 8;
            num/=10;
        }
    }

}

void paint_letters(pro2::Window& window, pro2::Pt pos, string s) {
    int length = s.length();
    for(int i = 0; i < length; i++){
        char c = s[i];
        int index = c - 'A';
        if(c != ' ') paint_sprite(window, {pos.x + i * 10, pos.y}, lettersprites[index], false);
        if(c == ' ') pos.x += 3;
    }    
}

void paint_wasted(pro2::Window& window){
    pro2::Rect wrect = window.camera_rect();
    //Posicio text
    pro2::Pt wpos = {window.camera_center().x - 30, window.camera_center().y- 20};
    pro2::Pt restart_pos = {wpos.x - 50, wpos.y + 25};
    paint_rect(window, wrect, pro2::black);
    paint_letters(window, wpos, "WASTED");
    paint_letters(window,restart_pos , "PRESS R TO RESTART");
}

void paint_wined(pro2::Window& window){
    pro2::Rect wrect = window.camera_rect();
    paint_rect(window, wrect, pro2::wined);

    //Text wined i restart
    pro2::Pt wpos = {window.camera_center().x - 30, window.camera_center().y - 20};
    pro2::Pt restart_pos = {wpos.x - 50, wpos.y + 25};
    paint_letters(window, wpos, "WINED");
    paint_letters(window, restart_pos, "PRESS R TO RESTART");

    //Dibuixar confetis
    for (int i = 0; i < 100; i++) {
        // pos aleatories
        int x = rand() % window.width() + window.camera_rect().left;
        int y = rand() % window.height() + window.camera_rect().top;

        //colors random
        int color = rand() % 0xffffff;
        //rectangles simulant confeti
        pro2::Rect confeti_rect = {x, y, x + 2, y + 2};
        paint_rect(window, confeti_rect, color);
    }

}

void paint_paused(pro2::Window& window){
    pro2::Pt pause = {window.topleft().x + window.width()/2, window.topleft().y + window.height()/2 -20};
    paint_letters(window, pause, "PAUSE");
}