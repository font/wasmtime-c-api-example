#ifndef CUSTOM_HANDLER_H
#define CUSTOM_HANDLER_H

struct custom_handler_s
{
  const char *name;
  const char *feature_string;
  int (*load) (void **handle);
  int (*unload) (void *handle);
  int (*exec_func) (void *handle, const char *pathname, char *const argv[]);
};

#endif
