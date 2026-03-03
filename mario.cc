#include "mario.hh"
#include "utils.hh"
using namespace std;
using namespace pro2;

const int _ = -1;
const int r = pro2::red;
const int s = 0xecc49b;
const int b = 0x5e6ddc;
const int y = pro2::yellow;
const int h = pro2::black;
const int g = 0xaaaaaa;
const int w = 0x8d573c;

// clang-format off
const vector<vector<int>> Mario::mario_sprite_normal_ = {
    {_, _, _, _, _, r, r, r, r, r, _, _, _, _, _, _},
    {_, _, _, _, r, r, r, r, r, r, r, r, r, _, _, _},
    {_, _, _, _, h, h, h, s, s, h, s, _, _, _, _, _},
    {_, _, _, h, s, h, s, s, s, h, s, s, s, _, _, _},
    {_, _, _, h, s, h, h, s, s, s, h, s, s, s, _, _},
    {_, _, _, h, h, s, s, s, s, h, h, h, h, _, _, _},
    {_, _, _, _, _, s, s, s, s, s, s, s, _, _, _, _},
    {_, _, _, _, r, r, b, r, r, r, _, _, _, _, _, _},
    {_, _, _, r, r, r, b, r, r, b, r, r, r, _, _, _},
    {_, _, r, r, r, r, b, b, b, b, r, r, r, r, _, _},
    {_, _, g, g, r, b, y, b, b, y, b, r, g, g, _, _},
    {_, _, g, g, g, b, b, b, b, b, b, g, g, g, _, _},
    {_, _, g, g, b, b, b, b, b, b, b, b, g, g, _, _},
    {_, _, _, _, b, b, b, _, _, b, b, b, _, _, _, _},
    {_, _, _, w, w, w, _, _, _, _, w, w, w, _, _, _},
};


const vector<vector<int>> Mario::mario_run_frame1_ = {
    {_, _, _, _, _, r, r, r, r, r, _, _, _, _, _, _},
    {_, _, _, _, r, r, r, r, r, r, r, r, r, _, _, _},
    {_, _, _, _, h, h, h, s, s, h, s, _, _, _, _, _},
    {_, _, _, h, s, h, s, s, s, h, s, s, s, _, _, _},
    {_, _, _, h, s, h, h, s, s, s, h, s, s, s, _, _},
    {_, _, _, h, h, s, s, s, s, h, h, h, h, _, _, _},
    {_, _, _, _, _, s, s, s, s, s, s, s, _, _, _, _},
    {_, _, _, _, r, r, b, r, r, r, r, _, _, _, _, _},
    {_, _, _, r, r, r, r, b, b, r, r, r, r, _, _, _},
    {_, _, _, r, r, r, b, b, y, r, r, g, g, _, _, _},
    {_, _, _, r, r, r, r, b, b, b, b, b, b, _, _, _},
    {_, _, _, b, r, r, g, g, g, b, b, b, b, _, _, _},
    {_, _, _, _, b, r, g, g, b, b, b, b, _, _, _, _},
    {_, _, _, _, _, b, b, b, w, w, w, w, _, _, _, _},
    {_, _, _, _, _, w, w, w, w, w, w, w, w, _, _, _},
    {_, _, _, _, _, w, w, w, w, _, _, _, _, _, _, _}
};
const vector<vector<int>> Mario::mario_run_frame2_ = {
    {_, _, _, _, _, r, r, r, r, r, _, _, _, _, _, _},
    {_, _, _, _, r, r, r, r, r, r, r, r, r, _, _, _},
    {_, _, _, _, h, h, h, s, s, h, s, _, _, _, _, _},
    {_, _, _, h, s, h, s, s, s, h, s, s, s, _, _, _},
    {_, _, _, h, s, h, h, s, s, s, h, s, s, s, _, _},
    {_ ,_, _, h, h, s, s, s, s, h, h, h, h, _, _, _},
    {_, _, _, _, _, s, s, s, s, s, s, s, _, _, _, _},
    {_, _, r, r, r, r, b, b, r, r, r, _, _, _, _, _},
    {g, g, r, r, r, r, b, b, b, r, r, r, g, g, g, g},
    {g, g, g, g, r, r, b, y, b, b, b, r, r, g, g, g},
    {g, g, g, _, b, b, b, b, b, b, b, b, _, w, w, _},
    {_, _, _, b, b, b, b, b, b, b, b, b, w, w, w, _},
    {_, _, b, b, b, b, b, b, b, b, b, b, w, w, w, _},
    {_, w, w, b, b, b, b, _, _, b, b, b, w, w, w, _},
    {_, w, w, w, w, _, _, _, _, _, _, _, _, _, _, _},
    {_, _, w, w, w, w, _, _, _, _, _, _, _, _, _, _}

};
const vector<vector<int>> Mario::mario_run_frame3_ = {
    {_, _, _, _, r, r, r, r, r, _, _, _, _, _, _, _},
    {_, _, _, r, r, r, r, r, r, r, r, r, _, _, _, _},
    {_, _, _, h, h, h, s, s, h, s, _, _, _, _, _, _},
    {_, _, h, s, h, s, s, s, h, s, s, s, _, _, _, _},
    {_, _, h, s, h, h, s, s, s, h, s, s, s, _, _, _},
    {_, _, h, h, s, s, s, s, h, h, h, h, _, _, _, _},
    {_, _, _, _, s, s, s, s, s, s, s, _, _, _, _, _},
    {_, _, _, r, r, r, r, y, r, g, g, _, _, _, _, _},
    {_, _, g, r, r, r, r, r, g, g, g, g, _, _, _, _},
    {_, g, g, b, r, r, r, r, g, g, g, _, _, _, _, _},
    {_, w, w, b, b, b, b, b, b, b, _, _, _, _, _, _},
    {_, w, b, b, b, b, b, b, b, b, _, _, _, _, _, _},
    {w, w, b, b, b, b, b, b, b, _, _, _, _, _, _, _},
    {w, w, _, _, _, w, w, w, _, _, _, _, _, _, _, _},
    {_, _, _, _, _, w, w, w, w, _, _, _, _, _, _, _},
};


