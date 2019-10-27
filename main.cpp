#include <iostream>
#include <stdio.h>
#include <gtk/gtk.h>


int main(int argc, char *argv[]) {
    GtkWidget *window;

    /**
     * calls gtk_init(gint *argc, gchar ***argv) to set up default visual and color map
     * calls gdk_init(gint *argc, gchar ***argv) to set up default signal handlers and checks the arguments
     *       passed to your application on the command line. Removes gtk-module, g-fatal-warnings, gtk-debug,
     *       gtk-no-debug, display, sync, name, class. Creates a set of standard arguments accepted by all GTK applications */
    gtk_init(&argc, & argv);

    /** Create a window
     * GTK_WINDOW_TOPLEVEL says that we want the window to undergo window manager decoration and placement. Creates a
     * window of 200x200 by default to allow manipulation even w/o children */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /** Displays the window
     * Lets GTK know that we are done setting the attributes of this widget and that it can display it
     */
    gtk_widget_show(window);

    /** Enters the GTK main processing loop
     * When control reaches this point, GTK will sleep waiting for events (button/key presses), timeouts,
     * or file IO notifications to occur.
     */
    gtk_main();
    return 0;
}