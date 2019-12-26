SOURCE_DIR="secp256k1"
cd $SOURCE_DIR
./autogen.sh
./configure
make
sudo make install