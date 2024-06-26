#ifndef ALIBTCC_LIBTCC_EXT_H
#define ALIBTCC_LIBTCC_EXT_H

#ifdef __ANDROID__
# include <android/asset_manager.h>
#endif

#include "tcc/libtcc.h"

#ifdef __cplusplus
extern "C" {
#endif

/* sets the paths of an TCC compilation context */
LIBTCCAPI void atcc_configure_state(TCCState* state);
/* create a new TCC compilation context, compiles libtcc1 if missing and configures with atcc_configure_state */
LIBTCCAPI TCCState* atcc_new();

/* build ar archives with tiny_libmaker. Returns 0 on success, another value on failure */
LIBTCCAPI int atcc_make_ar(const char* name, int file_count, char** files);

/* build libtcc1.a, returns 0 on success, another value on failure */
LIBTCCAPI int atcc_build_libtcc1();

#ifdef __ANDROID__
LIBTCCAPI void atcc_set_asset_manager(AAssetManager* manager);
#endif

/* set error/warning callback for every TCCState that will be configured with atcc_configure */
LIBTCCAPI void atcc_set_error_func(void* error_opaque, TCCErrorFunc *error_func);
/* set include path of every TCCState that will be configured with atcc_configure */
LIBTCCAPI void atcc_set_include_path(const char* path);

/* set name of libtcc1, pass NULL to reset this to default */
LIBTCCAPI void atcc_set_libtcc1_name(const char* name);
/* set path where the source files of libtcc1 are located, pass NULL to reset this to default */
LIBTCCAPI void atcc_set_libtcc1_src_path(const char* path);
/* set path where the object files of libtcc1 should be generated, pass NULL to reset this to default */
LIBTCCAPI void atcc_set_libtcc1_obj_path(const char* path);
/* set path where libtcc1 should be created, pass NULL to reset this do default */
LIBTCCAPI void atcc_set_libtcc1_dest_path(const char* path);

#ifdef __cplusplus
}
#endif

#endif //ALIBTCC_LIBTCC_EXT_H
