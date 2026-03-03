/**
 * @file Circuitfloor.hh
 * @brief Especificació de la classe Circuitfloor
 */
#ifndef Circuitfloor__HH
#define Circuitfloor__HH

#include "window.hh"
#include "utils.hh"
using namespace pro2;
#ifndef NO_DIAGRAM
#include <vector>   
#endif

/**
 * @class Circuitfloor
 * @brief Plataforma de 32 x 32 pixels que es un terra
 */
class Circuitfloor{
    //atributs privats
    private:
    int left_, right_, top_, bottom_;
	static const std::vector<std::vector<int>> circuit_floor_sprite_;


    public:
    //constructores
     /**
     * @brief Constructor per defecte de la classe Circuitfloor.
     * Inicialitza un terra amb coordenades (0,0) i mida 0.
     */
    Circuitfloor() : left_(0), right_(0), top_(0), bottom_(0) {}

    
    /**
     * @brief Constructor de la classe Circuitfloor amb coordenades específiques.
     * Inicialitza el terra amb les coordenades donades per als costats esquerre, dret, superior i inferior.
     * 
     * @param left Coordenada X del costat esquerre del terra.
     * @param right Coordenada X del costat dret del terra.
     * @param top Coordenada Y del costat superior del terra.
     * @param bottom Coordenada Y del costat inferior del terra.
     */
    Circuitfloor(int left, int right, int top, int bottom){
        left_ = left, right_ = right, top_ = top, bottom_ = bottom;
    }


    //consultores
    int bottom() const {
        return bottom_;
    }
    int top() const {
        return top_;
    }
    
    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }

    /**
     * @brief Pinta el sprite de circuit floor
     * @param window finestra on es pinta la plataforma
     */
    void paint_circuit_f(pro2::Window& window) const; 

    /**
     * @brief Comprova si un objecte ha creuat per sota de Circuitfloor
     * @param plast Posicio anterior de l'objecte.
     * @param pcurr Posicio actual de l'objecte.
     * @pre : Cap
     * @post: Retorna true si l'objecte ha travessat el terra cap avall, false  en cas contrari.
     */
    bool has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const;


};

#endif