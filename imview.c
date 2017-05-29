#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp = popen ("display -resize 300% -filter Box -", "w");
  int i, r, g, b;
  scanf ("%d %d", &r, &b);
  if (r != -1) {
    printf ("Error: expected -1 as first integer\n");
    return 0;
  }
  fprintf (fp, "P6\n256 256\n255\n");
  for (i=0; i<65536; i++) {
    scanf ("%d %d %d", &r, &g, &b);
    fprintf (fp, "%c%c%c", r, g, b);
  } 
  pclose (fp);
}
