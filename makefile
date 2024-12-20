main :process

process : server.cpp console.h
		date   &>> .err
		echo -e '\n\n' &>> .err
		g++ server.cpp &>> .err
clean : clear.bat
		./clear.bat
