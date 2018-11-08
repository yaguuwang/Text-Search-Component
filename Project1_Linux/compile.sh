#!/bin/sh

# compile FileMgrCom
cd FileMgrCom
make

# compile TextSearchCom
cd ../SearchCom
make

# compile client
cd ../Client
make

cd ..


