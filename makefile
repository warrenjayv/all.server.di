main : process

objects = server.cpp console.cpp iface/player.cpp

process : server.cpp console.h
		echo -e '\n' &>> .err
		date   &>> .err
		echo -e "\n--------------------------------------\n" &>> .err
		g++ -g ${objects} -std=c++17 -o server &>> .err
clean : clear.bat
		if [ -f  ".err"  ]; then rm .err;   fi
		if [ -f "server" ]; then rm server; fi 
