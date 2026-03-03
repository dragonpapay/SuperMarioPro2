/**
 * @file Background.hh
 * @brief Funcions que dibuixen elements decoratius 
 */
#ifndef BACKGROUNG__HH
#define BACKGROUND__HH

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#endif

#include "window.hh"
#include "utils.hh"
/**
 * @brief Dibuixa un nuvol de tempesta en la finestra a una posicio random
 * @param window Finestra en la que es dibuixa la línea
 * @param pos Posicio on es dibuixa el sprite
 * @pre Cap.
 * @post S'ha dibuixat un sprite de nuvol en una posicio determinada de la finestra.
 * 
 */
void paint_clouds(pro2::Window& window, pro2::Pt pos);

#endif