#include "Cd.hh"
#include <cmath>
using namespace std;
using namespace pro2;

//colors 
const int _ = -1;
const int x = 0x000000;
const int w = 0xffffff; 
const int g = 0x78da91;
const int b = 0x74c0c5;
const int p = 0x989ac3;
const int lp =0xb4b8d3;
const int y = 0xe2efb1;
const int ly =0xedd3a8;
const int c = 0xd9e0ea;
const int t = 0x78bec5;

//sprite cd 28 x28 pixels
const vector<vector<int>> Cd::Cd_sprite_ = {
    {_, _, _, _, _, _, _, _, _, _, x, x, x, x, x, x, x, x, _, _, _, _, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, _, x, x, p, lp, lp, lp, c, c, c, c, x, x, _, _, _, _, _, _, _, _},
    {_, _, _, _, _, _, x, x, t, t, p, lp, lp, lp, c, c, c, c, c, w, x, x, _, _, _, _, _, _},
    {_, _, _, _, _, x, y, g, t, t, p, p, lp, lp, c, c, c, c, w, w, c, w, x, _, _, _, _, _, _},
    {_, _, _, _, x, ly, y, g, g, t, p, p, lp, lp, c, c, c, c, w, c, w, w, w, x, _, _, _, _, _},
    {_, _, _, x, ly, ly, ly, y, g, t, t, p, lp, lp, lp, c, c, w, w, c, w, w, w, w, x, _, _, _},
    {_, _, x, y, y, ly, ly, ly, g, g, t, p, lp, lp, lp, c, c, w, c, w, w, w, w, w, w, x, _, _},
    {_, _, x, g, g, y, ly, ly, y, g, t, p, p, lp, lp, c, w, w, c, w, w, w, w, w, w, x, _, _},
    {_, x, t, g, g, g, g, y, ly, y, g, t, p, lp, lp, c, w, c, w, w, w, w, w, w, w, w, x, _},
    {_, x, t, t, t, t, g, g, y, ly, y, g, b, b, b, b, w, w, w, w, w, w, w, w, w, w, x, _},
    {x, p, p, p, t, t, t, t, g, y, ly, b, _, _, _ , _, b, w, w, w, w, w, c, c, c, c, x},
    {x, p, p, p, p, p, p, p, t, t, b, _, _, _, _, _, _, b, w, w, w, c, c, c, c, c, c, x},
    {x, p, p, p, p, p, p, p, p, b, _, _, _, _, _, _, _, _, b, c, c, c, c, c, c, c, c, x},
    {x, lp, lp, lp, lp, p, p, p, p, b, _, _, _, _, _, _, _, _, b, c, c, c, c, lp, lp, lp, lp, x},
    {x, lp, lp, lp, lp, lp, lp, lp, lp, b, _, _, _, _, _, _, _, _, b, lp, lp, lp, lp, lp, lp, p, p, x},
    {x, lp, lp, lp, lp, lp, lp, c, c, b, _, _, _, _, _, _, _, _, b, t, t, p, p, p, p, p, p, x},
    {x, c, c, c, c, c, c, c, w, w, b, _, _, _, _, _, _, b, g, g, t, t, t, t, p, p, p, x},
    {x, c, c, c, c, c, w, w, w, w, w, b, _, _, _, _, b, y, ly, ly, g, g, g, g, t, t, t, x},  
    {_, x, c, c, w, w, w, w, w, w, w, w, b, b, b, b, p, t, y, ly, ly, y, y, g, g, g, x, _}, 
    {_, x, w, w, w, w, w, w, w, w, c, w, c, c, c, lp, lp, p, t, y, ly, ly, ly, y, y, y, x, _},
    {_, _, x, w, w, w, w, w, w, c, w, w, c, c, lp, lp, p, t, g, y, y, ly, ly, ly, ly, x, _, _},
    {_, _, x, w, w, w, w, w, w, c, w, c, c, c, lp, lp, p, p, t, g, y, ly, ly, ly, ly, x, _, _},
    {_, _, _, x, w, w, w, w, c, w, w, c, c, c, c, lp, lp, lp, p, t, t, g, y, y, x, _, _, _},
    {_, _, _, _, x, w, w, w, c, w, c, c, c, c, c, lp, lp, lp, p, t, t, g, g, x, _, _, _, _},
    {_, _, _, _, _, x, w, c, w, c, c, c, c, c, c, c, lp, lp, p, p, t, t, x, _, _, _, _, _},
    {_, _, _, _, _, _, x, y, w, c, c, c, c, c, c, c, lp, lp, p, p, x, x, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, x, x, c, c, c, c, c, c, c, lp, lp, x, x, _, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, _, _, _, x, x, x, x, x, x, x, x, _, _, _, _, _, _, _, _, _, _}
    
};
 


void Cd::paint_cd(pro2::Window& window) const {
    const Pt top_left = {pos_.x - 14, pos_.y -28}; 
    paint_sprite(window, top_left, Cd_sprite_, false);
  
}

void Cd::apply_physics_cd(pro2::Window& window) {
    if(movement == WAVE_HORIZONTAL){
        int amplx = 10;
        int amply = 10;
        int f = window.frame_count();
        pos_.x = posini_.x + f;       
        pos_.y = posini_.y + sin((f / 2*M_PI)/10) * amply;
   
    }
    
}

void Cd::update(pro2::Window& window){   
    apply_physics_cd(window);
}
    