#include <gtk/gtk.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "Grammar_logic_lib.cpp"
using namespace std;
//#include "Grammar_logic_lib.cpp" 
GtkWidget *radiobutton1, *radiobutton2, *toglebutton,*toglebutton1;
int answer = 0;

static gboolean close (GtkWidget *widget, GdkEvent* event, gpointer *data) {
	gtk_main_quit ();
	return FALSE;
}
gchar* str_to_char(string s){
gchar* chrstr = new gchar[s.length() + 1];
strcpy(chrstr,s.c_str());
return chrstr;
}
void press_button(GtkWidget *button){
	const char *butt = gtk_button_get_label(GTK_BUTTON(button));
	printf(butt);
}
void add_widget_with_label(GtkContainer *box, gchar *caption, GtkWidget *widget)
{
    GtkWidget *label = gtk_label_new(caption);
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    gtk_label_set_width_chars(GTK_LABEL(label), 15);

    gtk_container_add(GTK_CONTAINER(hbox), label);
    gtk_container_add(GTK_CONTAINER(hbox), widget);

    gtk_container_add(box, hbox);
}
void first_mode(void){
	GtkWidget *dialog, *vbox, *hbox1,*hbox2,*hbox3,*hbox4, *button1, *button2, *button3, *button4,*button5, *button6, *label1, *label2, *label3,*label4, *content_area;
	GtkDialogFlags flags;
	flags = GTK_DIALOG_DESTROY_WITH_PARENT;
	dialog =gtk_dialog_new_with_buttons("Заучивание",NULL,flags,GTK_STOCK_STOP ,GTK_RESPONSE_ACCEPT,NULL);
	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	vbox = gtk_vbox_new (TRUE, 3);
	gtk_container_add (GTK_CONTAINER (content_area), vbox);
	hbox1 = gtk_hbox_new (TRUE, 3);
	hbox2 = gtk_hbox_new (TRUE, 3);
	hbox3 = gtk_hbox_new (TRUE, 3);
	hbox4 = gtk_hbox_new (TRUE, 3); 
	gtk_box_pack_start (GTK_BOX (vbox), hbox1, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox2, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox3, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox4, FALSE, FALSE, 0);
	label1 = gtk_label_new("Режим: ");
	gtk_box_pack_start (GTK_BOX (hbox1),label1, FALSE, FALSE, 0);
	label4 = gtk_label_new("Заучивание");
	label2 = gtk_label_new("Счет: ");
	gtk_box_pack_start (GTK_BOX (hbox1), label4, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (hbox1), label2, FALSE, FALSE, 0);




	srand(time(0));
     	string correct_rus[10];
     	string correct_eng[10];
     	string incorrect[30];
     	int state[10][2];
     	for(int i = 0; i < 10; ++i){ 
	 	state[i][0] = 0;
         	state[i][1] = 0;
     	}
	int mas[10];
	int mas_inc[30];
	get_correct_words_for_first_mode(mas,correct_rus,correct_eng,10);
	get_incorrect_words_for_first_mode(mas,mas_inc,incorrect,10,30);
	bool active = true;
	int answer_correct,incorrect_pos = 5;
	int k = 0;
	//while(active){
		//if(state[k%10][0] < 2){
		answer_correct = rand()%4 + 1;
		incorrect_pos = rand()%28 + 2;
	//gchar* s =str_to_char(correct_eng[k%10]);
	switch (answer_correct){
			case 1: {

		button2 = gtk_button_new_with_label (str_to_char(correct_eng[k%10]));
		gtk_box_pack_start (GTK_BOX (hbox3), button2, FALSE, FALSE, 0);
		g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(press_button), NULL);
		button3 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos]));
		gtk_box_pack_start (GTK_BOX (hbox3), button3, FALSE, FALSE, 0);
		button4 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos-1]));
		gtk_box_pack_start (GTK_BOX (hbox4), button4, FALSE, FALSE, 0);
		button5 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos-2]));
		gtk_box_pack_start (GTK_BOX (hbox4), button5, FALSE, FALSE, 0);
		break;
}
			case 2:{
		button2 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos]));
		gtk_box_pack_start (GTK_BOX (hbox3), button2, FALSE, FALSE, 0);
		button3 = gtk_button_new_with_label (str_to_char(correct_eng[k%10]));
		gtk_box_pack_start (GTK_BOX (hbox3), button3, FALSE, FALSE, 0);
		g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(press_button), NULL);
		button4 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos-1]));
		gtk_box_pack_start (GTK_BOX (hbox4), button4, FALSE, FALSE, 0);
		button5 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos-2]));
		gtk_box_pack_start (GTK_BOX (hbox4), button5, FALSE, FALSE, 0);
			break;
}
			case 3:{
		button2 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos]));
		gtk_box_pack_start (GTK_BOX (hbox3), button2, FALSE, FALSE, 0);
		button3 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos-1]));
		gtk_box_pack_start (GTK_BOX (hbox3), button3, FALSE, FALSE, 0);
		button4 = gtk_button_new_with_label (str_to_char(correct_eng[k%10]));
		gtk_box_pack_start (GTK_BOX (hbox4), button4, FALSE, FALSE, 0);
		g_signal_connect(G_OBJECT(button4), "clicked", G_CALLBACK(press_button), NULL);
		button5 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos-2]));
		gtk_box_pack_start (GTK_BOX (hbox4), button5, FALSE, FALSE, 0);
			break;
}
			case 4:{
		button2 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos]));
		gtk_box_pack_start (GTK_BOX (hbox3), button2, FALSE, FALSE, 0);
		button3 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos-1]));
		gtk_box_pack_start (GTK_BOX (hbox3), button3, FALSE, FALSE, 0);
		button4 = gtk_button_new_with_label (str_to_char(incorrect[incorrect_pos-2]));
		gtk_box_pack_start (GTK_BOX (hbox4), button4, FALSE, FALSE, 0);
		button5 = gtk_button_new_with_label (str_to_char(correct_eng[k%10]));
		gtk_box_pack_start (GTK_BOX (hbox4), button5, FALSE, FALSE, 0);
		g_signal_connect(G_OBJECT(button5), "clicked", G_CALLBACK(press_button), NULL);
			break;
}
}
		label3 = gtk_label_new(str_to_char(correct_rus[k%10]));
		gtk_box_pack_start (GTK_BOX (hbox2), label3, FALSE, FALSE, 0);
		
	/*if(answer == answer_correct) state[k%10][0]++;
	else state[k%10][1]++;
	if(state[k%10][0] == 2){
		put_words_mem(correct_rus,correct_eng);
		}
	}
	k++;
	} */
	//printf(butt);
	gtk_widget_show_all(content_area);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);	
}


