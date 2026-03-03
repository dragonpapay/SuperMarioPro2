#include "Android.hh"
#include "utils.hh"
#include <cmath>
using namespace std;
using namespace pro2;

//colors;
const int _ = -1;
const int b = 0x000000;
const int g = 0x0BE60B;
const int w = 0xFFFFFF;

//Sprite de Android 27 X 28 pixels
const vector <vector<int>> Android::Android_sprite_normal_ = {
    {_, _, _, _, _, b, b, _, _, _, _, _, _, _, _, _, _, _, _, _, b, b, _, _, _, _, _},
    {_, _, _, _, _, b, g, b, _, _, _, _, _, _, _, _, _, _, _, b, g, b, _, _, _, _, _},
    {_, _, _, _, _, _, b, g, b, _, _, b, b, b, b, b, _, _, b, g, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, b, g, b, b, g, g, g, g, g, b, b, g, b, _, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, b, b, g, g, g, g, g, g, g, g, g, b, b, _, _, _, _, _, _, _},
    {_, _, _, _, _, _, b, g, g, g, g, g, g, g, g, g, g, g, g, g, b, _, _, _, _, _, _},
    {_, _, _, _, _, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, _, _, _, _, _},
    {_, _, _, _, b, b, g, g, g, g, w, g, g, g, g, g, w, g, g, g, g, b, b, _, _, _, _},
    {_, _, _, _, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, _, _, _, _},
    {_, _, _, _, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, _, _, _, _},
    {_, _, b, _, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, _, b, _, _},
    {_, b, g, b, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, b, g, b, _},
    {b, g, g, g, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, g, g, g, b},
    {b, g, g, g, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, g, g, g, b},
    {b, g, g, g, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, g, g, g, b},
    {b, g, g, g, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, g, g, g, b},
    {b, g, g, g, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, g, g, g, b},
    {b, g, g, g, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, g, g, g, b},
    {_, b, g, b, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, b, g, b, _},
    {_, _, b, _, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, _, b, _, _},
    {_, _, _, _, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, _, _, _, _},
    {_, _, _, _, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, _, _, _, _},
    {_, _, _, _, _, b, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, b, _, _, _, _, _},
    {_, _, _, _, _, _, b, b, g, g, g, g, b, b, b, g, g, g, g, b, b, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, b, g, g, g, g, b, _, b, g, g, g, g, b, _, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, b, g, g, g, g, b, _, b, g, g, g, g, b, _, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, _, b, g, g, b, _, _, _, b, g, g, b, _, _, _, _, _, _, _, _},
    {_, _, _, _, _, _, _, _, _, b, b, _, _, _, _, _, b, b, _, _, _, _, _, _, _, _, _},


};

void Android::paint(pro2::Window& window) const{
    const pro2::Pt topleft = {pos_.x - 14, pos_.y -27};
    paint_sprite(window, topleft, Android_sprite_normal_, looking_left_);

}


void Android::apply_physics_a(){
    if(grounded_){
        speed_.y = 0;
        accel_.y = 0;
    }
    const int gravity = 1;
    
    if (accel_time_ > 0) {
        speed_.y += accel_.y;
        accel_time_--;
    }
    pos_.x += speed_.x;
    pos_.y += speed_.y;
    
    

}

void Android::update_platforms(pro2::Window& window, std::set<Platform*> platforms){

    for (Platform* platform : platforms) {
        //para cada platform coloca a android encima si cruza
        if ((*platform).has_crossed_floor_downwards(last_pos_, pos_)) {
            set_grounded(true);
            set_y((*platform).top());
        }
        
        if((*platform).has_crossed_floor_horizontall(last_pos_, pos_)) {
            pro2::Rect prect = platform->get_rect();
            //hascrossed left
            if(rect_touch(get_rect(), prect)){
                //colision izquierda
                if(last_pos_.x <= prect.left and pos_.x <= prect.right){
                    speed_.x = -speed_.x;
                    
                }
                //colision derecha
                else if(last_pos_.x >= prect.right and  pos_.x >= prect.left){
                    speed_.x = -speed_.x;
                }
            }
        }
        
    }
}
void Android::update_clfoor(pro2::Window& window, std::set<Circuitfloor*> clfoor){
    for(Circuitfloor* cf : clfoor){
        //para cada cfloor coloca a android encima si cruza
        if((*cf).has_crossed_floor_downwards(last_pos_, pos_)){
            set_grounded(true);
            set_y((*cf).top());
        }
        
    }
}


void Android::update(pro2::Window& window, std::set<Platform*> platforms, std::set<Circuitfloor*> cfloor){    
    apply_physics_a();
    update_platforms(window, platforms);
    update_clfoor(window, cfloor);

}

bool Android::mario_has_crossed_downwards(pro2::Pt plast, pro2::Pt pcurr){
    pro2::Rect androidhb = get_rect();
    return (androidhb.left <= plast.x && plast.x <= androidhb.right) && (androidhb.left <= pcurr.x && pcurr.x <= androidhb.right) &&
    (plast.y <= androidhb.top && pcurr.y >= androidhb.top);
}