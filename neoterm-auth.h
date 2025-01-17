#ifndef NEOTERM_AUTH_H
#define NEOTERM_AUTH_H

#include <stdbool.h>

#ifdef __ANDROID__
# ifndef NEOTERM_HOME
#  define NEOTERM_HOME "/data/data/com.neoterm/files/home"
# endif
# ifndef NEOTERM_PREFIX
#  define NEOTERM_PREFIX "/data/data/com.neoterm/files/usr"
# endif
# define AUTH_HASH_FILE_PATH NEOTERM_HOME "/.neoterm_authinfo"
#else
# define AUTH_HASH_FILE_PATH "/tmp/access_hash"
#endif

#ifdef  __cplusplus
extern "C" {
#endif

// Hash password using PBKDF function.
// Returns digest (in binary form) or NULL if failed.
unsigned char *neoterm_passwd_hash(const char *password);

// Update file that stores password hash
// Return true on success, false otherwise.
bool neoterm_change_passwd(const char *new_password);

// Check validity of password (user name is ignored).
// Return true if password is ok, otherwise return false.
bool neoterm_auth(const char *user, const char *password);

#ifdef  __cplusplus
}
#endif

#endif
