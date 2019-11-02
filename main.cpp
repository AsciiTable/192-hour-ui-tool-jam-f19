#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "ui_toolkit.h"
using namespace std;

int main(int argc, char* argv[]) {
    ui_toolkit tool;
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *grid;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "UI Toolkit");

    g_signal_connect(window, "delete-event", G_CALLBACK(tool.delete_event),NULL);

    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid),5);
    /* Puts the table in the main window */
    gtk_container_add (GTK_CONTAINER (window), grid);


    /* Insert button 1 into the upper left quadrant of the table */
    button = gtk_button_new_with_label ("button 1");
    g_signal_connect (button, "clicked",G_CALLBACK (tool.callback), (gpointer) "button 1");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);
    gtk_widget_show (button);

    gtk_grid_insert_row(GTK_GRID(grid), 2);


    button = gtk_button_new_with_label("Quit");
    g_signal_connect(button, "clicked", G_CALLBACK(tool.delete_event), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);
    gtk_widget_show(button);

    gtk_widget_show(grid);
    gtk_widget_show(window);

    gtk_main();
    return 0;
}

