#include "grammar_graph.cpp"
#include <gtk/gtk.h>
int main (int argc, char *argv[]) {
	gtk_init (&argc, &argv);
	draw_pre_inter();
	gtk_main ();
	return (0);
}
