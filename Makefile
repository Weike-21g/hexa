CPPFLAGS = -Wall `pkg-config --cflags --libs gl` -lglut -lGL -lGLU

main: main.cc color.h camera.h 3d_ext.h blocklist.h level.h
	g++ main.cc -o main $(CPPFLAGS)

clean:
	rm main
