#include QMK_KEYBOARD_H

// （１）変数・タイマー定義
static uint16_t mouse_timer = 0; // オートマウス用のタイマー
static int16_t scroll_accum_v = 0; // スクロール移動量を保持する変数１
static int16_t scroll_accum_h = 0; // スクロール移動量を保持する変数２

// （２）レイヤーー定義
#define _L0 0
#define _L1 1 // オートマウス用レイヤー（マウス操作時に自動で本レイヤに遷移する）
#define _L2 2 // スクロール用レイヤー(トラボがスクロールホイールになる。マウスカーソルは動かない)
#define _L3 3
#define _L4 4
#define _L5 5
#define _L6 6
#define _L7 7

// （３）キーマップ定義
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_L0] = LAYOUT(
        KC_X,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    [_L1] = LAYOUT(
        KC_Y,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    [_L2] = LAYOUT(
        KC_Y,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    [_L3] = LAYOUT(
        KC_Y,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    [_L4] = LAYOUT(
        KC_Y,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    [_L5] = LAYOUT(
        KC_Y,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    [_L6] = LAYOUT(
        KC_Y,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    [_L7] = LAYOUT(
        KC_Y,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
};

// （４）マウス制御メインロジック
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // 1. オートマウス判定
    if (mouse_report.x != 0 || mouse_report.y != 0) {
    // ボールが動いたらレイヤー1をONにする        
        if (!IS_LAYER_ON(_L1)) {
            layer_on(_L1);
        }
        mouse_timer = timer_read(); // 最後に動いた時間を記録
    } else {
        // 1000ms動きがなければレイヤー1を解除して元のレイヤーへ戻る
        if (IS_LAYER_ON(_L1) && timer_elapsed(mouse_timer) > 1000) {
            layer_off(_L1);
        }
    }

    // 2. スクロール処理（蓄積方式）
    if (IS_LAYER_ON(_L2)) {
        // 現在の移動量をスクロール移動量を保持する変数に足す
        scroll_accum_v += mouse_report.y;
        scroll_accum_h += mouse_report.x;
        // 10で割った分だけスクロールさせる（上下の移動量vはマイナスで反転）
        // スクロール感度を高くしたい場合は数字を小さく（低くしたい場合は大きく）する        
        mouse_report.v = -(scroll_accum_v / 10);
        mouse_report.h = (scroll_accum_h / 10);
        // スクロールに使った分だけ変数から引く（余りは次回に持ち越し）
        scroll_accum_v %= 10;
        scroll_accum_h %= 10;
        // スクロール中はマウスカーソルを動かさない
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        // レイヤーを離したときは変数を空にする
        scroll_accum_v = 0;
        scroll_accum_h = 0;
    }
    return mouse_report;
}

// （５）デバイス初期化設定
void pointing_device_init_user(void) {
    // 起動時の初期解像度（CPI）を設定
    pointing_device_set_cpi(500);
}
