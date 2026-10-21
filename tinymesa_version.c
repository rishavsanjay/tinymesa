__attribute__((visibility("default"))) const char *tinymesa_mesa_version(void);

const char *tinymesa_mesa_version(void) {
  return PACKAGE_VERSION;
}
