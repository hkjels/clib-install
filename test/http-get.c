
#include <assert.h>
#include <stdlib.h>
#include "fs.h"
#include "http-get.h"

int main() {
  response_t *res = http_get("http://google.com");
  assert(res);
  assert(res->data);
  assert(res->ok);
  assert(200 == res->status);

  assert(0 == http_get_file("http://google.com", "./google.html"));
  assert(0 == fs_exists("./google.html"));
  return 0;
}
