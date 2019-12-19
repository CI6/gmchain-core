EXEFILE=gmchian
CC=gcc
CFLAGS="-std=c99 -Wall -g"
BASE_DIR=$(pwd)
SRC_DIR=$BASE_DIR/src
OUT_DIR=$BASE_DIR/out
OBJECTS=""

mkdir $OUT_DIR
chmod -R 777 $OUT_DIR

compile_obj(){
  COMPILE_DIR=$1
  for file in $COMPILE_DIR/*.c 
  do
    CFILE=${file##$COMPILE_DIR/}
    OFILE=${CFILE//.c/.o}

    echo "[compile] $CFILE -> $OFILE"

    # OUT_CFILE=

    ${CC} -I $SRC_DIR $CFLAGS -c $COMPILE_DIR/$CFILE -o $OUT_DIR/$OFILE
    chmod -R 777 $OUT_DIR/$OFILE
    BASE_OBJECTS="$BASE_OBJECTS $OUT_DIR/$OFILE"
  done
}
compile_obj src
compile_obj src/chain
compile_obj src/module
compile_obj src/network

echo "[link] $BASE_OBJECTS"

${CC} -o $BASE_DIR/$EXEFILE $BASE_OBJECTS

echo "[finish] please run -> ./gmchian to start gmchian ~"

