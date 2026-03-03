/**
 * @file game.hh
 * @brief Declaració principal de la classe game
 */
#ifndef GAME_HH
#define GAME_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <set>
#include <list>
#endif

#include "Stack.hh"
#include "Finder.hh"
#include "mario.hh"
#include "Floppy.hh"
#include "Cd.hh"
#include "Android.hh"
#include "Bowser.hh"
#include "platform.hh"
#include "window.hh"
#include "utils.hh"
#include "Circuitfloor.hh"
#include "Dictionary.hh"
#include "Background.hh"

/**
 * @brief els estats que té game
 */
enum game_state_s{
    PLAYING, PAUSED, WINED, WASTED, RESTART,

};
/** 
 *
 * @class Game
 * @brief Representa el bucle principal del joc i gestiona tots els objectes, actualitzacions i interaccions.
 *
 * Aquesta classe encapsula tota la lògica del joc, incloent la gestió del jugador (Mario), enemics, 
 * plataformes, decoració, temporitzador i l'estat del joc. També és responsable de pintar i actualitzar 
 * tots els elements visuals i lògics durant l'execució del joc.
 */

class Game {
    /*Atributs privats*/
    Mario                 mario_;
    Bowser                bowser_;
    std::vector<Platform> platforms_;
    std::list<Floppy> Floppys_;
    std::list<Cd> Cds_;
    std::list<Android> Androids_;
    vector<Circuitfloor> cfloor_; 
    
    pro2::Stack<int> timer_stack_; /// Temporitzador implementat amb la classe "Stack.hh"

    Finder<Floppy> finder_floppy_;
    Finder<Cd> finder_cd_;
    Finder<Android> finder_android_;
    Finder<Platform> finder_platrform_;
    Finder<Circuitfloor> finder_cfloor_;
    Finder<Spark> finder_sparks_;
    Finder<Bowser> finder_bowser_;

    
    bool finished_;
    game_state_s state_;
    int counter_;
   
    /**
     * @brief Processa les tecles polsades al teclat
     */
    void process_keys(pro2::Window& window);

    /**
    * @brief Actualitza tots els objectes visibles del joc.
    *
    * Filtra els objectes visibles segons la càmera i actualitza el seu estat,
    * incloent col·lisions, moviments i interaccions amb Mario.
    * @param window finestra on es realitza update
    */
    void update_objects(pro2::Window& window);

    //updates obj individuals

  

    /**
     * @brief Actualitza tots els floppydisk visibles
     */
    void update_floppy(pro2::Window& window, const std::set<Floppy*>& vis_floppys);

     /**
     * @brief Actualitza tots els Cd visibles
     */
    void update_cds(pro2::Window& window, const std::set<Cd*>& vis_cds);

     /**
     * @brief Actualitza tots els Android visibles
     */
    void update_androids(pro2::Window& window,std::set<Android*>& vis_androids,
        const std::set<Platform*>& vis_platforms, const std::set<Circuitfloor*>& vis_cfloor );

    /**
     * @brief Actualitza a bowser
     */
    void update_bowser(pro2::Window& window, std::set<Bowser*>& vis_bowser_ ,std::set<Platform*>& vis_platforms, 
             std::set<Circuitfloor*>& vis_cfloor, const pro2::Rect& mario_rect);

    /**
     * @brief Actualitza a els sparks visibles
     */
    void update_sparks(pro2::Window& window, const std::set<Spark*>& vis_sparks, Mario& mario_);

    /**
     * @brief Mou la camera en funció de la posicio de mario
     */
    void update_camera(pro2::Window& window);

    /**
     * @brief Treu un enter del Stack "timer_stack_" cada segon
     */
    void timer_countdown(pro2::Window& window);

 public:
    /**
     * @brief Constructor de la classe Game
     * @param width Amplada de la finestra de game
     * @param height Alçada de la finestra de game
     */
    Game(int width, int height);

    /**
     * @brief Actualitza tot l’estat del joc
     * @param window Finestra on es mostra el game
     */
    void update(pro2::Window& window);
    /**
     * @brief Pinta tot l'estat del game
     */
    void paint(pro2::Window& window);
    
    /**
     * @brief Pinta tots els objectes (enemics, mario, estructures, floppy...)
     */
    void paint_all_obj(pro2::Window& window);
    /**
     * @brief Pinta el text del timer del joc i el #floppys recollits
     */

    void paint_text_digits(pro2::Window& window);
    /**
     * @brief Pinta els elements decoratius
     */
    void paint_backround(pro2::Window& window);
    
    //consultores 
    bool is_finished() const {
        return finished_;
    }
    bool is_restarted() const {
        return state_ == RESTART;
    }

 private:
    static constexpr int sky_blue = 0x2E4F5A;
};

#endif