/**
 * @file platform.hh
 * @brief Especificació de la classe platform
 */
#ifndef PLATFORM_HH
#define PLATFORM_HH

#ifndef NO_DIAGRAM
#include <vector>
#endif
#include "window.hh"

/**
 * @class Platform
 * @brief Representa una plataforma per la cual es pot saltar per sota i caminar
 */
class Platform {
/** Atributs privats */
 private:
    int left_, right_, top_, bottom_;

	static const std::vector<std::vector<int>> platform_texture_;


 public:
    /**
     * @brief Constructora per defecte que crea una plataforma buida (totes les coordenades a 0)
     * \pre cert
     * \post Plataforma creada amb coordenades (0,0,0,0)   
     */
    Platform() : left_(0), right_(0), top_(0), bottom_(0) {}

     /**
     * @brief Constructora de còpia
     * \pre Cert
     * \post Plataforma duplicada amb les mateixes coordenades que 'other'
     * @param other Plataforma a copiar
     */
    Platform(const Platform& other)
        : left_(other.left_), right_(other.right_), top_(other.top_), bottom_(other.bottom_) {}

     /**
     * @brief Constructora amb coordenades específiques
     * @param left Coordenada esquerra de la plataforma
     * @param right Coordenada dreta
     * @param top Coordenada superior
     * @param bottom Coordenada inferior
     * @pre les coordenades formen un rectangle valid
     * @post Plataforma creada amb les coordenades donades
     */
    Platform(int left, int right, int top, int bottom)
        : left_(left), right_(right), top_(top), bottom_(bottom) {}

    /**
     * @brief pintar la plataforma a window
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Determina si s'ha creuat la plataforma cap avall entre dos punts
     * @param plast Punt anterior
     * @param pcurr Punt actual
     * @pre Els punts plast i pcurr representen posicions consecutives d’un objecte
     * @post Retorna true si s’ha creuat el nivell inferior de la plataforma en la direcció cap avall
     */
    bool has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const;
    
    /**
     * @brief Determina si s'ha creuat la plataforma horizontalment entre dos punts
     * @param plast Punt anterior
     * @param pcurr Punt actual
     * @pre Els punts plast i pcurr representen posicions consecutives d’un objecte
     * @post Retorna true si s’ha creuat horizontalment la plataforma 
     */
    bool has_crossed_floor_horizontall(pro2::Pt plast, pro2::Pt pcurr) const;
    
    bool is_pt_inside(pro2::Pt pt) const;
  
    //Consultores 
    int top() const {
        return top_;
    }
    int left() const {
        return left_;
    }
    int right() const{
        return right_;
    }
    int bottom() const{
        return bottom_;
    }
   
    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }
};

#endif