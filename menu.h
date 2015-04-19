#ifndef MENU_H_INCLUDED
#define NENU_H_INCLUDED

#include<gtk/gtk.h>
#include "callingfunctions.h"

GtkWidget *table;
GtkWidget *button;
GSList *group;

/* This callback quits the program */
gint delete_widget( GtkWidget *widget,
                    GdkEvent  *event,
                    gpointer   data )
{
    gtk_widget_destroy(widget);
    return(FALSE);
}

/* This callback quits the program */
gint delete_event( GtkWidget *widget,
                   GdkEvent  *event,
                   gpointer   data )
{
    gtk_main_quit ();
    return(FALSE);
}


void callback(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
}

void callbackPoint1(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    convexmirror(0);
}

void callbackPoint2(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    concavemirror(0);
}

void callbackPoint3(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s wpas chosen.\n", (char *) data);
    planemirror(0);
}

void callbackPoint4(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s wpas chosen.\n", (char *) data);
    convexlens(0);
}

void callbackPoint5(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s wpas chosen.\n", (char *) data);
    concavelens(0);
}

void callbackExtended1(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    convexmirror(1);
}

void callbackExtended2(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    concavemirror(2);
}

void callbackExtended3(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    planemirror(3);
}

void callbackExtended4(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    convexlens(4);
}

void callbackExtended5(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    concavelens(5);
}

//Function for getting radius
/*void getradius(int p)
{
    GtkWidget *label;
    GtkWidget *entry;
    const gchar *textradius;

    // create a new label.
    label = gtk_label_new ("Enter Radius:" );
    //gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE (table), label, 1, 3, 15, 16);
    gtk_widget_show(label);


    //create a text box
    entry = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry),3);
    //textradius = gtk_entry_get_text (GTK_ENTRY(entry));
    //cout<<*textradius;
    gtk_signal_connect(GTK_OBJECT(entry), "activate" ,GTK_SIGNAL_FUNC(callback), (gpointer) *gtk_entry_get_text (GTK_ENTRY (entry)));
    gtk_table_attach_defaults (GTK_TABLE (table), entry, 0, 4, 16, 17);
    gtk_widget_show(entry);

    //create a enter button
    button = gtk_button_new_with_label("ENTER");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 5, 7, 16, 17);
    gtk_signal_connect(GTK_OBJECT(button), "activate" ,GTK_SIGNAL_FUNC(callback), (gpointer) "Machaya");
    gtk_widget_show (button);

    if(p==4||p==5)
    {
        // create a new label.
        label = gtk_label_new ("Enter Refractive Index:" );
        //gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
        gtk_table_attach_defaults (GTK_TABLE (table), label, 1, 3, 17, 18);
        gtk_widget_show(label);


        //create a text box
        entry = gtk_entry_new ();
        gtk_entry_set_max_length (GTK_ENTRY (entry),0);
        gtk_table_attach_defaults (GTK_TABLE (table), entry, 0, 4, 18, 19);
        gtk_widget_show(entry);

        //create a enter button
        button = gtk_button_new_with_label("ENTER");
        gtk_table_attach_defaults (GTK_TABLE (table), button, 5, 7, 18, 19);
        gtk_widget_show (button);

    }

}*/

/* Our callback.
 * The data passed to this function is printed to stdout */


void callback1(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    /* Create second button */

    button = gtk_button_new_with_label ("Select type of object");

    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 1, 6, 15, 16);

    gtk_widget_show (button);


    button = gtk_button_new_with_label ("POINT");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackPoint1), (gpointer) "POINT");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 3, 17, 18);

    gtk_widget_show (button);

    /* Create third button */

    button = gtk_button_new_with_label ("EXTENDED");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackExtended1), (gpointer) "EXTENDED");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 4, 7, 17, 18);

    gtk_widget_show (button);

}

void callback2(GtkWidget* widget,gpointer data)
{

    g_print("Hello again - %s was chosen.\n", (char *) data);
    /* Create second button */

    button = gtk_button_new_with_label ("Select type of object");

    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 1, 6, 15, 16);

    gtk_widget_show (button);


    button = gtk_button_new_with_label ("POINT");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackPoint2), (gpointer) "POINT");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 3, 17, 18);

    gtk_widget_show (button);

    /* Create third button */

    button = gtk_button_new_with_label ("EXTENDED");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackExtended2), (gpointer) "EXTENDED");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 4, 7, 17, 18);

    gtk_widget_show (button);

}

void callback3(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    /* Create second button */

    button = gtk_button_new_with_label ("Select type of object");

    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 1, 6, 15, 16);

    gtk_widget_show (button);


    button = gtk_button_new_with_label ("POINT");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackPoint3), (gpointer) "POINT");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 3, 17, 18);

    gtk_widget_show (button);

    /* Create third button */

    button = gtk_button_new_with_label ("EXTENDED");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackExtended3), (gpointer) "EXTENDED");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 4, 7, 17, 18);

    gtk_widget_show (button);

}


