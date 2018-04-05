#include "main.h"
#include "two3.h"
#include "three2.h"
#include <iostream>

Main::Main()
: m_button1("2D to 3D"),
  m_button2("3D to 2D"),
  m_button3("Quit")
{
  // This just sets the title of our new window.
  set_title("FACC Rep");

  // sets the border width of the window.
  set_border_width(100);

  // put the box into the main window.
  add(m_box1);
m_box1.set_spacing(15);

  // Now when the button is clicked, we call the "on_button_clicked" function
  // with a pointer to "button 1" as it's argument
  m_button1.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &Main::on_button_clicked1), "3D to 2D"));

  // instead of gtk_container_add, we pack this button into the invisible
  // box, which has been packed into the window.
  // note that the pack_start default arguments are Gtk::EXPAND | Gtk::FILL, 0
  m_box1.pack_start(m_button1);

  // always remember this step, this tells GTK that our preparation
  // for this button is complete, and it can be displayed now.
  m_button1.show();

  // call the same signal handler with a different argument,
  // passing a pointer to "button 2" instead.
  m_button2.signal_clicked().connect(sigc::bind<-1, Glib::ustring>(
              sigc::mem_fun(*this, &Main::on_button_clicked2), "2D to 3D"));

  m_box1.pack_start(m_button2);

  m_button3.signal_clicked().connect(sigc::bind<-1, Glib::ustring>(
              sigc::mem_fun(*this, &Main::on_button_clicked_1), "2D to 3D"));

  m_box1.pack_start(m_button3);



  // Show the widgets.
  // They will not really be shown until this Window is shown.
  m_button2.show();
  m_button3.show();
  m_box1.show();
}

Main::~Main()
{
}

// Our new improved signal handler.  The data passed to this method is
// printed to stdout.
void Main::on_button_clicked1(Glib::ustring data)
{
  Three2* e=new Three2;
  e->show();
}

void Main::on_button_clicked2(Glib::ustring data)
{
  Two3* e=new Two3;
  e->show();
}

void Main::on_button_clicked_1(Glib::ustring data)
{
  hide();
}
