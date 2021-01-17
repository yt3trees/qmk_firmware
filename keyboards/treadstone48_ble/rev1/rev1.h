/*
 * rev1.h
 *
 *  Created on: 2019/01/01
 *      Author: Sekigon
 */

#ifndef KEYBOARDS_TREADSTONE48_BLE_REV1_REV1_H_
#define KEYBOARDS_TREADSTONE48_BLE_REV1_REV1_H_

#include "quantum.h"

// full Keymap
// (TRRS jack on the left half is to the right, TRRS jack on the right half is to the left)
#define LAYOUT_FULL( \
  L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, R00, R01, R02, R03, R04, R05, R40, R41, R42, R43, R44, R45, \
  L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, R10, R11, R12, R13, R14, R15, R50, R51, R52, R53, R54, R55, \
  L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, R20, R21, R22, R23, R24, R25, R60, R61, R62, R63, R64, R65, \
  L30, L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75, R30, R31, R32, R33, R34, R35, R70, R71, R72, R73, R74, R75 \
  ) \
  { \
    { L45, L44, L43, L42, L41, L40 }, \
    { L55, L54, L53, L52, L51, L50 }, \
    { L65, L64, L63, L62, L61, L60 }, \
    { L75, L74, L73, L72, L71, L70 }, \
    { L05, L04, L03, L02, L01, L00 }, \
    { L15, L14, L13, L12, L11, L10 }, \
    { L25, L24, L23, L22, L21, L20 }, \
    { L35, L34, L33, L32, L31, L30 }, \
    { R45, R44, R43, R42, R41, R40 }, \
    { R55, R54, R53, R52, R51, R50 }, \
    { R65, R64, R63, R62, R61, R60 }, \
    { R75, R74, R73, R72, R71, R70 }, \
    { R05, R04, R03, R02, R01, R00 }, \
    { R15, R14, R13, R12, R11, R10 }, \
    { R25, R24, R23, R22, R21, R20 }, \
    { R35, R34, R33, R32, R31, R30 }, \
  }

#define K_N KC_NO

//////////////////////////////////////////////////////////////////////////////
// When only use Treadstone48.
// L75 is ExtraKey
//////////////////////////////////////////////////////////////////////////////
#define LAYOUT_BASE( \
  L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, \
  L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, \
  L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, \
  L30, L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75  \
  ) \
  LAYOUT_FULL( \
    L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, \
    L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, \
    L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, \
    L30, L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N, K_N  \
  )

// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT_BASE_kc( \
  L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, \
  L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, \
  L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, \
  L30, L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75  \
  ) \
  LAYOUT_BASE( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##L40, KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_##L45, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##L50, KC_##L51, KC_##L52, KC_##L53, KC_##L54, KC_##L55, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##L60, KC_##L61, KC_##L62, KC_##L63, KC_##L64, KC_##L65, \
    KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##L70, KC_##L71, KC_##L72, KC_##L73, KC_##L74, KC_##L75  \
  )
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// When connecting Rhymestone to Treadstone48.
// L75 is ExtraKey
//////////////////////////////////////////////////////////////////////////////
#define LAYOUT_RS( \
  L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, \
  L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, R50, R51, R52, R53, R54, \
  L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, R60, R61, R62, R63, R64, \
  L30, L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, R70, R71, R72, R73, R74, L75  \
  ) \
  LAYOUT_FULL( \
    L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, K_N, K_N, K_N, K_N, K_N, K_N, K_N, R44, R43, R42, R41, R40, \
    L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, K_N, K_N, K_N, K_N, K_N, K_N, K_N, R54, R53, R52, R51, R50, \
    L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, K_N, K_N, K_N, K_N, K_N, K_N, K_N, R64, R63, R62, R61, R60, \
    L30, L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75, K_N, K_N, K_N, K_N, K_N, K_N, K_N, R74, R73, R72, R71, R70  \
  )

// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT_RS_kc( \
  L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, \
  L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, R50, R51, R52, R53, R54, \
  L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, R60, R61, R62, R63, R64, \
  L30, L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75, R70, R71, R72, R73, R74  \
  ) \
  LAYOUT_RS( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##L40, KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_##L45, KC_##R40, KC_##R41, KC_##R42, KC_##R43, KC_##R44, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##L50, KC_##L51, KC_##L52, KC_##L53, KC_##L54, KC_##L55, KC_##R50, KC_##R51, KC_##R52, KC_##R53, KC_##R54, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##L60, KC_##L61, KC_##L62, KC_##L63, KC_##L64, KC_##L65, KC_##R60, KC_##R61, KC_##R62, KC_##R63, KC_##R64, \
    KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##L70, KC_##L71, KC_##L72, KC_##L73, KC_##L74, KC_##L75, KC_##R70, KC_##R71, KC_##R72, KC_##R73, KC_##R74  \
  )
//////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////
// Alpha version keymap.
// L30 is ExtraKey
//////////////////////////////////////////////////////////////////////////////
#define LAYOUT_ALPHA_kc( \
  L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, \
  L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, \
  L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, \
  L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75, L30  \
  ) \
  LAYOUT_BASE( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##L40, KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_##L45, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##L50, KC_##L51, KC_##L52, KC_##L53, KC_##L54, KC_##L55, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##L60, KC_##L61, KC_##L62, KC_##L63, KC_##L64, KC_##L65, \
    KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##L70, KC_##L71, KC_##L72, KC_##L73, KC_##L74, KC_##L75  \
  )

#define LAYOUT_ALPHA_RS( \
  L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, \
  L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, R50, R51, R52, R53, R54, \
  L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, R60, R61, R62, R63, R64, \
  L30, L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75, R70, R71, R72, R73, R74  \
  ) \
  LAYOUT_FULL( \
    L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, K_N, K_N, K_N, K_N, K_N, K_N, K_N, R44, R43, R42, R41, R40, \
    L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, K_N, K_N, K_N, K_N, K_N, K_N, K_N, R54, R53, R52, R51, R50, \
    L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, K_N, K_N, K_N, K_N, K_N, K_N, K_N, R64, R63, R62, R61, R60, \
    L30, L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75, K_N, K_N, K_N, K_N, K_N, K_N, K_N, R74, R73, R72, R71, R70  \
  )

// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT_ALPHA_RS_kc( \
  L00, L01, L02, L03, L04, L05, L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, \
  L10, L11, L12, L13, L14, L15, L50, L51, L52, L53, L54, L55, R50, R51, R52, R53, R54, \
  L20, L21, L22, L23, L24, L25, L60, L61, L62, L63, L64, L65, R60, R61, R62, R63, R64, \
  L31, L32, L33, L34, L35, L70, L71, L72, L73, L74, L75, R70, R71, R72, R73, R74, L30  \
  ) \
  LAYOUT_ALPHA_RS( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##L40, KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_##L45, KC_##R40, KC_##R41, KC_##R42, KC_##R43, KC_##R44, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##L50, KC_##L51, KC_##L52, KC_##L53, KC_##L54, KC_##L55, KC_##R50, KC_##R51, KC_##R52, KC_##R53, KC_##R54, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##L60, KC_##L61, KC_##L62, KC_##L63, KC_##L64, KC_##L65, KC_##R60, KC_##R61, KC_##R62, KC_##R63, KC_##R64, \
    KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##L70, KC_##L71, KC_##L72, KC_##L73, KC_##L74, KC_##L75, KC_##R70, KC_##R71, KC_##R72, KC_##R73, KC_##R74  \
  )
//////////////////////////////////////////////////////////////////////////////




#endif /* KEYBOARDS_TREADSTONE48_BLE_REV1_REV1_H_ */
