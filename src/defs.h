#ifndef _DEFS__H
#define _DEFS__H

#define SCREEN_WIDTH 875
#define SCREEN_HEIGHT 658
#define WINDOW_TITLE "Hungry Fish"
#define INITIAL_SPEED 3
#define MAX_KEYBOARD_KEYS 350

#define BACKGROUND_IMG "background\\back.png"
#define SCORE_IMG "text\\Score.ttf"
#define TITLE_IMG "text\\gametitle.ttf"
#define GAMEOVER_IMG "text\\GameOver.ttf"
#define WINSCORE 1000
#define HEALTH 100
#define SCORE_BARRA 100
#define SCORE_ORCA 300
#define SCORE_MARLIN 500
#define SCORE_LIONFISH 700
#define SCORE_SHARK 900
#define DIS_BOMB 150

const int minnowposx[2] = {0,SCREEN_WIDTH};
const char*  PLAYER_SPRITE_FILE = "image\\Player.png";
const int PLAYER_CLIPS[][4] = {
    {750, 0, 50, 50},
    {800, 0, 50, 50},
    {850, 0, 50, 50},
    {900, 0, 50, 50},
    {950, 0, 50, 50},
    {1000, 0, 50, 50},
    {1050, 0, 50, 50},
    {1100, 0, 50, 50},
    {1150, 0, 50, 50},
    {1200, 0, 50, 50},
    {1250, 0, 50, 50},
    {1300, 0, 50, 50},
};
const int PLAYER_FRAMES = sizeof(PLAYER_CLIPS)/sizeof(int)/4;

const char*  PLAYER_SPRITE_FILE_RIGHT = "image\\PlayerRight.png";
const int PLAYER_CLIPS_RIGHT[][4] = {
    {300, 0, 50, 50},
    {350, 0, 50, 50},
    {400, 0, 50, 50},
    {450, 0, 50, 50},
    {500, 0, 50, 50},
    {550, 0, 50, 50},

    {600, 0, 50, 50},
    {650, 0, 50, 50},
    {700, 0, 50, 50},
    {750, 0, 50, 50},
    {800, 0, 50, 50},
};
const int PLAYER_FRAMES_RIGHT = sizeof(PLAYER_CLIPS_RIGHT)/sizeof(int)/4;

const char*  MINNOW_SPRITE_FILE = "image\\Minnow.png";
const int MINNOW_CLIPS[][4] = {
    {0, 0, 50, 50},
    {50, 0, 50, 50},
    {100, 0, 50, 50},
    {150, 0, 50, 50},
    {200, 0, 50, 50},
    {250, 0, 50, 50},

    {300, 0, 50, 50},
    {350, 0, 50, 50},
    {400, 0, 50, 50},
    {450, 0, 50, 50},
    {500, 0, 50, 50},
    {550, 0, 50, 50},

    {600, 0, 50, 50},
    {650, 0, 50, 50},
    {700, 0, 50, 50},
    {750, 0, 50, 50},
};
const int MINNOW_FRAMES = sizeof(MINNOW_CLIPS)/sizeof(int)/4;

const char*  MINNOW_SPRITE_FILE_RIGHT = "image\\MinnowRight.png";
const int MINNOW_CLIPS_RIGHT[][4] = {
    {300, 0, 50, 50},
    {350, 0, 50, 50},
    {400, 0, 50, 50},
    {450, 0, 50, 50},
    {500, 0, 50, 50},
    {550, 0, 50, 50},

    {600, 0, 50, 50},
    {650, 0, 50, 50},
    {700, 0, 50, 50},
    {750, 0, 50, 50},
    {800, 0, 50, 50},
    {850, 0, 50, 50},
    {900, 0, 50, 50},
    {950, 0, 50, 50},
    {1000, 0, 50, 50},

};
const int MINNOW_FRAMES_RIGHT = sizeof(MINNOW_CLIPS_RIGHT)/sizeof(int)/4;

const char*  PLAYER_BITE_SPRITE_FILE = "image\\Player.png";
const int PLAYER_BITE_CLIPS[][4] = {
    {0, 0, 50, 50},
    {50, 0, 50, 50},
    {100, 0, 50, 50},
    {150, 0, 50, 50},
    {200, 0, 50, 50},

};
const int PLAYER_BITE_FRAMES = sizeof(PLAYER_BITE_CLIPS)/sizeof(int)/4;

