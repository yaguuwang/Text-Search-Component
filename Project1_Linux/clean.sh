#!/bin/sh

# clean FileMgrCom
cd FileMgrCom
make clean

# clean TextSearchCom
cd ../TextSearchCom
make clean

# clean client
cd ../Client
make clean

cd ..



