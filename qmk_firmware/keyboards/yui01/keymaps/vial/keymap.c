#include QMK_KEYBOARD_H

static bool is_drag_scroll = false;
static uint16_t mouse_timer = 0;

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

// ... レイヤー定義（省略せず、あなたの現在の keymap.c のものをそのまま使ってください） ...

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // 判定用に元の値を保持
    int8_t raw_x = mouse_report.x;
    int8_t raw_y = mouse_report.y;

    // 【ここが本番】ドラッグスクロールが ON なら座標をスクロールへ転送
    if (is_drag_scroll) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    // オートマウス判定（生の値 raw_x/y を使う）
    if (raw_x != 0 || raw_y != 0) {
        if (!IS_LAYER_ON(1)) { // マウスレイヤーを1と仮定
            layer_on(1);
        }
        mouse_timer = timer_read();
    } else {
        if (IS_LAYER_ON(1) && timer_elapsed(mouse_timer) > 500) {
            layer_off(1);
        }
    }

    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            is_drag_scroll = record->event.pressed;
            return false;
    }
    return true;
}