const vector<vector<int>> Mario::mario_sprite_jump_ = {
    {_, _, _, _, _, _, _, _, _, _, _, _, _, g, g, g},
    {_, _, _, _, _, _, r, r, r, r, _, _, _, g, g, g},
    {_, _, _, _, _, r, r, r, r, r, r, r, r, r, g, g},
    {_, _, _, _, h, h, h, h, s, s, h, s, _, r, r, r},
    {_, _, _, _, h, s, h, s, s, s, h, s, s, s, r, r},
    {_, _, _, _, h, s, h, h, s, s, s, h, s, s, s, r},
    {_, _, _, _, h, h, s, s, s, s, h, h, h, h, h, _},
    {_, _, _, _, _, _, s, s, s, s, s, s, s, h, _, _},
    {_, _, r, r, r, r, r, b, r, r, r, b, r, _, _ ,_},
    {_, r, r, r, r, r, r, r, b, r, r, r, r, _, _, w},
    {g, g, r, r, r, r, r, r, b, b, b, b, b, _, _, w},
    {g, g, g, _, b, b, r, b, b, y, b, b, y, b, w, w},
    {_, g, _, w, b, b, b, b, b, b, b, b, b, b, w, w},
    {_, _, w, w, w, b, b, b, b, b, b, b, b, b, w, w},
    {_, w, w, w, b, b, b, b, b, b, _, _, _, _, _, _},
    {_, w, _, _, b, b, b, _, _, _, _, _, _, _, _, _}
};

