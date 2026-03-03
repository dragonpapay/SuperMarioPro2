#ifndef UTILS_HH
#define UTILS_HH

#include <vector>
#include "geometry.hh"
#include "window.hh"

namespace pro2 {

/**
 * @brief Dibuja una línea horizontal en la ventana.
 *
 * @param window Ventana en la que se dibuja la línea.
 * @param xini Coordenada x inicial.
 * @param xfin Coordenada x final.
 * @param y Coordenada y.
 * @param color Color de la línea (opcional, si no se pone se asume `white`).
 */
void paint_hline(pro2::Window& window, int xini, int xfin, int y, pro2::Color color = pro2::white);

/**
 * @brief Dibuja una línea vertical en la ventana.
 *
 * @param window Ventana en la que se dibuja la línea.
 * @param x Coordenada x.
 * @param yini Coordenada y inicial.
 * @param yfin Coordenada y final.
 * @param color Color de la línea (opcional, si no se pone se asume `white`).
 */
void paint_vline(pro2::Window& window, int x, int yini, int yfin, pro2::Color color = pro2::white);

/**
 * @brief Dibuixa el marc del joc
 * 
 * @param window Finestra en la que es dibuixa el requadre
 * @param r Rectangle per dibuixar el recuadre
 * @param color Color del requadre 
 * @param size: mida del requadre
 */
void paint_frame(pro2::Window& window, pro2::Rect r, pro2::Color color, int size);

/**
 * @brief Dibuixa un rectangle  en el joc
 * 
 * @param window Finestra en la que es dibuixa el requadre
 * @param r Rectangle a dibuixar
 * @param color Color del rectangle
 */
void paint_rect(pro2::Window& window, pro2::Rect r, pro2::Color color);



/**
 * @brief Determina si dos rectangles s'intersequen es a dir "es toquen"
 * @param r1 Rectangle 1
 * @param r2 Rectangle 2
 */
bool rect_touch(pro2::Rect r1, pro2::Rect r2);


/**
 * @brief Dibuixa una imatge/textura a la finestra a partir d'una posició
 *
 * @param window Finestra a la que pintar
 * @param orig   Origen (cantonada de dalt a l'esquerra) del rectangle que forma el _sprite_
 * @param sprite Matriu de colors que representa la imatge (_sprite_).
 * @param mirror Si cal pintar girar la textura horitzontalment
 */
void paint_sprite(pro2::Window&                        window,
                  pro2::Pt                             orig,
                  const std::vector<std::vector<int>>& sprite,
                  bool                                 mirror);

}  // namespace pro2

#endif