#!/bin/bash
# Build DreeRally for the web with Emscripten. Needs `emcc` on PATH.
# Usage: web/build_web.sh   (run from repo root)
set -e
OUT=web/out; mkdir -p $OUT /tmp/drobj; rm -f /tmp/drobj/*.o
CF="-sUSE_SDL=1 -I. -Iportability -D_WINDOWS_TYPES1 -D__WIN32__2 -DPORTABILITY -D_NO_MINIFMOD -w -O2 \
 -Wno-error=implicit-function-declaration -Wno-error=int-conversion -Wno-error=incompatible-pointer-types \
 -Wno-error=implicit-int -Wno-error=return-type -Wno-error=incompatible-function-pointer-types \
 -fno-strict-aliasing -include stdio.h -include stdlib.h -include string.h -include math.h -idirafter libincludes -include web/proto_fix.h"
for f in $(find . -name '*.c' -not -path './libs/*' -not -path './linux/*' -not -path './MINGW32/*' -not -path './libincludes/*' -not -path './tools/*') web/web_shim.c; do
  emcc -c $f -o /tmp/drobj/$(echo $f | tr '/.' '__').o $CF
done
# ASYNCIFY: the game uses blocking loops; this lets them yield to the browser.
emcc /tmp/drobj/*.o -o $OUT/index.html -sUSE_SDL=1 -sLEGACY_GL_EMULATION=1 -sALLOW_MEMORY_GROWTH=1 \
  -sASYNCIFY -sFORCE_FILESYSTEM=1 -lidbfs.js -Wl,--allow-multiple-definition
echo "OK -> $OUT/index.html"
