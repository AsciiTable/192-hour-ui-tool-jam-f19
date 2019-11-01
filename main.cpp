#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "ui_toolkit.h"
using namespace std;

int main(int argc, char* argv[]) {
    ui_toolkit tool;
    GtkWidget *window;
    //GtkWidget *completebutton;
    //GtkWidget *exitbutton;
    //GtkWidget *tabel;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "UI Toolkit");

    g_signal_connect(window, "delete-event", G_CALLBACK(tool.delete_event),NULL);

    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    gtk_widget_show(window);

    gtk_main();
    return 0;
}

