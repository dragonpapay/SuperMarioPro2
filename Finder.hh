/**
 * @file Finder.hh 
 * @brief Classe per a la gestió d'elements i optimització del joc
 */
#ifndef FINDER_HH
#define FINDER_HH
#ifndef NO_DIAGRAM
#include <map>
#include <set>
#endif
#include "geometry.hh"


/**
 * @class Finder
 * @brief Estructura per accelerar cerques espacials mitjançant una quadrícula de cel·les.
 * 
 * Aquesta classe divideix la pantalla en celes de mida fixa i indexa els objectes segons
 * els rectangles que ocupen. Permet afegir, eliminar, actualitzar i cercar objectes que intersecten
 * amb un rectangle donat de forma eficient.
 * 
 * @tparam T Tipus de l'objecte que ha d'implementar la funció "get_rect() " que retorna  pro2::Rect
 */
template <typename T>
class Finder {
private:
  
    int cell_size = 128; // celes de 128 x 128

    std::map <pro2::Pt, std::set< T* > > screensquares; //mapa de les celes i els objectes que s'hi troben a dins
    std::map <T*, std::set<pro2::Pt > > t_cells; //Mapa d'objectes i les cel·les que ocupen

    /**
     * @brief Comprova si dos rectangles s'intersecten.
     * @param r1 Primer rectangle
     * @param r2 Segon rectangle
     * @return Cert si hi ha intersecció
     */
    bool rect_intersects(const pro2::Rect& r1, const pro2::Rect& r2)  {
        if (r1.left <= r2.right and r1.right >= r2.left and r1.top <= r2.bottom and r1.bottom >= r2.top ) return true;
        return false;
    }
    
     /**
     * @brief retorna les celes (per coordenada topleft) que intersecten amb un rectangle.
     * @param r Rectangle 
     * @pre cert
     * @post Conjunt de punts que representen les celes tocades pel rectangle
     */
    std::set <pro2::Pt> get_tl_of_intersections_with_obj(pro2::Rect r) {
        std::set<pro2::Pt> point_intersect;
        pro2::Pt tlobj = {r.left, r.top};
        
        int left = tlobj.x / cell_size;
        int right = r.right / cell_size;
        int top =  tlobj.y / cell_size;
        int bottom = r.bottom / cell_size;

        for(int row = top; row <= bottom; row++){
            for(int col = left; col <= right; col++){

                int cell_x = col * cell_size;
                int cell_y = row * cell_size;
                pro2::Pt tl_cell = {cell_x, cell_y};
                point_intersect.insert(tl_cell);
            }
        }

        return point_intersect;
    }



public:

    Finder() {}

    /**
     * @brief Afegeix un objecte a les celes que el seu rectangle toca.
     * @param t Punter a l'objecte
     * @pre L'objecte te get_rect()
     * @post L'objecte queda indexat dins l'estructura
     */
    void add(T *t){
        pro2::Rect r = t->get_rect();
        std::set<pro2::Pt> intersects = get_tl_of_intersections_with_obj(r);
        std::set<pro2::Pt>::iterator iti = intersects.begin();
        t_cells.insert({t, intersects});
        while (iti != intersects.end()){
            screensquares[*(iti)].insert(t);
            ++iti;
        }
        
    }
    /**
     * @brief Actualitza la posició d’un objecte dins l’estructura.
     * @param t Punter a l’objecte
     * @pre cert
     * @post L’objecte es reindexa segons la seva nova posició
    */
    void update(T *t){
        remove(t);
        add(t);       
    }


    /**
     * @brief Elimina un objecte de l’estructura
     * @param t Punter a l’objecte
     * @pre cert
     * @post L’objecte ja no estarà indexat
     */
    void remove(T *t){
        
        typename std::map<T*, std::set<pro2::Pt>>::iterator it = t_cells.find(t);
        if (it != t_cells.end()){
            
            std::set<pro2::Pt>::iterator cell_it = it->second.begin();
            while (cell_it != it->second.end()){

                typename std::map<pro2::Pt, std::set<T*> >::iterator sq_it = screensquares.find(*cell_it);
                if (sq_it != screensquares.end()) {
                    (*sq_it).second.erase(t);
            
                    if ((*sq_it).second.empty()){
                        screensquares.erase(sq_it);
                    }
                }
                ++cell_it;
            }
            
            t_cells.erase(it);
        }
    }

    /**
     * @brief Retorna el conjunt d'objectes amb rectangles 
     *        total o parcialment dins de `rect`.
     *
     * Si el nombre de rectangles del contenidor és `n`, el 
     * cost de l'algorisme ha de ser O(log n).
     *
     * @param rect El rectangle de cerca
     *
     * @returns Un conjunt de punters a objectes que tenen un 
     *          rectangle parcial o totalment dins de `rect`
     */
    std::set< T *> query(pro2::Rect rect)  {
       typename std::set< T*> res;
        std::set<pro2::Pt> intersects = get_tl_of_intersections_with_obj(rect);
        std::set<pro2::Pt>::iterator it = intersects.begin();

        while(it != intersects.end()){
            typename std::map<pro2::Pt, std::set< T*>>::iterator itcells = screensquares.find(*it);
            if(itcells != screensquares.end()){
                typename std::set< T*>::iterator itobj = (*itcells).second.begin();
                while (itobj != (*itcells).second.end()){
                    T* obj = *itobj;
                    pro2::Rect robj = obj->get_rect();
                    if(rect_intersects(rect, robj)){
                        res.insert(obj);
                    }
                    ++itobj;
                }
            }

            ++it;
        }
        return res;
    }   
    

};
#endif


