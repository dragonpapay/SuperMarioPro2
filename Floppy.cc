#include "Floppy.hh"
#include <cmath>
using namespace std;
using namespace pro2;

//colors 
const int _ = -1;
const int b = 0x080808, b1 = 0x060606, b2 = 0x040404, b3 = 0x020202;
const int g = 0x444444, g1 = 0x3a3a3a,  g2 = 0x303030,  g3 = 0x262626;
const int gg = 0x232323, gg1 = 0x1f1f1f, gg2 = 0x1b1b1b, gg3 = 0x171717;
const int lg = 0x9d9d9d, lg1 = 0x8a8a8a, lg2 = 0x777777, lg3 = 0x646464;
const int w = 0xffffff, w1 = 0xe5e5e5, w2 = 0xcccccc, w3 = 0xb2b2b2;

const int gr = 0xFF006400;
const int y =  0xFFFFD700;

const vector<vector<int>>Floppy::Floppy_sprite_ = {
    // 16 vert , 14 hor;
    {_, b, b, b, b, b, b, b, b, b, _, _, _, _},
    {b, g, g, gg, lg, lg, lg, lg, lg, lg, b, _, _, _},
    {b, g, g, gg, lg, lg, lg, lg, lg, lg, lg, b, _, _},
    {b, g, g, gg, lg, lg, lg, gg, gg, lg, lg, lg, b, _},
    {b, g, g, gg, lg, lg, lg, gg, gg, lg, lg, lg, lg, b},
    {b, g, g, gg, lg, lg, lg, lg, lg, lg, lg, lg, lg, b},
    {b, g, g, g, g, g, g, g, g, g, g, g, g, b},
    {b, g, g, g, g, g, g, g, g, g, g, g, g, b},
    {b, g, g, g, g, g, g, g, g, g, g, g, g, b},
    {b, g, g, g, g, g, g, g, g, g, g, g, g, b},
    {b, g, g, g, g, g, g, g, g, g, g, g, g, b},
    {b, g, g, w, w, w, w, w, w, w, w, g, g, b},
    {b, g, g, w, w, w, w, w, w, w, w, g, g, b},
    {b, g, g, w, w, w, w, w, w, w, w, g, g, b},
    {b, g, g, w, w, w, w, w, w, w, w, g, g, b},
    {b, g, g, w, w, w, w, w, w, w, w, g, g, b},
    {_, b, b, b, b, b, b, b, b, b, b, b, b, _},
};

const vector<vector<int>> Floppy::Floppy_sprite_2 = {

    {_, b1, b1, b1, b1, b1, b1, b1, b1, b1, _, _, _, _},
    {b1, g1, g1, gg1, lg1, lg1, lg1, lg1, lg1, lg1, b1, _, _, _},
    {b1, g1, g1, gg1, lg1, lg1, lg1, lg1, lg1, lg1, lg1, b1, _, _},
    {b1, g1, g1, gg1, lg1, lg1, lg1, gg1, gg1, lg1, lg1, lg1, b1, _},
    {b1, g1, g1, gg1, lg1, lg1, lg1, gg1, gg1, lg1, lg1, lg1, lg1, b1},
    {b1, g1, g1, gg1, lg1, lg1, lg1, lg1, lg1, lg1, lg1, lg1, lg1, b1},
    {b1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, b1},
    {b1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, b1},
    {b1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, b1},
    {b1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, b1},
    {b1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, g1, b1},
    {b1, g1, g1, w1, w1, w1, w1, w1, w1, w1, w1, g1, g1, b1},
    {b1, g1, g1, w1, w1, w1, w1, w1, w1, w1, w1, g1, g1, b1},
    {b1, g1, g1, w1, w1, w1, w1, w1, w1, w1, w1, g1, g1, b1},
    {b1, g1, g1, w1, w1, w1, w1, w1, w1, w1, w1, g1, g1, b1},
    {b1, g1, g1, w1, w1, w1, w1, w1, w1, w1, w1, g1, g1, b1},
    {_, b1, b1, b1, b1, b1, b1, b1, b1, b1, b1, b1, b1, _},
};

