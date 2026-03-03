#include "utils.hh"
using namespace std;

namespace pro2 {

void paint_hline(pro2::Window& window, int xini, int xfin, int y, Color color) {
    for (int x = xini; x <= xfin; x++) {
        window.set_pixel({x, y}, color);
    }
}

void paint_vline(pro2::Window& window, int x, int yini, int yfin, Color color) {
    for (int y = yini; y <= yfin; y++) {
        window.set_pixel({x, y}, color);
    }
}

void paint_frame(pro2::Window& window, pro2::Rect r, pro2::Color color, int size){
    for(int i = 0; i < size; i++){
        // horizontal top
        paint_hline(window, r.left, r.right, r.top + i, color);
        //hor bottom
        paint_hline(window, r.left , r.right, r.bottom - 1 - i, color);

        //vertical l
        paint_vline(window, r.left + i, r.top, r.bottom, color);
        //vertical r
        paint_vline(window, r.right - 1 - i, r.top, r.bottom, color);
    }
}


void paint_rect(pro2::Window& window, pro2::Rect r, pro2::Color color){
    for(int i = r.left ;  i <= r.right; ++i){
        paint_vline(window, i, r.top, r.bottom -1, color);
    }
}



bool rect_touch(Rect r1, Rect r2){
    if (r1.left < r2.right and r1.right > r2.left and r1.top < r2.bottom and r1.bottom > r2.top ) return true;
    return false;
}  

void paint_sprite(pro2::Window&              window,
                  pro2::Pt                   orig,
                  const vector<vector<int>>& sprite,
                  bool                       mirror) {
    for (int i = 0; i < sprite.size(); i++) {
        const vector<int>& line = sprite[i];
        for (int j = 0; j < line.size(); j++) {
            const int _j = mirror ? line.size() - j - 1 : j;
            if (line[_j] >= 0) {
                window.set_pixel({orig.x + j, orig.y + i}, line[_j]);
            }
        }
    }
}

}  // namespace pro2