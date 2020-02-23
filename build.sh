EXEFILE=gmchain
CC=gcc
CFLAGS="-std=c99 -Wall -g -pipe -v -Q -pedantic -O2"
DEBUG_FLAGS="-DDEVELOPMENT"
BASE_DIR=$(pwd)
SRC_DIR=$BASE_DIR/src
OUT_DIR=$BASE_DIR/out
BIN_DIR=$BASE_DIR/bin

INCLUDE_SRC="-I $SRC_DIR"

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

compile_file(){
  CFILE=$2
  COMPILE_DIR="$1"
  OFILE=${CFILE//.c/.o}
  echo "[compile] $CFILE -> $OFILE"
  ${CC} $INCLUDE_SRC $CFLAGS $DEBUG_FLAGS -c $COMPILE_DIR/$CFILE -o $OUT_DIR/$OFILE
  chmod -R 777 $OUT_DIR/$OFILE
  BASE_OBJECTS="$BASE_OBJECTS $OUT_DIR/$OFILE"
}

compile_dir(){
  COMPILE_DIR=$1
  for file in $COMPILE_DIR/*.c 
  do
    compile_file $COMPILE_DIR ${file##$COMPILE_DIR/}
  done
}

BASE_OBJECTS=""
CFILES=""

# libs
compile_dir src/libs/base58
compile_dir src/libs/lzma
compile_dir src/libs/rmd160
compile_dir src/libs/sha
compile_dir src/libs/aes

# src
compile_dir src/chain
compile_dir src/module
compile_dir src/network
compile_dir src

echo "[link] $BASE_OBJECTS"

${CC} -o $BIN_DIR/$EXEFILE $BASE_OBJECTS -o $BIN_DIR/$EXEFILE -L/usr/local/lib -lsecp256k1

# ${CC} -I $SRC_DIR $CFLAGS $DEBUG_FLAGS $CFILES -L/usr/local/lib -lsecp256k1 -o $BIN_DIR/$EXEFILE

rm -r $OUT_DIR 

echo "[finish] please run -> ./gmchian to start gmchian ~"

