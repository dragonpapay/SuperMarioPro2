#ifndef GEOMETRY_HH
#define GEOMETRY_HH

namespace pro2 {
/**
 * @brief Punt amb coordenades enters (x, y).
 */
struct Pt {
    int x = 0, y = 0;
};

/**
 * @brief Compara dos punts del pla
 * 
 * La comparació és necessària per poder fer servir `Pt` com la clau d'un `map`.
 * La comparació utilitza primer la coordenada `x` (com si fos més "important"), 
 * i, quan les `x`s són iguals, la coordenada `y`.
 */
inline bool operator<(const Pt& a, const Pt& b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

/**
 * @brief Punt amb coordenades en coma flotant (x, y).
 */
struct Ptd {
    double x, y;
};

/**
 * @brief Converteix un punt en coma flotant a enters.
 * 
 * @param pd Punt amb coordenades double.
 * @return Punt amb coordenades enters.
 */

inline pro2::Pt toPt(pro2::Ptd pd) {
    return {int(pd.x), int(pd.y)};
}

/**
 * @brief Rectangle definit per coordenades esquerra, superior, dreta i inferior.
 * 
 * Les coordenades són enters i defineixen una regió rectangular tancada.
 */
struct Rect {
    int left, top, right, bottom;
};


}

#endif