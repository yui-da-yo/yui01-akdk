#pragma once

#define EE_HANDS
#define VIAL_KEYBOARD_UID {0xc4, 0xfd, 0xa3, 0x5f, 0x87, 0xa9, 0x48, 0xca}
#define VIAL_TAP_DANCE_ENTRIES 8
#define VIAL_COMBO_ENTRIES 8
#define PICO_FLASH_SIZE_BYTES (1 * 1024 * 1024)

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_LEFT
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define VIAL_AUTO_MOUSE_LAYER 1
// 最小の動き（1カウント）で反応させる設定を追加
#define VIAL_AUTO_MOUSE_THRESHOLD 1 
// 猶予時間を1秒（1000ms）に延長
#define VIAL_AUTO_MOUSE_TIMEOUT 1000 
#define VIAL_AUTO_MOUSE_ON_BY_DEFAULT

#define POINTING_DEVICE_CPI 400

/* --- 修正箇所：ここから --- */
// ドラッグスクロール機能を有効化
#define POINTING_DEVICE_DRAG_SCROLL_ENABLE

// ボタンを押している間だけスクロールにする設定を追加
#define POINTING_DEVICE_DRAG_SCROLL_MOMENTARY
/* --- 修正箇所：ここまで --- */