//16 x 33
const vector<vector<int>> Mario::mario_big_sprite_normal_{
    {_, _, _, _, _, r, r, r, r, r, _, _, _, _, _, _},
    {_, _, _, r, r, r, r, r, r, y, _, _, _, _, _, _},
    {_, _, r, r, r, r, r, r, y, y, _, _, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, r, r, _, _, _},
    {_, _, h, h, h, s, s, h, s, s, s, _, _, _, _, _},
    {_, h, s, s, h, s, s, h, h, s, s, s, s, _, _, _},
    {_, h, s, s, h, h, s, s, s, s, s, s, s, s, _, _},
    {h, h, s, s, h, h, s, s, s, h, s, s, s, s, _, _},
    {h, h, s, s, s, s, s, h, h, h, h, h, h, _, _, _},
    {h, h, h, h, s, s, s, s, h, h, h, h, h, _, _, _},
    {_, _, h, h, h, s, s, s, s, s, s, s, _, _, _, _},
    {_, _, _, _, b, s, s, s, s, s, r, _, _, _, _, _},
    {_, _, _, _, r, b, r, r, r, r, b, r, _, _, _, _},
    {_, _, _, r, r, b, r, r, r, r, b, r, r, _, _, _},
    {_, _, r, r, r, b, r, r, r, r, b, r, r, r, _, _},
    {_, r, r, r, r, b, r, r, r, r, b, r, r, r, r, _},
    {_, r, r, r, r, b, r, r, r, r, b, r, r, r, r, _},
    {r, r, r, r, b, b, r, r, r, r, b, b, r, r, r, r},
    {r, r, r, r, b, b, r, r, r, r, b, b, r, r, r, r},
    {r, r, r, r, b, b, b, b, b, b, b, b, r, r, r, r},
    {r, r, r, r, b, y, b, b, b, b, y, b, r, r, r, r},
    {g, g, g, g, b, b, b, b, b, b, b, b, g, g, g, g},
    {g, g, g, g, b, b, b, b, b, b, b, b, g, g, g, g},
    {_, g, g, g, b, b, b, b, b, b, b, b, g, g, g, _},
    {_, g, g, b, b, b, b, b, b, b, b, b, b, g, g, _},
    {_, _, b, b, b, b, b, b, b, b, b, b, g, g, _, _},
    {_, b, b, b, b, b, b, _, _, b, b, b, b, b, b, _},
    {_, b, b, b, b, b, _, _, _, _, b, b, b, b, b, _},
    {_, b, b, b, b, b, _, _, _, _, b, b, b, b, b, _},
    {_, _, w, w, w, w, _, _, _, _, w, w, w, w, _, _},
    {_, _, w, w, w, w, _, _, _, _, w, w, w, w, _, _},
    {w, w, w, w, w, w, _, _, _, _, w, w, w, w, w, w},
    {w, w, w, w, w, w, _, _, _, _, w, w, w, w, w, w}
    
};


// clang-format on

void Mario::paint(pro2::Window& window) const {

    if(mario_state == SMALL){
        const Pt top_left = {pos_.x - 8, pos_.y - 15};
        //Pintem els sprites de mario segons el moviment
        if(window.is_key_down(Keys::Space) and not grounded_){
            paint_sprite(window, top_left, mario_sprite_jump_, looking_left_);
        } 
        else if (window.is_key_down(Keys::Left) or window.is_key_down(Keys::Right)) {
            int frame = (pos_.x / 12) % 3;
        
            if (frame == 0) paint_sprite(window, top_left, mario_run_frame1_, looking_left_);
            else if (frame == 1) paint_sprite(window, top_left, mario_run_frame2_, looking_left_);
            
            else paint_sprite(window, top_left, mario_run_frame3_, looking_left_);
        } 
        else paint_sprite(window, top_left, mario_sprite_normal_, looking_left_);
    }
    
    else if (mario_state == BIG){
        const Pt top_left_b = {pos_.x - 8, pos_.y - 32};
        paint_sprite(window, top_left_b, mario_big_sprite_normal_, looking_left_);
        
    }
    

}


void Mario::apply_physics_() {
    if (grounded_) {
        speed_.y = 0;
        accel_.y = 0;
    }

    // Always falling to check if we aren't grounded
    // If we are, we will return to the same spot

    const int gravity = 1;  // gravity = 1 pixel / frame_time^2
    speed_.y += gravity;

    if (accel_time_ > 0) {
        speed_.y += accel_.y;
        accel_time_--;
    }

    pos_.x += speed_.x;
    pos_.y += speed_.y;
}

void Mario::jump() {
    if (grounded_) {
        accel_.y = -6;
        grounded_ = false;
        accel_time_ = 2;
    }
}

