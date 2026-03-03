#include "platform.hh"
using namespace std;

using pro2::Color;

const int b = 0x046307;
const int _ = 0xFFDF00;

// clang-format off
const vector<vector<int>> Platform::platform_texture_ = {
    {b, b, b, b, b, b, _}, 
	{b, b, b, b, b, b, _}, 
	{b, b, b, b, b, b, _}, 
	{_, _, _, _, _, _, _},
    {b, b, b, _, b, b, b}, 
	{b, b, b, _, b, b, b}, 
	{b, b, b, _, b, b, b}, 
	{_, _, _, _, _, _, _},
};
// clang-format on

void Platform::paint(pro2::Window& window) const {
    const int xsz = platform_texture_.size();
    const int ysz = platform_texture_[0].size();
    for (int i = top_ + 1; i <= bottom_; i++) {
        for (int j = left_; j <= right_; j++) {
            window.set_pixel({j, i}, platform_texture_[(i - top_ - 1) % xsz][(j - left_) % ysz]);
        }
    }
}

bool Platform::has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const {
    return (left_ <= plast.x && plast.x <= right_) && (left_ <= pcurr.x && pcurr.x <= right_) &&
           (plast.y <= top_ && pcurr.y >= top_);
}
bool Platform::has_crossed_floor_horizontall(pro2::Pt plast, pro2::Pt pcurr) const {
        bool was_within_y = (top_ <= plast.y and plast.y <= bottom_) and
                            (top_ <= pcurr.y and pcurr.y <= bottom_);
    
        bool was_outside_x = plast.x < left_ or plast.x > right_;
        bool is_inside_x = pcurr.x >= left_ and pcurr.x <= right_;
    
        return was_within_y and was_outside_x or is_inside_x;
    
}
bool Platform::is_pt_inside(pro2::Pt pt) const {
	return left_ <= pt.x && pt.x <= right_ && top_ <= pt.y && pt.y <= bottom_;
}


