#include "menu.h"

int main( int   argc,
          char *argv[] )
{
    GtkWidget *window;
    GtkWidget *labelimage;

    gtk_init (&argc, &argv);

    /* Create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* Set the window title */
    gtk_window_set_title (GTK_WINDOW (window), "MENU");
    gtk_window_set_default_size (GTK_WINDOW (window),800,600);

    /* Set a handler for delete_event that immediately
     * exits GTK. */
    gtk_signal_connect (GTK_OBJECT (window), "delete_event",
                        GTK_SIGNAL_FUNC (delete_event), NULL);

    /* Sets the border width of the window. */
    gtk_container_set_border_width (GTK_CONTAINER (window), 20);

    /* Create a 2x2 table */
    table = gtk_table_new (20, 19, TRUE);

    /* Put the table in the main window */
    gtk_container_add (GTK_CONTAINER (window), table);

    labelimage = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(labelimage), "<large>I</large>ma<large>G</large>");
    gtk_widget_show(labelimage);

    /* Create first button */
    button = gtk_button_new_with_label ("MENU");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 1" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callback), (gpointer) "MENU");


    /* Insert button 1 into the upper left quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 8, 11, 0, 2);

    gtk_widget_show (button);

    /* Create second button */

    button = gtk_button_new_with_label ("MIRROR");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackMirror), (gpointer) "MIRROR");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 4, 7, 5, 6);

    gtk_widget_show (button);

    /* Create third button */

    button = gtk_button_new_with_label ("LENS");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackLens), (gpointer) "LENS");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 12, 15, 5, 6);

    gtk_widget_show (button);

    /* Create thirteenth button */

    button = gtk_button_new_with_label ("ImaGe");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackInfo), (gpointer) "ImaGe");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 3, 0, 2);

    gtk_widget_show (button);


    /* Create fourteenth button */

    button = gtk_button_new_with_label ("Help");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackHelp), (gpointer) "Help");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 13, 15, 18, 19);

    gtk_widget_show (button);


    /* Create "Quit" button */
    button = gtk_button_new_with_label ("Quit");

    /* When the button is clicked, we call the "delete_event" function
     * and the program exits */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (delete_event), NULL);

    /* Insert the quit button into the both
     * lower quadrants of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 16, 18, 18, 19);

    gtk_widget_show (button);

    gtk_widget_show (table);
    gtk_widget_show (window);

    gtk_main ();

    return 0;
}
