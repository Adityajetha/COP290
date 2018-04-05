FLAG = `pkg-config gtkmm-3.0 --cflags --libs` 
DEPS = main.cpp myarea.cpp two3.cpp three2.cpp myarea1.cpp vertex.cpp examplewindow.cpp helloworld.cpp
test: $(DEPS)
    g++ -o $@ $^ $(FLAG)
