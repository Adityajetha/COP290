#ifndef GTKMM_TWO3_H
#define GTKMM_TWO3_H

#include <gtkmm.h>
#include <string.h>
#include "main.h"

class Two3 : public Gtk::Window
{
public:
  Two3();
  virtual ~Two3();

protected:
  //Signal handlers:
  void on_checkbox_editable_toggled();
  void on_checkbox_visibility_toggled();
  void on_button_close();
  void topview();
  void frontview();
  void sideview();
  std::string str1,str2,str3;

  //Child widgets:
  Gtk::Box m_HBox;
  Gtk::Box m_VBox;
  Gtk::Button m_Entryx,m_Entryy,m_Entryz;
  Gtk::Button m_Button_Close;
  Gtk::Button m_CheckButton_Editable, m_CheckButton_Visible;
};

#endif //GTKMM_EXAMPLEWINDOW_H
