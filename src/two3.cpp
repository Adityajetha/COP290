#include "two3.h"
#include "main.h"
#include "myarea1.h"
#include <iostream>
#include <string.h>

Two3::Two3()
: m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Entryx("Top View"),
  m_Entryy("Front View"),
  m_Entryz("Side View"),
  m_Button_Close("Home"),
  m_CheckButton_Visible("Submit")
{
  set_border_width(200);
  set_title("2D to 3D");
   
  add(m_VBox);
  m_VBox.set_spacing(10);
  m_VBox.pack_start(m_Entryx);
  m_Entryx.signal_clicked().connect( sigc::mem_fun(*this,
  &Two3::topview) );

  m_VBox.pack_start(m_Entryy);
  m_Entryy.signal_clicked().connect( sigc::mem_fun(*this,
  &Two3::frontview) );

  m_VBox.pack_start(m_Entryz);
  m_Entryz.signal_clicked().connect( sigc::mem_fun(*this,
  &Two3::sideview) );


  // Note that add() can also be used instead of pack_xxx()
  m_VBox.add(m_HBox);

  m_HBox.pack_start(m_CheckButton_Visible);
  m_CheckButton_Visible.signal_clicked().connect( sigc::mem_fun(*this,
              &Two3::on_checkbox_visibility_toggled) );

  m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
              &Two3::on_button_close) );
  m_VBox.pack_start(m_Button_Close);
  m_Button_Close.set_can_default();
  m_Button_Close.grab_default();

  show_all_children();
}

Two3::~Two3()
{
}

void Two3::topview()
{
Gtk::FileChooserDialog dialog1("Please choose a file",
          Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog1.set_transient_for(*this);

  //Add response buttons the the dialog:
  dialog1.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog1.add_button("_Open", Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:

  auto filter_text = Gtk::FileFilter::create();
  filter_text->set_name("Text files");
  filter_text->add_mime_type("text/plain");
  dialog1.add_filter(filter_text);

  auto filter_cpp = Gtk::FileFilter::create();
  filter_cpp->set_name("C/C++ files");
  filter_cpp->add_mime_type("text/x-c");
  filter_cpp->add_mime_type("text/x-c++");
  filter_cpp->add_mime_type("text/x-c-header");
  dialog1.add_filter(filter_cpp);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog1.add_filter(filter_any);

  //Show the dialog and wait for a user response:
  int result = dialog1.run();

  //Handle the response:
  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      std::cout << "Open clicked." << std::endl;

      //Notice that this is a std::string, not a Glib::ustring.
      str1 = dialog1.get_filename();
      std::cout << "File selected: " <<  str1 << std::endl;
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
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
  //m_Entryx.get_text();
  //m_Entryy.get_text();
  //m_Entryz.get_text();
  //m_Entryx.set_text("");
  //m_Entryy.set_text("");
  //m_Entryz.set_text("");
  //m_Entry.set_editable(m_CheckButton_Editable.get_active());
}

void Two3::frontview()
{
Gtk::FileChooserDialog dialog2("Please choose a file",
          Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog2.set_transient_for(*this);

  //Add response buttons the the dialog:
  dialog2.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog2.add_button("_Open", Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:

  auto filter_text = Gtk::FileFilter::create();
  filter_text->set_name("Text files");
  filter_text->add_mime_type("text/plain");
  dialog2.add_filter(filter_text);

  auto filter_cpp = Gtk::FileFilter::create();
  filter_cpp->set_name("C/C++ files");
  filter_cpp->add_mime_type("text/x-c");
  filter_cpp->add_mime_type("text/x-c++");
  filter_cpp->add_mime_type("text/x-c-header");
  dialog2.add_filter(filter_cpp);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog2.add_filter(filter_any);

  //Show the dialog and wait for a user response:
  int result = dialog2.run();

  //Handle the response:
  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      std::cout << "Open clicked." << std::endl;

      //Notice that this is a std::string, not a Glib::ustring.
      str2 = dialog2.get_filename();
      std::cout << "File selected: " <<  str2 << std::endl;
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
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
  //m_Entryx.get_text();
  //m_Entryy.get_text();
  //m_Entryz.get_text();
  //m_Entryx.set_text("");
  //m_Entryy.set_text("");
  //m_Entryz.set_text("");
  //m_Entry.set_editable(m_CheckButton_Editable.get_active());
}

void Two3::sideview()
{
Gtk::FileChooserDialog dialog3("Please choose a file",
          Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog3.set_transient_for(*this);

  //Add response buttons the the dialog:
  dialog3.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog3.add_button("_Open", Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:

  auto filter_text = Gtk::FileFilter::create();
  filter_text->set_name("Text files");
  filter_text->add_mime_type("text/plain");
  dialog3.add_filter(filter_text);

  auto filter_cpp = Gtk::FileFilter::create();
  filter_cpp->set_name("C/C++ files");
  filter_cpp->add_mime_type("text/x-c");
  filter_cpp->add_mime_type("text/x-c++");
  filter_cpp->add_mime_type("text/x-c-header");
  dialog3.add_filter(filter_cpp);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog3.add_filter(filter_any);

  //Show the dialog and wait for a user response:
  int result = dialog3.run();

  //Handle the response:
  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      std::cout << "Open clicked." << std::endl;

      //Notice that this is a std::string, not a Glib::ustring.
      str3 = dialog3.get_filename();
      std::cout << "File selected: " <<  str3 << std::endl;
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
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
  //m_Entryx.get_text();
  //m_Entryy.get_text();
  //m_Entryz.get_text();
  //m_Entryx.set_text("");
  //m_Entryy.set_text("");
  //m_Entryz.set_text("");
  //m_Entry.set_editable(m_CheckButton_Editable.get_active());
}


void Two3::on_checkbox_visibility_toggled()
{
   int k=0;
double zr=1,xr=0,yr=0,t=0,s=0;

   Gtk::Window* win = new Gtk::Window();
   win->set_title("3D Object");
   win->show();
   MyArea1* area=new MyArea1(str1,str2,str3);
   win->add(*area);
   area->show();
   //area->hide();
   /*while(k<10){
   
   sleep(2);
   win->close();
   win = new Gtk::Window();
   area=new MyArea1(str1,str2,str3,xr,yr,zr);
   win->add(*area);
   area->show();
   win->show();
   t+=1.11;
s+=1.21;
zr=cos(t/180);
yr=sin(t/180);
k++;}*/
   
  //m_Entry.set_visibility(m_CheckButton_Visible.get_active());
}

void Two3::on_button_close()
{
  hide();
}
