/**
 * @file mario.hh
 * @brief especificacio de la classe mario
 */
#ifndef MARIO_HH
#define MARIO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
#include <vector>
#endif 
#include "Android.hh"
#include "Bowser.hh"
#include "platform.hh"
#include "window.hh"
#include "Circuitfloor.hh"

/**
 * @brief Estats de mario
 */
enum mario_state_{
   SMALL ,BIG
};

/**
 * @class Mario
 * @brief Representa el protagonista Mario amb moviment, estats i interaccions.
 *
 * La classe Mario gestiona la posició, velocitat, acceleració, estats (petit o gran),
 * col·lisions amb plataformes, enemics, i interaccions amb altres objectes.
 */
class Mario {
 // Atributs privats
 private:
    pro2::Pt pos_, last_pos_;
    pro2::Pt speed_ = {0, 0};
    pro2::Pt accel_ = {0, 0};

    int width,height;
    int frames_immortal_ = 0;
    int frames_immortal_limit = 30;

    pro2::Rect rect_mario_;
    
    int      accel_time_ = 0;
   
    bool grounded_ = false;

	bool looking_left_ = false;
    
    mario_state_ mario_state = SMALL;
    
    /**
     * @brief Aplica la física (moviment, acceleració, gravetat) a Mario.
     * @pre Cert
     * @post L’estat de posició i velocitat s’actualitzen segons les físiques.
    */    
	void apply_physics_();
	
    public:
    /**
     * @brief Constructor de Mario.
     * @param pos Posició inicial de Mario
     */
    Mario(pro2::Pt pos) : pos_(pos), last_pos_(pos) {
        width = 16;
        height = 16;
    }
    
     /**
     * @brief Dibuixa Mario a la finestra.
     * @param window finestra on es dibuixa.
     */
    void paint(pro2::Window& window) const;

    //consultores
    pro2::Pt pos() const {
        return pos_;
    }
    pro2::Pt last_pos() const{
        return last_pos_;
    }

    pro2::Rect get_rect() const {
        pro2::Rect hitbox_mario = {pos_.x - width/2, pos_.y - height + 1, pos_.x + width/2, pos_.y};
        return hitbox_mario;
    }


    int speed_y(){
        return speed_.y;
    }
    

    void set_y(int y) {
        pos_.y = y;
    }
    
    void set_x(int x){
        pos_.x = x;
    }

    bool is_grounded() const {
        return grounded_;
    }
    bool is_big() const {
        return mario_state == BIG;
    }


    bool is_immortal() const {
        return frames_immortal_ > 0;
    }

    //Modificadores

    /**
     * @brief Canvia l'estat de mario a gran o petit.
     * @param s Estat de mario
     * @pre cert
     * @post ajusta mario a l'estat
     */
    void toggle_state(mario_state_ s){
        if(s == SMALL){
            width = 16;
            height = 16;
            frames_immortal_ = frames_immortal_limit;
        }
        else {
            width = 16;
            height = 33;
        }
        
        mario_state = s;
    }

    void set_immortal(){
    
    }


    void set_grounded(bool grounded) {
        grounded_ = grounded;
        if (grounded_) {
            speed_.y = 0;
        }
    }

    void toggle_grounded() {
        set_grounded(!grounded_);
    }
    
    /**
    * @brief Fa saltar a Mario.
    */
    void jump();

    /** @brief Actualitza Mario segons la física, col·lisions i interaccions
    *  @param window Finestra on es dibuixa
    *  @param queryplat Conjunt de plataformes per col·lisions
    *  @param cfloor Conjunt de circuit floors per col·lisions
    *  @pre Cert
    * @post L’estat, posició i accions de Mario s’actualitzen
    */
    void update(pro2::Window& window, std::set<Platform*> queryplat, std::set<Circuitfloor*> cfloor);
    
     /**
     * @brief Actualitza la posició de Mario segons les col·lisions amb les plataformes
     * @param queryplat Conjunt de plataformes amb les quals Mario pot col·lisionar.
     * @pre Cert.
     * @post La posició de Mario s’actualitza tenint en compte les col·lisions amb les plataformes.
     */
    void update_platform(std::set<Platform*> queryplat);
    
    /**
     * @brief Actualitza la posició   de Mario segons les col·lisions amb els cfloor
     * @param cfloor Conjunt de circuit floors amb les quals Mario pot col·lisionar
     * @pre Cert.
     * @post La posició de Mario s’actualitza tenint en compte les col·lisions amb els circuit floors.
     */
    void update_cfloor(std::set<Circuitfloor*> cfloor);


    /**
     * @brief Determina la direcció de la col·lisió entre Mario i un rectangle donat.
     * @param r Rectangle per comprovar la col·lisió
     * @return Un valor enter que indica la direcció de la col·lisió
     */
    int collision_direction(pro2::Rect r);

    /**
     * @brief Comprova si Mario mata a un Android 
     * @param android Punter a l'Android a comprovar
     * @return Cert si Mario mata l'Android, fals en cas contrari
     */
    bool kill(Android* android);

    /**
     * @brief Comprova si Mario mata a Bowser
     * @param bowser Referència a Bowser
     * @return Cert si Mario mata Bowser, fals en cas contrari
     */
    bool killb(Bowser& bowser);


    
    /**
     * @brief Gestiona la colisio amb platform
     */
    void col_platform(Platform* plat);
    /**
     * @brief Gestiona la coliso amb clfoor
     */
    void col_cfloor(Circuitfloor* cf);


 private:
    /**Sptries de mario */
    static const std::vector<std::vector<int>> mario_sprite_normal_;
    static const std::vector<std::vector<int>> mario_run_frame1_;
    static const std::vector<std::vector<int>> mario_run_frame2_;
    static const std::vector<std::vector<int>> mario_run_frame3_;
    static const std::vector<std::vector<int>> mario_sprite_jump_;
    
    static const std::vector<std::vector<int>> mario_big_sprite_normal_;
    

};

#endif