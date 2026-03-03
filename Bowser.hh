/**
 * @file Bowser.hh
 * @brief especificacio de la classe Bowser i Spark
 */
#ifndef BOWSER_HH
#define BOWSER_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <cmath>
#endif
#include "Android.hh"
#include "platform.hh"
#include "window.hh"
#include "Circuitfloor.hh"

/**
 * @class Spark
 * @brief Representa una espurna que Bowser llança com a atac.
 * 
 * La classe Spark modela una petita partícula amb física simple que es mou cap a una posició final 
 * i pot causar danys a Mario si el toca. 
 */

class Spark{
    /**Atributs privats */
    private:
    pro2::Ptd pos_, last_pos_, pos_ini_, pos_fi_;
    pro2::Ptd speed_ = {0, 0};
    pro2::Ptd accel_ = {0, 0};
    
    int      accel_time_ = 0;
   
 

    std::list<Spark> sparks_;
     /** @brief Aplica la física (moviment, acceleració, gravetat) a l'espurna
     *  @pre: Cert.
     *  @post L’estat de posició i velocitat s’actualitzen segons les físiques.
     */
    void apply_physicis();
    /**
     * @brief Matriu de sprite de spark
     */
    static const std::vector<std::vector<int>> spark_sprite_normal_;

    public:
    /** 
     * @brief Constructor de l'espurna que ja va en la ultima direcció de mario
     * @param pos Posició inicial
     * @param pos_fi Posició final a la que es dirigeix
     */
    Spark(pro2::Ptd pos, pro2::Ptd pos_fi): pos_(pos),pos_ini_(pos_),pos_fi_(pos_fi) {
        
        //calcul de la direcio vectorial
        pro2::Ptd dir = {pos_fi_.x - pos_ini_.x,pos_fi_.y - pos_ini_.y};
        
        double mod = sqrt(dir.x*dir.x + dir.y*dir.y);
        if(mod != 0){
            speed_.x = dir.x  / mod *5;
            speed_.y = dir.y / mod *5;
        }
        accel_ = {0, 0.3};
        
    }
    
    /** @brief Pintar l'espurna a la finestra */
    void paint(pro2::Window& window) const;
    
    /** Consultores */
    pro2::Ptd pos() const {
        return pos_;
    }
    
    pro2::Ptd last_pos() const{
        return last_pos_;
    }
    double speed_y(){
        return speed_.y;
    }
    
    pro2::Rect get_rect() const {                       
        pro2::Pt point = toPt(pos_);
        pro2::Rect hitbox_spark = {point.x - 7, point.y - 9, point.x + 7, point.y+9};
        return hitbox_spark;
    }

    /**Modificadores */
    void set_y(double y) {
        pos_.y = y;
    }

    void set_x(double x){
        pos_.x = x;
    }
    
    /**
     * @brief Actualitza l'estat de l'objecte, aplicant física i moviment
     * @param window Referència a la finestra on es dibuixa i on es processa l'estat.
     * @pre Cert
     * @post L'estat i la posició queden actualitzades.
     */
    void update(pro2::Window& window);

    /**
     * @brief Comprova si l'objecte ha matat a Mario a partir del seu rectangle de col·lisió
     * @param rmario rectangle de mario dins window
     * @pre El rectangle rmario es troba dins els límits de la finestra window
     * @post Retorna cert si l'objecte ha col·lisionat amb Mario, false en cas contrari
     */
    bool mario_killed(const pro2::Rect& rmario);
};

/**********************
 * BOWSER
 **********************/


enum bowser_state_s{
    ALIVE, DEAD
};
/** @class Bowser
 *  @brief Representa l'enemic Bowser amb moviment, atacs i física.
 *
 *  La classe Bowser gestiona la posició, velocitat, estat (viu o mort), moviment, salts,
 *  llançament d'espurnes i interaccions amb Mario i l'entorn.
 */
class Bowser {
    //Atributs privats
    private:
    std::list<Spark> sparks_; /**< Llista d'espurnes a llençar */
    pro2::Pt pos_, last_pos_;
    pro2::Pt speed_ = {0, 0};
    pro2::Pt accel_ = {0, 0};

