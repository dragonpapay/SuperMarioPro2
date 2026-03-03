/**
 * @file Floppy.hh
 * @brief Especificacio de la classe Floppy
 */

#ifndef Floppy_HH
#define Floppy_HH

#include "window.hh"
#include "mario.hh"
#include "platform.hh"
#include "utils.hh"
#include "geometry.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

enum movement_t {
    STATIC, VERTICAL, HORIZONTAL, WAVE
};

/** @class Floppy
 *  @brief Representa un floppy disk. Aquest pot fer moviments;
 *         Al llarg del window, verticals, horizontals, ondulatoris o be estatic,
 *         en el joc equival a una moneda un objecte amb un valor,
 *         tal que al fer tocar-lo desapareix i incrementa el contador de objectes
 *         recollits pel jugador.
 * 
 */
class Floppy {
private:
    pro2::Pt pos_ {0,0};
    pro2::Pt posini_;
    pro2::Rect rect_f_;

    int height_ = Floppy_sprite_.size();
    int widht_ = Floppy_sprite_[0].size();

    int val_ = 1;
    
    int movement;

    /**
     * @brief  Aplica a floppy un moviment segons el parametre implicit 
     *   Aquesta funció actualitza la posició de l'objecte Floppy en funció del tipus de moviment:
     * - VERTICAL: moviment sinusoidal vertical respecte a la posició inicial.
     * - HORIZONTAL: moviment sinusoidal horitzontal respecte a la posició inicial.
     * - WAVE: moviment lineal horitzontal combinat amb moviment sinusoidal vertical.
     * @param window finestra on es dibuixa Floppy i obtenim el contador de frames
     */
    void apply_physics_f(pro2::Window& window);

public:
    //constructores    
    /**
     * @brief Constructor de la classe Floppy.
     * 
     * @param pos Posició inicial del Floppy en el joc.
     * @param posini Posició original o de referència per al moviment.
     * @param m Tipus de moviment que seguirà el Floppy (especificat per l'enumeració movement_t).
     */
    Floppy(pro2::Pt pos, movement_t m){
        pos_ = pos;
        posini_ = pos;
        movement = m;
    } 
    
    //consultores
    pro2::Pt pos() const {
        return pos_;
    }
    pro2::Rect get_rect() const{
        pro2::Rect hitbox_floppy = {pos_.x -7, pos_.y - 15, pos_.x + 7, pos_.y};
        return hitbox_floppy;
    }
    
    /**
     * @brief  Actualitza la posicio de l'objecte floppy segons el moviment 
     * @param window Finestra en la que es dibuixa a floppy
     * @param platforms Platformes en les que floppy pot ser
     * @param cfloor Circuitfloor en els que floppy pot ser
     */
    void update(pro2::Window& window);
    
    /**
     * @brief  Dibuixa 4 sprites de l'objecte Floppy 
     * @param window Finestra en la que es dibuixa a floppy
     * 
     */
    void paint_f(pro2::Window& window) const;
private:
    //Matrius que contenen els sprites del objecte
    static const std::vector<std::vector<int>> Floppy_sprite_;
    static const std::vector<std::vector<int>> Floppy_sprite_2;
    static const std::vector<std::vector<int>> Floppy_sprite_3;
    static const std::vector<std::vector<int>> Floppy_sprite_4; 

};



#endif