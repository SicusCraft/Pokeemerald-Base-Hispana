#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "window.h"
#include "text.h"
#include "palette.h"
#include "task.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "decompress.h"
#include "graphics.h"
#include "sprite.h"
#include "sound.h"
#include "trig.h"
#include "overworld.h"
#include "scanline_effect.h"
#include "pokemon_summary_screen.h"
#include "text_window.h"
#include "menu_helpers.h"
#include "data.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "config/tutoriales.h"

#if TUTORIAL_EFECTIVIDAD_TIPOS == TRUE

enum FondosEfectividad
{
    FONDO_TEXTO,
    FONDO_MOVIMIENTO,
};

struct EfectividadTiposResources
{
    u32 temporizadorZigZag;
    u32 posH;
    u32 posV;
    u32 indiceTipo;
    u32 numeroSprites;
    u32 centerSpriteId;
    u32 spriteIds[64];
};

static EWRAM_DATA struct EfectividadTiposResources *sData = NULL;

extern const struct TypeInfo gTypesInfo[NUMBER_OF_MON_TYPES];
extern const uq4_12_t gTypeEffectivenessTable[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES];

static const u32 sTiposValidos[] = {
    TYPE_NORMAL, TYPE_FIGHTING, TYPE_FLYING, TYPE_POISON, TYPE_GROUND,
    TYPE_ROCK, TYPE_BUG, TYPE_GHOST, TYPE_STEEL, TYPE_FIRE,
    TYPE_WATER, TYPE_GRASS, TYPE_ELECTRIC, TYPE_PSYCHIC, TYPE_ICE,
    TYPE_DRAGON, TYPE_DARK, TYPE_FAIRY
};

#define NUMERO_TIPOS_VALIDOS ARRAY_COUNT(sTiposValidos)

// --- Configuración de Hardware ---

static const struct BgTemplate sBgTemplatesEfectividad[] =
{
    [FONDO_TEXTO] =
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .priority = 0
    },
    [FONDO_MOVIMIENTO] =
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .priority = 1
    }
};

static const struct WindowTemplate sWindowTemplatesEfectividad[] = {
    { .bg = 0, .tilemapLeft = 1, .tilemapTop = 1, .width = 12, .height = 2, .paletteNum = 15, .baseBlock = 0x001 },
    { .bg = 0, .tilemapLeft = 17, .tilemapTop = 1, .width = 12, .height = 2, .paletteNum = 15, .baseBlock = 0x019 },
    DUMMY_WIN_TEMPLATE
};

// --- Lógica de Carga ---

static void LoadBgsEfectividad(void)
{
    InitBgsFromTemplates(0, sBgTemplatesEfectividad, ARRAY_COUNT(sBgTemplatesEfectividad));

    LoadBgTiles(FONDO_MOVIMIENTO, FondoEfectividadTipos_Tiles, 0x800, 0);
    
    LoadBgTilemap(FONDO_MOVIMIENTO, FondoEfectividadTipos_Tilemap, 0x800, 0);

    LoadPalette(FondoEfectividadTipos_Paleta, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZE_4BPP);

    ResetAllBgsCoordinates();
    
    ShowBg(FONDO_TEXTO);
    ShowBg(FONDO_MOVIMIENTO);
}

static void ClearPreviousIcons(void)
{
    u32 i;
    for (i = 0; i < sData->numeroSprites; i++)
        DestroySprite(&gSprites[sData->spriteIds[i]]);
    
    if (sData->centerSpriteId != 0xFF)
        DestroySprite(&gSprites[sData->centerSpriteId]);
        
    sData->numeroSprites = 0;
    sData->centerSpriteId = 0xFF;
}

static void AddIcon(u32 tipo, u32 x, u32 y)
{
    u32 spriteId = CreateSprite(&gSpriteTemplate_MoveTypes, x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[spriteId], tipo);
        
        // ASIGNACIÓN DE PALETA DINÁMICA:
        // Los iconos de tipos suelen cargarse en slots de paleta específicos.
        // Si usas gIconosTipos_Pal (que cargaste en OBJ_PLTT_ID(11)), 
        // cada tipo debe apuntar a su sub-paleta dentro de ese rango.
        gSprites[spriteId].oam.paletteNum = gTypesInfo[tipo].palette;
        
        sData->spriteIds[sData->numeroSprites++] = spriteId;
    }
}

