#include "three2.h"
#include "main.h"
#include <iostream>
#include "myarea.h"
#include <cstring>

Three2::Three2()
: m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Entryx("3D File"),
  m_Button_Close("Home"),
  m_CheckButton_Visible("Submit")
{

  set_border_width(150);
  set_size_request(200, 100);
  set_title("2D to 3D");
  add(m_VBox);
  m_VBox.set_spacing(10);

  m_VBox.pack_start(m_Entryx);
  m_Entryx.signal_clicked().connect( sigc::mem_fun(*this,
  &Three2::inp) );
  m_VBox.pack_start(m_Entry_x);
  m_VBox.pack_start(m_Entry_y);
m_VBox.pack_start(m_Entry_z);


  // Note that add() can also be used instead of pack_xxx()
  m_VBox.add(m_HBox);

  m_HBox.pack_start(m_CheckButton_Visible);
  m_CheckButton_Visible.signal_clicked().connect( sigc::mem_fun(*this,
              &Three2::on_checkbox_visibility_toggled) );

  m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
              &Three2::on_button_close) );
  m_VBox.pack_start(m_Button_Close);
  m_Button_Close.set_can_default();
  m_Button_Close.grab_default();
  m_Entry_x.set_text("x-coordinate");
  m_Entry_y.set_text("y-coordinate");
  m_Entry_z.set_text("z-coordinate");

  show_all_children();
}

Three2::~Three2()
{
}

void Three2::inp()
{
Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  //Add response buttons the the dialog:
  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("_Open", Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:

  auto filter_text = Gtk::FileFilter::create();
  filter_text->set_name("Text files");
  filter_text->add_mime_type("text/plain");
  dialog.add_filter(filter_text);

  auto filter_cpp = Gtk::FileFilter::create();
  filter_cpp->set_name("C/C++ files");
  filter_cpp->add_mime_type("text/x-c");
  filter_cpp->add_mime_type("text/x-c++");
  filter_cpp->add_mime_type("text/x-c-header");
  dialog.add_filter(filter_cpp);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  //Show the dialog and wait for a user response:
  int result = dialog.run();

  //Handle the response:
  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      std::cout << "Open clicked." << std::endl;

      //Notice that this is a std::string, not a Glib::ustring.
      str = dialog.get_filename();
      std::cout << "File selected: " <<  str << std::endl;
      break;
    }
    {
      std::cout << "Cancel clicked." << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unexpected button clicked." << std::endl;
      break;
    }
  }
  //m_Entry_x.get_text();
  //m_Entry_y.get_text();
  //m_Entry_z.get_text();
  //m_Entry_x.set_text("x");
  //m_Entry_y.set_text("y");
  //m_Entry_z.set_text("z");
  //m_Entry.set_editable(m_CheckButton_Editable.get_active());
}


void Three2::on_checkbox_visibility_toggled()
{
  char * UStringToCharArray = (char*)m_Entry_x.get_text().c_str();
  double a = atof(UStringToCharArray);
  UStringToCharArray = (char*)m_Entry_y.get_text().c_str();
  double b = atof(UStringToCharArray);
  UStringToCharArray = (char*)m_Entry_z.get_text().c_str();
  double c = atof(UStringToCharArray);
  m_Entry_x.set_text("0");
  m_Entry_y.set_text("0");
  m_Entry_z.set_text("1");
Gtk::Window* win = new Gtk::Window();
   win->set_title("x= " + m_Entry_x.get_text() + " y= " + m_Entry_y.get_text() +" z= " + m_Entry_z.get_text());
   MyArea* area=new MyArea(str,a,b,c);
   win->add(*area);
   area->show();

   win->show();
  //m_Entry.set_visibility(m_CheckButton_Visible.get_active());
}

void Three2::on_button_close()
{
  hide();
}
