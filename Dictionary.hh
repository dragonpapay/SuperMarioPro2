/**
 * @file Dictionary.hh
 * @brief Sprites de L'alphabet i dels digits numerics
 */
#ifndef DICTIONARY__HH
#define DICTIONARY__HH

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#endif

#include "window.hh"
#include "utils.hh"

/**
 * @brief Dibuixa a la finestra els digits {0, ... ,9} d'un numero.
 * 
 * @pre : Cap
 * @post: S`ha dibuixat a la finestra el numero "num"
 * @param window finestra en la que es dibuixa
 * @param pos Punt de la finestra on es dibuixa
 * @param num Numero a dibuixar
 */
void paint_digits(pro2::Window& window, pro2::Pt pos, int num);

/**
 * @brief Dibuixa a la finestra els caracters entre {A, ... ,Z}
 * 
 * @pre : La string s conte caracters entre {A, ... ,Z};
 * @post : S'ha dibuixat a la finestra la string s
 * @param window finestra en la que es dibuixa
 * @param pos Punt de la finestra on es dibuixa
 * @param s string 
 */
void paint_letters(pro2::Window& window, pro2::Pt pos, std::string s);

/**
 * @brief Dibuixa el estat de game  "WASTED" a la finestra.
 * @param window Finestra en la qual es dibuixa
 * @pre Cert
 * @post El estat "WASTED" s’ha dibuixat a la finestra
 */
void paint_wasted(pro2::Window& window);

/**
 * @brief Dibuixa el estat de "WINED"  a la finestra.
 * 
 * @param window Finestra en la qual es dibuixa
 * @pre Cert
 * @post El estat "WASTED" s’ha dibuixat a la finestra
 */
void paint_wined(pro2::Window& window);

/**
 * @brief Dibuixa el estat de "PAUSED" a la finestra.
 * 
 * @param window Finestra en la qual es dibuixa
 * @pre Cert
 * @post El estat "PAUSED" s’ha dibuixat a la finestra
 */
void paint_paused(pro2::Window& window);


#endif