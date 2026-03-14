#pragma once

// （１）基本設定
// 左右の判定をEEPROM（基板のメモリ）で行う
#define EE_HANDS
// VIAL識別用の固有ID
#define VIAL_KEYBOARD_UID {0xc4, 0xfd, 0xa3, 0x5f, 0x87, 0xa9, 0x48, 0xca}
// タップダンス機能の最大登録数
#define VIAL_TAP_DANCE_ENTRIES 20
// コンボ機能の最大登録数
#define VIAL_COMBO_ENTRIES 20
// レイヤー数8（0～7レイヤー）
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
// RP2040等のフラッシュメモリ容量指定
#define PICO_FLASH_SIZE_BYTES (1 * 1024 * 1024)

// （２）トラックボール関連設定
// 分割キーボード間でのポインティングデバイス通信を有効化
#define SPLIT_POINTING_ENABLE
// トラックボールが左手側に配置されていることを定義
#define POINTING_DEVICE_LEFT
// X軸（横方向）の移動を反転（左手トラボのため）
#define POINTING_DEVICE_INVERT_X
// Y軸（縦方向）の移動を反転（左手トラボのため）
#define POINTING_DEVICE_INVERT_Y
// マウスカーソルの移動速度（数値が大きいほど速い）
#define POINTING_DEVICE_CPI 600

// （３）オートマウスレイヤ関連設定
// オートマウスレイヤー機能を有効化
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// マウス操作時に自動で切り替わるレイヤー番号
#define VIAL_AUTO_MOUSE_LAYER 1
// 反応感度。1カウントの小さな動きでもレイヤーを切り替える
#define VIAL_AUTO_MOUSE_THRESHOLD 1 
// マウス停止後、元のレイヤーに戻るまでの猶予時間(ms)
#define VIAL_AUTO_MOUSE_TIMEOUT 1000 
// キーボード起動時にオートマウス機能をONにする
#define VIAL_AUTO_MOUSE_ON_BY_DEFAULT

// （４）スクロール機能関連設定
// QMK標準のドラッグスクロール機能を有効化（keymap.cでのカスタム制御と併用）
#define POINTING_DEVICE_DRAG_SCROLL_ENABLE
// ボタン（またはレイヤー）がアクティブな間だけスクロールモードを維持する
#define POINTING_DEVICE_DRAG_SCROLL_MOMENTARY

