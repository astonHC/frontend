/* COPYRIGHT (C) HARRY CLARK 2024 */

/* FRONTEND FOR GUI APPLICATIONS IN C */

/* THIS FILE ENCOMPASSES THE FUNCTIONALITY SURROUNDING */
/* MY OWN PORTFOLIO PROJECT PERTAINING TO EMULATING THE SEGA MEGA DRIVE */

/* THE PURPOSE OF INCLUDING THIS UTILITY IS TO BE ABLE TO USE */
/* THIS FRONTEND WITHIN THAT PROJECT */

/* SEE: https://github.com/hazzaaclark/MD68000 */

#ifndef MD_UTIL
#define MD_UTIL

/* NESTED INCLUDES */

#include "common.h"

/* SYSTEM INCLUDES */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if defined(USE_MD)
#define USE_MD
#else
#define USE_MD

#define     MD_MASTER_CLOCK_NTSC        53693175
#define     MD_MASTER_CLOCK_PAL         53203424
#define     MD_REG_CLOCK_DIVDIER               7
#define     MD_BASE_CLOCK_NTSC          (MD_MASTER_CLOCK_NTSC / MD_REG_CLOCK_DIVDIER)
#define     MD_BASE_CLOCK_PAL           (MD_MASTER_CLOCK_PAL /  MD_REG_CLOCK_DIVDIER)


#define     MD_Z80_CLOCK_NTSC           (MD_MASTER_CLOCK_NTSC / MD_Z80_CLOCK_DIVIDER)
#define     MD_Z80_CLOCK_PAL            (MD_MASTER_CLOCK_PAL / MD_Z80_CLOCK_DIVIDER)
#define     MD_Z80_CLOCK_DIVIDER                15

#define     MD_PSG_CLOCK_NTSC           (MD_Z80_CLOCK_NTSC / MD_PSG_CLOCK_DIVIDER)
#define     MD_PSG_CLOCK_PAL            (MD_Z80_CLOCK_PAL / MD_PSG_CLOCK_DIVIDER)
#define     MD_PSG_CLOCK_DIVIDER                16

#define     MD_FM_SR_NTSC               (MD_MASTER_CLOCK_NTSC / MD_PSG_CLOCK_DIVIDER)
#define     MD_FM_SR_PAL                (MD_MASTER_CLOCK_PAL / MD_PSG_CLOCK_DIVIDER)

#define     MD_FRAMERATE_NTSC(VALUE)    ((VALUE) * (60 * 1000) / 1001)
#define     MD_FRAMERATE_PAL(VALUE)     ((VALUE) * 50)

/* GENERAL PURPOSE CONFIGURATION STRUCTURE */
/* WITH SOME METHODS THAT WILL ALLOW THE FRONTEND TO COMMUNICATE */
/* WITH MY EMULATOR */

/* THE IDEA IS TO BE ABLE TO HAVE DEBUGGING FEATURES ALONGSIDE */
/* PROVIDING FURTHER INCENTIVE TO INCLUDE THESE METHODS HERE */

typedef struct MD_CONFIG
{
    union STATE
    {
        U16 M68K;
        U16 Z80;

    } STATE;

    U16 MD_RAM[0x8000];
    U16 PSG_RAM[0x40000];
    U8 Z80_RAM[0x2000];
    U16 Z80_MEM_BANK;
    U16 PSG_MEM_BANK;

    bool Z80_RESET;
    bool DMA_MODE;

    bool HAS_3_BUTTON;
    bool HAS_6_BUTTON;

} MD_CONFIG;

#define     MD_DPAD_UP              1 << 0
#define     MD_DPAD_DOWN            1 << 1
#define     MD_DPAD_LEFT            1 << 2
#define     MD_DPAD_RIGHT           1 << 3
#define     MD_BUTTON_A             1 << 4
#define     MD_BUTTON_B             1 << 5
#define     MD_BUTTON_C             1 << 6
#define     MD_BUTTON_START         1 << 7

/* FOR 6 BUTTON CONFIG */

#define     MD_BUTTON_X             1 << 8
#define     MD_BUTTON_Y             1 << 9
#define     MD_BUTTON_Z             1 << 10

#define     MD_TV_STANDARD_NTSC         0        
#define     MD_TV_STANDARD_PAL          1

/* CALLBACKS TO BE ABLE TO COMMUNICATE BETWEEN FRONTEND AND BACKEND EMULATION */

typedef struct MD_CALLBACKS
{
    void(*USER)(void);
    void(*CART_READ)(void*, U32* ADDRESS);
    void(*CART_WRITE)(void*, U32* ADDRESS, U8* WRITE_VALUE);
    void(*RENDER_SCANLINE)(void*, U16 SCANLINE, const U8 PIXELS, U16 WIDTH, U16 HEIGHT);

} MD_CALLBACKS;

void MD_EMU_INIT(struct MD_CONFIG* MD_CONFIG);
void MD_EMU_STATE_INIT(struct MD_CONFIG* MD_CONFIG);
void MD_EMU_RESET(const struct MD_CONFIG* MD_CONFIG);
void(*MD_FM_AUDIO_INIT(void*, UNK* TOTAL_SAMPLES, void(*GENERATE_AUDIO), S16* SAMPLE_RATE_BUFFER));
void(*MD_PSG_AUDIO_INIT(void*, UNK* TOTAL_SAMPLES, void(*GENERATE_AUDIO), S16* SAMPLE_RATE_BUFFER));
bool(*MD_INPUT_CALLBACK)(void*, U8 PLAYER_COUNT);

#endif

#endif