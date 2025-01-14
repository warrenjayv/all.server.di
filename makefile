main : process

objects = server.cpp console.cpp iface/player.cpp

process : server.cpp console.h
		echo -e '\n' &>> .err
		date   &>> .err
		echo -e "\n--------------------------------------\n" &>> .err
		g++ -g ${objects} -o server &>> .err
clean : clear.bat
		rm .err
		rm server
