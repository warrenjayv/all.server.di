main :process

process : server.cpp console.h
		echo -e '\n' &>> .err
		date   &>> .err
		echo -e "\n--------------------------------------\n" &>> .err
		g++ -g console.cpp server.cpp -o server &>> .err
clean : clear.bat
		rm .err
		rm server
