/**
 * @file Cd.hh
 * @brief Especificacio de la classe Cd
 */

 #ifndef Cd_HH
 #define Cd_HH
 
 #include "window.hh"
 #include "mario.hh"
 #include "platform.hh"
 #include "utils.hh"
 #include "geometry.hh"
 
 #ifndef NO_DIAGRAM
 #include <iostream>
 #include <vector>
 #endif
 
 enum movement_tc {
    //se pueden hacer mas tipos de movimineto;
    WAVE_HORIZONTAL, STATIC_C
 };
 
 /** @class Cd
  *  @brief Representa un Cd, que es pot moure i ser recollit pel jugador
  *         els moviments de l'objecte son sinusoidal i estatic
  *         la seva funció en el joc es la mateixa que un "mushroom" original del mario
  */
class Cd {
   /**Atributs privats */
 private:
   pro2::Pt pos_ {0,0};
   pro2::Pt posini_;
   pro2::Rect rect_cd_;

   int height_ = Cd_sprite_.size();
   int widht_ = Cd_sprite_[0].size();

   int movement;

   /**
    * @brief  Aplica a Cd un moviment segons el parametre implicit 
    *   Aquesta funció actualitza la posició de l'objecte Cd en funció del tipus de moviment:
    *  - WAVE_HORIZONTAL: Moviment sinusoidal horizontal constant
    * @param window finestra on es dibuixa Cd i obtenim el contador de frames
    */
   void apply_physics_cd(pro2::Window& window);

 public:
    //constructores
    /**
     * @brief Constructor del Cd.
     * @param pos Posició inicial del Cd.
     * @param posini Posició original per a càlculs de moviment.
     * @param m Tipus de moviment 
     */
     Cd(pro2::Pt pos, movement_tc m){
        pos_ = pos;
        posini_ = pos;
        movement = m;
     } 
     
     //consultores
     pro2::Pt pos() const {
        return pos_;
     }
     pro2::Rect get_rect() const{
        pro2::Rect hitbox_cd = {pos_.x - 14, pos_.y - 27, pos_.x + 14, pos_.y};
        return hitbox_cd;
     }
     
     /**
      * @brief  Actualitza la posicio de l'objecte cd segons el moviment 
      * @param window Finestra en la que es dibuixa a cd
      * @param platforms Platformes en les que cd pot ser
      * @param cfloor Circuitfloor en els que cd pot ser
      */
     void update(pro2::Window& window);
     
     /**
      * @brief  Dibuixa el sprite de l'objecte Cd 
      * @param window Finestra en la que es dibuixa a cd
      * 
      */
     void paint_cd(pro2::Window& window) const;
     
 private:
     //Matriu que contenen els sprites del objecte
     static const std::vector<std::vector<int>> Cd_sprite_;
  
 };
 
 
 
 #endif