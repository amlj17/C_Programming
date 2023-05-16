//
//  Gtk calculadora.c
//  
//
//  Created by Andres Moguel on 4/21/21.
//

#include <gtk/gtk.h>
#include <string.h>


//GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
void ButtonClicked(GtkButton *button, gpointer data);
void ButtonClicked2(GtkButton *button, gpointer data);
void StopTheApp(GtkWidget *window, gpointer data);

gint main ( gint argc, gchar *argv[])
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *entrybox;
  GtkWidget *verticalbox;
  GtkWidget *horizontalbox1;
  GtkWidget *horizontalbox2;
  GtkWidget *horizontalbox3;
  GtkWidget *horizontalbox4;
  GtkWidget *label;

  gtk_init(&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window),320,200);
  gtk_container_border_width(GTK_CONTAINER(window),5);

  verticalbox = gtk_vbox_new(TRUE,0);

  entrybox = gtk_entry_new();

  horizontalbox1 = gtk_hbox_new(TRUE,0);
  horizontalbox2 = gtk_hbox_new(TRUE,0);
  horizontalbox3 = gtk_hbox_new(TRUE,0);
  horizontalbox4 = gtk_hbox_new(TRUE,0);

  //button = AddButton(box,"pon texto",ButtonClicked,entrybox);
  //button = AddButton(box,"captura texto",HelloAction,entrybox);

// boton 1
button = gtk_button_new_with_label("1"); //creo
   gtk_box_pack_start(GTK_BOX(horizontalbox1),button,FALSE,TRUE,0); //empaco
   gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox); //conecto
   gtk_widget_show(button);
// boton 2
   button = gtk_button_new_with_label("2");
   gtk_box_pack_start(GTK_BOX(horizontalbox1),button,FALSE,TRUE,0);
   gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
   gtk_widget_show(button);

   button = gtk_button_new_with_label("3");
   gtk_box_pack_start(GTK_BOX(horizontalbox1),button,FALSE,TRUE,0);
   gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
   gtk_widget_show(button);

   label = gtk_label_new(" "); //para dejar espacio en blanco
   gtk_box_pack_start(GTK_BOX(horizontalbox1),label,FALSE,TRUE,0);

   button = gtk_button_new_with_label("4");
   gtk_box_pack_start(GTK_BOX(horizontalbox2),button,FALSE,TRUE,0);
   gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
   gtk_widget_show(button);

   button = gtk_button_new_with_label("5");
   gtk_box_pack_start(GTK_BOX(horizontalbox2),button,FALSE,TRUE,0);
   gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
   gtk_widget_show(button);
   // boton 2
       button = gtk_button_new_with_label("6");
       gtk_box_pack_start(GTK_BOX(horizontalbox2),button,FALSE,TRUE,0);
       gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
       gtk_widget_show(button);

       button = gtk_button_new_with_label("+");
       gtk_box_pack_start(GTK_BOX(horizontalbox2),button,FALSE,TRUE,0);
       gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
       gtk_widget_show(button);




       button = gtk_button_new_with_label("7");
       gtk_box_pack_start(GTK_BOX(horizontalbox3),button,FALSE,TRUE,0);
       gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
       gtk_widget_show(button);

       button = gtk_button_new_with_label("8");
       gtk_box_pack_start(GTK_BOX(horizontalbox3),button,FALSE,TRUE,0);
       gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
       gtk_widget_show(button);
       // boton 2
    button = gtk_button_new_with_label("9");
    gtk_box_pack_start(GTK_BOX(horizontalbox3),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
    gtk_widget_show(button);

    button = gtk_button_new_with_label("-");
    gtk_box_pack_start(GTK_BOX(horizontalbox3),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
    gtk_widget_show(button);




    button = gtk_button_new_with_label("0");
    gtk_box_pack_start(GTK_BOX(horizontalbox4),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
    gtk_widget_show(button);

    button = gtk_button_new_with_label("*");
    gtk_box_pack_start(GTK_BOX(horizontalbox4),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
    gtk_widget_show(button);
    // boton 2
    button = gtk_button_new_with_label("/");
    gtk_box_pack_start(GTK_BOX(horizontalbox4),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked),entrybox);
    gtk_widget_show(button);

    button = gtk_button_new_with_label("=");
    gtk_box_pack_start(GTK_BOX(horizontalbox4),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ButtonClicked2),entrybox);
    gtk_widget_show(button);


  gtk_box_pack_start(GTK_BOX(verticalbox),entrybox,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),horizontalbox1,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),horizontalbox2,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),horizontalbox3,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),horizontalbox4,FALSE,TRUE,0);

  gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(StopTheApp),NULL);

  gtk_container_add(GTK_CONTAINER(window),verticalbox);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;

}
GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
    GtkWidget *button;
    button = gtk_button_new_with_label(buttonText);
    gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CallBackFunction),EntryBox);
    gtk_widget_show(button);
    return button;
}

void ButtonClicked(GtkButton *button, gpointer data)
{
    const gchar *text, *text2;
    char texto2[25];

    text = gtk_button_get_label(GTK_BUTTON(button));

    text2 = gtk_entry_get_text(GTK_ENTRY(data));
    strcpy(texto2,text2);
    strcat(texto2,text);
    gtk_entry_set_text(GTK_ENTRY(data),texto2);
}

void StopTheApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}
void ButtonClicked2(GtkButton *button, gpointer data)
{
  const gchar *text;
  int op1,op2;
  int res;
  char operacion,resultado[30];

  text = gtk_entry_get_text(GTK_ENTRY(data));
  sscanf(text,"%d%c%d",&op1,&operacion,&op2);
  switch(operacion)
  {
    case '+': res=op1+op2;
    break;
    case '-': res=op1-op2;
    break;
    case '*': res=op1*op2;
    break;
    case '/': res=op1/op2;
    break;
  }
  sprintf(resultado,"%d", res);
  gtk_entry_set_text(GTK_ENTRY(data),resultado);
}
