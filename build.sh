EXEFILE=gmchain
CC=gcc
CFLAGS="-std=c99 -Wall -g -pipe -v -Q -pedantic -O2"
DEBUG_FLAGS="-DDEVELOPMENT"
BASE_DIR=$(pwd)
SRC_DIR=$BASE_DIR/src
OUT_DIR=$BASE_DIR/out
BIN_DIR=$BASE_DIR/bin
OBJECTS=""

if [ ! -d $BIN_DIR ]; then
  mkdir $BIN_DIR
  chmod -R 777 $BIN_DIR
fi
if [ ! -d $OUT_DIR ]; then
  mkdir $OUT_DIR
  chmod -R 777 $OUT_DIR
fi
if [ -f $BIN_DIR/$EXEFILE ]; then
  rm -f $BIN_DIR/$EXEFILE
fi

compile_obj(){
  COMPILE_DIR=$1
  for file in $COMPILE_DIR/*.c 
  do
    CFILE=${file##$COMPILE_DIR/}
    OFILE=${CFILE//.c/.o}
    
    echo "[compile] $CFILE -> $OFILE"

    ${CC} -I $SRC_DIR $CFLAGS $DEBUG_FLAGS -c $COMPILE_DIR/$CFILE -o $OUT_DIR/$OFILE
    chmod -R 777 $OUT_DIR/$OFILE
    BASE_OBJECTS="$BASE_OBJECTS $OUT_DIR/$OFILE"
  done
}
compile_obj src
compile_obj src/chain
compile_obj src/module
compile_obj src/network

echo "[link] $BASE_OBJECTS"

${CC} -o $BIN_DIR/$EXEFILE $BASE_OBJECTS 

rm -r $OUT_DIR

echo "[finish] please run -> ./gmchian to start gmchian ~"

