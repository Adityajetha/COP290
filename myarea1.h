#ifndef GTKMM_EXAMPLE_MYAREA1_H
#define GTKMM_EXAMPLE_MYAREA1_H

#include <gtkmm/drawingarea.h>
#include <string.h>

class MyArea1 : public Gtk::DrawingArea
{
public:
  MyArea1(std::string,std::string,std::string);
  virtual ~MyArea1();

protected:
  std::string file1,file2,file3;
  double xr,yr,zr,s,t;
  bool on_timeout();
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif // GTKMM_EXAMPLE_MYAREA_H
