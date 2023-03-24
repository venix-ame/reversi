BASEFILE = base/reversi.cpp 
SHELLFILE = shell/main.cpp shell/shell.cpp shell/print.cpp shell/analysis.cpp

default:
	g++ -Wall -Wextra -O2 -o reversi $(BASEFILE) $(SHELLFILE)

clear:
	rm reversi

clear2:
	rm reversi
	rm /shell/main
	rm /gui/gtkmain