const char*  PLAYER_BITE_SPRITE_FILE_RIGHT = "image\\PlayerRight.png";
const int PLAYER_BITE_CLIPS_RIGHT[][4] = {
    {1550, 0, 50, 50},
    {1500, 0, 50, 50},
    {1450, 0, 50, 50},
    {1400, 0, 50, 50},
    {1350, 0, 50, 50},
};
const int PLAYER_BITE_FRAMES_RIGHT = sizeof(PLAYER_BITE_CLIPS_RIGHT)/sizeof(int)/4;

const char*  BARRA_SPRITE_FILE = "image\\Barra.png";
const int BARRA_CLIPS[][4] = {
    {0, 0, 78, 49},
    {78, 0, 78, 49},
    {157, 0, 78, 49},
    {237, 0, 78, 49},
    {317, 0, 78, 49},
    {397, 0, 78, 49},
    {477, 0, 78, 49},
    {557, 0, 78, 49},
    {637, 0, 78, 49},
    {717, 0, 78, 49},
    {797, 0, 78, 49},
    {877, 0, 78, 49},
    {957, 0, 78, 49},
    {1037, 0, 78, 49},
};
const int BARRA_FRAMES = sizeof(BARRA_CLIPS)/sizeof(int)/4;

const char*  BARRA_SPRITE_FILE_RIGHT = "image\\BarraRight.png";
const int BARRA_CLIPS_RIGHT[][4] = {
    {484, 0, 80, 49},
    {564, 0, 80, 49},
    {644, 0, 80, 49},
    {724, 0, 80, 49},
    {804, 0, 80, 49},
    {884, 0, 80, 49},
    {964, 0, 80, 49},
    {1044, 0, 80, 49},
    {1124, 0, 80, 49},
    {1204, 0, 80, 49},
    {1284, 0, 78, 49},
    {1364, 0, 76, 49},
};
const int BARRA_FRAMES_RIGHT = sizeof(BARRA_CLIPS_RIGHT)/sizeof(int)/4;

const char*  ORCA_SPRITE_FILE = "image\\Orca.png";
const int ORCA_CLIPS[][4] = {
    {0, 0, 110, 53},
    {110, 0, 110, 53},
    {220, 0, 110, 53},
    {330, 0, 110, 53},
    {440, 0, 110, 53},
    {550, 0, 110, 53},
    {660, 0, 110, 53},
    {770, 0, 110, 53},
    {880, 0, 110, 53},
    {990, 0, 110, 53},
    {1100, 0, 110, 53},
    {1210, 0, 110, 53},
    {1320, 0, 110, 53},
    {1430, 0, 110, 53},
    {1540, 0, 110, 53},
};
const int ORCA_FRAMES = sizeof(ORCA_CLIPS)/sizeof(int)/4;

const char*  ORCA_SPRITE_FILE_RIGHT = "image\\OrcaRight.png";
const int ORCA_CLIPS_RIGHT[][4] = {
    {3, 0, 110, 53},
    {113, 0, 110, 53},
    {223, 0, 110, 53},
    {333, 0, 110, 53},
    {443, 0, 110, 53},
    {553, 0, 110, 53},
    {663, 0, 110, 53},
    {773, 0, 110, 53},
    {883, 0, 110, 53},
    {993, 0, 110, 53},
    {1103, 0, 110, 53},
    {1213, 0, 110, 53},
    {1323, 0, 110, 53},
    {1433, 0, 110, 53},
    {1543, 0, 110, 53},
};
const int ORCA_FRAMES_RIGHT = sizeof(ORCA_CLIPS_RIGHT)/sizeof(int)/4;

const char*  MARLIN_SPRITE_FILE = "image\\Marlin.png";
const int MARLIN_CLIPS[][4] = {
    {0, 0, 120, 86},
    {120, 0, 120, 86},
    {240, 0, 120, 86},
    {360, 0, 120, 86},
    {480, 0, 120, 86},
    {600, 0, 120, 86},
    {720, 0, 120, 86},
    {840, 0, 120, 86},
    {960, 0, 120, 86},
    {1080, 0, 120, 86},
    {1200, 0, 120, 86},
    {1320, 0, 120, 86},
    {1440, 0, 120, 86},
    {1560, 0, 120, 86},
    {1680, 0, 120, 86},
};
const int MARLIN_FRAMES = sizeof(MARLIN_CLIPS)/sizeof(int)/4;

