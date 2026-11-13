/* Real prototypes for functions the decompiled sources call before (or without) a declaration.
 * Without these, clang assumes `int f()` at call sites; wasm-ld then reports a signature
 * mismatch and replaces the call with a trap. Force-included via build_web.sh. */
#ifndef WEB_PROTO_FIX_H
#define WEB_PROTO_FIX_H
void removeBackgroundRefreshFunction_43C730(void);
void inicializeGraphicVars(void);
long long recalculateSDLTicks_43C740(void);
void refreshAllScreen(void);
void enterBlackMarketScreen(void);
void easyRaceResults(int, int, int);
void mediumRaceResults(int, int, int);
void hardRaceResults(int, int, int);
void loadMusic(int, char *, int, char *);
void openAnimation(const char *, int, char *, int, char *, char, char);
void refreshAndCheckConnection_42A570(void);
void decryptTexture(int, int, int, int);
void initCars(void);
void loadGraphics3(void);
int  sub_424240(int, double, double, double);
void freeMemoryGraphics(void);
void nullsub_1(void);
void errorExitScreen(int);
void copyImageToBuffer(int, int);
int  drawSprite_402590(int, int, int, signed int, int, int, int, int);
void copyBuffer2Screen(void *, const void *, int);
void showEndAnim_4312D0(void);
void addParticipantToRace(signed int);
void previewRaceScreen(signed int);
void startRace(int, int);
void selectRaceScreen(void);
void freeMemoryGraphics3(void);
#endif
