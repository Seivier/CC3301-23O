#include <stdio.h>

int main(){
  FILE *f = fopen("prueba.txt", "r+");
  /*
   * modo:
   * r -> read  para leer un archivo
   * w -> write   escribir, lo que estaba antes se borra
   * a -> append  escribir, agregar al final del archivo
   * r+ -> read+write    leer y escribir, no borra lo que estaba antes
   */

  /* fgetc: obtiene un caracter y avanza en uno el f
  char c = fgetc(f);
  printf("caracter: %c\n", c);
  */

  /* fgets: lee una línea de a lo más size-1 caracteres
   * char *fgets(char *s, int len, FILE *stream);
   * s : string al que se va a leer
   * len: cantidad maxima a leer
   * stream: archivo (FILE*)
   */
  /*
  char buf[100]; // buf de buffer
  fgets(buf, 100, f);
  printf("%s\n", buf);
  */

  /* fread: lee una cantidad size de elementos en un string
   * size_t fread(char *buf, size_t len, size_t size, FILE *file);
   * buf: string al que se ve a leer
   * len: cantidad de elementos a leer
   * size: tamaño en bytes de un elemento
   * file: archivo
   */
  /*
  char buf[100];
  fread(buf, 4, 1, f);
  printf("%s\n", buf);
  */

  /*
   * fputc
   * int putc(char c, FIL *stream);
   * coloca el caracter c donde está el puntero
   */
  // fputc('y', f);

  /*
   * fputs
   * int fputs(const char *s, FILE *stream);
   * 
   */
  // fputs("chao", f);
  
  /* fwrite
   * size_t fwrite(const void *buf, size_t len, size_t size, FILE *stream)
   * buf: buffer desde el que se escribe
   * len: cantidad de elementos a escribir
   * size: tamaño en bytes de cada elemento
   */
  // char buf[] = {"holahola"};
  // fwrite(buf, 4, 1, f);

  /* fseek: mover el puntero al archivo
   * int fseek(FILE *stream, long offset, int mode);
   * stream es el archivo
   * offset: cantidad de espacios que vamos a mover el puntero
   * mode: modo de la funcion
   *       SEEK_SET: mover desde el inicio del archivo
   *       SEEK_CUR: mover desde la posición actual del puntero
   *       SEEK_END: mover desde el fin del archivo
   */
  /*
  fseek(f, 5*k, SEEK_CUR);
  char buf[4];
  fread(buf, 4, 1, f);
  printf("%s\n", buf);
  */
}
