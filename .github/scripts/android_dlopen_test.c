#include <dlfcn.h>
#include <stdio.h>

int
main(int argc, char **argv)
{
   if (argc != 2) {
      fprintf(stderr, "usage: %s /path/to/libtinymesa.so\n", argv[0]);
      return 2;
   }

   void *library = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
   if (!library) {
      fprintf(stderr, "dlopen_failed: %s\n", dlerror());
      return 1;
   }

   dlerror();
   void *ir3_compile = dlsym(library, "ir3_compile_shader_nir");
   const char *error = dlerror();
   if (error) {
      fprintf(stderr, "dlsym_failed: %s\n", error);
      return 1;
   }

   printf("dlopen_ok\n");
   printf("ir3_compile_shader_nir=%p\n", ir3_compile);
   dlclose(library);
   return 0;
}
