OBJS = *.cpp
CXX = g++ -std=c++17
CPPFLAGS = -WALL
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

app: $(OBJS)
	$(CXX) -o runDriver $(OBJS) $(LDLIBS)

clean:
	$(RM) runDriver
