//
//  Modificar clientes.c
//  
//
//  Created by Andres Moguel on 5/3/21.
//

#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

void StopTheApp(GtkWidget *window, gpointer data);

gint main ( gint argc, gchar *argv[])
{

  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *verticalbox;
  GtkWidget *hbox1;
  GtkWidget *hbox2;
  GtkWidget *hbox3;
  GtkWidget *hbox4;
  GtkWidget *hbox5;
  GtkWidget *hbox6;
  GtkWidget *hbox7;
  GtkWidget *label;
  GtkWidget *entrybox;
  GtkWidget *radio;
  GSList *grupo;
  GtkWidget *vbox;

  gtk_init(&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window),320,200);
  gtk_container_border_width(GTK_CONTAINER(window),5);

  verticalbox= gtk_vbox_new(TRUE,0);
  vbox = gtk_vbox_new(FALSE,0);
  hbox1 = gtk_hbox_new(TRUE,0);
  hbox2 = gtk_hbox_new(TRUE,0);
  hbox3 = gtk_hbox_new(TRUE,0);
  hbox4 = gtk_hbox_new(TRUE,0);
  hbox5 = gtk_hbox_new(TRUE,0);
  hbox6 = gtk_hbox_new(TRUE,0);
  hbox7 = gtk_hbox_new(TRUE,0);

  label=gtk_label_new("Nombre");
  entrybox=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox1),label,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(hbox1),entrybox,FALSE,TRUE,0);

  label=gtk_label_new("Ap Paterno");
  entrybox=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox2),label,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(hbox2),entrybox,FALSE,TRUE,0);

  label=gtk_label_new("Ap Materno");
  entrybox=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox3),label,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(hbox3),entrybox,FALSE,TRUE,0);

  label=gtk_label_new("Telefono");
  entrybox=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox4),label,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(hbox4),entrybox,FALSE,TRUE,0);

  label=gtk_label_new("Correo");
  entrybox=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox5),label,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(hbox5),entrybox,FALSE,TRUE,0);

  label=gtk_label_new("Estatus");
  radio=gtk_radio_button_new_with_label(NULL, "Activo");
  gtk_box_pack_start(GTK_BOX(vbox),radio,TRUE,TRUE,0);
  gtk_widget_show(radio);

  grupo=gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio));
  radio=gtk_radio_button_new_with_label(grupo, "Inactivo");
  gtk_box_pack_start(GTK_BOX(vbox),radio,TRUE,TRUE,0);
  gtk_widget_show(radio);

  
  gtk_box_pack_start(GTK_BOX(hbox7),label,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(hbox7),vbox,FALSE,TRUE,0);
  

  button= gtk_button_new_with_label("Actualizar");
  gtk_box_pack_start(GTK_BOX(hbox6),button,FALSE,TRUE,0);
  gtk_widget_show(button);

  button= gtk_button_new_with_label("Clear");
  gtk_box_pack_start(GTK_BOX(hbox6),button,FALSE,TRUE,0);
  gtk_widget_show(button);

  button= gtk_button_new_with_label("Cancelar");
  gtk_box_pack_start(GTK_BOX(hbox6),button,FALSE,TRUE,0);
  gtk_widget_show(button);

  label=gtk_label_new("Modificar Cliente");
  gtk_box_pack_start(GTK_BOX(verticalbox),label,FALSE,TRUE,0);

  label=gtk_label_new("Modifique los datos correspondientes");
  gtk_box_pack_start(GTK_BOX(verticalbox),label,FALSE,TRUE,0);

  gtk_box_pack_start(GTK_BOX(verticalbox),hbox1,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),hbox2,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),hbox3,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),hbox4,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),hbox5,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),hbox7,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),hbox6,FALSE,TRUE,0);


  gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(StopTheApp),NULL);

  gtk_container_add(GTK_CONTAINER(window),verticalbox);

  gtk_widget_show_all(window);

  gtk_main();
  
  return 0;

}


void StopTheApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
    

}
