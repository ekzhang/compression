xd: xd.cpp
	g++ -std=c++1y -O2 -o xd xd.cpp
run: xd
	./xd | ./xd | ./imview
run3: xd
	python run3.py cow$(cow)
