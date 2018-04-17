#! /bin/bash
echo "Hello Bash"

echo "Arg1: "$1
echo "Arg2: "$2
echo "Arg3: "$3

OUTPUTDIR=`cygpath $1`
OUTPUTFILENAME=$2
BDSCOMMONDIR=$3

echo "OUTPUTDIR: "$OUTPUTDIR
echo "Outputfilename: "$OUTPUTFILENAME
echo "BDSCOMMONDIR: "$BDSCOMMONDIR

#Extract version
VERSION=`cat ../VERSION.txt | tr -d '\r'`
APPNAME=PluginManager
echo "Copy stuff"

pythonPlugins="/cygdrive/p/ArrayCam/plugins/python"

#LOCAL bin folder
cp $pythonPlugins/*.py                          $OUTPUTDIR/plugins

