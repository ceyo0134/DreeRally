/* Web (Emscripten) shim for DreeRally.
 * - FMOD 3.75 is closed-source / x86-only; these stubs keep the game silent for now.
 *   TODO: replace with SDL audio or libxmp for module music + SFX.
 * - Provides the MSVC-style integer->string helpers the game expects.
 * Stubs use all-int signatures on purpose: the game calls them via implicit
 * declarations, so the wasm call signatures are (i32...)->i32. */
#include <string.h>

float FSOUND_GetVersion() { return 0; }
int FSOUND_Init(int a, int b, int c) { return 0; }   /* 0 => game skips sound */
int FSOUND_SetVolume(int a, int b) { return 0; }
void FSOUND_Update() { }
int FSOUND_Stream_Stop(int a) { return 0; }
int FSOUND_Stream_Close(int a) { return 0; }
int FMUSIC_LoadSongEx(int a, int b, int c, int d, int e, int f) { return 0; }
int FMUSIC_PlaySong(int a) { return 0; }
int FMUSIC_SetMasterVolume(int a, int b) { return 0; }
int FMUSIC_SetOrder(int a, int b) { return 0; }
int FMUSIC_StopSong(int a) { return 0; }

char* _itoa(int value, char* str, int radix) {
    static const char dig[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char tmp[34]; int n = 0, neg = 0; unsigned int v;
    if (radix < 2 || radix > 36) radix = 10;
    if (radix == 10 && value < 0) { neg = 1; v = (unsigned int)(-value); } else v = (unsigned int)value;
    do { tmp[n++] = dig[v % radix]; v /= radix; } while (v);
    if (neg) tmp[n++] = '-';
    int i = 0; while (n) str[i++] = tmp[--n];
    str[i] = 0; return str;
}
char* SDL_ltoa(long value, char* str, int radix) { return _itoa((int)value, str, radix); }
int FMUSIC_GetOrder(int a) { return 0; }
