#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "ui_toolkit.h"
using namespace std;

int main(int argc, char* argv[]) {
    int MAINROWCOUNT = 6;
    ui_toolkit tool;
    ui_toolkit::PlaygroundDimensions pdimen;
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *grid;
    GtkWidget *label, *space;
    GtkWidget *rspin, *cspin;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "UI Toolkit");
    gtk_window_set_resizable(GTK_WINDOW(window), false);

    g_signal_connect(window, "delete-event", G_CALLBACK(tool.delete_event),NULL);

    gtk_container_set_border_width(GTK_CONTAINER(window), 30);

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid),5);
    gtk_grid_set_column_spacing(GTK_GRID(grid),10);
    /* Puts the table in the main window */
    gtk_container_add (GTK_CONTAINER (window), grid);

    /* Row Spin Button */
    label = gtk_label_new("Row: ");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, MAINROWCOUNT-6, 1, 1);
    gtk_widget_show(label);

    rspin = gtk_spin_button_new_with_range(1, 10, 1);
    gtk_grid_attach(GTK_GRID(grid), rspin, 1, MAINROWCOUNT-6, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(rspin), true);
    gtk_widget_show(rspin);
    pdimen.row = rspin;

    /* Row Space Spin Button */
    label = gtk_label_new("Row Space: ");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, MAINROWCOUNT-5, 1, 1);
    gtk_widget_show(label);

    rspin = gtk_spin_button_new_with_range(10, 100, 1);
    gtk_grid_attach(GTK_GRID(grid), rspin, 1, MAINROWCOUNT-5, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(rspin), true);
    gtk_widget_show(rspin);
    pdimen.rowSize = rspin;

    /* Column Spin Button */
    label = gtk_label_new("Column: ");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, MAINROWCOUNT-4, 1, 1);
    gtk_widget_show(label);

    cspin = gtk_spin_button_new_with_range(1, 10, 1);
    gtk_grid_attach(GTK_GRID(grid), cspin, 1, MAINROWCOUNT-4, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(cspin), true);
    gtk_widget_show(cspin);
    pdimen.col = cspin;

    /* Column Space Spin Button */
    label = gtk_label_new("Column Space: ");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, MAINROWCOUNT-3, 1, 1);
    gtk_widget_show(label);

    cspin = gtk_spin_button_new_with_range(10, 100, 1);
    gtk_grid_attach(GTK_GRID(grid), cspin, 1, MAINROWCOUNT-3, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(cspin), true);
    gtk_widget_show(cspin);
    pdimen.colSize = cspin;

    /* Space for Formatting */
    space = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), space, 0, MAINROWCOUNT-2, 2, 1);
    gtk_widget_show(space);

    /* Create Playground Button */
    button = gtk_button_new_with_label ("Create Playground");
    g_signal_connect (button, "clicked",G_CALLBACK (tool.make_playground), &pdimen);
    gtk_grid_attach(GTK_GRID(grid), button, 0, MAINROWCOUNT-1, 2, 1);
    gtk_widget_show (button);

    /* Quit Button */
    button = gtk_button_new_with_label("Quit");
    g_signal_connect(button, "clicked", G_CALLBACK(tool.delete_event), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, MAINROWCOUNT, 2, 1);
    gtk_widget_show(button);

    gtk_widget_show(grid);
    gtk_widget_show(window);

    gtk_main();
    return 0;
}

