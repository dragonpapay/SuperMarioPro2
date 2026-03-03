/** @file Android.hh
 *  @brief Especificació de la classe Android, que representa un enemic mòbil dins el joc.
 */

#ifndef ANDROID__HH
#define ANDROID__HH
#ifndef NO_DIAGRAM
#include <set>
#endif
#include "platform.hh"
#include "window.hh"
#include "Circuitfloor.hh"

/** @class Android
 *  @brief Representa un enemic Android amb moviment, fisiques i interaccions amb el joc.
 * 
 *  Aquesta classe gestiona la posició, velocitat, estat i comportament de l’enemic Android,
 *  incloent detecció de col·lisions amb plataformes i circuit floors.
 */

class Android {
/**Atributs privats de la classe */
 private:
    pro2::Pt pos_, pos_ini_, last_pos_;
    pro2::Pt speed_ = {-2, 0};
    pro2::Pt accel_ = {0, 0};

    pro2::Rect rect_Android_;
    
    int accel_time_ = 0;

    bool killed_ = false;

    bool grounded_ = false;

    bool looking_left_ = false;
    /** @brief Aplica la física (moviment, acceleració, gravetat) a l'Android
     *  @pre: Cert.
     *  @post L’estat de posició i velocitat s’actualitzen segons les físiques.
     */
    void apply_physics_a();

    /** @brief Conte el sprite de android */
    static const std::vector<std::vector<int>> Android_sprite_normal_;
    

 public:
     /** @brief Constructora per defecte amb posició inicial
      *  @pre pos es valid en el rang del mapa
      *  @post Crea un Android a la posició indicada i amb velocitat; 
      */
    Android(pro2::Pt pos){
        pos_ = pos;
        pos_ini_ = pos;
        last_pos_ = pos;
    }
    /** @brief Dibuixa l'Android a la finestra de joc
     *  @param window finestra on es dibuixa
     *  @pre La finestra està inicialitzada i activa
     *  @post Es representa l'Android en la seva posició actual
     */
    void paint(pro2::Window& window) const;

    /** CONSULTORES DELS ATRIBUTS */
    pro2::Pt pos() const {
        return pos_;
    }
    
    pro2::Rect get_rect() const {
        pro2::Rect hitbox_android = {pos_.x - 14, pos_.y -28, pos_.x + 14, pos_.y};
        return hitbox_android;
    }

    void set_y(int y) {
        pos_.y = y;
    }
    
    void set_x(int x){
        pos_.x = x;
    }

    /** MODIFICADORES */
    void set_killed(bool x){
        killed_ = x;
    }

    bool is_grounded() const {
        return grounded_;
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
     * @brief  Actualitza l'estat de Android segons les colisions i les fisiques
     * @param window Finestra en la que es dibuixa a android
     * @param platforms Platformes en les que android pot colisionar
     * @param cfloor Circuitfloor en els que android pot colisionar
     * @pre Cert
     * @post Andorid actualitza la seva posicio i estat
     */
    void update(pro2::Window& window, std::set<Platform*> platforms, std::set<Circuitfloor*> cfloor);
    /**
     * @brief Actualitza a Android segons les platforms visibles funcio auxiliar de update
     * @param window Finestra en la que es dibuixa a android
     * @param platforms Platformes en les que android pot colisionar
     * @pre Cert
     * @post La posicio d'android s'actualitza amb pos
     */
    void update_platforms(pro2::Window& window, std::set<Platform*> platforms);
    
     /**
     * @brief Actualitza a Android segons els Circuitfloor visibles funcio auxiliar de update
     * @param window Finestra en la que es dibuixa a android
     * @param cfloor Circuitfloor en les que android pot colisio
     * @pre Cert
     * @post La posicio d'android s'actualitza amb pos
     */
    void update_clfoor(pro2::Window& window, std::set<Circuitfloor*> clfoor);
    
    /** @brief Comprova si Mario ha creuat l'android cap avall entre dues posicions
     *  @param plast posicio anterior de mario
     *  @param pcurr posicio actual de mario
     *  @pre Les posicions anteriors i actuals de Mario són valides
     *  @post Retorna cert si Mario ha creuat l'android cap avall
     */
    bool mario_has_crossed_downwards(pro2::Pt plast, pro2::Pt pcurr);

};



#endif