const char*  MARLIN_SPRITE_FILE_RIGHT = "image\\MarlinRight.png";
const int MARLIN_CLIPS_RIGHT[][4] = {
    {0, 0, 120, 86},
    {120, 0, 120, 86},
    {240, 0, 120, 86},
    {360, 0, 120, 86},
    {480, 0, 120, 86},
    {600, 0, 120, 86},
    {720, 0, 120, 86},
    {840, 0, 120, 86},
    {960, 0, 120, 86},
    {1080, 0, 120, 86},
    {1200, 0, 120, 86},
    {1320, 0, 120, 86},
    {1440, 0, 120, 86},
    {1560, 0, 120, 86},
    {1680, 0, 120, 86},
};
const int MARLIN_FRAMES_RIGHT = sizeof(MARLIN_CLIPS_RIGHT)/sizeof(int)/4;

const char*  SHARK_SPRITE_FILE = "image\\Shark.png";
const int SHARK_CLIPS[][4] = {
    {0, 0, 110, 46},
    {110, 0, 110, 46},
    {220, 0, 110, 46},
    {330, 0, 110, 46},
    {440, 0, 110, 46},
    {550, 0, 110, 46},
    {660, 0, 110, 46},
    {770, 0, 110, 46},
    {880, 0, 110, 46},
    {990, 0, 110, 46},
    {1100, 0, 110, 46},
    {1210, 0, 110, 46},
    {1320, 0, 110, 46},
    {1430, 0, 110, 46},
};
const int SHARK_FRAMES = sizeof(SHARK_CLIPS)/sizeof(int)/4;

const char*  SHARK_SPRITE_FILE_RIGHT = "image\\SharkRight.png";
const int SHARK_CLIPS_RIGHT[][4] = {
    {0, 0, 110, 46},
    {110, 0, 110, 46},
    {220, 0, 110, 46},
    {330, 0, 110, 46},
    {440, 0, 110, 46},
    {550, 0, 110, 46},
    {660, 0, 110, 46},
    {770, 0, 110, 46},
    {880, 0, 110, 46},
    {990, 0, 110, 46},
    {1100, 0, 110, 46},
    {1210, 0, 110, 46},
    {1320, 0, 110, 46},
    {1430, 0, 110, 46},
};
const int SHARK_FRAMES_RIGHT = sizeof(SHARK_CLIPS_RIGHT)/sizeof(int)/4;

const char*  LIONFISH_SPRITE_FILE = "image\\LionFish.png";
const int LIONFISH_CLIPS[][4] = {
    {0, 0, 100, 88},
    {100, 0, 100, 88},
    {200, 0, 100, 88},
    {300, 0, 100, 88},
    {400, 0, 100, 88},
    {500, 0, 100, 88},
    {600, 0, 100, 88},
    {700, 0, 100, 88},
    {800, 0, 100, 88},
    {900, 0, 100, 88},
    {1000, 0, 100, 88},
    {1100, 0, 100, 88},
    {1200, 0, 100, 88},
    {1300, 0, 100, 88},
};
const int LIONFISH_FRAMES = sizeof(LIONFISH_CLIPS)/sizeof(int)/4;

const char*  LIONFISH_SPRITE_FILE_RIGHT = "image\\LionFishRight.png";
const int LIONFISH_CLIPS_RIGHT[][4] = {
    {0, 0, 100, 88},
    {100, 0, 100, 88},
    {200, 0, 100, 88},
    {300, 0, 100, 88},
    {400, 0, 100, 88},
    {500, 0, 100, 88},
    {600, 0, 100, 88},
    {700, 0, 100, 88},
    {800, 0, 100, 88},
    {900, 0, 100, 88},
    {1000, 0, 100, 88},
    {1100, 0, 100, 88},
    {1200, 0, 100, 88},
    {1300, 0, 100, 88},
};
const int LIONFISH_FRAMES_RIGHT = sizeof(LIONFISH_CLIPS_RIGHT)/sizeof(int)/4;

const char*  EXPLODE_SPRITE_FILE = "image\\Explosion.png";
const int EXPLODE_CLIPS[][4] = {
    {0, 0, 155, 110},
    {155, 0, 155, 110},
    {310, 0, 155, 110},
    {465, 0, 155, 110},
};
const int EXPLODE_FRAMES = sizeof(EXPLODE_CLIPS)/sizeof(int)/4;

#endif
