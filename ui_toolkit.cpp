//
// Created by Jessica Wei on 10/31/19.
//

#include "ui_toolkit.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
using namespace std;

gboolean ui_toolkit::delete_event(GtkWidget *widget, GdkEvent *event, gpointer data){
    g_print("Program closed.\n");
    gtk_main_quit();

    /* Return FALSE to let GTK emit the "destroy" signal */
    return FALSE;
    /* Return TRUE to stop the window from being destroyed -- useful for confirming quit request popups */
    //return TRUE;
}

GtkWidget *ui_toolkit::make_playground(GtkWidget *widget, gpointer data){
    GtkWidget *space;
    PlaygroundDimensions *p = (PlaygroundDimensions*)data;

    p->playwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(p->playwin), "Playground");
    gtk_window_set_resizable(GTK_WINDOW(p->playwin), false);
    gtk_window_set_position(GTK_WINDOW(p->playwin), GTK_WIN_POS_CENTER_ALWAYS);

    g_signal_connect(p->playwin, "delete-event", G_CALLBACK(gtk_window_close),NULL);

    gtk_container_set_border_width(GTK_CONTAINER(p->playwin), 30);

    p->play = gtk_grid_new();
    int rS = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->rowSize));
    int cS = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->colSize));

    gtk_grid_set_row_spacing(GTK_GRID(p->play), rS);
    gtk_grid_set_column_spacing(GTK_GRID(p->play),cS);

    int r = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->row));
    int c = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->col));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            space = gtk_label_new("");
            gtk_grid_attach(GTK_GRID(p->play), space, j, i, 1,  1);
            gtk_widget_show(space);
        }
    }
    cout << r << "x" << c << " playground created." << endl;
    gtk_container_add (GTK_CONTAINER (p->playwin), p->play);

    gtk_widget_show(p->play);
    gtk_widget_show(p->playwin);


    return p->playwin;
}