void callback4(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);

    /* Create second button */

    button = gtk_button_new_with_label ("Select type of object");

    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 1, 6, 15, 16);

    gtk_widget_show (button);


    button = gtk_button_new_with_label ("POINT");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackPoint4), (gpointer) "POINT");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 3, 17, 18);

    gtk_widget_show (button);

    /* Create third button */

    button = gtk_button_new_with_label ("EXTENDED");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackExtended4), (gpointer) "EXTENDED");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 4, 7, 17, 18);

    gtk_widget_show (button);

}

void callback5(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    /* Create second button */

    button = gtk_button_new_with_label ("Select type of object");

    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 1, 6, 15, 16);

    gtk_widget_show (button);


    button = gtk_button_new_with_label ("POINT");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackPoint5), (gpointer) "POINT");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 3, 17, 18);

    gtk_widget_show (button);

    /* Create third button */

    button = gtk_button_new_with_label ("EXTENDED");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackExtended5), (gpointer) "EXTENDED");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 4, 7, 17, 18);

    gtk_widget_show (button);

}


void callbackHelp(GtkWidget* widget,gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    help();
    /* GtkWidget *helpwindow, *tablehelp, *labelhelp;
     helpwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_window_set_default_size(GTK_WINDOW(helpwindow),600,600);
     gtk_window_set_title (GTK_WINDOW(helpwindow),"HELP");
     gtk_signal_connect(GTK_OBJECT(helpwindow),"delete_widget",GTK_SIGNAL_FUNC(delete_widget),NULL);
     gtk_container_set_border_width (GTK_CONTAINER (helpwindow), 20);
     gtk_widget_show(helpwindow);

     tablehelp = gtk_table_new(4,4,TRUE);
     gtk_container_add (GTK_CONTAINER (helpwindow),tablehelp);

     labelhelp = gtk_label_new ("Machaya");
     gtk_table_attach_defaults (GTK_TABLE(tablehelp), labelhelp, 0, 2, 0, 2);
     gtk_widget_show (labelhelp); */
}

void callbackInfo(GtkWidget* widget, gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);
    /* GtkWidget *infowindow;
    infowindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(infowindow),500,400);
    gtk_window_set_title (GTK_WINDOW(infowindow),"INFO");
    gtk_signal_connect(GTK_OBJECT(infowindow),"delete_widget",GTK_SIGNAL_FUNC(delete_widget),NULL);
    gtk_container_set_border_width (GTK_CONTAINER (infowindow), 20);
    gtk_widget_show(infowindow);  */
    info();
}


void callbackConvex(GtkWidget* widget, gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);

    /* Create tenth button */

    button = gtk_button_new_with_label ("REAL OBJECT");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callback4), (gpointer) "REAL OBJECT");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 10, 13, 11, 12);
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("VIRTUAL OBJECT");
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callback4), (gpointer) "Virtual OBJECT");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 14, 17, 11, 12);
    gtk_widget_show (button);

}

void callbackConcave(GtkWidget* widget, gpointer data)
{
    g_print("Hello again - %s was chosen.\n", (char *) data);

    /* Create tenth button */

    button = gtk_button_new_with_label ("REAL OBJECT");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callback5), (gpointer) "REAL OBJECT");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 10, 13, 11, 12);
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("VIRTUAL OBJECT");
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callback5), (gpointer) "Virtual OBJECT");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 14, 17, 11, 12);
    gtk_widget_show (button);

}

void callbackMirror(GtkWidget *widget, gpointer data )
{
    g_print ("Hello again - %s was chosen.\n", (char *) data);

    /* Create fourth button */

    button = gtk_button_new_with_label ("CONVEX MIRROR");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callback1), (gpointer) "CONVEX MIRROR");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 2, 5, 8, 9);

    gtk_widget_show (button);

    /* Create fifth button */

    button = gtk_button_new_with_label ("CONCAVE MIRROR");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callback2), (gpointer) " CONCAVE MIRROR");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 6, 9, 8, 9);

    gtk_widget_show (button);

    /* Create sixth button */

    button = gtk_button_new_with_label ("PLANE MIRROR");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callback3), (gpointer) "PLANE MIRROR");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 4, 7, 10, 11);

    gtk_widget_show (button);

}

void callbackLens( GtkWidget *widget, gpointer   data )
{
    g_print ("Hello again - %s was chosen.\n", (char *) data);

    /* Create seventh button */

    button = gtk_button_new_with_label ("CONVEX LENS");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackConvex), (gpointer) "CONVEX LENS");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 10, 13, 8, 9);

    gtk_widget_show (button);

    /* Create eighth button */

    button = gtk_button_new_with_label ("CONCAVE LENS");

    /* When the button is clicked, we call the "callback" function
     * with a pointer to "button 2" as its argument */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
                        GTK_SIGNAL_FUNC (callbackConcave), (gpointer) " CONCAVE LENS");
    /* Insert button 2 into the upper right quadrant of the table */
    gtk_table_attach_defaults (GTK_TABLE(table), button, 14, 17, 8, 9);

    gtk_widget_show (button);

}


#endif
