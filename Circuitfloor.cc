#include "Circuitfloor.hh"

using namespace std;
using namespace pro2;

//colors
const int _ = 0x00000000; 
const int b = 0x1e1412;
const int lt = 0x769594;
const int g = 0x396b56;
const int t = 0x183c47;
const int y = 0xDAA520;
const int c = 0xc4ab7a;
const int m = 0x77452b;
//Sprite de 32 x 32
const vector<vector<int>> Circuitfloor::circuit_floor_sprite_ = {
    {lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt,lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, g},
    {lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt,lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, lt, t},
    {g, b ,b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, b, g},
    {g, b ,b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, b, g},
    {g, g, g, g, g, g, g, g, c, y, y, m, t, m, y, y, c, g, g, g, g, c, y, y, g, g, g, g, g, g, g, t},
    {g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, y, g, g, g, g, g, g, g, t},
    {g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, y, g, y, y, y, y, c, g, t},
    {g, g, g, g, g, g, g, g, c, g, g, g, g, g, g, g, g, g, g, g, g, g, g, c, g, y, g, g, g, g, g, t},
    {g, g, g, g, g, g, g, g, y, g, g, g, g, g, g, g, t, t, t, b, g, g, g, c, g, y, g, y, y, c, g, t},
    {g, g, g, g, g, g, g, g, y, y, y, c, c, c, y, y, t, t, b, b, m, y, c, c, g, y, g, y, g, g, g, t},
    {g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, t, b, b, b, t, g, g, g, g, y, g, y, g, g, g, t},
    {g, g, g, y, y, y, y, c, c, c, y, y, y, y, y, y, t, b, b, b, m, y, y, c, c, y, g, y, g, g, g, t},
    {g, g, g, c, g, g, g, g, g, g, g, g, g, g, g, g, t, b, b, b, t, g, g, g, g, g, g, y, g, g, g, t},
    {g, g, g, c, g, y, y, y, y, c, c, c, y, y, y, y, t, b, b, b, m, y, y, c, c, c, y, y, g, g, g, t},
    {g, g, g, c, g, y, g, g, g, g, g, g, g, g, g, g, t, b, b, b, t, g, g, g, g, g, g, g, g, g, g, t},
    {g, g, g, c, g, y, g, g, g, g, g, c, c, c, y, y, t, b, b, b, m, y, y, c, c, c, c, g, g, g, g, t}, // 16
    {g, g, t, t, t, t, b, g, g, g, g, c, g, g, g, g, b, b, b, b, t, g, g, g, g, g, c, g, g, g, g, t},
    {g, g, t, b, b, b, b, t, g, g, g, y, g, g, g, g, g, g, t, t, t, g, g, g, g, g, y, g, g, g, g, t},
    {g, g, b, b, b, b, b, t, g, g, g, y, g, g, g, g, g, g, t, t, t, g, g, g, g, g, y, g, g, g, g, t},
    {g, g, g, m, t, m, t, t, g, g, g, y, g, g, g, g, g, g, g, g, g, g, g, g, g, g, y, g, g, g, g, t},
    {g, g, g, y, g, g, g, g, g, g, g, y, g, g, g, g, g, g, g, g, g, g, g, t, t, t, t, b, g, g, g, t},
    {g, g, g, y, g, g, g, g, g, g, g, y, g, g, g, g, g, g, g, g, g, g, g, t, b, b, b, b, t, g, g, t},
    {g, g, g, c, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, b, b, b, b, t, g, g, t},
    {g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, m, t, m, t, t, g, g, t},
    {g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, y, g, y, g, g, g, g, t},
    {g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, c, g, y, g, g, g, g, t},
    {g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, c, g, c, g, g, g, g, t},
    {g, g, g, g, g, c, y, y, m, t, m, y, c, c, g, g, g, g, g, c, y, y, y, y, c, g, c, g, g, g, g, t},
    {g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, c, g, g, g, g, t},
    {g, b, b, g, g, c, y, y, m, t, m, y, c, c, g, g, g, g, c, y, y, y, y, y, y, y, y, g, g, b, b, t},
    {g, b ,b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, b, t},
    {g, g ,g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, t},
    {t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t}
};


void Circuitfloor::paint_circuit_f(pro2::Window& window) const {
    const int xsz = circuit_floor_sprite_.size();
    const int ysz = circuit_floor_sprite_[0].size();
    for (int i = top_ + 1; i <= bottom_; i++) {
        for (int j = left_; j <= right_; j++) {
            window.set_pixel({j, i}, circuit_floor_sprite_[(i - top_ - 1) % xsz][(j - left_) % ysz]);
        }
    }

}

bool Circuitfloor::has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const{
    return (left_ <= plast.x && plast.x <= right_) && (left_ <= pcurr.x && pcurr.x <= right_) &&
    (plast.y <= top_ && pcurr.y >= top_);
}