void povt(GtkButton *button, gpointer data){
	GtkWidget *dialog, *vbox, *hbox1,*hbox2,*hbox3,*hbox4, *button1, *button2, *button3, *button4,*button5, *button6, *label1, *label2, *label3,*label4, *radiobutton1, *radiobutton2, *content_area;
	GtkDialogFlags flags;
	flags = GTK_DIALOG_DESTROY_WITH_PARENT;
	dialog =gtk_dialog_new_with_buttons("Повторение",NULL,flags,GTK_STOCK_STOP ,GTK_RESPONSE_ACCEPT,NULL);
	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	vbox = gtk_vbox_new (TRUE, 3);
	gtk_container_add (GTK_CONTAINER (content_area), vbox);

	hbox1 = gtk_hbox_new (TRUE, 3);
	hbox2 = gtk_hbox_new (TRUE, 3);
	hbox3 = gtk_hbox_new (TRUE, 3);
	hbox4 = gtk_hbox_new (TRUE, 3); 
	gtk_box_pack_start (GTK_BOX (vbox), hbox1, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox2, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox3, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox4, FALSE, FALSE, 0);
	button2 = gtk_button_new_with_label ("%Answer1%");
	gtk_box_pack_start (GTK_BOX (hbox3), button2, FALSE, FALSE, 0);
	button3 = gtk_button_new_with_label ("%Answer2%");
	gtk_box_pack_start (GTK_BOX (hbox3), button3, FALSE, FALSE, 0);
	button4 = gtk_button_new_with_label ("%Answer3%");
	gtk_box_pack_start (GTK_BOX (hbox4), button4, FALSE, FALSE, 0);
	button5 = gtk_button_new_with_label ("%Answer4%");
	gtk_box_pack_start (GTK_BOX (hbox4), button5, FALSE, FALSE, 0);
	//button6 = gtk_button_new_with_label ("START/STOP");
	//gtk_box_pack_start (GTK_BOX (vbox), button6, FALSE, FALSE, 0);
	label1 = gtk_label_new("Режим: ");
	gtk_box_pack_start (GTK_BOX (hbox1),label1, FALSE, FALSE, 0);
	//radiobutton1 = gtk_radio_button_new(NULL);
	label4 = gtk_label_new("Заучивание");
	//add_widget_with_label(GTK_CONTAINER(hbox1), "Заучивание", radiobutton1);
	//add_widget_with_label(GTK_CONTAINER(hbox1), "Повторение", radiobutton2);
	label2 = gtk_label_new("Счет: ");
	label3 = gtk_label_new("%Word%");
	gtk_box_pack_start (GTK_BOX (hbox1), label4, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (hbox1), label2, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (hbox2), label3, FALSE, FALSE, 0);

	gtk_widget_show_all(content_area);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

void zauch(GtkButton *button, gpointer data){
	GtkWidget *dialog, *vbox, *hbox1,*hbox2,*hbox3,*hbox4, *button1, *button2, *button3, *button4,*button5, *button6, *label1, *label2, *label3,*label4, *radiobutton1, *radiobutton2, *content_area;
	GtkDialogFlags flags;
	flags = GTK_DIALOG_DESTROY_WITH_PARENT;
	dialog =gtk_dialog_new_with_buttons("Заучивание",NULL,flags,GTK_STOCK_STOP ,GTK_RESPONSE_ACCEPT,NULL);
	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	vbox = gtk_vbox_new (TRUE, 3);
	gtk_container_add (GTK_CONTAINER (content_area), vbox);

	hbox1 = gtk_hbox_new (TRUE, 3);
	hbox2 = gtk_hbox_new (TRUE, 3);
	hbox3 = gtk_hbox_new (TRUE, 3);
	hbox4 = gtk_hbox_new (TRUE, 3); 
	gtk_box_pack_start (GTK_BOX (vbox), hbox1, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox2, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox3, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), hbox4, FALSE, FALSE, 0);
	button2 = gtk_button_new_with_label ("%Answer1%");
	gtk_box_pack_start (GTK_BOX (hbox3), button2, FALSE, FALSE, 0);
	button3 = gtk_button_new_with_label ("%Answer2%");
	gtk_box_pack_start (GTK_BOX (hbox3), button3, FALSE, FALSE, 0);
	button4 = gtk_button_new_with_label ("%Answer3%");
	gtk_box_pack_start (GTK_BOX (hbox4), button4, FALSE, FALSE, 0);
	button5 = gtk_button_new_with_label ("%Answer4%");
	gtk_box_pack_start (GTK_BOX (hbox4), button5, FALSE, FALSE, 0);
	//button6 = gtk_button_new_with_label ("START/STOP");
	//gtk_box_pack_start (GTK_BOX (vbox), button6, FALSE, FALSE, 0);
	label1 = gtk_label_new("Режим: ");
	gtk_box_pack_start (GTK_BOX (hbox1),label1, FALSE, FALSE, 0);
	//radiobutton1 = gtk_radio_button_new(NULL);
	//radiobutton2 = gtk_radio_button_new_from_widget(GTK_RADIO_BUTTON(radiobutton1));
;
	label4 = gtk_label_new("Заучивание");
	//add_widget_with_label(GTK_CONTAINER(hbox1), "Повторение", radiobutton2);
	label2 = gtk_label_new("Счет: ");
	label3 = gtk_label_new("%Word%");
	gtk_box_pack_start (GTK_BOX (hbox1), label4, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (hbox1), label2, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (hbox2), label3, FALSE, FALSE, 0);
	gtk_container_remove(GTK_CONTAINER(hbox4),button4);
	gtk_widget_show_all(content_area);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

void draw_pre_inter(void){
	GtkWidget *window, *vbox, *hbox1,*hbox2,*hbox3,*hbox4, *button2, *button3, *button4,*button5, *button6, *label1, *label2, *label3, *radiobutton1, *radiobutton2, *togglebutton;
	GSList *group;
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
	label1 = gtk_label_new("Режим: ");
	gtk_box_pack_start (GTK_BOX (hbox1),label1, FALSE, FALSE, 0);
	radiobutton1 =gtk_radio_button_new_with_label(NULL, "Заучивание");
	//toglebutton2 =gtk_toggle_button_new_with_label(group, "Повторение"); 	
	gtk_box_pack_start (GTK_BOX (hbox1),radiobutton1, FALSE, FALSE, 0);
	//gtk_box_pack_start (GTK_BOX (hbox1),radiobutton2, FALSE, FALSE, 0);
	button6= gtk_button_new_with_label ("START/STOP");
 	//if 			(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1)))		
	//printf("TRUE");
			
	g_signal_connect(G_OBJECT(button6), "clicked", G_CALLBACK(first_mode), NULL);
	//printf("TRUE");
	gtk_box_pack_start (GTK_BOX (vbox),button6, FALSE, FALSE, 0);
	gtk_widget_show_all (window);
}