static void RefreshUI(void)
{
    u32 i;
    u32 currentType = sTiposValidos[sData->indiceTipo];
    u32 xOff = 30, yOff = 50;
    u32 xDef = 150, yDef = 50;

    ClearPreviousIcons();
    
    for (i = 0; i < 2; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        AddTextPrinterParameterized(i, FONT_SMALL, (i == 0) ? COMPOUND_STRING("OFENSIVO") : COMPOUND_STRING("DEFENSIVO"), 2, 1, 0, NULL);
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }

    // Icono Central
    sData->centerSpriteId = CreateSprite(&gSpriteTemplate_MoveTypes, 120, 24, 0);
    StartSpriteAnim(&gSprites[sData->centerSpriteId], currentType);
    gSprites[sData->centerSpriteId].oam.paletteNum = gTypesInfo[currentType].palette;

    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (i == TYPE_NONE || i == TYPE_MYSTERY || i == TYPE_STELLAR) continue;

        // Ofensivo
        if (gTypeEffectivenessTable[currentType][i] != UQ_4_12(1.0))
        {
            AddIcon(i, xOff, yOff);
            xOff += 16;
            if (xOff > 110)
            {
                xOff = 30;
                yOff += 16;
            }
        }

        // Defensivo
        if (gTypeEffectivenessTable[i][currentType] != UQ_4_12(1.0))
        {
            AddIcon(i, xDef, yDef);
            xDef += 16;
            if (xDef > 220)
            {
                xDef = 150;
                yDef += 16;
            }
        }
    }
}

// --- Callbacks y Main Loop ---

static void VBlankCB_EfectividadTipos(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG1HOFS, sData->posH);
    SetGpuReg(REG_OFFSET_BG1VOFS, sData->posV);
}

static void CB2_EfectividadTipos(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_EfectividadTiposMain(u8 taskId)
{
    sData->posH++;
    sData->temporizadorZigZag++;
    sData->posV = (gSineTable[(sData->temporizadorZigZag * 2) & 0xFF] >> 5);

    if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        sData->indiceTipo = (sData->indiceTipo + 1) % NUMERO_TIPOS_VALIDOS;
        RefreshUI();
    }
    else if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        sData->indiceTipo = (sData->indiceTipo == 0) ? NUMERO_TIPOS_VALIDOS - 1 : sData->indiceTipo - 1;
        RefreshUI();
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = (void *)SetMainCallback2;
        SetMainCallback2(CB2_ReturnToField);
    }
}

static void CB2_InitTutorialSetUp(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 4096);
        
        sData = AllocZeroed(sizeof(struct EfectividadTiposResources));
        sData->centerSpriteId = 0xFF;
        gMain.state++;
        break;
    case 1:
        LoadBgsEfectividad();
        InitWindows(sWindowTemplatesEfectividad);
        gMain.state++;
        break;
    case 2:
        LoadCompressedSpriteSheet(&gSpriteSheet_MoveTypes);
        // Carga de paletas de tipos
        if (TUTORIAL_ICONOS_DE_TIPOS)
            LoadPalette(gIconosTipos_Pal, OBJ_PLTT_ID(11), 5 * PLTT_SIZE_4BPP);
        else
            LoadPalette(gMoveTypes_Pal, OBJ_PLTT_ID(11), 3 * PLTT_SIZE_4BPP);
            
        RefreshUI();
        gMain.state++;
        break;
    case 3:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_EfectividadTipos);
        SetMainCallback2(CB2_EfectividadTipos);
        CreateTask(Task_EfectividadTiposMain, 0);
        gMain.state = 0;
        break;
    }
}

#endif

void StartTutorialEfectividadTipos_CB2(void)
{
    #if TUTORIAL_EFECTIVIDAD_TIPOS == TRUE
    if (!gPaletteFade.active)
    {
        gMain.state = 0;
        CleanupOverworldWindowsAndTilemaps();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetMainCallback2(CB2_InitTutorialSetUp);
    }
    #endif
}
