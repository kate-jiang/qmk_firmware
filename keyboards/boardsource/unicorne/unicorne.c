// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
#include "wpm.h"
#include "lib/bongo.h"
#include "lib/oled.h"
#include "lib/utils.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        render_layer_state();
    } else {
        render_anim();
        oled_write(PSTR("WPM "), false);
        oled_write(fmt(get_current_wpm(), '0'), false);
    }
    return false;
}
#endif
