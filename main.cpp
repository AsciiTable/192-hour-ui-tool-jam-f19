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
    GtkWidget *label, *space;
    GtkWidget *rspin, *cspin;

    bool playgroundCreated = false;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "UI Toolkit");

    g_signal_connect(window, "delete-event", G_CALLBACK(tool.delete_event),NULL);

    gtk_container_set_border_width(GTK_CONTAINER(window), 30);

    if(!playgroundCreated){
        grid = gtk_grid_new();
        gtk_grid_set_row_spacing(GTK_GRID(grid),5);
        gtk_grid_set_column_spacing(GTK_GRID(grid),10);
        /* Puts the table in the main window */
        gtk_container_add (GTK_CONTAINER (window), grid);

        /* Row Spin Button */
        label = gtk_label_new("Row: ");
        gtk_label_set_xalign(GTK_LABEL(label), 0);
        gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
        gtk_widget_show(label);

        rspin = gtk_spin_button_new_with_range(1, 10, 1);
        gtk_grid_attach(GTK_GRID(grid), rspin, 1, 0, 1, 1);
        gtk_widget_show(rspin);

        /* Column Spin Button */
        label = gtk_label_new("Column: ");
        gtk_label_set_xalign(GTK_LABEL(label), 0);
        gtk_grid_attach(GTK_GRID(grid), label, 0, 1, 1, 1);
        gtk_widget_show(label);

        cspin = gtk_spin_button_new_with_range(1, 10, 1);
        gtk_grid_attach(GTK_GRID(grid), cspin, 1, 1, 1, 1);
        gtk_widget_show(cspin);

        /* Space for Formatting */
        space = gtk_label_new("");
        gtk_grid_attach(GTK_GRID(grid), space, 0, 2, 2, 1);
        gtk_widget_show(space);

        /* Create Playground Button */
        button = gtk_button_new_with_label ("Create Playground");
        g_signal_connect (button, "clicked",G_CALLBACK (tool.callback), (gpointer) "button 1");
        gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);
        gtk_widget_show (button);

        /* Quit Button */
        button = gtk_button_new_with_label("Quit");
        g_signal_connect(button, "clicked", G_CALLBACK(tool.delete_event), NULL);
        gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 2, 1);
        gtk_widget_show(button);

        gtk_widget_show(grid);
        gtk_widget_show(window);
    }

    gtk_main();
    return 0;
}

