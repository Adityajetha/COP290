#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H

#include <gtkmm/drawingarea.h>
#include <string.h>

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea(std::string,double,double,double);
  virtual ~MyArea();

protected:
  std::string file;
  double xr,yr,zr;
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif // GTKMM_EXAMPLE_MYAREA_H
