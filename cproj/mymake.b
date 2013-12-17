clear
echo "--------------------------------------------------------------"
date "+Date : %d-%h-%y"
echo "--------------------------------------------------------------"
if test $# -eq 1 
then
	if (test $1 = "-D" || test $1 = "-d")
	then
		gmake clean 1>object/tmp.xxx 2>object/tmp.xxx
		echo "msg : Deleted all executable & obj files ..."
		rm object/tmp.xxx
		exit
	elif (test $1 = "-A" || test $1 = "-a")
	then
		./mymake -d
		echo "msg : Compiling all files & linking ..."
		gmake 1>object/tmp.xxx
		rm object/tmp.xxx
		echo "msg : Completed compiling all files & linking ..."
	elif (test $1 = "-M" || test $1 = "-m")
	then
		echo "msg : Compiling mainApp.cc ..."
		gmake main 1>object/tmp.xxx
		echo "msg : Completed compiling mainApp.cc & linking ..."
		gmake proj 1>object/tmp.xxx
		rm object/tmp.xxx
	elif (test $1 = "-E" || test $1 = "-e")
	then
		echo "msg : Compiling error.cc ..."
		gmake error 1>object/tmp.xxx
		echo "msg : Completed compiling error.cc & linking ..."
		gmake proj 1>object/tmp.xxx
		rm object/tmp.xxx
	elif (test $1 = "-F" || test $1 = "-f")
	then
		echo "msg : Compiling first.cc ..."
		gmake first 1>object/tmp.xxx
		echo "msg : Completed compiling first.cc & linking ..."
		gmake proj 1>object/tmp.xxx
		rm object/tmp.xxx
	else
		echo "info : Use option [-d/D] to delete all executables ..."
		echo "info : Use option [-m/M] to recompile mainApp ..."
		echo "info : Use option [-f/F] to recompile first ..."
		echo "info : Use option [-e/E] to recompile error ..."
		echo "info : Use option [-a/A] to recompile the project ..."
		exit
	fi
fi
echo "msg : Running the program ..."
#clear
echo ".......................... Results ..........................."
if(test -x object/proj)
then
	proj "How are you ?" 
else
	./mymake -a
	exit
fi
