#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0
    [0] = LAYOUT(LAYOUT_Vial_Standard),
    // Layer 1
    [1] = LAYOUT(LAYOUT_Vial_Standard),
    // Layer 2
    [2] = LAYOUT(LAYOUT_Vial_Standard),
    // Layer 3
    [3] = LAYOUT(LAYOUT_Vial_Standard),
    // Layer 4
    [4] = LAYOUT(LAYOUT_Vial_Standard),
    // Layer 5
    [5] = LAYOUT(LAYOUT_Vial_Standard)
};
#ifdef POINTING_DEVICE_ENABLE
void pointing_device_task_user(void) {
    vial_auto_mouse_task();
}
#endif