    pro2::Rect rect_Bowser_;
    
    double      accel_time_ = 0;
   
    bool grounded_ = false;

    bowser_state_s bstate = ALIVE;

	bool looking_left_ = true;
    /** @brief Aplica la física (moviment, acceleració, gravetat) a Bowser
     *  @pre: Cert.
     *  @post L’estat de posició i velocitat s’actualitzen segons les físiques.
     */
	void apply_physics_();
    
    
	
 public:

    /** @brief Constructor de Bowser
     *  @param pos Posició inicial de Bowser
     */
    Bowser(pro2::Pt pos) : pos_(pos), last_pos_(pos) {}
     
    /** @brief Dibuixa Bowser a la finestra */
    void paint(pro2::Window& window) const;
    /* Consultores  */
    pro2::Pt pos() const {
        return pos_;
    }
    pro2::Pt last_pos() const{
        return last_pos_;
    }

    pro2::Rect get_rect() const {                       
        pro2::Rect hitbox_bowser = {pos_.x - 32, pos_.y - 55, pos_.x + 32, pos_.y};
        return hitbox_bowser;
    }

    std::list<Spark> get_sparks(){
        return sparks_;
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
   
    bowser_state_s bowser_state(){
        return bstate;
    }
    /*Modificadores*/
    void set_grounded(bool grounded) {
        grounded_ = grounded;
        if (grounded_) {
            speed_.y = 0;
        }
    }

    void toggle_state(bowser_state_s s){
        bstate = s;
    }

    void toggle_grounded() {
        set_grounded(!grounded_);
    }
  
    /**
     * @brief Fa saltar a bowser
     */
    void jump();

    /**
     * @brief Actualitza la posició i estat de Bowser segons les colisions amb les plataformes
     * @param queryplat Conjunt de plataformes amb les quals Bowser pot colisionar
     * @pre Cert
     * @post L’estat i posició de Bowser s’actualitza tenint en compte les colisions amb les plataformes
     */
    void update_platform(std::set<Platform*>& queryplat);

    /**
     * @brief Actualitza la posició i estat de Bowser segons les col·lisions amb els circuit floors.
     * @param cfloor Conjunt de circuit floors amb les quals Bowser pot col·lisionar.
     * @pre Cert
     * @post L’estat i posició de Bowser s’actualitza tenint en compte les col·lisions amb els circuit floors.
     */

    void update_cfloor(std::set<Circuitfloor*>& cfloor);
    
    /** @brief Actualitza Bowser segons la física, col·lisions i interaccions
     *  @param window Finestra on es dibuixa
     *  @param queryplat Conjunt de plataformes per col·lisions
     *  @param cfloor Conjunt de circuit floors per col·lisions
     *  @param rmario Hitbox de Mario
     *  @param mkilled Referència per indicar si Mario ha mort
     *  @pre Cert
     * @post L’estat, posició i accions de Bowser s’actualitzen; si Bowser mata Mario, mkilled queda a true.
     */
    void update(pro2::Window& window, std::set<Platform*>& queryplat, std::set<Circuitfloor*>& cfloor,const pro2::Rect& rmario,  bool& mkilled);
    
    /**
     * @brief Llança una espurna  des de Bowser cap a Mario 
     * @param rmario Rectangle que representa la hitbox de Mario, per orientar el llançament
     * @pre Cert
     * @post S’afegeix una nova espurna a la llista de projectils de Bowser, dirigida cap a Mario
     */
    void launch_spark(const pro2::Rect& rmario);
    
    /**
     * @brief Comprova si Mario ha creuat Bowser en moviment descendent
     * @param plast Posició anterior de Mario
     * @param pcurr Posició actual de Mario
     * @pre plast i pcurr són posicions vàlides
     * @post Retorna cert si Mario ha creuat cap avall la posició de Bowser entre plast i pcurr; fals en cas contrari
     */
    bool mario_has_crossed_downwards(pro2::Pt plast, pro2::Pt pcurr) const;

 private:
    /**
     * @brief Matriu de sprites de bowser
     */
    static const std::vector<std::vector<int>> bowser_sprite_normal_;
    
    
  
};

#endif