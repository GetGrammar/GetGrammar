#include <gtk/gtk.h>

static gboolean close (GtkWidget *widget, GdkEvent* event, gpointer *data) {
	gtk_main_quit ();
	return FALSE;
}

void sett(GtkButton *button, gpointer data){
	GtkWidget *dialog, *button1, *button2, *content_area;
	GtkDialogFlags flags;
	flags = GTK_DIALOG_DESTROY_WITH_PARENT;
dialog =gtk_dialog_new_with_buttons("Режим",NULL,flags,GTK_STOCK_OK,GTK_RESPONSE_ACCEPT,NULL);
	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	button1 = gtk_button_new_with_label("Заучивание");
	button2 = gtk_button_new_with_label("Повторение");
	gtk_container_add(GTK_CONTAINER(content_area),button1);
	gtk_container_add(GTK_CONTAINER(content_area),button2);
	gtk_widget_show(button1);
	gtk_widget_show(button2);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}


int main (int argc, char *argv[]) {
	GtkWidget *window, *vbox, *hbox1,*hbox2,*hbox3,*hbox4, *button1, *button2, 		*button3, *button4,*button5, *button6, *label1, *label2;

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window), "destroy", 					G_CALLBACK(gtk_main_quit), NULL);

	gtk_container_set_border_width (GTK_CONTAINER (window), 50);
	vbox = gtk_vbox_new (TRUE, 3);
	gtk_container_add (GTK_CONTAINER (window), vbox);

	hbox1 = gtk_hbox_new (TRUE, 3);
	hbox2 = gtk_hbox_new (TRUE, 3);
	hbox3 = gtk_hbox_new (TRUE, 3);
	hbox4 = gtk_hbox_new (TRUE, 3); 
	gtk_box_pack_start (GTK_BOX (vbox), hbox1, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox2, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox3, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox4, FALSE, FALSE, 0);
	button1 = gtk_button_new_with_label ("Режим");
	g_signal_connect(GTK_BUTTON(button1), "clicked", G_CALLBACK(sett), 							NULL);
	gtk_box_pack_start (GTK_BOX (hbox1), button1, FALSE, FALSE, 0);
	button2 = gtk_button_new_with_label ("%Answer1%");
	gtk_box_pack_start (GTK_BOX (hbox3), button2, FALSE, FALSE, 0);
	button3 = gtk_button_new_with_label ("%Answer2%");
	gtk_box_pack_start (GTK_BOX (hbox3), button3, FALSE, FALSE, 0);
	button4 = gtk_button_new_with_label ("%Answer3%");
	gtk_box_pack_start (GTK_BOX (hbox4), button4, FALSE, FALSE, 0);
	button5 = gtk_button_new_with_label ("%Answer4%");
	gtk_box_pack_start (GTK_BOX (hbox4), button5, FALSE, FALSE, 0);
	button6 = gtk_button_new_with_label ("STOP");
	gtk_box_pack_start (GTK_BOX (vbox), button6, FALSE, FALSE, 0);
	label1 = gtk_label_new("Счет: ");
	label2 = gtk_label_new("%Word%");
	gtk_box_pack_start (GTK_BOX (hbox1), label1, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (hbox2), label2, FALSE, FALSE, 0);
	gtk_widget_show_all (window);

	gtk_main ();

	return (0);

}
