CXXFLAGS =	-g3 -Wall -fmessage-length=0 #-Werror

OBJS = util.o Interface.o DrawingObjects.o MovingObjects.o Player.o Mushroom.o Bullet.o Centipede.o CentiHead.o CentiPart.o Board.o game.o 

LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage -pthread



TARGET =	game


$(TARGET):	$(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