void Mario::update_platform(std::set<Platform*> queryplat){
    for (Platform* platform : queryplat) {
        col_platform(platform);
        if ((*platform).has_crossed_floor_downwards(last_pos_, pos_)) {
            set_grounded(true);
            set_y((*platform).top());
        }

        if((*platform).has_crossed_floor_horizontall(last_pos_, pos_)){
            pro2::Rect prect = platform->get_rect();
            //hascrossed left
            if(rect_touch(get_rect(), prect)){

                if(last_pos_.x <= prect.left and pos_.x <= prect.right){
                    //set_grounded(true);
                    set_x(prect.left - 4);
                    
                }
                else if(last_pos_.x >= prect.right and  pos_.x >= prect.left){
                    //set_grounded(true);
                    set_x(prect.right + 4);
                }
            }

        }
        
    }
}

void Mario::update_cfloor(std::set<Circuitfloor*> cfloor){
    for(Circuitfloor* cf : cfloor){
        col_cfloor(cf);
       
    }
}


void Mario::col_platform(Platform* plat){
    if((*plat).has_crossed_floor_downwards(last_pos_, pos_)){
        speed_.y = 0;
        set_grounded(true);
        set_y((*plat).top());
    }
    else {
        pro2::Rect prect = plat->get_rect();
        int dir = collision_direction(prect);
    
        if(dir == 2){
            set_x(prect.left - width/2);
        }
        else if(dir == 3){
            set_x(prect.right + width/2);
        }
    }
}
void Mario::col_cfloor(Circuitfloor* cf){
    if((*cf).has_crossed_floor_downwards(last_pos_, pos_)){
        speed_.y = 0;
        set_grounded(true);
        set_y((*cf).top());
    }
    else {
        pro2::Rect crect = cf->get_rect();
        int dir = collision_direction(crect);
    
        if(dir == 2){
            set_x(crect.left - width/2);
        }
        else if(dir == 3){
            set_x(crect.right + width/2);
        }
    }
}

/***********************************
 * Update Mario general
 ***********************************/
void Mario::update(pro2::Window& window, std::set<Platform*> queryplat, std::set<Circuitfloor*> cfloor) {
    last_pos_ = pos_;
    if (window.is_key_down(Keys::Space)) {
        jump();
    }

    // Velocitat horitzontal
    speed_.x = 0; 
    if (window.is_key_down(Keys::Left)) {
        speed_.x = -4;
    } else if (window.is_key_down(Keys::Right)) {
        speed_.x = 4;
    }
    if (speed_.x != 0) {
        looking_left_ = speed_.x < 0;
    }

    // Apply acceleration and speed
    apply_physics_();
    
    // Check position
    set_grounded(false);
    
    update_platform(queryplat);
    update_cfloor(cfloor);
   
    

    if(frames_immortal_ > 0){
        --frames_immortal_;
    }
}


bool Mario::kill(Android* android){
    if((*android).mario_has_crossed_downwards(last_pos_, pos_)) {
        speed_.y = -5;
        return true;
    }
    else return false;   
    
}
bool Mario::killb(Bowser& bowser){
    pro2::Rect brect = bowser.get_rect();
    if(bowser.mario_has_crossed_downwards(last_pos_, pos_)){
        speed_.y = -5;
        return true;
    }
    
    return false;
}



int Mario::collision_direction(pro2::Rect r){
    pro2::Rect last_rm, rm;
    rm = get_rect();
    last_rm = {last_pos_.x-width/2,last_pos_.y-height+1,last_pos_.x+width/2,last_pos_.y };

    bool is_within_x = (rm.left >= r.left and rm.left <= r.right) or (rm.right >= r.left and rm.right <= r.right);
    bool is_within_y = (rm.top >= r.top and rm.top <= r.bottom) or (rm.bottom >= r.top and rm.bottom <= r.bottom);
    bool up_crossed = last_rm.top <= r.bottom and rm.top >= r.bottom; 
    bool down_crossed = last_rm.bottom <= r.top and rm.bottom >= r.top;
    bool left_crossed = last_rm.right <= r.left and rm.right >= r.left; 
    bool right_crossed = last_rm.left >= r.right and rm.left <= r.right; 
    if(is_within_x and up_crossed) return 1; //UP
    if(is_within_y and left_crossed) return 2; //LEFT
    if(is_within_y and right_crossed) return 3; //RIGHT
    if(is_within_x and down_crossed) return 4; // DOWN
    else return 0; 
    
}
    
