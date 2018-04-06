#ifndef GTKMM_THREE2_H
#define GTKMM_THREE2_H

#include <gtkmm.h>
#include "main.h"

class Three2 : public Gtk::Window
{
public:
  Three2();
  virtual ~Three2();

protected:
  //Signal handlers:
  void on_checkbox_editable_toggled();
  void on_checkbox_visibility_toggled();
  void on_button_close();
  void inp();
  std::string str;

  //Child widgets:
  Gtk::Entry m_Entry_x,m_Entry_y,m_Entry_z;
  Gtk::Box m_HBox;
  Gtk::Box m_VBox;
  Gtk::Button m_Entryx;
  Gtk::Button m_Button_Close;
  Gtk::Button m_CheckButton_Editable, m_CheckButton_Visible;
};

#endif //GTKMM_CREATE3D_H
