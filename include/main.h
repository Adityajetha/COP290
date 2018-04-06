#ifndef GTKMM_EXAMPLE_MAIN_H
#define GTKMM_EXAMPLE_MAIN_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include "two3.h"
#include "three2.h"

class Main : public Gtk::Window
{
public:
  
  Main();
  virtual ~Main();

protected:

  // Signal handlers:
  // Our new improved on_button_clicked(). (see below)
  void on_button_clicked1(Glib::ustring data);
  void on_button_clicked2(Glib::ustring data);
  void on_button_clicked_1(Glib::ustring data);

  // Child widgets:
  Gtk::Box m_box1;
  Gtk::Button m_button1, m_button2, m_button3;
};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H