const vector<vector<int>> Floppy::Floppy_sprite_3 = {
    {_, b2, b2, b2, b2, b2, b2, b2, b2, b2, _, _, _, _},
    {b2, g2, g2, gg2, lg2, lg2, lg2, lg2, lg2, lg2, b2, _, _, _},
    {b2, g2, g2, gg2, lg2, lg2, lg2, lg2, lg2, lg2, lg2, b2, _, _},
    {b2, g2, g2, gg2, lg2, lg2, lg2, gg2, gg2, lg2, lg2, lg2, b2, _},
    {b2, g2, g2, gg2, lg2, lg2, lg2, gg2, gg2, lg2, lg2, lg2, lg2, b2},
    {b2, g2, g2, gg2, lg2, lg2, lg2, lg2, lg2, lg2, lg2, lg2, lg2, b2},
    {b2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, b2},
    {b2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, b2},
    {b2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, b2},
    {b2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, g2, b2},
    {b2, g2, g2, w2, w2, w2, w2, w2, w2, w2, w2, g2, g2, b2},
    {b2, g2, g2, w2, w2, w2, w2, w2, w2, w2, w2, g2, g2, b2},
    {b2, g2, g2, w2, w2, w2, w2, w2, w2, w2, w2, g2, g2, b2},
    {b2, g2, g2, w2, w2, w2, w2, w2, w2, w2, w2, g2, g2, b2},
    {b2, g2, g2, w2, w2, w2, w2, w2, w2, w2, w2, g2, g2, b2},
    {_, b2, b2, b2, b2, b2, b2, b2, b2, b2, b2, b2, b2, _},
};

const vector<vector<int>> Floppy::Floppy_sprite_4 = {
    {_, b3, b3, b3, b3, b3, b3, b3, b3, b3, _, _, _, _},
    {b3, g3, g3, gg3, lg3, lg3, lg3, lg3, lg3, lg3, b3, _, _, _},
    {b3, g3, g3, gg3, lg3, lg3, lg3, lg3, lg3, lg3, lg3, b3, _, _},
    {b3, g3, g3, gg3, lg3, lg3, lg3, gg3, gg3, lg3, lg3, lg3, b3, _},
    {b3, g3, g3, gg3, lg3, lg3, lg3, gg3, gg3, lg3, lg3, lg3, lg3, b3},
    {b3, g3, g3, gg3, lg3, lg3, lg3, lg3, lg3, lg3, lg3, lg3, lg3, b3},
    {b3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, b3},
    {b3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, b3},
    {b3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, b3},
    {b3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, g3, b3},
    {b3, g3, g3, w3, w3, w3, w3, w3, w3, w3, w3, g3, g3, b3},
    {b3, g3, g3, w3, w3, w3, w3, w3, w3, w3, w3, g3, g3, b3},
    {b3, g3, g3, w3, w3, w3, w3, w3, w3, w3, w3, g3, g3, b3},
    {b3, g3, g3, w3, w3, w3, w3, w3, w3, w3, w3, g3, g3, b3},
    {b3, g3, g3, w3, w3, w3, w3, w3, w3, w3, w3, g3, g3, b3},
    {_, b3, b3, b3, b3, b3, b3, b3, b3, b3, b3, b3, b3, _},
};




void Floppy::paint_f(pro2::Window& window) const {
    const Pt top_left = {pos_.x - 7, pos_.y -15}; 
    paint_sprite(window, top_left, Floppy_sprite_, false);

    
    int f = window.frame_count();
    if(f / 7 % 4 == 0) paint_sprite(window, top_left, Floppy_sprite_, false);
    else if( f / 7 % 4 == 1)paint_sprite(window, top_left, Floppy_sprite_2, false);
    else if( f / 7 % 4 == 2) paint_sprite(window, top_left, Floppy_sprite_3, false);
    else if( f / 7 % 4 == 3) paint_sprite(window, top_left, Floppy_sprite_4, false);
}



void Floppy::apply_physics_f(pro2::Window& window) {
    
    if(movement == VERTICAL){        
        int ampl = 6;
        int f = window.frame_count();
        pos_.y = posini_.y + sin((f / 2*M_PI)/10) * ampl;
    }   
    else if(movement == HORIZONTAL){
        int ampl = 10;
        int f = window.frame_count();
        pos_.x = posini_.x + sin((f / 2*M_PI)/ 10) * ampl;
    }
    else if(movement == WAVE){
        int amplx = 6;
        int amply = 10;
        int f = window.frame_count();
   
        pos_.x = posini_.x + f;       
        pos_.y = posini_.y + sin((f / 2*M_PI)/10) * amply;
   
    }
    
}



void Floppy::update(pro2::Window& window){   
    apply_physics_f(window);
}
    