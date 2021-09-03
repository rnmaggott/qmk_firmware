// !!! DO NOT ADD #pragma once !!! //


// ###########################
// DZ60RGB LED addressing
//// ###########################

// R5: 13,12,11,10,... 1,0
// R4: 27...15,14
// R3: 40...29,28
// R2:



// ###########################
// The resulting animation names are something along the lines of:
// RGB_MATRIX_CUSTOM_my_cool_effect
// ###########################


// ###########################
// Animation: saph_static_purple
// ###########################

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)

RGB_MATRIX_EFFECT(saph_static_purple)
RGB_MATRIX_EFFECT(saph_eva_border)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS


static bool saph_static_purple(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    // rgb_matrix_set_color_all(0x19, 0x00, 0x33);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x19, 0x00, 0x33);
    }
    uprintf("STATIC RUN was called\n");
    return led_max < DRIVER_LED_TOTAL;
}

// ###########################
// Animation: _eva_borders
// ###########################

// Saph Color Palette
// #define EVA_WHITE  {0x70, 0x70, 0x70}
// #define EVA_PURPLE {0x19, 0x00, 0x33}
// #define EVA_GREEN  {0x0C, 0x1d, 0x00}
// #define EVA_ORANGE {0xb3, 0x59, 0x00}
// #define EVA_CORE   {0x99, 0x00, 0x00}

// Hotline Color Palette
#define EVA_ONE    {0x27, 0xfd, 0xf5}
#define EVA_TWO    {0xf7, 0x65, 0xb8}
#define EVA_THREE  {0xd7, 0xff, 0xfe}

const uint8_t rgb_eva_borders[][3] PROGMEM = {
    EVA_TWO, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_TWO, EVA_TWO, EVA_TWO, EVA_TWO, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_THREE,

    EVA_TWO, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_TWO, EVA_TWO, EVA_TWO, EVA_TWO, EVA_TWO, EVA_ONE, EVA_ONE, EVA_ONE, EVA_TWO,

    EVA_TWO, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_TWO, EVA_TWO, EVA_TWO, EVA_TWO, EVA_ONE, EVA_ONE, EVA_ONE, EVA_TWO,

    EVA_TWO, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_ONE, EVA_TWO,

    EVA_TWO, EVA_TWO, EVA_TWO, EVA_TWO, EVA_ONE, EVA_TWO, EVA_THREE, EVA_TWO
};

static bool saph_eva_border_init(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for(uint8_t i = led_min; i < led_max; i++) {
        uint8_t colour_r = pgm_read_byte(&(rgb_eva_borders[i][0]));
        uint8_t colour_g = pgm_read_byte(&(rgb_eva_borders[i][1]));
        uint8_t colour_b = pgm_read_byte(&(rgb_eva_borders[i][2]));
        rgb_matrix_set_color(i, colour_r, colour_g, colour_b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

static bool saph_eva_border_run(effect_params_t* params) {
    // nothin to do
    return false;
}

static bool saph_eva_border(effect_params_t* params) {
    if (params->init){
        return saph_eva_border_init(params);
    }
    return saph_eva_border_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
