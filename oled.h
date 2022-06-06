#pragma once

oled_rotation_t oled_init_user(oled_rotation_t rotation);
bool oled_task_user(void);
bool oled_process_record(uint16_t keycode, keyrecord_t *record);